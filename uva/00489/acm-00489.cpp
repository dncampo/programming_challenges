/**
 * Title: Hangman Judge
 * URL: http://online-judge.uva.es/p/v4/489.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se va registrando la cantidad de letras correctas e incorrectas, como también las latreas que
	aparecen en la solución y aquellas que ya no están disponibles para usar.

**/


#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int main () {
	int round;
	char solution[20], guesses[20];

	while (~scanf ("%d", &round)) {
		if (-1 == round) return 0;

		vector <unsigned> alphabet (26, 0); //letras que aparecen en la solución
		vector <bool> used (26, false); //letras usadas en guessed

		scanf ("%s\n%s", solution, guesses);

		unsigned sol_len = strlen (solution);
		for (unsigned i = 0; i < sol_len; i++)
			alphabet[ solution[i] - 'a' ]++;

		unsigned strokes = 0;
		for (unsigned i = 0; i < strlen (guesses); i++) {
			unsigned c = guesses[i] - 'a';
			if (!used[c]) {

				if (0 == alphabet[c]) strokes++;

				used[c] = true;
				sol_len -= alphabet[c];

				if (0 == sol_len) break;

				alphabet[c] = 0;
			}
		}
		printf ("Round %d\n", round);
		if (strokes >= 7) printf ("You lose.\n");
		else if (sol_len == 0) printf ("You win.\n");
		else  printf ("You chickened out.\n");
	}
}
