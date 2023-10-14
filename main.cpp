#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void permutacja(vector<int>& permutacja, int &sciezka, vector<int>& najkrotsza, vector<vector<int> > macierz){
    int obliczona = 0;
    do {
        /*                      // wypisanie danej permutacji ( już nie używane )
        for(int i : permutacja){
            cout << i << " ";
        }
        cout << endl;
        */

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

vector<vector<int> > wczytaj_macierz(const string& daneWejsciowe, int &liczba_miast) {

    ifstream plikWejsciowy;  // na odczyt pliku

    plikWejsciowy.open(daneWejsciowe);    // otwieram plik
    if (plikWejsciowy.is_open()) {          // sprawdzam czy plik poprawnie otwarty
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        exit(-1);
    }

    plikWejsciowy >> liczba_miast; // wczytanie liczby miast

    vector<vector<int> > macierz(liczba_miast, vector<int>(liczba_miast));   // macierz na przechowanie danych z pliku

    for (int i = 0; i < liczba_miast; ++i) {    // wpisywanie do macierzy
        for (int j = 0; j < liczba_miast; ++j) {
            plikWejsciowy >> macierz[i][j];
        }
    }
    plikWejsciowy.close();   // zamykam plik

    return macierz;     // zwracam gotowa macierz
}


int main() {
    while(true){

    int dlugosc_sciezki = INT_MAX , liczba_miast = 0;  // dlugosc sciezki na max aby potem szukac najkrotszej
    vector<int> tablica_miast, najkrotsza;              // vector najkrotsza przechowuje najkrotsza droge przez miasta


    cout << "Podaj liczbe miast w zakresie 4-20: ";   // w pliku i tak jest liczba miast,
    cin >> liczba_miast;             // ale to jest po to aby latwo wybrac ktore chcemy z kilku plikow
    cout << endl;

    vector<vector<int> > macierz = wczytaj_macierz(to_string(liczba_miast) + "_test.txt", liczba_miast);

    for (int i=1; i < liczba_miast; i++)   // wstawiam miasta do vectora, bez miasta startowego
        tablica_miast.push_back(i);          // gdyż miasto startowe zostaje na sowim miejscu
                                                // i nie bierze udziału w generowaniu permutacji,

    auto start = chrono::high_resolution_clock::now(); // start pomiaru czasu

    permutacja(tablica_miast, dlugosc_sciezki, najkrotsza, macierz);    // obliczanie najkrotszej sciezki

    auto koniec = chrono::high_resolution_clock::now(); // koniec pomiaru czasu

    auto czas_wykonania = chrono::duration_cast<chrono::microseconds>(koniec - start);
    cout << "Czas wykonania: " << czas_wykonania.count() << " mikrosekund" << endl;

    cout << "najkrotsza dlugosc_sciezki dlugosc: " << dlugosc_sciezki << endl;
    cout << "najkrotsza dlugosc_sciezki przez miasta: ";

    for (int j : najkrotsza)    // wypisanie najkrotszej drogi
        cout << j <<" ";
    cout<<endl;
    cout<<endl;
    }

}
