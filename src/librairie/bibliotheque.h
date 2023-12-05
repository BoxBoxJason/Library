#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <QString>
#include "livre.h"

class Bibliotheque
{
private:
    QString nom;
    QString adresse;
    int code;
    Livre* livres;

public:
    Bibliotheque();
};

#endif // BIBLIOTHEQUE_H
