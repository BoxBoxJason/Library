#include "theatre.h"


QHash<int,Theatre*> Theatre::liste;


Theatre::Theatre(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible,int siecle,int code_bibliotheque_origine)
    : Livre{auteur,titre,editeur,isbn,public_cible,code_bibliotheque_origine} , siecle(siecle)
{

}


QSet<Theatre*> Theatre::getTheatresFromSiecle(int siecle){
    QSet<Theatre*> result;
    for (Theatre * theatre : Theatre::liste){
        if (theatre->siecle == siecle) result.insert(theatre);
    }
    return result;
}


QHash<int,Theatre*>* Theatre::getListe(){return &(Theatre::liste);}
