#include <iostream>
#include <QApplication>
#include "interface/library.h"
#include "librairie/adherent.h"
#include "librairie/roman.h"
#include "librairie/album.h"
#include "librairie/bd.h"
#include "librairie/recueil.h"
#include "librairie/theatre.h"

int main(int argc, char *argv[]) {
    Adherent adhe1( "Grandbois","Jeoffroi","57 rue Sadi Carnot 93600 AULNAY-SOUS-BOIS");
    Adherent adhe2( "Bonenfant", "Nicole","23 rue Marguerite 94300 VINCENNES");
    Adherent adhe3( "Petit","Émile", "6 Chemin Du Lavarin Sud 62100 CALAIS");
    Adherent adhe4("Monjeau", "René", "1 rue Sadi Carnot 93300 AUBERVILLIERS");
    Adherent adhe5("LeBatelier","Nathalie","75 Rue St Ferréol 57070 METZ");
    Adherent adhe6("Chaussée","Camille","18 boulevard Amiral Courbet 01100 OYONNAX");
    Adherent adhe7("Bazin","Frédéric","59 rue Gouin de Beauchesne 91240 SAINT-MICHEL-SUR-ORGE");
    Adherent adhe8("Laforest", "Lucas","46 rue de l'Aigle 93210 LA PLAINE-SAINT-DENIS");
    Adherent adhe9("Parmentier","Victor","86 rue de la Hulotais 02100 SAINT-QUENTIN");

    Bibliotheque b0("Bibliothèque du Panier","Place du Refuge 13002 Marseille");
    Bibliotheque b1("Bibliothèque d'Alcazar","58 cours Belsunce, 13001 Marseille");
    Bibliotheque b2("Bibliothèque Cinq-Avenue","Impasse Fissiaux, 13004 Marseille");
    Bibliotheque b3("Bibliothèque Castellane","Station métro Castellane 13006 Marseille");
    Bibliotheque b4("Bibliothèque Saint-André","6 boulevard Salducci 13016 Marseille");

    adhe1.setBibliotheque(&b0);
    adhe2.setBibliotheque(&b0);
    adhe3.setBibliotheque(&b1);
    adhe4.setBibliotheque(&b1);
    adhe5.setBibliotheque(&b0);
    adhe6.setBibliotheque(&b2);
    adhe7.setBibliotheque(&b3);
    adhe8.setBibliotheque(&b3);
    adhe9.setBibliotheque(&b4);

    Roman roman1("Fiodor Dostoïevski","Les Frères Karamazov","GALLIMARD","9788437606385","adulte","Fiction philosophique",-1);
    Roman roman2("Homere","Odyssée","GALLIMARD","9782081258594","adulte","Mythes & épopée",-1);


    Theatre theatre1("Henry Bauchau","Antigone"," Actes Sud","9782290310083","adulte",20,-1);
    Theatre theatre2("Jean Racine","Phèdre","Gallimard","9782070466665","adulte",17,-1);

    BD bd1("René Goscinny","Astérix - L Iris blanc","Albert Rene","9782014001334","Tout Public","Didier Conrad",-1);
    BD bd2("Delaf","Gaston - Le retour de Lagaffe","Dupuis","9791034752065","Tout Public","Delaf",-1);

    Album album1("Nadja","Chien Bleu","L`Ecole des loisirs","9782211066563","Enfant","dessin",-1);
    Album album2("Tomi Ungerer","OTTO","L`Ecole des loisirs","9782211061988","Jeunesse","dessin",-1);

    Recueil recueil1("Charles Baudelaire","Les Fleurs du mal","Auguste Poulet-Malassis","9780192829726","Tout Public","vers",-1) ;
    Recueil recueil2("Victor Hugo","Les Contemplations"," Editions Flammarion","9782253014997","Tout Public","vers",-1);

    // Achat livre bibliotheque
    b0.acheterLivre("9788437606385");
    std::cout << "Livres de b0 avant emprunt:\n";
    for(Livre* livre : b0.obtenirLivres()){
        std::cout << *livre << "\n";
    }

    // Emprunt livre par adhérent
    adhe1.emprunterLivre(0);
    std::cout << "Livres de b0 après emprunt:\n";
    for(Livre* livre : b0.obtenirLivres()){
        std::cout << *livre << "\n";
    }
    std::cout << "Livres empruntés par adhe1:\n";
    for (Livre* livre : adhe1.getLivresEmpruntes()){
        std::cout << *livre << "\n";
        adhe1.rendreLivre(livre);
    }

    std::cout << "Livres de b0 après restitution:\n";
        for(Livre* livre : b0.obtenirLivres()){
        std::cout << *livre << "\n";
    }

    // Emprunt livre entre bibliothèque
    b1.emprunterLivre(&b0,"9788437606385");
    std::cout << "Livres de b0 après emprunt biblio:\n";
        for(Livre* livre : b0.obtenirLivres()){
        std::cout << *livre << "\n";
    }

    std::cout << "Livres de b1 après emprunt biblio:\n";
        for(Livre* livre : b1.obtenirLivres()){
    std::cout << *livre << "\n";
    }

    for(Livre* livre : b1.getLivresEmpruntes()){
        b1.rendreLivre(livre);
    }

    std::cout << "Livres de b1 après rendu biblio:\n";
        for(Livre* livre : b1.obtenirLivres()){
        std::cout << *livre << "\n";
    }

    std::cout << "Livres de b0 après rendu biblio:\n";
        for(Livre* livre : b0.obtenirLivres()){
    std::cout << *livre << "\n";
    }

/*
    QApplication a(argc, argv);

    Library mainWindow;
    mainWindow.show();

    return a.exec();
*/
    return 0;
}

