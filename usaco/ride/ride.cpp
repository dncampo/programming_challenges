/*
ID: dncampo1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string comet, group;

    while(fin >> comet >> group){
       unsigned comet_prod = 1, group_prod = 1;

       for(unsigned i = 0; i < comet.size(); i++)
         comet_prod *= comet[i] - 'A' + 1;

       for(unsigned i = 0; i < group.size(); i++)
         group_prod *= group[i] - 'A' + 1;

       if( (group_prod % 47) == (comet_prod % 47) )
          fout << "GO" << endl;
       else
          fout << "STAY" << endl;

    }
    return 0;
}

