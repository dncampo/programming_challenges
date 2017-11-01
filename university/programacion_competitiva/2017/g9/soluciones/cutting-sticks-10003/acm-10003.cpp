/**
 * Title: Cutting sticks 
 * URL: http://online-judge.uva.es/p/v100/10003.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se utiliza programacion dinamica para resolver el problema.
    La funcion recursiva que se define es:
    m[i][j] = | 0, si i+1 = j ; 
              | min  {m[i][k]+[k][j]} + p[j]-p[i], para todo i < k < j
    y la implementación de la funcion se asemeja a el problema de multiplicacion optima de matrices
**/

#include<iostream>
#include<vector>
#include<limits>

using namespace std;

vector<vector<unsigned> > m;

unsigned solve(vector<unsigned>& p){
    m.resize(p.size());
    
    for(unsigned i = 0; i < p.size(); i++){
        m[i].assign(p.size(), 0);
    }
    
    for(unsigned l = 2; l < p.size(); l++) {
        for(unsigned i = 0; i < p.size()-l;i++){
            unsigned j = i+l;

            m[i][j] = numeric_limits<unsigned>::max();

            for(unsigned k = i+1; k < j ; k++){
                unsigned q = m[i][k] + m[k][j] + p[j] - p[i];
                
                if(q < m[i][j]){
                    m[i][j] = q;
                }
            }
        } 
    }

    return m[0][p.size()-1];
}

int main(){
    unsigned n, size;
    vector<unsigned> p;    
    
    cin >> n;
    
    while(n > 0){
        cin >> size;

        p.push_back(0);
        
        for(unsigned i = 0; i < size; i++){
            unsigned tmp;
            cin >> tmp;
            p.push_back(tmp);
        }
        
        p.push_back(n);
        
        cout << "The minimum cutting is " << solve(p) << "." << endl;

        cin >> n;
        p.clear();
    }

    return 0;
}

