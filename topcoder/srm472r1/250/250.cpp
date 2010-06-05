#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;


class ColorfulTilesEasy {
public:
   int theMin(string room) {
      unsigned count = 0;
      
      for (unsigned i = 1; i < room.size(); i++)  {
         if (room[i - 1] == room[i]) {
            count++;
            i++;
         }
      }
		return count;
   }


};
