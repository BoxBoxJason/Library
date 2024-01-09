#include "bd.h"

QHash<int,BD*> BD::liste;

BD::BD(const QString& auteur, const QString& titre, const QString& editeur, long long isbn, const QString& public_cible,const QString& dessinateur,int code_bibliotheque_origine)
    : Livre{auteur,titre,editeur,isbn,public_cible,code_bibliotheque_origine} , dessinateur(dessinateur) {

}

QString BD::getDessinateur(){return dessinateur;}

QSet<BD*> BD::getBDsFromDessinateurSubstring(const QString& dessinateur_substring){
    QSet<BD*> result;
    for (BD* bd : BD::liste){
        if (bd->dessinateur.contains(dessinateur_substring)) result.insert(bd);
    }

    return result;
}


QHash<int,BD*>* BD::getListe(){return &(BD::liste);}
