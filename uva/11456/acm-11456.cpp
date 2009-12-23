#include<iostream>
#include<algorithm>
#include<set>
#include<deque>
#include <vector>


using namespace std;

// Longest increasing subsequence O(nlogk) sin camino.
int LIS(const vector<unsigned>& input){
    set<int> s;
    set<int>::iterator k;

    for(unsigned i = 0; i < input.size(); i++){
        if(s.insert(input[i]).second){
           k = s.find(input[i]);

           if(++k != s.end()){
              s.erase(k);
           }
        }
    }
    return s.size();
}

int main() {
   unsigned n_cases;
   cin >> n_cases;

   for (unsigned i = 0; i < n_cases; i++) {
      unsigned q;
      cin >> q;
      //vector<Car> cars(q);
      //vector<unsigned> cars(q);
      deque<unsigned> d;
      for (unsigned j = 0; j < q; j++) {
         unsigned tmp;
         cin >> tmp;
         if (0 == d.size()) {
            d.push_back(tmp);
         }
         else {
            if (d.front() < tmp) {
               d.push_front(tmp);
            }
            else if (d.back() > tmp) {
               d.push_back(tmp);
            }
         }
      }
      cout << d.size() << endl;
   }
   return 0;
}