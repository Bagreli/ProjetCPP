//
// Created by utilisateur on 01/10/2019.
//

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <istream>
#include "fonctionsPratiques.h"

using namespace std;


string sMAJ(string p_mot){
    int i = 0;
    string motEnMaj;
    while(p_mot[i]){
        motEnMaj += toupper(p_mot[i]);
        i++;
    }
    return motEnMaj;
}

int iTailleMot(string p_mot){
    int iTailleMot = p_mot.length();
    return iTailleMot;
}

bool bVerifTailleMot(string p_mot, int p_tailleMini, int p_tailleMaxVoulue){
    int iTailleDuMot(0);
    iTailleDuMot = iTailleMot(p_mot);
    if(iTailleDuMot >= p_tailleMini && iTailleDuMot <= p_tailleMaxVoulue){
        return true;
    }
    return false;
}

string verifEspace(string p_mot){
    int i(0);
    string mot = p_mot;

    while(mot[i]){
        if(mot[i] == ' '){
            cout << "Le mot ne doit pas contenir un espace. Recommencez :" << endl;
            getline(cin, mot);
            mot = sMAJ(mot);
            i = 0;
        }
        i++;
    }
    return mot;
}

void sauterLignes(int p_nombreLignes){
    for(int i(0); i < p_nombreLignes; i++){
        cout << endl;
    }
}

int chiffreRandom(int iScope){
    int chiffre = rand() % iScope;
    return chiffre;
}

/**
 * Fonction destinée à demander à l'utilisateur s'il veut rejouer
 * @return bool
 */
bool recommencer(){
    string reponse;
    bool recommencer;

    cout << "Voulez-vous recommencer? Y/N" << endl;
    getline(cin, reponse);

    while ((reponse[0] != 'Y') && (reponse[0] != 'y') && (reponse[0] != 'N') && (reponse[0] != 'n')){
        cout << reponse << endl;
        cout << "Je n'ai pas compris votre reponse... Y (oui je veux recommencer) ou N (non : je veux sortir du jeu) ? " << endl;
        getline(cin, reponse);
    }
    if (reponse[0] == 'Y' || reponse[0] == 'y' ) {
        recommencer = true;
    }
    else {
        recommencer = false;
    }
    return recommencer;
}

/*
int compterLignes(string p_monFlux) {
    string mot;
    int iNbMots(0);
    while(getline(p_monFlux, mot){
        iNbMots++;
    }
    return iNbMots;
}
 */

