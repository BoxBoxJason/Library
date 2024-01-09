#include "roman.h"


QHash<int,Roman*> Roman::liste;

Roman::Roman(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& genre,int code_bibliotheque_origine)
    : Livre{auteur,titre,editeur,isbn,public_cible,code_bibliotheque_origine} , genre(genre)
{

}

QString Roman::getGenre(){return genre;}


QHash<int,Roman*>* Roman::getListe(){return &(Roman::liste);}


QSet<Roman*> Roman::getRomansFromGenre(const QString& genre){
    QSet<Roman*> result;
    for (Roman* roman : Roman::liste){
        if (roman->genre == genre) result.insert(roman);
    }
    return result;
}
