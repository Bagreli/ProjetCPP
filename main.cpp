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

int main() {
    // integrations obligatoires :
    srand(time(0));
    // fin intégrations obligatoires

    // variables de statistiques
    int debug = 1; // si mode debug : 1 : le mot mystère est révélé
    int coupsPerdants(0), partiesJouees(0), partiesGagnees(0);
    bool rejouer = false;

    // choix du type de jeu
    int choix = choisirPartie();
    // à des fins de test :
    // int choix = 1;
    if(choix == 1){
        // /!\ si besoin mettre le chemin principal. pas possible avec Clion sur windows de mettre chemin relatif
        ifstream monFlux("C:/ProjetsCPP/dico.txt");
        //ifstream monFlux("dico.txt"); // ne fonctionne pas...

        if(monFlux){
            do{
                partiesJouees++;
                monFlux.seekg(0, ios::beg); // curseur au début du fichier
                int iNbMots = compterLignes(monFlux); // compter nombre de lignes possibles
                if (debug == 1){ cout << "Il y a " << iNbMots << " mots dans le fichier." << endl; }

                string motMystere = getMotRandom(monFlux, iNbMots);
                if(debug == 1){ cout << "mot mystere : "  << motMystere << endl; }

                cout << "Veuillez entrer le NOMBRE DE COUPS MAXIMUM (entre 2 et 10) que vous vous donnez pour trouver le mot mystere :" << endl;
                int nombreCoups = iEntrerNombreCoupsMax();
                cin.ignore();
                string motFloute = sFlouterMot(motMystere);
                string anagramme = creerAnagramme(motMystere, /*debug*/ 0);

                int coupsTemp(0); // pour calcul des stats
                coupsTemp = tenterTrouverMotMystere(motMystere, motFloute, anagramme, nombreCoups, /*debug*/ 0);

                if(coupsTemp == nombreCoups + 1){
                    coupsPerdants += nombreCoups;
                }
                else{
                    partiesGagnees++;
                    coupsPerdants = coupsTemp - 1;
                }

                float pourcentReussite = calculerStatistiques(partiesJouees, partiesGagnees, coupsPerdants);
                cout << "Vous avez joue " << partiesJouees << " parties avec un taux de coups gagnants de : " << pourcentReussite << "%." << endl;

                rejouer = recommencer(); // on demande au joueurs s'ils veulent recommencer la partie

            } while (rejouer == true);
        }
        else{
            cout << "probleme ouverture fichier dico.txt. "<< endl;
            cout << "Le projet n'a pas du etre place a la racine du repertoire C:/ comme demande." << endl;
        }
    }
    else{
        // boucle Jeu à deux
        do {
            cout << "Vous avez choisi de jouer au mot mystere a deux... " << endl;
            partiesJouees++;
            int nombreCoups(0);

            // Joueur 1 entre un mot et le nombre de coups max que le joueur aura pour gagner
            string message = "Joueur 1, veuillez entrer le NOMBRE DE COUPS MAXIMUM (entre 2 et 10) que le joueur 2 aura pour trouver le mot.";
            cout << message << endl;
            nombreCoups = iEntrerNombreCoupsMax();
            cin.ignore();
            string motMystere = sEntrerMot(debug);

            // les lettres du mots sont mélangées (anagramme) et (ça c'est bonus) floutées en parties mais dans l'ordre pour aider un peu à trouver
            string motFloute = sFlouterMot(motMystere);
            string anagramme = creerAnagramme(motMystere,0);

            // l'utilisateur 2 doit trouver le mot en 5 coups
            sauterLignes(15); // on saute des lignes pour que l'utilis
            int coupsTemp(0);
            cout << "Merci joueur 1. Joueur 2, a vous de jouer." << endl;
            coupsTemp = tenterTrouverMotMystere(motMystere, motFloute, anagramme, nombreCoups, debug);

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