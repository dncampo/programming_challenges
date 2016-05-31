/*
Title: The Blocks Problem
Tags: ad-hoc, simulation, parsing, strings
URL: https://uva.onlinejudge.org/external/1/101.pdf
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + The sequence of each number is calculated and stored into an array
    + The input is readed and the longest subsequence in the interval [n1, n2] is searched
*/

#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace std;
typedef unsigned short ushort;

unsigned short SIZE;

void initData(const ushort);

void move_onto(const ushort block_a, const ushort block_b);
void move_over(const ushort block_a, const ushort block_b);
void pile_onto(const ushort block_a, const ushort block_b);
void pile_over(const ushort block_a, const ushort block_b);
ushort find(const ushort);
void print_out();

vector < list<ushort> > data;

int main (int argc, char **argv){
  string command_a, command_b;
  ushort block_a, block_b;

  cin >> SIZE;
  initData(SIZE);

  while (1) {
	 cin >> command_a;
	 if("quit" == command_a) {
		print_out();
		return 0;
	 }
	 cin >> block_a >> command_b >> block_b;

	 if(block_a != block_b) {
		if("move" == command_a){
		  "onto" == command_b ? move_onto(block_a,block_b) : \
			 move_over(block_a,block_b);
		}
		else { //command_a == pile
		  "onto" == command_b ? pile_onto(block_a,block_b) : \
			 pile_over(block_a,block_b);
		}
	 }
  }
  return 0;
}

void initData(const ushort size){
	for(ushort i = 0; i < size; i++){
		list<ushort> l;
		l.push_back(i);
		data.push_back(l);
	}
}

void move_over(const ushort block_a, const ushort block_b){
  const ushort index_a = find(block_a);
  const ushort index_b = find(block_b);

  // invalid
  if(index_a == index_b) return;

  while(data[index_a].back() != block_a){ //pop what is necessary from a
	 ushort tmp = data[index_a].back();
	 data[tmp].push_back(tmp);
	 data[index_a].pop_back();
  }
  data[index_a].pop_back();
  data[index_b].push_back(block_a); //stack a over b
}

void pile_onto(const ushort block_a, const ushort block_b){
  const ushort index_a = find(block_a);
  const ushort index_b = find(block_b);

  // invalid
  if(index_a == index_b) return;

	while(data[index_b].back() != block_b){ //b's top blocks to its place
			ushort tmp = data[index_b].back();
			data[tmp].push_back(tmp);
			data[index_b].pop_back();
		}

		vector<ushort> tmp;
		for(; data[index_a].back() != block_a;){ //a stack over tmp
			tmp.push_back(data[index_a].back());
			data[index_a].pop_back();
		}
		tmp.push_back(data[index_a].back());
		data[index_a].pop_back();

		while(tmp.size() != 0){ //tmp stack over b
			data[index_b].push_back(tmp.back());
			tmp.pop_back();
		}
}

void pile_over(const ushort block_a, const ushort block_b){
  const ushort index_a = find(block_a);
  const ushort index_b = find(block_b);

  // invalid
  if(index_a == index_b) return;
  vector<ushort> tmp;

  //stack a and all what is above it on top of b
  for(; data[index_a].back() != block_a;){
	 tmp.push_back(data[index_a].back());
	 data[index_a].pop_back();
  }
  tmp.push_back(data[index_a].back());
  data[index_a].pop_back();

  while(tmp.size() != 0){
	 data[index_b].push_back(tmp.back());
	 tmp.pop_back();
  }
}


void move_onto(const ushort block_a, const ushort block_b){
  const ushort index_a = find(block_a);
  const ushort index_b = find(block_b);

  // invalid
  if(index_a == index_b) return;

  ushort index = index_a, n = block_a;

  for(ushort i = 0; i < 2; i++){ //pop a, then b
	 while(data[index].back() != n){
		ushort tmp = data[index].back();
		data[tmp].push_back(tmp);
		data[index].pop_back();
	 }
	 index = index_b;
	 n = block_b;
  }
  data[index_a].pop_back();
  data[index_b].push_back(block_a); //move a onto b
}


ushort find(ushort nblock){
  for(ushort i = 0; i < data.size(); i++) {
	 list<ushort>::iterator index = data[i].begin();
	 for(; index != data[i].end(); index++){
		if(*index == nblock) return i;
	 }
  }
  return SIZE;
}

void print_out(){
  for(ushort i = 0; i < data.size(); i++){
	 list<ushort> l = data[i];
	 cout << i  << ":";
	 for(list<ushort>::iterator l= data[i].begin(); l != data[i].end(); l++)
		cout << " " << *l;
	 cout << endl;
	}
}
