#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* L'election a la française consiste a voté un premier tour pour elire un candidat
 * si un candidat arrive à la majoritée absolue (> 50%) il est elu directement sinon un
 * second tour a lieu entre les 2 premiers candidats */

vector<string> listeJeux{"CSGO","Street Fighter II", "Civilisation VI", "Mario Kart"};


/* Cette fonction permet de récuper dans un vecteur le premier et le possible second vote d'une personne */
vector<unsigned> recupVoteParVotant(const string & ligne){
    string note;
    vector<unsigned> listeNoteVotant;
    for(unsigned i (0); i < ligne.size(); ++i)
    {
        if(isspace(ligne[i]))
        {
            listeNoteVotant.push_back(stoi(note));
            note = "";
        }
        else note += ligne[i];
    }
    listeNoteVotant.push_back(stoi(note));
    return listeNoteVotant;
}


/* Cette fonction pour chaque ligne du flux d'entrée et renvoie un tableau contenue les votes de toutes
 * les personnes qui ont voté */
vector<vector<unsigned>> recupVoteTotal()
{
    string ligne;
    vector<vector<unsigned>> voteTotal;
    while(true){
        getline(cin,ligne); // NOM
        getline(cin, ligne); // PRENOM
        getline(cin, ligne); // VOTES
        if(cin.eof()) break;
        voteTotal.push_back(recupVoteParVotant(ligne));
    }
    return voteTotal;
}


/* Cette fonction permet a partir d'une liste de vote et d'un numero de tour
 * de donner le nombre de voix de chaque candidat */
vector<unsigned> resultatTour(vector<vector<unsigned>> votes, short tour)
{
    vector<unsigned> voteParJeux (listeJeux.size());
    for(unsigned i = 0; i < votes.size(); ++i)
    {
        ++voteParJeux[votes[i][tour-1]];
    }
    return voteParJeux;
}


/* Cette fonction renvois un vecteur contenant les indices des deux jeux arrivé premier au premier tour */
vector<string> trouveGagnantPremierTour(vector<unsigned> resulats){
    vector<unsigned> indiceJeuVote{0,1};
    for(unsigned i = 0; i < resulats.size(); ++i)
    {
        for(unsigned j = 0; j < 2; ++j)
        {
            if(resulats[i] > resulats[j]){
                indiceJeuVote[j] = i;
                break;
            }
        }
    }
    vector<string> jeuxSecondTour{listeJeux[indiceJeuVote[0]], listeJeux[indiceJeuVote[1]]};
    return jeuxSecondTour;
}

int main()
{
    vector<vector<unsigned>> listeVotes = recupVoteTotal();
    vector<unsigned> resultatPremierTour = resultatTour(listeVotes,1);

    for(unsigned i = 0; i < resultatPremierTour.size(); ++i)
    {
        if(resultatPremierTour[i] > listeVotes.size()/2) // Vrai -> gagnant au premier tour, fin de l'election
        {
            cout << "Vainqueur au premier tour : " << listeJeux[i] << " " << resultatPremierTour[i]*100/listeVotes.size() << "%" << endl;
            return 0;
        }
    }

    // Second tour
    vector<string> listeJeuxSecondTour = trouveGagnantPremierTour(resultatPremierTour);
    vector<unsigned> resultatSecondTour = resultatTour(listeVotes,2);
    cout << "Second tour entre " << endl << "0 - " << listeJeuxSecondTour[0] << endl << "1 - " << listeJeuxSecondTour[1] << endl;
    cout << "Vainqueur : ";
    unsigned m = max(resultatSecondTour[0],resultatSecondTour[1]);
    // Find permet de trouver l'indice du jeu gagnant donné par max
    auto it = find(resultatSecondTour.begin(), resultatSecondTour.end(), m);
    unsigned indice = it - resultatSecondTour.begin();
    cout << listeJeuxSecondTour[indice] << " (" << *it*100/listeVotes.size() << "%)" << endl;
    return 0;
}
