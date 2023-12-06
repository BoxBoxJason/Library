#ifndef LIVRE_H
#define LIVRE_H

#include <QString>
#include <QList>

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
protected:
    int code;
    QString auteur;
    QString titre;
    QString editeur;
    int isbn;
    QString public_cible;
    QString etat;
    static int compteur;
    static QList<Livre*> liste_livres;
};

#endif // LIVRE_H
