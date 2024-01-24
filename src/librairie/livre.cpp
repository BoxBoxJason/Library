#include "livre.h"


int Livre::compteur = 0;
QHash<int,Livre*> Livre::liste_physique;
QSet<Livre*> Livre::liste_theorique;


Livre::Livre(const QString& auteur, const QString& titre, const QString& editeur, QString isbn, const QString& public_cible, int code_bibliotheque)
    : auteur(auteur), titre(titre),editeur(editeur), isbn(isbn), public_cible(public_cible), code_bibliotheque_origine(code_bibliotheque){
    disponibilite = code_bibliotheque > -1;
    if (code_bibliotheque > -1){
        code = compteur++;
        liste_physique.insert(code,this);
    }
    else {
        code = -1;
        liste_theorique.insert(this);
    }
}

void Livre::setDisponibilite(bool disponibilite){this->disponibilite = disponibilite;}

int Livre::getCode(){return code;}
QString Livre::getAuteur(){return auteur;}
QString Livre::getTitre(){return titre;}
QString Livre::getEditeur(){return editeur;}
QString Livre::getISBN(){return isbn;}
QString Livre::getPublicCible(){return public_cible;}
bool Livre::getDisponibilite(){return disponibilite;}
int Livre::getCodeBibliothequeOrigine(){return code_bibliotheque_origine;}

Livre* Livre::getExemplaireFromCode(int code){return Livre::liste_physique.value(code,nullptr);}

Livre* Livre::getLivreFromISBN(QString isbn){
    Livre* result = nullptr;
    for (Livre* livre : Livre::liste_theorique){
        if (livre->isbn == isbn){
            result = livre;
            break;
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivres(){
    QSet<Livre*> result;
    for(Livre* livre : Livre::liste_theorique){
        if(livre->code_bibliotheque_origine == -1){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getExemplairesFromISBN(QString isbn){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste_physique){
        if (livre->isbn == isbn){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromAuteurSubstring(const QString& auteur_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste_theorique){
        if (livre->auteur.contains(auteur_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromTitreSubstring(const QString& titre_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste_theorique){
        if (livre->titre.contains(titre_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromEditeurSubstring(const QString& editeur_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste_theorique){
        if (livre->editeur.contains(editeur_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromPublicCible(const QString& public_cible){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste_theorique){
        if (livre->public_cible== public_cible){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::filtrerLivresDisponibles(const QSet<Livre*>& livres){
    QSet<Livre*> result;
    for (Livre* livre : livres){
        if (livre->getDisponibilite()) result.insert(livre);
    }
    return result;
}
