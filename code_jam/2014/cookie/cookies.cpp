#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main () {
	unsigned n_cases;
	double C, F, X;
	
	cin >> n_cases;
	
	for (unsigned t=0; t<n_cases; t++) {
		cin >> C >> F >> X;
		
		unsigned farms = 0;
		double acum = 0;
		double until_here;
		while (1) {
			until_here = acum + X/(2 + farms*F);
			double new_farm = acum + C/(2 + farms*F) + X/(2 + (farms + 1)*F);
			if (until_here  < new_farm) {				
				break;
			}
			else {
				acum += C / (2 + farms*F);
				farms++;
			}
		}
		cout << "Case #" << t+1 << ": " << fixed << setprecision(7) << until_here << endl;

	}
	return 0;
}
