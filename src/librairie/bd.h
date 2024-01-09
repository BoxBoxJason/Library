#ifndef BD_H
#define BD_H

#include "livre.h"

class BD : public Livre
{

public:
    BD(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& dessinateur,int code_bibliotheque_origine=-1);

    QString getDessinateur();

    QSet<BD*> getBDsFromDessinateurSubstring(const QString& dessinateur_substring);

private:
    QString dessinateur;
    static QHash<int,BD*> liste;
    static QHash<int,BD*>* getListe();
};

#endif // BD_H
