#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main () {

	unsigned n_cases, n_candidates; 
	
	cin >> n_cases; cin.ignore ();

	for (unsigned i = 0; i < n_cases; i++) {
		cin >> n_candidates;
		cin.ignore ();
		
		vector<string> candidates (n_candidates + 1);
		for (unsigned j = 1; j < n_candidates + 1; j++) {
			getline (cin, candidates[j]);
		}

		vector <vector<unsigned> > voters;
		string line;
		getline (cin, line);

		while ("" != line) {
			stringstream ss;
			unsigned c;
			vector <unsigned> vot;
			ss << line;
			while (ss >> c) {
				vot.push_back (c);
			}
			voters.push_back (vot);
			getline (cin, line);
		}

		vector<unsigned> max (1,1);
		while (! max.empty ()) {
			max.clear ();

			vector <unsigned> count_votes (n_candidates, 0);
			for (unsigned i = 0; i < voters.size (); i++) {
				count_votes[ voters[i][0] - 1]++;
			}

			vector <double> perc_votes (n_candidates, 0);
			for (unsigned i = 0; i < voters.size (); i++) {
				perc_votes[i] = count_votes[i] / voters.size ();
				if (perc_votes[i] > 0.5){
					max.push_back (i);
				}
			}

			unsigned min = *min_element (count_votes.begin (), count_votes.end ());
			unsigned i;
			for (i = 0; i < count_votes.size (); i++) { //buscamos el cand con menos votos
				if (min == count_votes[i]) {
					break;
				}
			}

			//i = i + 1;
			//cout << i << endl;
for (unsigned y = 0; y < voters.size () ; y++) {
	//for (unsigned z = 1; z < voters[y].size () - 1; z++) {
		cout << voters [y].size () << " ";
	//}
	cout << endl;
}
cout << endl;
			
/*			for (unsigned j = 0; j < voters.size (); j++) {// lo removemos
				remove (voters[j].begin (), voters[j].end (),i);
			}
*/
		}
		//for (unsigned i = 0; i < max.size (); i++) cout << candidates [max[i] + 1] << endl;
		
	}

	return 0;
}
