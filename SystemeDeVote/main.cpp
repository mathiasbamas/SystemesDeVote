#include <iostream>
#include <SystemeFrancais.h>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

vector<string> listeJeux {"CS:GO", "Street Fighter II", "Civilisation VI", "Mario Kart"};

// FONCTION VERIFICATION FICHIER BIEN OUVERT

vector<unsigned> choixJeuxUnique(){
    string nom;
    string prenom;
    vector<unsigned> listeVotes;
    srand(time(NULL));

    ifstream listeVotant ("votants.txt");
    while(true)
    {
     getline(listeVotant, nom);
     getline(listeVotant, prenom);
     cout << nom << " " << prenom << endl;
     /*getline(listeVotant, nom);
     getline(listeVotant, prenom);
     unsigned choix = rand()%4;
     cout << nom << " " << prenom << " a voté pour " << listeJeux[choix] << endl;
     listeVotes.push_back(choix);*/
     if(listeVotant.eof()) break;
    }
    return listeVotes;
}

int main()
{
    choixJeuxUnique();
    return 0;

    // APPEL DE CHAQUE SYSTEMES
}


