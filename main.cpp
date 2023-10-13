#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void permutacja(vector<int>& array){
    do {
        for(int i : array){
            cout<<i<<" ";
        }
        cout<<endl;
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
    int liczba_miast;
    vector<int> tablica_miast;
    cout<<"Podaj liczbe miast: ";
    cin>>liczba_miast;
    cout<<endl<<endl;

    vector<vector<int> > macierz = wczytaj_macierz(to_string(liczba_miast) + "_test.txt");
    liczba_miast = wczytaj_liczbe_miast(to_string(liczba_miast) + "_test.txt");

    for (int i=1; i<liczba_miast; ++i){
        tablica_miast.push_back(i);
    }

    cout<<"liczba miast: "<<liczba_miast<<endl;

    permutacja(tablica_miast);


    return 0;
}
