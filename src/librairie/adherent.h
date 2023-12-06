#ifndef ADHERENT_H
#define ADHERENT_H

#include <QString>
#include <QList>
#include "bibliotheque.h"
#include "livre.h"

class Adherent
{
public:
    Adherent(const QString& nom,const QString& prenom, const QString& adresse);
    bool emprunterLivre(int code);
    bool rendreLivre(int code);

    int getNumero();
    void setBibliotheque(Bibliotheque* bibliotheque);

private:
    QString nom;
    QString prenom;
    QString adresse;
    int numero;
    Bibliotheque* bibliotheque;
    QList<Livre*> livres;
    static int max_emprunts;
    static int compteur;
    static QList<Adherent*> liste;
    static bool checkNomPrenomExiste(const QString& nom,const QString& prenom);
};

#endif // ADHERENT_H
