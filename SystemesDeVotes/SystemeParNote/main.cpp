#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/* Le Systeme par note permet a chaque votant de donner une note sur 20 pour chaque jeu
 * Le jeu avec la meilleur moyenne est elu */

vector<string> listeJeu{"CSGO", "Street Fighter II", "Civilisation VI", "Mario Kart"};


/* Cette fonction permet de recuperer les notes sur une ligne pour les mettre dans un tableau d'entier */
vector<unsigned> recupVoteIndividuel(const string & ligne){
    string note;
    vector<unsigned> listeNoteVotant;
    for(unsigned i = 0; i < ligne.size(); ++i)
    {
        if(isspace(ligne[i]))
        {
            listeNoteVotant.push_back(stoi(note));
            note = "";
        }
        else note += + ligne[i];
    }
    listeNoteVotant.push_back(stoi(note));
    return listeNoteVotant;
}


/* Cette fonction parcours toutes les lignes du flux d'entrée et ajoute chaque ligne de note dans
 * listeVote a l'aide de la fonction recupVoteIndividuel */
vector<vector<unsigned>> recupVote(){
    string ligne;
    vector<vector<unsigned>> listeVotes;
    while(true)
    {
        getline(cin,ligne);
        getline(cin,ligne);
        getline(cin,ligne);
        if(cin.eof()) break;
        listeVotes.push_back(recupVoteIndividuel(ligne));
    }
    return listeVotes;
}


/* Cette fonction renvoie la moyenne obtenue pour chaque jeu */
vector<float> moyenneParChoix(vector<vector<unsigned>> listeVote)
{
    vector<float> totalVote{0,0,0,0};
    for(unsigned i = 0; i < listeVote.size(); ++i)
    {
        for(unsigned j = 0; j < listeJeu.size(); ++j)
        {
            totalVote[j] += listeVote[i][j];
        }
    }

    /* Moyenne pour chaque jeu */
    for(auto & totalParNote : totalVote)
    {
        totalParNote = float(totalParNote)/listeVote.size();
    }

    return totalVote;
}


void trouveGagnant(vector<float> moyennes)
{
    vector<unsigned> gagnants{0};
    for(unsigned i = 1; i < moyennes.size(); ++i)
    {
        if(moyennes[i] > moyennes[gagnants[0]]) gagnants.clear();
        if(moyennes[i] >= moyennes[gagnants[0]]) gagnants.push_back(i);
    }

    /* Affichage gagnant(s)
     * 2 chiffre aprés la virgule avec fixed et setprecision(2) */
    cout << "Gagnant(s) :" << endl;
    for(auto indiceJeu : gagnants)  cout << fixed << setprecision(2) << " - " << listeJeu[indiceJeu] << " (" << moyennes[indiceJeu] << ")" << endl;
}


int main()
{
    vector<float> moyennes = moyenneParChoix(recupVote());
    trouveGagnant(moyennes);
    return 0;
}
