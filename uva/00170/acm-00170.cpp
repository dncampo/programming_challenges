/**
 * Title: Clock Patience
 * URL: http://online-judge.uva.es/p/v1/170.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacena el mazo de cartas en una pila.
   + Se reparte dicho mazo en el "reloj". Éste se representa como un vector de pilas de cartas. La
   posición 0 del vector representa el rey (King, K), la posición 1 el As (A), ..., y la posición 12
   representa la Q.
   + Mientras en la pila actual existan cartas para sacar, se simula el juego.

**/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

unsigned mod_13[] = {
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
   0
};

struct Card {
   char rank, suit;
};

inline unsigned get_clock_number (const Card& card){
   if ('A' == card.rank)
      return 1;
   else if ('K' == card.rank)
      return 0;
   else if ('Q' == card.rank)
      return 12;
   else if ('J' == card.rank)
      return 11;
   else if ('T' == card.rank)
      return 10;
   else return card.rank - '0';
}

void deal_deck (stack<Card>& deck, vector<stack<Card> >& face_down_cards) {
   unsigned pos = 1; //start @ 1 o'clock :)
   while (! deck.empty ()) {
      face_down_cards[ mod_13[pos] ].push ( deck.top () );
      pos++;
      deck.pop ();
   }
}

void play_game (stack<Card>& deck) {
   vector<stack<Card> > face_down_cards (13);

   deal_deck (deck, face_down_cards);

   unsigned current = 0; //king's pile
   unsigned played_cards = 0;
   Card last_card;

   while (! face_down_cards[current].empty ()) {
      last_card = face_down_cards[current].top ();
      face_down_cards[current].pop ();
      played_cards++;

      current = get_clock_number (last_card);

   }
   if (played_cards < 10) cout << "0";
   cout << played_cards << "," << last_card.rank << last_card.suit << endl;
}

int main () {
   char r,s;

   while (cin >> r) {
      stack<Card> deck;

      if ('#' == r) return 0;
      cin >> s;
      Card c;
      c.rank = r, c.suit = s;
      deck.push (c);
      for (unsigned j = 1; j < 52; j++ ) {
         Card c;
         cin >> c.rank >> c.suit;
         deck.push (c);
      }
      play_game (deck);
   }
}