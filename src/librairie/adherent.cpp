#include "adherent.h"

int Adherent::max_emprunts= 10;
int Adherent::compteur = 0;
QList<Adherent*> Adherent::liste;

Adherent::Adherent(const QString& nom,const QString& prenom, const QString& adresse) {
    if (Adherent::checkNomPrenomExiste(nom,prenom)) throw ;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    numero = compteur++;
}


bool Adherent::emprunterLivre(int code){
    bool success = true;
    // TODO
    return success;
}


bool Adherent::rendreLivre(int code){
    bool success = true;
    // TODO
    return success;
}


bool Adherent::checkNomPrenomExiste(const QString& nom,const QString& prenom){
    for (Adherent* adherent : Adherent::liste){
        if (adherent->nom == nom && adherent->prenom == prenom){
            throw ; // TODO
        }
    }
}
