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

        if (obliczona > sciezka){   // sprawdzmy czy scieżka sie opłaca na samym początku
            obliczona = 0;
            int przesuw = permutacja.front();   // obliczam o ile permutacji należy się przesunąć gdyż nie będziemy ich sprawdzać
            while (przesuw == permutacja.front()){
                czy_dalej = next_permutation(permutacja.begin(),permutacja.end());
                if (!czy_dalej){
                    return;  // jeśli nie istnieje to koniec
                }
            }

            goto skip;      // kontynujemy jeśli permutacja istnieje
        }

        for(int j = 0; j < permutacja.size() - 1; j++){
            droga = macierz[ permutacja[j] ][ permutacja[j + 1] ]; // w vektorze permutacja są tylko miasta
            obliczona = obliczona + droga;  // po drodze bez sciezek ze start oraz do start


            if (obliczona > sciezka){   // sprawdzmy czy scieżka sie opłaca (kolejne po początku)
                obliczona = 0;
                int przesuw = permutacja[j+1];   // obliczam o ile permutacji należy się przesunąć gdyż nie będziemy ich sprawdzać
                while (przesuw == permutacja[j+1]){
                    czy_dalej = next_permutation(permutacja.begin(),permutacja.end());  // sprawdzamy czy istnieje kolejna permutacja
                    if (!czy_dalej){
                        return; // jeśli nie istnieje to koniec
                    }
                }

                goto skip;   // kontynujemy jeśli permutacja istnieje
            }
        }

        obliczona = obliczona + macierz[permutacja.back()][0];  // sciezka z ostatniego miasta do startu

        if (obliczona < sciezka){   // aktualizacja najkrotszej sciezki
            sciezka = obliczona;
            najkrotsza = permutacja;
        }

        obliczona = 0;    // reset obliczonej nowej sciezki

    } while ( next_permutation(permutacja.begin(), permutacja.end() ));    // iteruje po kolejnej permutacji

}


