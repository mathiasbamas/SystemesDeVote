#ifndef METHODEBORDA_H
#define METHODEBORDA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <random>


using namespace std;

vector<vector<unsigned>> listeJeuxParVotant()
{
    srand(time(NULL));
    string ligne;
    vector<vector<unsigned>> jeuxParVotant;
    ifstream listeVotant ("votants.txt");
    while(true)
    {
        getline(listeVotant, ligne);
        getline(listeVotant, ligne);
        if(listeVotant.eof()) break;
        vector<unsigned> listeJeux{0,1,2,3};
        for(unsigned i (0); i < 5; ++i){
            swap(listeJeux[random()%4], listeJeux[random()%4]);
        }
        jeuxParVotant.push_back(listeJeux);
    }
    return jeuxParVotant;
}



void compteVotes(vector<vector<unsigned>> jeuxParVotant)
{
    vector<unsigned> resultats{0,0,0,0};

    for(unsigned i (0); i < jeuxParVotant.size(); ++i)
    {
        for(unsigned j (0); j < 4; ++j)
        {
            resultats[jeuxParVotant[i][j]] = resultats[jeuxParVotant[i][j]] + (4-j);
        }
    }
    for(unsigned k (0); k < 4; ++k) cout << resultats[k] << " ";
    cout << endl;
}

#endif // METHODEBORDA_H
