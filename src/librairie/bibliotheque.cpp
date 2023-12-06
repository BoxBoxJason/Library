#include "bibliotheque.h"

int Bibliotheque::compteur = 0;
QSet<Bibliotheque*> Bibliotheque::liste;

Bibliotheque::Bibliotheque(const QString& nom, const QString& adresse){
    for (Bibliotheque* bibliotheque : Bibliotheque::liste){
        if (bibliotheque->nom == nom || bibliotheque->adresse == adresse) throw ; // TODO: definir erreur
    }
    this->nom = nom;
    this->adresse = adresse;
    code = compteur++;
    Bibliotheque::liste.insert(this);
}

void Bibliotheque::afficherLivres(){} // TODO
void Bibliotheque::afficherLivres(QString categorie){} // TODO
Livre* Bibliotheque::emprunterLivre(const Bibliotheque* bibliotheque, int isbn){} // TODO
bool Bibliotheque::setNom(const QString& nom){if (! Bibliotheque::checkNomExiste(nom)) this->nom = nom;}
bool Bibliotheque::setAdresse(const QString& adresse){if (! Bibliotheque::checkAdresseExiste(adresse)) this->adresse = adresse;}
bool Bibliotheque::acheterLivre(int isbn){} // TODO

bool Bibliotheque::checkNomExiste(const QString& nom){
    bool existe = false;
    for (Bibliotheque* bibliotheque : Bibliotheque::liste){
        if (bibliotheque->nom == nom){
            existe = true;
            break;
        }
    }
    return existe;
}


bool Bibliotheque::checkAdresseExiste(const QString& adresse){
    bool existe = false;
    for (Bibliotheque* bibliotheque : Bibliotheque::liste){
        if (bibliotheque->adresse == adresse){
            existe = true;
            break;
        }
    }
    return existe;
}
