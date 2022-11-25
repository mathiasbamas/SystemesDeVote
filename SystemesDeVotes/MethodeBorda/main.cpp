#include <iostream>
#include <vector>

using namespace std;

/* La methode Borda demande a chaque de votant de faire un classement des choix selon leur préferences
 * Pour n candidat le permier reçoit n points le deuxième n-1... */

vector<string> listeJeux{"CSGO", "Street Fighter II", "Civilisation VI", "Mario Kart"};


/* La fonction ligneEnTableau renvoie un tableau contenant chaque nombre sur une ligne */
vector<unsigned> ligneEnTableau(string ligne){
    vector<unsigned> tab;
    string str;
    for(unsigned i = 0; i < ligne.size(); ++i)
    {
        if(ligne[i] == ' ')
        {
            tab.push_back(stoul(str));
            str = "";
        }
        else{
            str = str + ligne[i];
        }
    }
    tab.push_back(stoul(str));
    return tab;
}


/* La fonction recupClassement parcours chaque ligne du flux d'entrée et ajoute chaque ligne de classement a
 * un tableau */
vector<vector<unsigned>> recupClassements(){
    vector<vector<unsigned>> classementParVotant;
    string ligne;
    while(true)
    {
        getline(cin,ligne); // NOM
        getline(cin,ligne); // PRENOM
        getline(cin,ligne); // CLASSEMENT
        if(cin.eof()) break;
        classementParVotant.push_back(ligneEnTableau(ligne));
    }
    return classementParVotant;
}


/* La fonction compteResultat ajoute pour chaque jeu un nombre de points correspondant a son classement pour chaque votants
 * Puis elle renvoie un tableau contenant le resultat de chaque jeu */
vector<unsigned> compteResultat(vector<vector<unsigned>> listeNotes){
    vector<unsigned> resultat (listeJeux.size());
    for(unsigned i = 0; i < listeNotes.size(); ++i)
    {
        for(unsigned j = 0; j < listeJeux.size(); ++j)
        {
            resultat[listeNotes[i][j]] += (listeJeux.size() - j);
        }
    }
    return resultat;
}

/* La fonction trouve gagnant renvoie dans le flux de sortie le ou les gagnants */
void trouveGagnant(vector<unsigned> resultat){
    vector<unsigned> gagnants{0};

    /* Trouve gagnant(s) */
    for(unsigned i = 1; i < resultat.size(); ++i)
    {
        if(resultat[i] > resultat[gagnants[0]]) gagnants.clear();
        if(resultat[i] >= resultat[gagnants[0]]) gagnants.push_back(i);
    }

    /* Affichage gagnants */
    cout << "Gagnant(s) :" << endl;
    for(auto indiceJeu : gagnants)
    {
        cout << "- " << listeJeux[indiceJeu] << endl;
    }
}

int main()
{
    vector<unsigned> resultat = compteResultat(recupClassements());
    trouveGagnant(resultat);
    return 0;
}


