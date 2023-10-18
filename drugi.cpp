#include "drugi.h"
#include <vector>
#include <iostream>

using namespace std;

void drugi::Branch_and_bound(vector<int>& permutacja, int &sciezka, vector<int>& najkrotsza, vector<vector<int> > macierz) {
    int obliczona = 0;
    do {
        // wypisanie danej permutacji ( już nie używane )
        for(int i : permutacja){
            cout << i << " ";
        }
        cout << endl;


        obliczona = obliczona + macierz[0][permutacja.front()];    // sciezka ze startu do pierwszego miasta

        for(int j = 0; j < permutacja.size() - 1; j++){                        // w vektorze permutacja są tylko miasta
            obliczona = obliczona + macierz[ permutacja[j] ][ permutacja[j + 1] ];  // po drodze bez sciezek ze start oraz do start
        }

        obliczona = obliczona + macierz[permutacja.back()][0];  // sciezka z ostatniego miasta do startu

        if (obliczona < sciezka){   // aktualizacja najkrotszej sciezki
            sciezka = obliczona;
            najkrotsza = permutacja;
        }

        obliczona = 0;    // reset obliczonej nowej sciezki

    } while ( next_permutation(permutacja.begin(), permutacja.end() ) );    // iteruje po kazdej permutacji
    // https://cplusplus.com/reference/algorithm/next_permutation/   <-- tu znalazłem
}



void drugi::Stop() {

}
