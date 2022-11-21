#include <iostream>
#include <SystemeFrancais.h>
#include <ScrutinUninominal.h>
#include <MethodeBorda.h>
#include <VoteParValeur.h>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

vector<string> listeJeux {"CS:GO", "Street Fighter II", "Civilisation VI", "Mario Kart"};

// FONCTION VERIFICATION FICHIER BIEN OUVERT

int main()
{
    afficheTab(generationNoteParJeu());
    return 0;

    // APPEL DE CHAQUE SYSTEMES
}


