#include<iostream>
#include<vector>
#include<limits>
#include<string>
using namespace std;

void ajouter(vector<int>& notes){
    int newnote;
    cout << "Note " << endl;
    cin >> newnote;

    while(cin.fail() || newnote < 0 || newnote > 20 || cin.peek() != '\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "valeur invalide , recommence(0-20) : ";
        cin >> newnote;
    }
    notes.push_back(newnote);
}

void afficher(const vector<int>& notes){
    if(notes.empty()){
        cout<< "Aucune note disponible." << endl;
        return;
    }
    for(int i : notes){
        cout << " " << i << " " ;
    }
    cout << endl;
}

void moyenne(const vector<int>& notes){
    int somme = 0;
    int moy;
    if(notes.empty()){
        cout << "Aucune note enregistré" << endl;
        return;
    }
    
        for(int i : notes){
            somme =+ i;
            
        }
    
    cout <<" la moyenne est : " << somme/notes.size() << endl;
    
}

void MinMax(vector<int>& notes){
    
    if(notes.empty()){

        cout<< "Aucune note enregistrer" << endl;
        return;
    }
    int max = notes[0];
    int min = notes[0];
    for(int i = 0; i < notes.size() ; i++){ 
        
        if(max < notes[i])
            max = notes[i];
        
        if(min > notes[i])
            min = notes[i];
        
    }
    cout << "Le minimum est : "<< min << " Alors que le max est : "<< max << endl; 
}

void compter(const vector<int>& notes){
    int compte = 0;
    if(notes.empty()){
        cout << " Aucune note " << endl; 
        return;
    }
    else{
        for(int i : notes){
            if(i >= 10)
                compte++;
            
        }
    }
    cout << "Nombre de note >= 10 : " << compte << endl;
    
}





int main(){
    bool continuer = false;
    vector<int> notes;
    int choix;
    while(!continuer){
        cout << "MENU" << endl
        << "1 - Ajouter une note" << endl
        << "2- Afficher les notes" << endl
        << "3- Afficher la moyenne" << endl
        << "4- Afficher le minimim et le maximum" << endl
        << "5 - Combien de notes sont superieur à 10 " << endl
        << "6- Quitter" << endl;
        cout << "choix :";
        cin >> choix;
        while(cin.fail() || choix < 0 || choix > 6 || cin.peek() !='\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "valeur invalide , recommence(1-6) : ";
        cin >> choix;
        }
        if(choix == 1){
            ajouter(notes);
        }
        else if(choix == 2){
            afficher(notes);
        }
        else if(choix == 3){
            moyenne(notes);
        }
        else if(choix == 4){
            MinMax(notes);
        }
        else if(choix == 5){
            compter(notes);
        }
        
        else{
            cout <<"A Bientôt" << endl;
            continuer = true;
        }
        
    }
    return 0;




}