#ifndef LIVRE_H
#define LIVRE_H

#include <QString>
#include <QHash>

class Livre
{
public:
    explicit Livre(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible);

    int getCode();
    QString getAuteur();
    QString getTitre();
    QString getEditeur();
    int getISBN();
    QString getPublicCible();
    QString getEtat();

    /*!
     * \brief setEtat Modifie l'état du livre.
     * Peut échouer si l'état fourni ne correspond pas aux états possibles.
     * \param etat
     * \return Statut de succès de l'opération (False si échec).
     */
    bool setEtat(const QString& etat);
    /*!
     * \brief getLivre Renvoie un pointeur vers le livre demandé.
     * Si le livre n'existe pas, renvoie nullptr.
     * \param code
     * \return Pointeur vers le livre demandé.
     */
    static Livre* getLivreFromCode(int code);
    static QSet<Livre*> getLivresFromISBN(int isbn);

protected:
    int code;
    QString auteur;
    QString titre;
    QString editeur;
    int isbn;
    QString public_cible;
    QString etat;
    static int compteur;
    static QHash<int,Livre*> liste;
    static QHash<int,Livre*>* getListe(){return &liste;}

};

#endif // LIVRE_H
