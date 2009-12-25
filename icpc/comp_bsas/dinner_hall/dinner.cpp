#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
   int H, M, S;
};

struct Card {
   Time time;
   char event;
};

bool less_time(const Time& a, const Time& c) {
   if (c.H > a.H) return true;
   else if (c.H == a.H && c.M > a.M) return true;
   else if (c.H == a.H && c.M == a.M && c.S > a.S) return true;
   else return false;
}

bool less_card(const Card& a, const Card& c) {
   if (less_time (a.time, c.time)) return true;
   else return false;
}

void read_card(Card &c) {
   char a,b;
   cin >> a >> b;
   char tmp[] = {a, b, '\0'};
   c.time.H = atoi(tmp);
   cin >> a; //:
   cin >> a >> b;
   tmp = {a, b, '\0'};
   c.time.M = atoi(tmp);
   cin >> a; //:
   cin >> a >> b;
   tmp = {a, b, '\0'};
   c.time.S = atoi(tmp);
   cin >> c.event;
}

unsigned count(vector<Card>& cards, unsigned enters, unsigned exits, unknowns) {


}

int main() {
   unsigned n_cards;
   while (cin >> n_cards) {
      if (0 == n_cards) return 0;
      vector<Card> cards(n_cards);
      unsigned unknowns = 0, enters = 0; exits = 0;
      for (unsigned i = 0; i < n_cards; i++) {
         Card c;
         read_card(c);
         if ('?' == c.event) unknowns++;
         else ('X' == c.event) exits++;
         else enters++;
         cards[i] = c;
      }
      sort(cards.begin(), cards.end(), less_card);
      cout << count(cards, enters, exits, unknowns);
      cout << "unknown: " << unknowns << endl;
      for (unsigned i = 0; i < n_cards; i++)
         cout << cards[i].time.H << ":" << cards[i].time.M << ":" << cards[i].time.S << " " << cards[i].event << endl;
   }
   return 0;
}
