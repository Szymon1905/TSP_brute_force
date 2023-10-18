#include "drugi.h"
#include <vector>
#include <iostream>

using namespace std;

void drugi::Branch_and_bound(vector<int>& permutacja, int &sciezka, vector<int>& najkrotsza, vector<vector<int> > macierz) {
    int obliczona = 0;
    int droga;
    bool czy_dalej;
    cout << endl;
    do {
        skip:

        obliczona = obliczona + macierz[0][permutacja.front()];    // sciezka ze startu do pierwszego miasta

        if (obliczona > sciezka){
            obliczona = 0;
            int przesuw = permutacja.front();
            while (przesuw == permutacja.front()){
                czy_dalej = next_permutation(permutacja.begin(),permutacja.end());
            }
            if (!czy_dalej){
                return;
            }
            goto skip;
        }

        for(int j = 0; j < permutacja.size() - 1; j++){
            droga = macierz[ permutacja[j] ][ permutacja[j + 1] ]; // w vektorze permutacja są tylko miasta
            obliczona = obliczona + droga;  // po drodze bez sciezek ze start oraz do start


            if (obliczona > sciezka){
                obliczona = 0;
                int przesuw = permutacja[j+1];
                while (przesuw == permutacja[j+1]){
                    czy_dalej = next_permutation(permutacja.begin(),permutacja.end());
                }
                if (!czy_dalej){
                    return;
                }
                goto skip;
            }
        }

        obliczona = obliczona + macierz[permutacja.back()][0];  // sciezka z ostatniego miasta do startu

        if (obliczona < sciezka){   // aktualizacja najkrotszej sciezki
            sciezka = obliczona;
            najkrotsza = permutacja;
        }

        obliczona = 0;    // reset obliczonej nowej sciezki

    } while ( next_permutation(permutacja.begin(), permutacja.end() ) );    // iteruje po kolejnej permutacji

}



void drugi::Stop() {

}
