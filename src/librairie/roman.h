#ifndef ROMAN_H
#define ROMAN_H

#include "livre.h"

class Roman : public Livre
{
public:
    Roman(const QString& auteur, const QString& titre, const QString& editeur, QString isbn, const QString& public_cible,const QString& genre,int code_bibliotheque_origine=-1);

    QString getGenre();

    QSet<Roman*> getRomansFromGenre(const QString& genre);

private:
    QString genre;
    static QHash<int,Roman*> liste;
    static QHash<int,Roman*>* getListe();
};

#endif // ROMAN_H
