//
// Created by utilisateur on 01/10/2019.
//

#ifndef PROJETSCPP_FONCTIONSPRATIQUES_H
#define PROJETSCPP_FONCTIONSPRATIQUES_H

using namespace std;

string sMAJ(string p_mot);
int iTailleMot(string p_mot);
bool bVerifTailleMot(string p_mot, int p_tailleMini, int p_tailleMaxVoulue);
string verifEspace(string p_mot);
void sauterLignes(int p_nombreLignes);
int chiffreRandom(int iScope);
bool recommencer();
int compterLignes(ifstream &p_monFlux);

#endif //PROJETSCPP_FONCTIONSPRATIQUES_H
