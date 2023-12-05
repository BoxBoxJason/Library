#ifndef LIVRE_H
#define LIVRE_H

#include <QString>

class Livre
{
public:
    Livre();
protected:
    int code;
    QString auteur;
    QString titre;
    QString editeur;
    int isbn;
    QString public_cible;
    QString etat;
};

#endif // LIVRE_H
