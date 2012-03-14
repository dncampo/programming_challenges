#include <iostream>

using namespace std;

int main () {
  int rows, cols;
  string array;

  while (cin >> cols) {
    if (0 == cols) return 0;
    
    cin >> array;
    rows = array.size() / cols;

    int increasing_even_column = 0;
    int decreasing_odd_column = 1;
    for (int i=0; i<cols;i++) {
      int multiplier_even_column = 0;
      int multiplier_odd_column = 2;
      for (int j=0; j<rows;j++) {
 
	//posición impar
	if (j & 1) {
	  cout << array[ multiplier_odd_column * cols - decreasing_odd_column ];
	  multiplier_odd_column += 2;
	}
	else {
	  cout <<  array[ multiplier_even_column * cols + increasing_even_column ];
	  multiplier_even_column += 2;
	}
      }
      increasing_even_column++;
      decreasing_odd_column++;
    }
    cout << "\n";
  }

}
