#ifndef ADHERENT_H
#define ADHERENT_H

#include <QString>
#include "bibliotheque.h"
#include "livre.h"

class Adherent
{
public:
    Adherent();

private:
    QString nom;
    QString prenom;
    QString adresse;
    int numero;
    Bibliotheque* bibliotheque;
    Livre* livres;
    static int max_emprunts;
};

#endif // ADHERENT_H
