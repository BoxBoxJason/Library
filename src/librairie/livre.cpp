#include "livre.h"


int Livre::compteur = 0;
QHash<int,Livre*> Livre::liste;


Livre::Livre(const QString& auteur, const QString& titre, const QString& editeur, int isbn, const QString& public_cible, int code_bibliotheque)
    : auteur(auteur), titre(titre),editeur(editeur), isbn(isbn), public_cible(public_cible), code_bibliotheque_origine(code_bibliotheque){
    if (code_bibliotheque > -1){
        code = compteur++;
        getListe()->insert(code,this);
    }
}

void Livre::setDisponibilite(bool disponibilite){this->disponibilite = disponibilite;}

int Livre::getCode(){return code;}
QString Livre::getAuteur(){return auteur;}
QString Livre::getTitre(){return titre;}
QString Livre::getEditeur(){return editeur;}
int Livre::getISBN(){return isbn;}
QString Livre::getPublicCible(){return public_cible;}
bool Livre::getDisponibilite(){return disponibilite;}

Livre* Livre::getExemplaireFromCode(int code){return liste.value(code,nullptr);}


Livre* Livre::getLivreFromISBN(int isbn){
    Livre* result = nullptr;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine < 0 && livre->isbn == isbn){
            result = livre;
            break;
        }
    }
    return result;
}

QSet<Livre*> Livre::getExemplairesFromISBN(int isbn){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine > -1 && livre->isbn == isbn){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromAuteurSubstring(const QString& auteur_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine < 0 && livre->auteur.contains(auteur_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromTitreSubstring(const QString& titre_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine < 0 && livre->titre.contains(titre_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromEditeurSubstring(const QString& editeur_substring){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine < 0 && livre->editeur.contains(editeur_substring)){
            result.insert(livre);
        }
    }
    return result;
}


QSet<Livre*> Livre::getLivresFromPublicCible(const QString& public_cible){
    QSet<Livre*> result;
    for (Livre* livre : Livre::liste){
        if (livre->code_bibliotheque_origine < 0 && livre->public_cible== public_cible){
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
