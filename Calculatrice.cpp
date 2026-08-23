#include <iostream>
using namespace std; 
int main() {
    double a, b;
    char op;
    
    
    cout << " Entrez la valeur du premier chiffre : ";
    cin >> a;
    cout << " choisissez l'opération à effectué  ";
    cin >> op;
    cout <<  "Choix du deuxième chiffre : ";
    cin >> b;
    
    double resultat;
    
    if ( op == '+') {
          resultat = a + b;
    }
          else if ( op == '-') {
                     resultat = a - b;
    }
          else if (op == '*') {
                    resultat = a * b;
    }
          else if (op == '/') {
                  if (b == 0) {
                  cout << " Dénominateur doit être différent de zéro (0) " << endl; 
                  return 1;
                  
                  }
                  resultat = a / b;
          
    }     else {
              cout << " Operateur inconnu ! " << endl;
              return 1;
          }
                  
               
         cout << " Résultat : " << resultat << endl;
         return 0;
                  
          }
        
