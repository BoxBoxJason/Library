#include "livre.h"


int Livre::compteur = 0;
QList<Livre*> Livre::liste_livres;


Livre::Livre(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible)
    : auteur(auteur), titre(titre),editeur(editeur), isbn(isbn), public_cible(public_cible){
    code = compteur++;
    Livre::liste_livres.push_front(this);
}

int Livre::getCode(){return code;}
QString Livre::getAuteur(){return auteur;}
QString Livre::getTitre(){return titre;}
QString Livre::getEditeur(){return editeur;}
int Livre::getISBN(){return isbn;}
QString Livre::getPublicCible(){return public_cible;}
QString Livre::getEtat(){return etat;}
bool Livre::setEtat(const QString& nouvel_etat){
    bool success = false;
    if (nouvel_etat == QString("libre") || nouvel_etat == QString("emprunté") || nouvel_etat == QString("prêté")){
        success = true;
        etat = nouvel_etat;
    }
    return success;
}
