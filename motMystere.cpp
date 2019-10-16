//
// Created by utilisateur on 01/10/2019.
//

#include <string>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include "fonctionsPratiques.h"

using namespace std;


int choisirPartie(){
    int choix(0);
    cout << "Bienvenue au jeu du mot mystere." << endl;
    cout << "Pour seul contre l'ordi, faites le 1." << endl;
    cout << "Pour jouer a 2, faites le 2." << endl;
    cout << "Quel est votre choix? (1 ou 2) :" << endl;
    cin >> choix;
    while(choix != 1 && choix != 2){
        cout << "Je n'ai pas compris la reponse... 1 pour jouer seul, 2 pour jouer a 2 :";
        cin >> choix;
    }
    cin.ignore();
    return choix;
}



int iEntrerNombreCoupsMax(){

    int nombreCoups(0);
    cin >> nombreCoups;

    while (nombreCoups < 2 || nombreCoups > 10){
        cout << "Le chiffre choisi doit etre compris entre 2 et 10. Recommencez :" << endl;
        cin >> nombreCoups;
    }
    return nombreCoups;
}

string sEntrerMot(int debug = 0){
    string message = "Joueur 1, veuillez entrez un mot entre 3 et 10 caracteres et sans espaces : ";
    cout << message << endl;
    string motMystere;
    getline(cin, motMystere);

    motMystere = verifEspace(motMystere);
    motMystere = sMAJ(motMystere);
    bool bTaille = bVerifTailleMot(motMystere, 3, 10);
 /*   if(debug == 1){
        cout << "### mot mystere : " << motMystere;
        cout << ", taille mot mystere : " << motMystere.length() << endl;
        cout << ", taille bool : " << bTaille << endl;
    } */
    while (!bTaille){
        if(iTailleMot(motMystere) < 3){
            cout << motMystere << " est trop court... " << message << endl;
        }
        else {
            cout << motMystere << " est trop long... " << message << endl;
        }
        getline(cin, motMystere);
        motMystere = verifEspace(motMystere);
        bTaille = bVerifTailleMot(motMystere,3, 10);
     /*   if(debug == 1){
            cout << "### mot mystere : " << motMystere;
            cout << "taille mot mystere : " << motMystere.length() << endl;
        } */
    }

    return motMystere;
}

string sFlouterMot(string p_sMot){

    int tailleMot(0);
    char d;
    char f;
    string motFloute;
    tailleMot = p_sMot.length();
    d = p_sMot[0];
    motFloute = d;

    f = p_sMot[tailleMot-1];

    int i = 1;
    for(i; i < tailleMot - 1; i++){
        motFloute += "*";
    }
    motFloute += f;
    motFloute = sMAJ(motFloute);

    return motFloute;
}

bool bVerifBienTrouve(string p_motMystere, string p_motTente){

    if(p_motMystere == p_motTente){
        return true;
    }
    return false;
}

string creerAnagramme(string p_motMystere, int debug = 0){
    // créer vector temp ou string temp
    string anagramme;
    int tailleMotMystere = iTailleMot(p_motMystere);
    int i(0);

    while(p_motMystere[i]){
        int chiffreAleatoire = chiffreRandom(tailleMotMystere);
        anagramme += p_motMystere[chiffreAleatoire];
        p_motMystere.erase(chiffreAleatoire, 1);
        tailleMotMystere = iTailleMot(p_motMystere);
        if(debug == 1){
            cout << "anagramme : " << anagramme << " et p_motMystere : " << p_motMystere << endl;
        }

    }

    return anagramme;
}


