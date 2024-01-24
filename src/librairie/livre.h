#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QSet>

class Livre
{
public:
    explicit Livre(const QString& auteur, const QString& titre, const QString& editeur, QString isbn, const QString& public_cible, int code_bibliotheque=-1);

    int getCode();
    QString getAuteur();
    QString getTitre();
    QString getEditeur();
    QString getISBN();
    QString getPublicCible();
    int getCodeBibliothequeOrigine();
    bool getDisponibilite();
    void setDisponibilite(bool disponibilite);
    /*!
     * \brief getLivre Renvoie un pointeur vers le livre demandé.
     * Si le livre n'existe pas, renvoie nullptr.
     * \param code
     * \return Pointeur vers le livre demandé.
     */
    static Livre* getExemplaireFromCode(int code);
    static Livre* getLivreFromISBN(QString isbn);
    static QSet<Livre*> getLivres();
    static QSet<Livre*> getExemplairesFromISBN(QString isbn);
    static QSet<Livre*> getLivresFromAuteurSubstring(const QString& auteur_substring);
    static QSet<Livre*> getLivresFromTitreSubstring(const QString& titre_substring);
    static QSet<Livre*> getLivresFromEditeurSubstring(const QString& editeur_substring);
    static QSet<Livre*> getLivresFromPublicCible(const QString& public_cible);

    static QSet<Livre*> filtrerLivresDisponibles(const QSet<Livre*>& livres);

    QStringList getInformations() const {
        QStringList infos;
        infos.append("Livre: " + titre);
        infos.append("Auteur: " + auteur);
        infos.append("ISBN: " + isbn);
        if(code > -1){
            infos.append("Code: " + QString::number(code));
            infos.append("Disponible: " + QString(disponibilite ? "oui" : "non"));
        }
        else {
            infos.append("EXEMPLAIRE IMMATÉRIEL");
        }
        return infos;
    };
    friend std::ostream& operator<<(std::ostream& os, const Livre& obj) {
        os << obj.getInformations().join("\n").toStdString() << "\n";
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
    QString isbn;
    // Public ciblé: adulte, ado, jeunesse, tout public
    QString public_cible;
    // Disponibilité dans sa bibliothèque
    bool disponibilite;
    // Code de la bibliothèque d'origine
    int code_bibliotheque_origine;

    // Compteur d'instances, sert à attribuer un nouveau code unique à chaque livre
    static int compteur;
    // Hashmap de tous les codes:livres physiques existants
    static QHash<int,Livre*> liste_physique;
    // Hashmap de tous les codes:livres théoriques existants
    static QSet<Livre*> liste_theorique;

};

#endif // LIVRE_H
