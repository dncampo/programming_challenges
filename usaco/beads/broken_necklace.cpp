/*
ID: dncampo1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

#define LEFT(start_w, n_beads) ((start_w + n_beads - 1) % n_beads)
#define RIGHT(end_w, n_beads) ((end_w + 1) % n_beads)

using namespace std;

ofstream fout ("beads.out");
ifstream fin ("beads.in");


void paint (string& necklace, const unsigned start_w, const unsigned end_w, const char color) {
//fout << "before: " << necklace << endl;
   for (unsigned i = start_w; i <= end_w; i++)
      necklace[i] = color;
//fout << "after:  " << necklace << endl << endl;
}

unsigned right_count (const string& necklace, const unsigned end_w, const unsigned n_beads) {
   unsigned count = 0, pos = RIGHT (end_w, n_beads);
   char right_color = necklace[pos];
   pos = RIGHT (pos, n_beads);

   if (right_color != 'w') count++;
   while (right_color == necklace[pos] && pos != end_w) {
      count++;
      pos = RIGHT (pos, n_beads);
   }
   return count;
}

unsigned left_count (const string& necklace, const unsigned start_w, const unsigned n_beads) {
   unsigned count = 0, pos = LEFT (start_w, n_beads);
   char left_color = necklace[pos];
   pos = LEFT (pos, n_beads);

   if (left_color != 'w') count++;
   while (left_color == necklace[pos] && pos != start_w) {
      count++;
      pos = LEFT (pos, n_beads);
   }
   return count;
}

unsigned get_max (const string& necklace, const unsigned n_beads) {
   unsigned max = 0;
   unsigned pos = 0;

   while (pos < n_beads) {
      if (necklace[pos] != necklace[RIGHT(pos, n_beads)]) {
         unsigned tmp = left_count (necklace, RIGHT(pos, n_beads), n_beads) + \
            right_count (necklace, pos, n_beads);
         if (tmp > max) max = tmp;
      }
      pos++;
   }
   if (0 == max) return necklace.size ();
   return max;
}

unsigned paint_whites (string& necklace, const unsigned n_beads) {
   unsigned no_painted = 0;
   unsigned i = 0;

   while (i < n_beads) {
      if ('w' == necklace[i]) {
         unsigned start_w = i;
         while ('w' == necklace[i] && i < n_beads) {
            i++;
         }
         unsigned end_w = i - 1;

         if (start_w == 0 && end_w == n_beads - 1) { //son todos w's!
            paint (necklace, 0, n_beads - 1, 'b'); //pinto todo de cualquier color
            //return necklace;
            return n_beads;
         }

         if (necklace[LEFT(start_w, n_beads )] == necklace[RIGHT(start_w, n_beads )]) { // bwwb => se convierte en bbbb
            paint (necklace, start_w, end_w, necklace[LEFT(start_w, n_beads )]);
         }
         else {
            unsigned left_cnt = left_count (necklace, start_w, n_beads);
            unsigned right_cnt = right_count (necklace, end_w, n_beads);
            if (left_cnt > right_cnt) {

               paint (necklace, start_w, end_w, necklace [LEFT(start_w, n_beads)] );
            }
            else if (left_cnt < right_cnt) {
               paint (necklace, start_w, end_w, necklace [RIGHT(end_w, n_beads)] );
            }
            else { //no se puede pintar (todavía) de ningún color
               //no_painted++;
               no_painted++;
            }
         }
      }
      else {
         i++;
      }
   }

   //a partir de acá es para solucionar el problema de: wwrww, wwbww; lo cuál
   //se debería hacer más eficiente.
   unsigned max_tmp1, max_tmp2, max_total;
   string tmp1, tmp2;
   tmp1 = tmp2 = necklace;
   if (0 < no_painted) {

      size_t w = necklace.find_first_of ('w');
      tmp1[w] = 'r';
      tmp2[w] = 'b';
      max_tmp1 = paint_whites (tmp1, n_beads);
      max_tmp2 = paint_whites (tmp2, n_beads);
   }
   else {
      max_tmp1 = get_max (tmp1, n_beads);
      max_tmp2 = get_max (tmp2, n_beads);
      if (max_tmp1 > max_tmp2) max_total = max_tmp1;
      else max_total = max_tmp2;

      return max_total;
   }
   max_total = (max_tmp1 > max_tmp2)? max_tmp1: max_tmp2;
   return max_total;
}



int main () {
   unsigned n_beads;
   fin >> n_beads;

   string necklace;
   fin >> necklace;

   fout << paint_whites (necklace, n_beads) << endl;
//   fout << get_max (tmp, n_beads) << endl;


}
