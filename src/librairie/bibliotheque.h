#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <QString>
#include <QHash>
#include <QSet>
#include "livre.h"

class Bibliotheque
{
public:
    explicit Bibliotheque(const QString& nom, const QString& adresse);
    /*!
     * \brief afficherLivres Affiche tous les livres possédés par la bibliothèque.
     * Tous les livres sont affichés, qu'ils soient disponibles ou non.
     */
    QSet<Livre*> obtenirLivres();
    /*!
     * \brief afficherLivres Affiche tous les livres de la catégorie possédés par la bibliothèque.
     * Tous les livres sont affichés, qu'ils soient disponibles ou non.
     * \param categorie Catégorie de livre. Si elle est inconnue, alors rien ne se passera.
     */
    QSet<Livre*> obtenirLivres(const QString& categorie);
    /*!
     * \brief emprunterLivre Emprunte un livre à une autre bibliothèque.
     * \param bibliotheque pointeur vers la bibliothèque dont on cherche à emprunter.
     * \param isbn Code ISBN du livre.
     * \return Pointeur vers le livre.
     */
    Livre* emprunterLivre(Bibliotheque* bibliotheque, int isbn);
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
    // Nom (unique) de la bibliothèque.
    QString nom;
    // Adresse (unique) de la bibliothèque.
    QString adresse;
    // Code (unique) de la bibliothèque.
    int code;
    // Hashmap des codes:livres de la bibliothèque (contient aussi ceux prêtés à adhérents).
    QHash<int,Livre*> livres;
    QSet<Livre*> getExemplairesFromISBN(int isbn);
    // Compteur d'instances, utilisé pour attribuer un code unique à une bibliothèque.
    static int compteur;
    // Hashmap des codes:Bibliothèques existantes.
    static QHash<int,Bibliotheque*> liste;
    /*!
     * \brief checkNomExiste Vérifie si un nom de bibliothèque existe déjà.
     * \param nom
     * \return Vrai si le nom existe déjà.
     */
    static bool checkNomExiste(const QString& nom);
    /*!
     * \brief checkAdresseExiste Vérifie si une adresse de bibliothèque est déjà prise.
     * \param adresse
     * \return Vrai si l'adresse est déjà prise.
     */
    static bool checkAdresseExiste(const QString& adresse);
};

#endif // BIBLIOTHEQUE_H
