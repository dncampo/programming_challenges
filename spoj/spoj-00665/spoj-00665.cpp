#include <iostream>
#include <string>

using namespace std;


bool check(string& x, string &y, unsigned max_m){
	unsigned y_size = y.size();
	unsigned x_size = x.size();
	

	for(unsigned i = 0, j = 0, c = 0, k=0; (i < y_size) && (j < x_size);){
	
		if( (y_size - i) < ( (max_m - c) * (x_size - j) ) ) {
/*			cout << "exit with: " << (y_size - i) << "-" << ((max_m - c) * (x_size - j)) << endl;
			cout << "X: " << x << endl;
			cout << "x_size: " << x_size << endl;
			cout << "j: " << j << endl;
			cout << "Y: " << y << endl;
			cout << "y_size: " << y_size << endl;
			cout << "i: " << i << endl;
			cout << "c: " << c << endl;
			cout << "max_m: " << max_m << endl;
			cout << "K: " << k << endl;*/
			return false;
		}
		
		if(c == max_m) {
			c = 0;
			j++;
		
			if(j == x_size){
				return true;
			}
		}		
		
		if(y[i] == x[j]){
			c++;
		}		
		else{
			k++;
			i = k - 1;
//			cout << "i == " << i << endl;
			j = 0;
			c = 0;
		}
			
		if(j == x_size){
//			cout << "j is end----------------" << endl;			
			return true;
		}
		i++;
	}
	
return true;
}


unsigned find_m(string& x, string& y){
	unsigned size_x = x.size();
	unsigned size_y = y.size();
	unsigned max_m = size_y / size_x;
	
	for(int i = max_m; i > 0; i--){
//		cout << "Trying: " << i << endl;
		if(check(x, y, i)) return i;
	}
		
	return 0;
}


int main (){
	int cases;
	cin >> cases;
	
	for (int i = 0; i < cases; i ++){
		string x ,y ;
		cin >> x >> y;
		cout << find_m(x,y) << endl;
	}
	return 0;
}


