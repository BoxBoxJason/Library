#include "recueil.h"

QHash<int,Recueil*> Recueil::liste;

Recueil::Recueil(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible,const QString& indicateur)
    : Livre{auteur,titre,editeur,isbn,public_cible}, indicateur(indicateur) {

}


QString Recueil::getIndicateur(){return indicateur;}

