#include <iostream>
#include <vector>


using namespace std;

class drugi {
public:

    void Stop();

    static void
    Branch_and_bound(vector<int> &permutacja, int &sciezka, vector<int> &najkrotsza, vector<vector<int>>);
};
