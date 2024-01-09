#ifndef RECUEIL_H
#define RECUEIL_H

#include "livre.h"

class Recueil : public Livre
{
public:
    explicit Recueil(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& indicateur,int code_bibliotheque_origine=-1);

    QString getIndicateur();

    QSet<Recueil*> getRecueilsFromIndicateur(const QString& indicateur);

private:
    QString indicateur;
    static QHash<int,Recueil*> liste;
    static QHash<int,Recueil*>* getListe();
};

#endif // RECUEIL_H
