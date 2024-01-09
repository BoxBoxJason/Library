#include "album.h"

QHash<int,Album*> Album::liste;

Album::Album(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& illustrations,int code_bibliotheque_origine)
    : Livre{auteur,titre,editeur,isbn,public_cible,code_bibliotheque_origine} , illustrations(illustrations){

}

QString Album::getIllustrations(){return illustrations;}

QSet<Album*> Album::getAlbumsFromIllustrations(const QString& illustrations){
    QSet<Album*> result;
    for (Album* album : Album::liste){
        if (album->illustrations == illustrations) result.insert(album);
    }

    return result;
}


QHash<int,Album*>* Album::getListe(){return &(Album::liste);}
