#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

        


class MatrixShiftings {
public:

   
   int minimumShifts(vector <string> matrix, int value) {
      int ret = 999999999;
      for (unsigned i = 0; i < matrix.size(); i++) {
         for (unsigned j = 0; j < matrix[0].size(); j++) {

            if (matrix[i][j] - '0' == value) {
     
               int tmp = min (i, matrix.size() - i);
               tmp += min (j, matrix[0].size() - j);
               if (tmp < ret) {
                  ret = tmp;
               }
            }
         }      
      }
      if (ret != 999999999) return ret;
      else return -1;
   }
};
