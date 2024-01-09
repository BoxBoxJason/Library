#ifndef THEATRE_H
#define THEATRE_H

#include "livre.h"

class Theatre : public Livre
{
public:
    Theatre(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,int siecle,int code_bibliotheque_origine=-1);

    int getSiecle();

    QSet<Theatre*> getTheatresFromSiecle(int siecle);

private:
    int siecle;
    static QHash<int,Theatre*> liste;
    static QHash<int,Theatre*>* getListe();
};

#endif // THEATRE_H
