#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <QString>
#include <QHash>
#include <QSet>

class Livre
{
public:
    explicit Livre(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible, int code_bibliotheque=-1);

    int getCode();
    QString getAuteur();
    QString getTitre();
    QString getEditeur();
    int getISBN();
    QString getPublicCible();
    bool getDisponibilite();
    void setDisponibilite(bool disponibilite);
    /*!
     * \brief getLivre Renvoie un pointeur vers le livre demandé.
     * Si le livre n'existe pas, renvoie nullptr.
     * \param code
     * \return Pointeur vers le livre demandé.
     */
    static Livre* getExemplaireFromCode(int code);
    static Livre* getLivreFromISBN(long long isbn);
    static QSet<Livre*> getExemplairesFromISBN(long long isbn);
    static QSet<Livre*> getLivresFromAuteurSubstring(const QString& auteur_substring);
    static QSet<Livre*> getLivresFromTitreSubstring(const QString& titre_substring);
    static QSet<Livre*> getLivresFromEditeurSubstring(const QString& editeur_substring);
    static QSet<Livre*> getLivresFromPublicCible(const QString& public_cible);

    static QSet<Livre*> filtrerLivresDisponibles(const QSet<Livre*>& livres);

    friend std::ostream& operator<<(std::ostream& os, const Livre& obj) {
        os << "Livre:  " << obj.titre.toStdString();
        os << "\nAuteur: " << obj.auteur.toStdString();
        os << "\nCode: " << obj.code;
        os << "\nISBN: " << obj.isbn;
        os << "\nDisponible: " << (obj.disponibilite ? "oui" : "non") << "\n";
        return os;
    }

protected:
    // Code unique d'un exemplaire de livre
    int code;
    // Auteur du livre
    QString auteur;
    // Titre du livre (unique)
    QString titre;
    // Éditeur du livre
    QString editeur;
    // Numéro isbn du livre
    long long isbn;
    // Public ciblé: adulte, ado, jeunesse, tout public
    QString public_cible;
    // Disponibilité dans sa bibliothèque
    bool disponibilite;
    // Code de la bibliothèque d'origine
    int code_bibliotheque_origine;

    // Compteur d'instances, sert à attribuer un nouveau code unique à chaque livre
    static int compteur;
    // Hashmap de tous les codes:livres existant
    static QHash<long long,Livre*> liste;
    // Renvoie la hashmap des codes:livres
    static QHash<long long,Livre*>* getListe(){return &Livre::liste;}

};

#endif // LIVRE_H
