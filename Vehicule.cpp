#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class vehicule {
    public : 
        double virtual consommation (){
            return 0;
        }
        string virtual nom(){
            return "Voiture";
        }
};

class voiture : public vehicule{
    private : 
        double consoVoiture;

    public : 
        voiture(double consV): consoVoiture(consV){}
        double consommation() override {
            return consoVoiture;
        }

        string nom() override{
            return "Voiture";
        }
};

class  moto : public vehicule{
    private : 
        double consoMoto;

        public : 
            moto(double consM ) : consoMoto(consM) {}
            double consommation() override {
                return consoMoto;
            }
            string nom() override{
                return "Moto";
            }
};

class camion : public vehicule {
    private : 
        double consoCamion;
    public: 
        camion (double  consC) : consoCamion(consC){}
        double consommation() override{
            return consoCamion;
        }
        string nom() override{
            return "Camion";
        }
};

class train  : public vehicule {
    private : 
        double consoTrain;
        
        public : 
            train (double consT) : consoTrain(consT){}
            double consommation() override{
                return consoTrain;
            }

            string nom() override {
                return "Train";
            }
};

int main(){
    vector<vehicule*> type;

    type.push_back( new voiture(10));
    type.push_back(new moto(20));
    type.push_back(new camion(20));
    type.push_back(new train(30));
    int totalcons = 0;
    for(vehicule* i : type){
        cout << i->nom() << "  consommamation: " << i->consommation() << " L/Kh" << endl;
        totalcons += i->consommation();
        
    }
    cout << "la moyenne de consommation totale est " << totalcons/ type.size() << endl;
    for(vehicule* i : type) delete i;
    return 0;
}