int tenterTrouverMotMystere( string p_motMystere, string p_motFloute, string p_anagramme, int p_nombreCoupsMax,  int debug = 0){

    int iCoupsPartie(0);

    int  iTailleMotMystere = iTailleMot(p_motMystere);
    string sTailleMotMystere = to_string(iTailleMotMystere);

    string messageAide = "Petite aide : le mot mystere contient " + sTailleMotMystere + " lettres, commence et finit ainsi : " + p_motFloute + ", et son anagramme est : " + p_anagramme + ".";
    cout << messageAide << endl;
    cout << "Pour vous quel est le mot mystere? " << endl;
    cout << "Il vous reste " << p_nombreCoupsMax << " chances pour le trouver. Allez-y :" << endl;

    iCoupsPartie++;  // iCoupsPartie :1

    string motTente;
    getline(cin, motTente);
    motTente = sMAJ(motTente);
    motTente = verifEspace(motTente);
    int iTailleMotTente = iTailleMot(motTente);
    bool reponseMotTrouve = bVerifBienTrouve(p_motMystere, motTente);


    if(debug == 1) {
        cout << "debug : mot tente : " << motTente << ", mot mystere :  " << p_motMystere << /* ", "  << reponseMotTrouve << */ endl;
    }

    while(((iTailleMotMystere != iTailleMotTente) || !reponseMotTrouve) && iCoupsPartie < p_nombreCoupsMax) {
        cout << "Non... Il vous reste encore " << p_nombreCoupsMax - iCoupsPartie << " coups pour gagner..." << endl;

        if (iTailleMotMystere != iTailleMotTente) {
          /*  if (debug == 1) {
                cout << "### mot mystere : " << p_motMystere;
                cout << ", mot tente : " << motTente;
                cout << ", reponse taille : " << iTailleMotMystere;
                cout << ", reponse mot trouve : " << reponseMotTrouve << endl;
            } */
            cout << "Le mot mystere doit avoir " << iTailleMotMystere << " lettres et non pas " << iTailleMotTente
                 << ". Recommencez" << endl;

        } else {
          /*  if (debug == 1) {
                cout << "###mot mystere : " << p_motMystere;
                cout << ", mot tente : " << motTente;
                cout << ", reponse taille : " << iTailleMotTente;
                cout << ", reponse mot trouve : " << reponseMotTrouve << endl;
            } */
            cout << motTente << " n'est pas le mot mystere... recommencez :" << endl;
        }
        iCoupsPartie++;
        cout << messageAide << endl;
        getline(cin, motTente);
        motTente = sMAJ(motTente);
        motTente = verifEspace(motTente);
        iTailleMotTente = iTailleMot(motTente);
        reponseMotTrouve = bVerifBienTrouve(p_motMystere, motTente);

    }
    if(debug == 1){
        cout << "mot mystere : " << p_motMystere << ", mot tente : " << motTente << endl;
    }

    if(!reponseMotTrouve){
        cout << "Vous avez essaye " << p_nombreCoupsMax << " fois sans reussir... Le mot mystere etait : " << p_motMystere << endl;
        iCoupsPartie++; // iCoupsPartie : 6
    }
    else{
        cout << "Felicitations! " << motTente << " est bien le mot mystere!" << endl;
        if(iCoupsPartie == 1){
            cout << "Vous avez trouve en " << iCoupsPartie << " coup." << endl;
        }
        else{
            cout << "Vous avez trouve en " << iCoupsPartie << " coups." << endl;
        }
    }

    return iCoupsPartie;
}

float calculerStatistiques(float p_partiesJouees,  float p_partieGagnees, float p_coupsPerdants){
    // p_partieGagnees == coups gagnants
    float coupsTotaux = p_partieGagnees + p_coupsPerdants;
    // cout << "coupsTotaux : " << coupsTotaux << ", parties gagnees : " << p_partieGagnees << ", coups perdants : " << p_coupsPerdants << endl;
    float fReussite = (p_partieGagnees/coupsTotaux);
    // cout << fReussite << endl;
    fReussite = fReussite * 100;
    fReussite = round (fReussite);
    // cout << fReussite << endl;
    return fReussite;
}

string getMotRandom(ifstream &p_monFlux, int p_iScope){
    int iNbRandom = chiffreRandom(p_iScope);
    int i(0);
    string motRandom;
    while(i <= iNbRandom){
        getline(p_monFlux, motRandom);
        i++;
    }
    p_monFlux.clear();
    p_monFlux.seekg(0, ios::beg);
    return motRandom;
}

