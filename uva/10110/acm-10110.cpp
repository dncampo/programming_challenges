	 /**
		*  Title: Light, more light
		*  URL: http://www.cs.ualberta.ca ~contest/club/020315/10110.html
		*  Resources of interest: 
		* Solver group: Mati-Mauri-Cesar
		* Contact e-mail:
		* Description of solution: En este problema simplemente preguntamos si el valor de entrada es un cuadrado perfecto es decir si su raiz es entera. Debemos usar unsigned long long para manejar estos nros ya que la entrada puede ser de 2^32-1
	  **/



#include <stdio.h>
#include <iostream.h>
#include <math.h>

using namespace std;

int main()
{
	unsigned long long n;

	cin >> n;
	while(n!=0)
	{
		unsigned long long m = (unsigned long long)sqrt((double)n);
		if(m*m == n)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cin >> n;
	}
	return 0;
}
