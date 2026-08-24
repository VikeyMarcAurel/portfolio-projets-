#include<iostream>
#include<vector>
#include<limits>
#include<string>
using namespace std;

struct livre{
    string nom;
    string auteur;
    bool disponible = true;
};
void ajouter(vector<livre>& document){
    livre l  ; 
    cout << "Nom : ";
    cin >> l.nom ;
    cout << "Auteur : ";
    cin >> l.auteur;
    document.push_back(l);
    
}

void afficher(const vector<livre>& document){
    for(const livre & l : document){
        cout << "Nom : " << l.nom << ", Auteur : " << l.auteur << endl;
    }
}

void emprunter(vector<livre> & document ){
    livre e;
    cout <<"Nom du livre : ";
    cin >> e.nom;
    cout << " Auteur : ";
    cin >> e.auteur;
    for(livre& l : document){
        if(l.nom == e.nom && l.auteur == e.auteur){
            if(l.disponible){
                cout << "Emprunté avec succès" << endl;
                l.disponible = false;
            }
            else{
                cout << "Livre déja emprunté" << endl;
            }
            return;
        }
    }
    cout << "Indisponible le livre n'existe pas dans la bibliothèque. ";
}
void rendre(vector<livre>& document){ 
    char rep;
    livre r;
    cout << "Nom du livre : ";
    cin >> r.nom;
    cout << "Auteur :";
    cin >> r.auteur;
    for(livre& l : document){
        
        if(l.nom == r.nom && l.auteur == r.auteur){
            if(!l.disponible){
                l.disponible = true;
                cout << "Rendu avec succès . " <<endl;
            }
            else{
                cout << "Ce livre n'était pas emprunté ." <<endl;
            }
            return;
        }
        
    }
    cout << "N'appartient pas a la Bibliotèque" << endl;
    cout<< "enregistrer comme new livre ? (o/n): ";
    cin >> rep;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(rep == 'o'){ // ici ne fonctionne pas 
        ajouter(document);
    }
    else {
        cout << "ok";
        return;
    }
    
}

int main(){
    vector<livre> document;
    int choix;
    bool saisie = false;
    while(!saisie){
        cout << "MENU" <<endl
        << "1-Ajouter un livre" << endl
        << "2-Afficher tout les livres" << endl
        << "3-Emprunter un livre" << endl
        << "4-Rendre un livre" << endl
        << "5-Quitter" << endl
        << "Choix : ";
        cin >> choix;
        if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "erreur de type";
        }
        else if(cin.peek()!= '\n'){
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "erreur de type";
        }
        else if(choix == 1){
            ajouter(document);
        }
        else if(choix == 2){
            afficher(document);
        }
        else if(choix == 3){
            emprunter(document);
        }
        else if(choix == 4){
            rendre(document);
        }
        else if(choix < 0 || choix > 5){
            cout << "erreur" << endl;
        }
        else{
            cout <<"A Bientôt" << endl;
            saisie = true;
        }
    }
    return 0;
}