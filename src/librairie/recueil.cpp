#include "recueil.h"

QHash<int,Recueil*> Recueil::liste;

Recueil::Recueil(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& indicateur,int code_bibliotheque_origine)
    : Livre{auteur,titre,editeur,isbn,public_cible,code_bibliotheque_origine}, indicateur(indicateur) {

}


QString Recueil::getIndicateur(){return indicateur;}


QHash<int,Recueil*>* Recueil::getListe(){return &(Recueil::liste);}


QSet<Recueil*> Recueil::getRecueilsFromIndicateur(const QString& indicateur){
    QSet<Recueil*> result;
    for (Recueil* recueil : Recueil::liste){
        if (recueil->indicateur == indicateur) result.insert(recueil);
    }
    return result;
}
