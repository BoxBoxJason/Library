#ifndef RECUEIL_H
#define RECUEIL_H

#include "livre.h"

class Recueil : public Livre
{
public:
    Recueil();
private:
    QString indicateur;
};

#endif // RECUEIL_H
