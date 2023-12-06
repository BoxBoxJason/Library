#ifndef ADHERENT_H
#define ADHERENT_H

#include <QString>
#include <QSet>
#include "bibliotheque.h"
#include "livre.h"

class Adherent
{
public:
    Adherent(const QString& nom,const QString& prenom, const QString& adresse);
    /*!
     * \brief emprunterLivre Emprunte un livre d'une bibliothèque.
     * Peut échouer si le livre n'existe pas dans la bibliothèque ou s'il n'y est pas (déjà prêté)
     * \param code Code (unique) du livre.
     * \return Statut de succès de l'emprunt (False si échec).
     */
    bool emprunterLivre(int code);
    /*!
     * \brief rendreLivre Rend un livre à sa bibliothèque.
     * Peut échouer si le livre n'est pas en possession de l'adhérent.
     * \param code Code (unique) du livre.
     * \return Statut de succès de l'opération (False si échec).
     */
    bool rendreLivre(int code);
    /*!
     * \brief getNumero
     * \return Donne le numéro d'adhérent.
     */
    int getNumero();
    /*!
     * \brief setBibliotheque Change la bibliothèque de l'adhérent.
     * \param bibliotheque
     */
    void setBibliotheque(Bibliotheque* bibliotheque);

private:
    QString nom;
    QString prenom;
    QString adresse;
    int numero;
    Bibliotheque* bibliotheque;
    QSet<Livre*> livres;
    static int max_emprunts;
    static int compteur;
    static QSet<Adherent*> liste;
    static bool checkNomPrenomExiste(const QString& nom,const QString& prenom);
};

#endif // ADHERENT_H
