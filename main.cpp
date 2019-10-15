#include <iostream>
#include <istream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "motMystere.h"
#include "fonctionsPratiques.h"

using namespace std;

/*
    pseudo code :
    {
    jouer à deux ou contre l'ordi? (choix 1 : jouer contre l'ordi // choix 2 : jouer à deux joueurs)
        {
        1 - Jouer à deux

        }
        {
        2 - Jouer contre l'ordi

        }
    }
    fin : au revoir!! >>> quitter le programme

 */





int main() {
    // integrations obligatoires :
    srand(time(0));
    // fin intégrations obligatoires

    // variables de statistiques
    int debug = 0; // si mode debug : 1 : le mot mystère est révélé
    int coupsPerdants(0);
    int partiesJouees(0);
    int partiesGagnees(0);

    bool rejouer = false;

    // choix du type de jeu
    int choix = choisirPartie();
    if(choix == 1){
        string const fichierDico("C:/ProjetsCPP/dico.txt");
        ifstream monFlux(fichierDico.c_str());
        if(monFlux){
            cout << "tout va bien" << endl;
            // compter nombre de lignes possibles
            string mot;
            int iNbMots(0);
            while(getline(monFlux, mot)){
                iNbMots++;
            }
            cout << iNbMots << endl;
        }
        else{
            cout << "probleme ouverture fichier dico.txt. "<< endl;
            cout << "Le projet n'a pas du etre place a la racine du repertoire C:/ comme demande." << endl;
        }
       // cout << "pas encore developpe..." << endl;
    }
    else{
        // boucle Jeu à deux
        do {
            cout << "Vous avez choisi de jouer au mot mystere a deux... " << endl;
            partiesJouees++;
            int nombreCoups(0);

            // Joueur 1 entre un mot et le nombre de coups max que le joueur aura pour gagner
            //nombreCoups = 5;
            nombreCoups = iEntrerNombreCoupsMax();
            cin.ignore();
            string motMystere = sEntrerMot(debug);

            // les lettres du mots sont mélangées (anagramme) et (ça c'est bonus) floutées en parties mais dans l'ordre pour aider un peu à trouver
            string motFloute = sFlouterMot(motMystere);
            string anagramme = creerAnagramme(motMystere, debug);

            // l'utilisateur 2 doit trouver le mot en 5 coups
            sauterLignes(15); // on saute des lignes pour que l'utilis
            int coupsTemp(0);
            coupsTemp = tenterTrouverMotMystere(motMystere, motFloute, anagramme, nombreCoups, debug); // si coupsTemps == 6 : coups perdants : +5. partie gagnée +0. si coupsTemps < 6 : partie gagnée +1, coups perdants +=

            if(coupsTemp == nombreCoups + 1){
                coupsPerdants += nombreCoups;
            }
            else{
                partiesGagnees++;
                coupsPerdants = coupsTemp - 1;
            }

            float pourcentReussite = calculerStatistiques(partiesJouees, partiesGagnees, coupsPerdants);
            cout << "Vous avez joue " << partiesJouees << " parties avec un taux de coups gagnants de : " << pourcentReussite << "%." << endl;

            // on demande au joueurs s'ils veulent recommencer la partie
            rejouer = recommencer();

        }
        while (rejouer == true);

    }

    cout << "Ok au revoir!" << endl;

    return 0;
}