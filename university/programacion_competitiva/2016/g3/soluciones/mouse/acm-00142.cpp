/**
 * Title:  Mouse Clicks
 * URL: http://online-judge.uva.es/p/v1/142.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se crean tipos de datos para almacenar regiones, íconos y clicks.
   + Se lee la entrada y se va almacenando en vectores. Al finalizar la entrada se deshabilitan
   los íconos ocultos por regiones.
   + Para cada click se busca si pertenece a alguna región (de atrás para adelante, por si existiesen
   regiones que contengan a un mimso click pero que se solapen).
   + Si el click no pertenece a ninguna región, se procede a imprimir los íconos más cercanos al click
   que no estén ocultos (es decir bajo una región). Para buscar los íconos más cercanos a un click se
   realiza la distancia euclídea (pero sólo la suma, sin la raíz cuadrada, para evitar errores de
   redondeo. La mínima suma es la distancia más cercana).

**/


#include <iostream>
#include <vector>

using namespace std;

struct Region {
   unsigned x0, y0, x1, y1;
   char id;
};

struct Icon {
   unsigned x, y;
   unsigned id;
   bool hidden;
};

struct Mouse_Click {
   unsigned x, y;
};

inline unsigned squared (int x) {
   return x * x;
}

void disable_hidden_icons (const vector<Region>& regions, vector<Icon> &icons) {
   for (unsigned i = 0; i < regions.size (); i++) {
      for (unsigned j = 0; j < icons.size (); j++) {
         if (!icons[j].hidden && regions[i].x0 <= icons[j].x && regions[i].y0 <= icons[j].y \
            && regions[i].x1 >= icons[j].x && regions[i].y1 >= icons[j].y) {
            icons[j].hidden = true;
         }
      }
   }
}

bool check_regions (const vector<Region>& regions, const Mouse_Click& click) {
   //I'll check in reverse order, so in case of overlap the ambiguity is already resolved
   for (vector<Region>::const_reverse_iterator it = regions.rbegin (); it != regions.rend (); it++) {
      if (it->x0 <= click.x && it->y0 <= click.y && it->x1 >= click.x && it->y1 >= click.y) { //bingo
         cout << it->id << endl;
         return true;
      }
   }
   return false; //if I have checked all the regions without success, so no region selected
}

void check_icons (const vector<Icon>& icons, const Mouse_Click& click) {
   vector <unsigned> icon_distances (icons.size ());

   //euclidean formula, without the sqrt to avoid rounding errors
   unsigned min_sum = 500000; //more than enough
   for (unsigned i = 0; i < icons.size (); i++) {
      if (!icons[i].hidden) {
         icon_distances[i] = squared (icons[i].x - click.x) + squared (icons[i].y - click.y);
      }
      else {
         icon_distances[i] = 500000;
      }

      if (icon_distances[i] < min_sum) min_sum = icon_distances[i];
   }

   for (unsigned i = 0; i < icons.size (); i++) {
      if (icon_distances[i] == min_sum) {
         cout.width(3);
         cout << icons[i].id;
      }
   }
   cout << endl;
}

int main () {
   char type;
   char region_id = 'A';
   unsigned icon_id = 1;

   vector<Region> regions;
   vector<Icon> icons;
   vector<Mouse_Click> clicks;

   while (cin >> type) {
      if ('#' == type) break;

      else if ('R' == type) {
         Region r;
         cin >> r.x0 >> r.y0 >> r.x1 >> r.y1;
         r.id = region_id++;
         regions.push_back (r);
      }

      else if ('I' == type) {
         Icon i;
         cin >> i.x >> i.y;
         i.hidden = false;
         i.id = icon_id++;
         icons.push_back (i);
      }

      else { //Mouse click
         Mouse_Click m;
         cin >> m.x >> m.y;
         clicks.push_back (m);
      }
   }

   disable_hidden_icons (regions, icons);

   for (unsigned i = 0; i < clicks.size (); i++) {
      if (! check_regions (regions, clicks[i])) { //not clicked over a region
         check_icons (icons, clicks[i]); //so clicked near (or on) some icon
      }
   }

   return 0;
}
