#ifndef RECUEIL_H
#define RECUEIL_H

#include "livre.h"

class Recueil : public Livre
{
public:
    explicit Recueil(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible,const QString& indicateur);
    QString getIndicateur();

private:
    QString indicateur;
};

#endif // RECUEIL_H
