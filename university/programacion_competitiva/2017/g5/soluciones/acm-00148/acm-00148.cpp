/**
 * Title: Anagram checker
 * URL: http://uva.onlinejudge.org/external/1/148.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se leen las palabras del diccionario y se trata de eliminar las que me asuguro no
   no sirven para las frases.
   + También se evitan procesar las frases que se sabe no tienen solución.
   + Por cada frase, se prueba por backtracking con las palabras del diccionario para 
   obtener todas las soluciones posibles.
   + Cada frase lleva una cuenta de las letras que utiliza y la cantidad de ocurrencias en la 
   que aparece. Luego una palabra del diccionario podrá utilizarse si todas sus letras aparecen
   en la frase y además en un número menor o igual de veces.

**/


#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

set<string> dictionary_full;
set<string> dictionary; //personalised dic for each phrase..


struct solution {
   vector <string> words; //words used in a solution
   map<char,int> letters; // letters[ ASCII_CODE ] = count
} sol;


struct phrase {   
   string line; //line as it is
   multiset<string> words; //repeated words
   map<char,int> letters; // letters[ ASCII_CODE ] = count
} p;


bool is_solution (){
   map<char,int>::iterator it2 = sol.letters.begin();
   for (; it2 != sol.letters.end (); it2++) {
      if (it2->second != 0) {
         return false;
      }
   }
   
   //see that I do not include the set consisting of the original words
   unsigned i = 0;
   for (; i < sol.words.size (); i++) {
      if (p.words.end () == p.words.find (sol.words[i]))
         return true;
   }

	return false;
}

void process_solution (){
   cout << p.line << " = ";
   for (unsigned i = 0; i < sol.words.size () - 1; i++) {
      cout << sol.words[i] << " ";
   }
   cout << sol.words[sol.words.size () - 1] << '\n';
}


bool valid_word (map<char, int>& tmp, string& w) {
   for (unsigned k = 0; k < w.size (); k++) {
      tmp[w[k]]--;
   }
   
   map<char,int>::iterator it2 = tmp.begin ();
   for (; it2 != tmp.end (); it2++) {
      if (it2->second < 0) {
         return false;
      }
   }
   return true;
}


void get_candidates (vector<string> &candidates){
   set<string>::iterator it1 = dictionary.begin ();
   if (sol.words.size () > 0) {
      it1 = dictionary.find (sol.words[sol.words.size () - 1]);
      it1++;
   }
   
   while (it1 != dictionary.end ()) {
      string w = *it1++;
      
      map<char, int> tmp = sol.letters;      
      if (! valid_word (tmp, w)) {
         continue;
      }
      
      candidates.push_back (w); //insert this word..
   }
	
}

void backtracking (){
	if(is_solution ()){
		process_solution ();
	}

	else{			
		vector<string> candidates;

		get_candidates(candidates);
		if (0 == candidates.size ())
		   return;
		
		
		for(unsigned i = 0; i < candidates.size (); i++){		
	      string w = candidates[i];
	      map<char, int> tmp = sol.letters;      
         if (! valid_word (tmp, w)) {
            continue;
         }

         //insert (use) this word
         map<char, int> lett = sol.letters;
         sol.letters = tmp;
			sol.words.push_back (candidates[i]);
			
			backtracking ();
			
			//undo last insert..
			sol.letters = lett;
			sol.words.pop_back ();
		}
	}
}


int main(){
   string word, line;
   int l_dic[256] = { 0 }; //count the instances of each letter in the dic..
   
   //fill up the dic...
	while (cin >> word) {
	   if ("#" == word) break;
	   for (unsigned i = 0; i < word.size (); i++) {
	      l_dic[(unsigned)word[i]]++;
	   }
	   dictionary_full.insert (word);
	}

   //phrases...
   cin.ignore ();
	while (getline(cin, line)) {
	   if ("#" == line) break;
 
	   p.line = line;
	   p.words.clear ();
	   p.letters.clear ();
	   stringstream ss;

	   ss << line;
	   
	   int l_phr[256] = { 0 }; //count the instances of each letter in the phrase..
	   
	   //tokenize phrase
	   while (ss >> word) {
	      p.words.insert (word);
         for (unsigned i = 0; i < word.size (); i++) {
            l_phr[(unsigned) word[i]]++;
            p.letters[ word[i] ]++;
         }
	   }


	   /* could I discard a phrase?...*/
	   unsigned i = 0;
	   for (; i < 256; i++) {
	      if (l_phr[i] > l_dic[i]) { //...yes
	         break;
	      }	   
	   }	   
	   if (i < 256) {
	      break; //...discard this phrase
	   }


      //try to shrink the dictionary!
      dictionary.clear ();      
      for (set<string>::iterator it = dictionary_full.begin(); it != dictionary_full.end (); it++) {
         string w = *it;
         
         unsigned i = 0;
         for (; i < w.size (); i++) {
            if (0 == l_phr[(unsigned) w[i]]) //I cannot use this word with actual phrase
               break;
         }
         if (i == w.size ()) {
            dictionary.insert (w);
         }
      }
      
      //..find all possible solutions...	   
      sol.letters = p.letters; // letters left
      sol.words.clear ();      
      backtracking ();
   }
	return 0;
}


