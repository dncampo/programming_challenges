/** 
 * Title: Army Strength
 * URL: http://www.spoj.pl/problems/ARMY/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution: 
   + Sólo se necesita saber quién tiene el individuo más fuerte. En caso de que sean de igual
	"fuerza" los más fuertes de cada ejército, por definició el problema ganará el perteneciente
	al bando de Godzilla.
	
**/

#include <stdio.h>

int n_cases, ng, nm, tmp, g_max, m_max, i, j;

int main(){

	scanf("%d",&n_cases);
	for(i = 0; i < n_cases; i++){
		g_max = m_max = -1;
		int flag = 0;
		
		scanf("%d%d", &ng,&nm);

		for(j = 0; j < ng; j++){
			scanf("%d",&tmp);
			if (tmp > g_max) g_max = tmp;
		}
		
		for(j = 0; j < nm; j++){
			scanf("%d",&tmp);
			if (tmp > g_max){
				printf("MechaGodzilla\n");
				break;
				falg = 1;
			}
		}
		if(flag == 0) printf ("Godzilla\n");
		cin.ignore(nm -j);
		
		if(g_max >= m_max) printf ("Godzilla\n");//cout << "Godzilla" << endl;
		else printf("MechaGodzilla\n");//cout << "MechaGodzilla" << endl;
	}
	return 0;
}
