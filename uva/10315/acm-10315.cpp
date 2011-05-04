#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char value[128];

bool black_wins () {
   cout << "Black wins.\n";
   return true;
}

bool white_wins () {
   cout << "White wins.\n";
   return true;
}

bool tie () {
   cout << "Tie.\n"; 
   return true;
}

class card {
   friend istream &operator>> (istream&, card &);
   
   public:
   char suite;
   int rank;
   const bool operator< (const card & c2) const {
     return rank < c2.rank;
   }

};

istream &operator>> (istream &input, card& c) {
   char tmp[3] = { 0 };
   input.getline (tmp, 3, ' ');
   c.rank = value[tmp[0]];
   c.suite = tmp[1];
   //cout << "rank: " << c.rank << ", suite: " << c.suite << endl;
   return input;
}


struct hand {
   vector<card> h;

   hand () {
      h.resize (5);
   }
};


bool high_card (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return true;
}

bool ppair (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool two_pair (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool three_kind (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool straight (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool flush (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool full_house (const hand & h1, const hand & h2) {
   cout << "high_card" << endl;
   return false;
}

bool four_kind (const hand & h1, const hand & h2) {
   int val_h1 = 0, val_h2 = 0;

   if (h1.h[4].rank == h1.h[3].rank) {
      val_h1 = h1.h[4].rank;
   }
   else {
      if (h1.h[0].rank == h1.h[1].rank) {
         val_h1 = h1.h[0].rank;
      }
   }
    
   if (h2.h[4].rank == h2.h[3].rank) {
      val_h2 = h2.h[4].rank;
   }
   else {
      if (h2.h[0].rank == h2.h[1].rank) {
         val_h2 = h2.h[0].rank;
      }
   } 
  
   if ((val_h1 != 0) && (val_h2 != 0)) {
      if (val_h1 > val_h2)
         return black_wins ();
      if (val_h1 < val_h2) 
         return white_wins ();
      else
         return tie ();
   }

   if (val_h1 != 0 && val_h2 == 0) {
      return black_wins ();  
   }

   if (val_h1 == 0 && val_h2 != 0) {
      return white_wins ();
   }

   return false;
}


bool straight_flush (const hand & h1, const hand & h2) {
   cout << "sf" << endl;
   bool suite_h1 = true, rank_h1 = true;
   bool suite_h2 = true, rank_h2 = true;

   for (unsigned i = 0; i < 4; i++) {
      suite_h1 = suite_h1 && (h1.h[i].suite == h1.h[i + 1].suite);
      rank_h1 = rank_h1 && (h1.h[i].rank + 1 == h1.h[i + 1].rank);

      suite_h2 = suite_h2 && (h2.h[i].suite == h2.h[i + 1].suite);
      rank_h2 = rank_h2 && (h2.h[i].rank + 1 == h2.h[i + 1].rank);
   }
   
   if (not ((suite_h1 || rank_h1) || (suite_h2 || rank_h2)) ) {
      return false;
   }

   if ( ((suite_h1 && rank_h1) == true) && ((suite_h2 && rank_h2) == false) ) { //h1 wins
      return black_wins ();
   }

   if ( ((suite_h1 && rank_h1) == false) && ((suite_h2 && rank_h2) == true) ) { //h1 wins
      return white_wins ();
   }

   else { //both are straight_flush
      if (h1.h[4].rank > h2.h[4].rank) return black_wins ();
      else if (h1.h[4].rank < h2.h[4].rank) return white_wins ();
      else return tie ();
   }

}

bool (*f[9])(const hand &, const hand &) = { high_card, ppair, two_pair, three_kind, straight, \
                                             flush, full_house, four_kind, straight_flush};


int main () {
   value['T'] = 10;
   value['J'] = 11;
   value['Q'] = 12;
   value['K'] = 13;
   value['A'] = 14;
   value['2'] = 2, value['3'] = 3, value['4'] = 4, value['5'] = 5;
   value['6'] = 6, value['7'] = 7, value['8'] = 8, value['9'] = 9; 

   hand b;
   hand w;
   while (cin >> b.h[0] >> b.h[1] >> b.h[2] >> b.h[3] >> b.h[4] >> w.h[0] >> w.h[1] >> w.h[2] >> w.h[3] >> w.h[4]) {
      sort (b.h.begin (), b.h.end ());
      sort (w.h.begin (), w.h.end ());

      for (int i = 0; i < 5; i++) {
         cout << b.h[i].rank << " ";
      }
      cout << endl;

      unsigned i = 8;
      while (!f[i](b, w)) i--;

//      cout << b1.rank << "--" << b1.suite << endl;
   }
}
