#include "bibliotheque.h"
#include "../exceptions/notuniqueelementexception.h"
#include "bd.h"
#include "theatre.h"
#include "recueil.h"
#include "album.h"
#include "roman.h"

int Bibliotheque::compteur = 0;
QHash<int,Bibliotheque*> Bibliotheque::liste;

QSet<Bibliotheque*> Bibliotheque::getBibliotheques(){
    QSet<Bibliotheque*> biblios;
    for (Bibliotheque* bibliotheque : Bibliotheque::liste) {
        biblios.insert(bibliotheque);
    }
    return biblios;
}


Bibliotheque::Bibliotheque(const QString& nom, const QString& adresse)
    : livres(), nom(nom), adresse(adresse), code(Bibliotheque::compteur++) , livres_empruntes(){
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


Livre* Bibliotheque::emprunterLivre(Bibliotheque* bibliotheque, QString isbn){
    Livre * livre = nullptr;
    // Choisir un exemplaire du livre dans la bibliothèque
    QSet<Livre*> exemplaires_disponibles = Livre::filtrerLivresDisponibles(bibliotheque->getExemplairesFromISBN(isbn));

    if (exemplaires_disponibles.count()) {
        // Si exemplaires disponibles: choisir un et le changer de bibliothèque
        livre = *exemplaires_disponibles.begin();
        int code_livre = livre->getCode();
        bibliotheque->livres.remove(code_livre);
        livres.insert(code_livre,livre);
        livres_empruntes.insert(livre);
    }

    return livre;
}


void Bibliotheque::rendreLivre(Livre* livre){
    int code_livre = livre->getCode();
    if(livres_empruntes.contains(livre)){
        Bibliotheque* origine = Bibliotheque::liste.value(livre->getCodeBibliothequeOrigine());
        livres.remove(code_livre);
        livres_empruntes.remove(livre);
        origine->livres.insert(code_livre,livre);
    }
}


QSet<Livre*> Bibliotheque::getLivresEmpruntes(){
    QSet<Livre*> result;
    for(Livre* livre : livres_empruntes){
        result.insert(livre);
    }
    return result;
}


bool Bibliotheque::setNom(const QString& nom){
    bool nom_existe = Bibliotheque::checkNomExiste(nom);
    if (!nom_existe) this->nom = nom;
    return !nom_existe;
}
bool Bibliotheque::setAdresse(const QString& adresse){
    bool adresse_existe = Bibliotheque::checkAdresseExiste(adresse);
    if (! adresse_existe) this->adresse = adresse;
    return ! adresse_existe;
}
bool Bibliotheque::acheterLivre(QString isbn){
    QSet<Livre*> livres_existants = Livre::getLivres() | BD::getLivres() | Theatre::getLivres() | Roman::getLivres() | Album::getLivres() | Recueil::getLivres();
    bool achat = false;
    for(Livre* livre : livres_existants) {
        if(livre->getISBN() == isbn){
            Livre* nouvel_exemplaire = new Livre(livre->getAuteur(),livre->getTitre(),livre->getEditeur(),isbn,livre->getPublicCible(),code);
            livres.insert(nouvel_exemplaire->getCode(),nouvel_exemplaire);
            achat = true;
            break;
        }
    }
    return achat;
}


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


QSet<Livre*> Bibliotheque::getExemplairesFromISBN(QString isbn){
    QSet<Livre*> result;
    for (Livre* livre : livres){
        if (livre->getISBN() == isbn){
            result.insert(livre);
        }
    }
    return result;
}

QString Bibliotheque::getNom(){
    return nom;
}
