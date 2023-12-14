#ifndef ALBUM_H
#define ALBUM_H

#include "livre.h"

class Album : public Livre
{
public:
    Album(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible,const QString& illustrations,int code_bibliotheque_origine=-1);

    QString getIllustrations();

    QSet<Album*> getAlbumsFromIllustrations(const QString& illustrations);

private:
    QString illustrations;
    static QHash<int,Album*> liste;
    static QHash<int,Album*>* getListe();
};

#endif // ALBUM_H
