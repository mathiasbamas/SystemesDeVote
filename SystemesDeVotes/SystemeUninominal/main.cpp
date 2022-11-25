#include <iostream>
#include <vector>

using namespace std;

/* Le vote uninominal permet aux votants de voté pour une personne
 * La personne qui a le plus de voix l'emporte */

vector<string> listeJeux = {"CSGO", "StreetFighter II", "Civilisation VI", "Mario Kart"};

/* La fonction recupVote renvoie les votes de chaque votant sous la forme d'un vecteur d'entier
 * Elle parcours chaque ligne et enregistre toutes les 3 lignes un vote dans listeVote*/
vector<unsigned> recupVote(){
    vector<unsigned> listeVote;
    string ligne;
    while(true){
        getline(cin, ligne); // NOM
        getline(cin, ligne); // PRENOM
        getline(cin, ligne); // VOTE
        if(cin.eof()) break;
        listeVote.push_back(stoul(ligne));
    }
    return listeVote;
}

/* La fonction voteUninomal ajoute pour chaque jeu son nombre de vote puis cherche le gagnants
 * On utilise un tableau pour les gagnants dans un cas d'égalité */
void voteUninominal(vector<unsigned> listeVote)
{
    /* Compte des voix*/
    vector<unsigned> resultats (listeJeux.size());
    for(unsigned i = 0; i < listeVote.size(); ++i) ++resultats[listeVote[i]];

    /* Calcul du gagnant(s) */
    vector<unsigned> gagnants{0};
    for(unsigned i = 1 ; i < resultats.size(); ++i)
    {
        if(resultats[i] == resultats[gagnants[0]]) gagnants.push_back(i);
        else if(resultats[i] > resultats[gagnants[0]])
        {
            gagnants.clear();
            gagnants.push_back(i);
        }
    }

    /* Affichage Gagnants*/
    if(gagnants.size() == 1)
    {
        cout << "Gagnant : " << listeJeux[gagnants[0]] << " ";
        cout << 100*resultats[gagnants[0]]/listeVote.size() << "%" << endl;
    }
    else{
        cout << "Gagnants par égalité" << endl;
        for(unsigned i = 0; i < gagnants.size(); ++i)
        {
            cout << " - " << listeJeux[i] << " " << 100*resultats[gagnants[i]]/listeVote.size() << "%" <<  endl;
        }
    }
}

int main()
{
    voteUninominal(recupVote());
    return 0;
}
