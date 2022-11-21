#ifndef VOTEPARVALEUR_H
#define VOTEPARVALEUR_H
#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;


vector<vector<unsigned>> generationNoteParJeu(){
    srand(time(NULL));
    string ligne;
    vector<vector<unsigned>> noteParVotant;
    ifstream listeVotant ("votants.txt");
    while(true)
    {
        if(listeVotant.eof()) break;
        getline(listeVotant, ligne);
        vector<unsigned> note;
        for(unsigned i = 0; i < 4; ++i)
        {
            note.push_back(random()%21);
        }
        noteParVotant.push_back(note);
    }
    return noteParVotant;
}

void afficheTab(vector<vector<unsigned>> tab){
    for(unsigned i = 0; i < tab.size(); ++i){
        for(unsigned j = 0; j < tab[0].size(); j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // VOTEPARVALEUR_H
