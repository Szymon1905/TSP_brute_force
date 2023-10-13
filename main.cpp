#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void permutacja(vector<int>& array, int &sciezka,vector<int>& najkrotsza, vector<vector<int> > macierz){
    int obliczona = 0;
    do {
        for(int i : array){
            cout<<i<<" ";
        }
        cout<<endl;

        obliczona = obliczona + macierz[0][array.front()];    // sciezka z startu do pierwszego miasta

        for(int j = 0; j < array.size()-1; j++){    // w array są tylko miasta po drodze bez sciezek z start, do start
            obliczona = obliczona + macierz[ array[j] ][ array[j+1] ];
        }

        obliczona = obliczona + macierz[0][array.back()];  // sciezka z ostatniego maista do startu

        if (obliczona < sciezka){
            sciezka = obliczona;
            najkrotsza = array;
        }

        obliczona = 0;

        } while ( next_permutation( array.begin(),array.end() ) );
}

vector<vector<int> > wczytaj_macierz(const string& daneWejsciowe) {

    int liczba_miast;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        exit(-1);
    }

    plikWejsciowy >> liczba_miast; // wczytanie liczby miast

    vector<vector<int> > macierz(liczba_miast, vector<int>(liczba_miast));

    for (int i = 0; i < liczba_miast; ++i) {
        for (int j = 0; j < liczba_miast; ++j) {
            plikWejsciowy >> macierz[i][j];
        }
    }
    plikWejsciowy.close();

    return macierz;
}

int wczytaj_liczbe_miast(const string& daneWejsciowe){
    int liczba_miast;
    ifstream plikWejsciowy;
    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        exit(-1);
    }
    plikWejsciowy >> liczba_miast; // wczytanie liczby miast
    return liczba_miast;
}




int main() {
    int sciezka = INT_MAX;
    int liczba_miast;
    vector<int> tablica_miast;
    vector<int> najkrotsza;

    cout<<"Podaj liczbe miast: ";
    cin>>liczba_miast;
    cout<<endl;

    vector<vector<int> > macierz = wczytaj_macierz(to_string(liczba_miast) + "_test.txt");
    liczba_miast = wczytaj_liczbe_miast(to_string(liczba_miast) + "_test.txt");

    for (int i=1; i<liczba_miast; i++){
        tablica_miast.push_back(i);
    }


    permutacja(tablica_miast, sciezka, najkrotsza, macierz);
    cout<<"najkrotsza sciezka dlugosc: "<<sciezka<<endl;
    cout<<"najkrotsza sciezka przez miasta: ";
    for (int j : najkrotsza){
        cout<< j <<" ";
    }

    return 0;
}
