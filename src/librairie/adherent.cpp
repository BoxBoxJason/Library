#include "adherent.h"
#include "../exceptions/notuniqueelementexception.h"
int Adherent::max_emprunts= 10;
int Adherent::compteur = 0;
QSet<Adherent*> Adherent::liste;

Adherent::Adherent(const QString& nom,const QString& prenom, const QString& adresse)
    : nom(nom) , prenom(prenom) , adresse(adresse), numero(Adherent::compteur++){
    if (Adherent::checkNomPrenomExiste(nom,prenom)) throw NotUniqueElementException("L'adhérent " + nom + " " + prenom + " est déjà enregistré.");
    Adherent::liste.insert(this);
}


Adherent::~Adherent(){
    for (Livre* livre : livres){
        livre->setDisponibilite(true);
    }
}


bool Adherent::emprunterLivre(int code) {
    bool success = false;
    if (livres.count() < Adherent::max_emprunts){
        success = true;
        Livre* livre = Livre::getExemplaireFromCode(code);
        livre->setDisponibilite(false);
        livres.insert(livre);
    }
    return success;
}


void Adherent::rendreLivre(Livre* livre){
    livre->setDisponibilite(true);
    livres.remove(livre);
}


bool Adherent::checkNomPrenomExiste(const QString& nom,const QString& prenom){
    bool existe = false;
    for (Adherent* adherent : Adherent::liste){
        if (adherent->nom == nom && adherent->prenom == prenom){
            existe = true;
            break;
        }
    }
    return existe;
}
