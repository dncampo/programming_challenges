//BackTracking

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> data;

//int data[5];
long long sum;
bool pos;

void back(int index){
	
	if(index == 5 ){
		if(sum == 23){
			pos = true;
		} 
	} else {	
		sum += data[index];
//		cout <<"sum " << index << " " << sum << endl;
		back(index + 1);
		sum -= data[index];
		
		sum -= data[index];
	//	cout <<"res " << index << " " << sum << endl;
		back(index + 1);
		sum += data[index];
		
		sum *= data[index];
	//	cout <<"mul " << index << " " << sum << endl;
		back(index + 1);
		sum /= data[index];
	}
}

int main(){
	
	data.resize(5);
	for(int i =0 ; i < 5; i++){
		cin >> data[i];
	}	
	
	while(data[0] != 0 && data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0){

		sum = 0;		
		pos = false;		
		sum = 0;		
		back(0);
		
		while (next_permutation(data.begin(), data.end()) && !pos) {
			sum = 0;		
			back(0);
		}


		
		if(pos){
			cout << "Possible" << endl;
		} else {
			cout << "Impossible" << endl;
			
		}
		for(int i =0 ; i < 5; i++){
			cin >> data[i];
		}
	}
	
	return 0;
}
