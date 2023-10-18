#include "drugi.h"
#include <vector>
#include <iostream>

using namespace std;

void drugi::Branch_and_bound(vector<int>& permutacja, int &sciezka, vector<int>& najkrotsza, vector<vector<int> > macierz) {
    int obliczona = 0;
    int droga;
    cout << endl;
    do {
        skip:
        // wypisanie danej permutacji ( już nie używane )
        /*
        for(int i : permutacja){
            cout << i << " ";
        }
        cout<<endl;
        */

        obliczona = obliczona + macierz[0][permutacja.front()];    // sciezka ze startu do pierwszego miasta

        cout<<obliczona<<endl;

        if (obliczona > sciezka){
            obliczona = 0;
            int przesuw = permutacja.front();
            while (przesuw == permutacja.front()){
                next_permutation(permutacja.begin(),permutacja.end());
            }
            goto skip;
        }

        for(int j = 0; j < permutacja.size() - 1; j++){
            droga = macierz[ permutacja[j] ][ permutacja[j + 1] ]; // w vektorze permutacja są tylko miasta
            obliczona = obliczona + droga;  // po drodze bez sciezek ze start oraz do start

            cout<<obliczona<<endl;

            if (obliczona > sciezka){
                break;
            }
        }

        if (obliczona > sciezka){
            obliczona = 0;
            continue;
        }

        obliczona = obliczona + macierz[permutacja.back()][0];  // sciezka z ostatniego miasta do startu

        cout<<obliczona<<endl;

        if (obliczona < sciezka){   // aktualizacja najkrotszej sciezki
            sciezka = obliczona;
            najkrotsza = permutacja;
        }


        obliczona = 0;    // reset obliczonej nowej sciezki

    } while ( next_permutation(permutacja.begin(), permutacja.end() ) );    // iteruje po kolejnej permutacji
    // https://cplusplus.com/reference/algorithm/next_permutation/   <-- tu znalazłem
}



void drugi::Stop() {

}
