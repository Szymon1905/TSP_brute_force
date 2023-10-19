
#include "test.h"
#include <vector>
#include <iostream>


void test::Branch_and_bound2(vector<int> &permutacja, int &sciezka, vector<int> &najkrotsza, vector<vector<int>> macierz) {
    int n = permutacja.size();
    int obliczona = 0;

    do {
        obliczona = 0;

        // Calculate the distance for the current permutation
        for (int i = 0; i < n - 1; i++) {
            int from = permutacja[i];
            int to = permutacja[i + 1];
            obliczona += macierz[from][to];
        }

        // Add the return trip to the starting city (city 0)
        obliczona += macierz[permutacja[n - 1]][0];

        // Check if this is a better route and update sciezka and najkrotsza
        if (obliczona < sciezka) {
            sciezka = obliczona;
            najkrotsza = permutacja;
        }

    } while (next_permutation(permutacja.begin() + 1, permutacja.end()));

    // Ensure the route starts and ends at the first city (city 0)
    najkrotsza.insert(najkrotsza.begin(), 0);
    najkrotsza.push_back(0);
}
