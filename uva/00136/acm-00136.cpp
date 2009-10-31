#include <iostream>

using namespace std;

unsigned pos[3] = {2, 3, 5};
unsigned mul[3] = {1, 1, 1};
unsigned prod[3] = {2, 3, 5};

int main(){
	unsigned count = 2, ugly = 2;

	while (count < 1500){
		for(int i = 0; i < 3; i++){
			if (prod[i] == ugly)	{
				do{
					mul[i]++;
					while (mul[i] % 7 == 0) mul[i]++;
					prod[i] = mul[i] * pos[i];
				} while (prod[i] % 7 == 0) ;
			}
		}
		
		ugly = min(prod[0], min(prod[1], prod[2]));
		count++;				
cout << count << "-" << ugly<<endl;
	}
	cout << "The 1500'th ugly number is "<< ugly << "." << endl;

	return 0;
}

