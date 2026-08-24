#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;
struct contact{
    string nom;
    int telephone;
};

void ajouter(vector<contact>& carnet){
    contact c;
    cout << "Nom : " ;
    cin >> c.nom;
    cout << "Téléphone : ";
    cin >> c.telephone;
    carnet.push_back(c);
}

void afficher(const vector<contact>& carnet){
    if(carnet.empty()){
        cout << "vide " << endl;
        return;
    }
    for(const contact & c : carnet){
        cout << "Nom : " << c.nom << ", Tel : " << c.telephone << endl;
    }
}

void recherche(vector<contact>& carnet){
    string nom;
    cout << "Nom à rechercher : " ;
    cin >> nom;
    for(const contact & c : carnet){
        if(nom == c.nom){
            cout << "trouvé :)" << endl;
        return;
        }
    }
    cout << "Absent :()" << endl;
}

void sup(vector<contact>& carnet){
    string nom;
    cout << "Nom à Supprimer : " ;
    cin >> nom;
    for(int i = 0 ; i < carnet.size(); i++){ // reprendre et comprend
        if(nom == carnet[i].nom){
            carnet.erase(carnet.begin() + i );
            cout << "Supprimer  :)" << endl;
        return;
        }
    }
    cout << "Absent :()" << endl;
}


int main(){
    bool continuer = false;
    int choix;
    vector<contact> carnet;

    while(!continuer){
        cout << "MENU" <<endl
        << "1-Ajouter un contact" << endl
        << "2-Afficher tous les contact" << endl
        << "3-Recherche" << endl
        << "4-supprimer un contact" << endl
        << "5-Quitter" << endl
        << "Choix : " ;
        cin >> choix;
        while(cin.fail() || choix < 0 || choix > 5 || cin.peek()!= '\n'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() ,'\n');
            cout <<" invalide , recommence(1-5) : ";
            cin >> choix;
        }
        if(choix == 1){
            ajouter(carnet);
        }
        else if(choix == 2){
            afficher(carnet);
        }
        else if(choix == 3){
            recherche(carnet);
        }
        else if(choix == 4){
            sup(carnet);
        }
        
        else{
            cout <<"A Bientôt" << endl;
            continuer = true;
        }
    }
}