/*
int main(int argc, char *argv[]) {
    Adherent adhe1( "Grandbois","Jeoffroi","57 rue Sadi Carnot 93600 AULNAY-SOUS-BOIS");
    Adherent adhe2( "Bonenfant", "Nicole","23 rue Marguerite 94300 VINCENNES");
    Adherent adhe3( "Petit","Émile", "6 Chemin Du Lavarin Sud 62100 CALAIS");
    Adherent adhe4("Monjeau", "René", "1 rue Sadi Carnot 93300 AUBERVILLIERS");
    Adherent adhe5("LeBatelier","Nathalie","75 Rue St Ferréol 57070 METZ");
    Adherent adhe6("Chaussée","Camille","18 boulevard Amiral Courbet 01100 OYONNAX");
    Adherent adhe7("Bazin","Frédéric","59 rue Gouin de Beauchesne 91240 SAINT-MICHEL-SUR-ORGE");
    Adherent adhe8("Laforest", "Lucas","46 rue de l'Aigle 93210 LA PLAINE-SAINT-DENIS");
    Adherent adhe9("Parmentier","Victor","86 rue de la Hulotais 02100 SAINT-QUENTIN");

    Bibliotheque b0("Bibliothèque du Panier","Place du Refuge 13002 Marseille");
    Bibliotheque b1("Bibliothèque d'Alcazar","58 cours Belsunce, 13001 Marseille");
    Bibliotheque b2("Bibliothèque Cinq-Avenue","Impasse Fissiaux, 13004 Marseille");
    Bibliotheque b3("Bibliothèque Castellane","Station métro Castellane 13006 Marseille");
    Bibliotheque b4("Bibliothèque Saint-André","6 boulevard Salducci 13016 Marseille");

    Roman roman1("Fiodor Dostoïevski","Les Frères Karamazov","GALLIMARD",9788437606385,"adulte","Fiction philosophique",-1);
    Roman roman2("Homere","Odyssée","GALLIMARD",9782081258594,"adulte","Mythes & épopée",-1);


    Theatre theatre1("Henry Bauchau","Antigone"," Actes Sud",9782290310083,"adulte",20,-1);
    Theatre theatre2("Jean Racine","Phèdre","Gallimard",9782070466665,"adulte",17,-1);

    BD bd1("René Goscinny","Astérix - L Iris blanc","Albert Rene",9782014001334,"Tout Public","Didier Conrad",-1);
    BD bd2("Delaf","Gaston - Le retour de Lagaffe","Dupuis",9791034752065,"Tout Public","Delaf",-1);

    Album album1("Nadja","Chien Bleu","L`Ecole des loisirs",9782211066563,"Enfant","dessin",-1);
    Album album2("Tomi Ungerer","OTTO","L`Ecole des loisirs",9782211061988,"Jeunesse","dessin",-1);

    Recueil recueil1("Charles Baudelaire","Les Fleurs du mal","Auguste Poulet-Malassis",9780192829726,"Tout Public","vers",-1) ;
    Recueil recueil2("Victor Hugo","Les Contemplations"," Editions Flammarion",9782253014997,"Tout Public","vers",-1);

    std::cout << roman1;
}
*/
