#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <QString>
#include <QHash>
#include <QList>
#include "livre.h"

class Bibliotheque
{
public:
    explicit Bibliotheque(const QString& nom, const QString& adresse);
    /*!
     * \brief afficherLivres Affiche tous les livres possédés par la bibliothèque.
     * Tous les livres sont affichés, qu'ils soient disponibles ou non.
     */
    void afficherLivres();
    /*!
     * \brief afficherLivres Affiche tous les livres de la catégorie possédés par la bibliothèque.
     * Tous les livres sont affichés, qu'ils soient disponibles ou non.
     * \param categorie Catégorie de livre. Si elle est inconnue, alors rien ne se passera.
     */
    void afficherLivres(QString categorie);
    /*!
     * \brief emprunterLivre Emprunte un livre à une autre bibliothèque.
     * \param bibliotheque pointeur vers la bibliothèque dont on cherche à emprunter.
     * \param isbn Code ISBN du livre.
     * \return Pointeur vers le livre.
     */
    Livre* emprunterLivre(const Bibliotheque* bibliotheque, int isbn);
    /*!
     * \brief setNom Change l'attribut nom de la bibliothèque.
     * Attention, rien ne se passe si on essaie de donner un nom qui existe déjà.
     * \param nom
     * \return Statut de succès de l'opération. (False si raté).
     */
    bool setNom(const QString& nom);
    /*!
     * \brief setAdresse Change l'adresse de la bibliothèque.
     * Attention, rien ne se passe si on essaie de donner une adresse qui existe déjà.
     * \param adresse
     * \return Status de succès de l'opération. (False si raté).
     */
    bool setAdresse(const QString& adresse);
    /*!
     * \brief acheterLivre Ajoute un livre à la collection de la bibliothèque.
     * \param isbn
     * \return
     */
    bool acheterLivre(int isbn);

private:
    QString nom;
    QString adresse;
    int code;
    QHash<int,Livre*> livres;
    static int compteur;
    static QList<Bibliotheque*> liste;
    static bool checkNomExiste(const QString& nom);
    static bool checkAdresseExiste(const QString& adresse);
};

#endif // BIBLIOTHEQUE_H
