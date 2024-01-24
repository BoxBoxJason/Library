#ifndef ADHERENT_H
#define ADHERENT_H

#include <QString>
#include <QSet>
#include <QStringList>
#include "bibliotheque.h"
#include "livre.h"

class Adherent
{
public:
    explicit Adherent(const QString& nom,const QString& prenom, const QString& adresse);
    /*!
     * \brief emprunterLivre Emprunte un livre d'une bibliothèque.
     * Peut échouer si le livre n'existe pas dans la bibliothèque ou s'il n'y est pas (déjà prêté)
     * \param code Code (unique) du livre.
     * \return Statut de succès de l'emprunt (False si échec).
     */
    ~Adherent();
    QString getFullname();
    bool emprunterLivre(int code);
    /*!
     * \brief rendreLivre Rend un livre à sa bibliothèque.
     * \param code Code (unique) du livre.
     */
    void rendreLivre(Livre* livre);
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
    /*!
     * \brief getAdherents Renvoie la liste de tous les adhérents.
     * \return
     */
    static QSet<Adherent*> getAdherents();
    /*!
     * \brief getInformations
     * \return Renvoie les informations du profil de l'adhérent (pour affichage)
     */
    QStringList getInformations() const {
        QStringList infos;
        infos.append("Numéro adhérent: " + QString::number(numero));
        infos.append("Nom: " + prenom + " " + nom);
        infos.append("Adresse: " + adresse);
        if (bibliotheque != nullptr){
            infos.append("Bibliothèque: " + bibliotheque->getNom());
        }
        else {
            infos.append("Bibliothèque: Aucune");
        }
        return infos;
    };
    friend std::ostream& operator<<(std::ostream& os, const Adherent& obj) {
        os << obj.getInformations().join("\n").toStdString() << "\n";
        return os;
    };

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
