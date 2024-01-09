#include "bibliotheque.h"
#include "../exceptions/notuniqueelementexception.h"
int Bibliotheque::compteur = 0;
QHash<int,Bibliotheque*> Bibliotheque::liste;

Bibliotheque::Bibliotheque(const QString& nom, const QString& adresse)
    : livres(), nom(nom), adresse(adresse), code(Bibliotheque::compteur++){
    for (Bibliotheque* bibliotheque : Bibliotheque::liste){
        if (bibliotheque->nom == nom) throw NotUniqueElementException("La bibliothèque " + nom + " existe déjà.");
        if (bibliotheque->adresse == adresse) throw NotUniqueElementException("L'adresse " + adresse + " est déjà prise.");
    }
    Bibliotheque::liste.insert(code,this);
}

QSet<Livre*> Bibliotheque::obtenirLivres(){
    QSet<Livre*> result;
    for (Livre* livre : livres){
        result.insert(livre);
    }
    return result;
}


QSet<Livre*> Bibliotheque::obtenirLivres(const QString& categorie){
    QSet<Livre*> result;
    for (Livre* livre : livres){
         result.insert(livre);
    }
    return result;
}


Livre* Bibliotheque::emprunterLivre(Bibliotheque* bibliotheque, long long isbn){
    Livre * livre = nullptr;
    // Choisir un exemplaire du livre dans la bibliothèque
    QSet<Livre*> exemplaires_disponibles = Livre::filtrerLivresDisponibles(bibliotheque->getExemplairesFromISBN(isbn));

    if (exemplaires_disponibles.count()) {
        // Si exemplaires disponibles: choisir un et le changer de bibliothèque
        livre = *exemplaires_disponibles.begin();
        int code_livre = livre->getCode();
        bibliotheque->livres.remove(code);
        livres.insert(code_livre,livre);
    }

    return livre;
}


bool Bibliotheque::setNom(const QString& nom){if (! Bibliotheque::checkNomExiste(nom)) this->nom = nom;}
bool Bibliotheque::setAdresse(const QString& adresse){if (! Bibliotheque::checkAdresseExiste(adresse)) this->adresse = adresse;}
bool Bibliotheque::acheterLivre(long long isbn){} // TODO

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


QSet<Livre*> Bibliotheque::getExemplairesFromISBN(long long isbn){
    QSet<Livre*> result;
    for (Livre* livre : livres){
        if (livre->getCode() > -1 && livre->getISBN() == isbn){
            result.insert(livre);
        }
    }
    return result;
}
