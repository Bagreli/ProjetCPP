//
// Created by utilisateur on 01/10/2019.
//

#ifndef PROJETSCPP_MOTMYSTERE_H
#define PROJETSCPP_MOTMYSTERE_H

using namespace std;

string sEntrerMot(int debug = 0);
int iEntrerNombreCoupsMax();
string sFlouterMot(string p_sMot);
bool bVerifBienTrouve(string p_motMystere, string p_motTente);
int tenterTrouverMotMystere(string p_motMystere, string p_motFloute, string p_anagramme, int p_nombreCoupsMax,  int debug = 0);
string creerAnagramme(string p_motMystere, int debug = 0);
float calculerStatistiques(float p_partiesJouees, float p_partieGagnees, float p_coupsPerdants);
int choisirPartie();


#endif //PROJETSCPP_MOTMYSTERE_H
