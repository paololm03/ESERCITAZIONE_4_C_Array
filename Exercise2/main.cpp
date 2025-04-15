#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    double S;
    size_t n;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportData("data.txt", S, n, w, r))
    {
	    cerr<< "Something goes wrong with import"<< endl;
        return 1;
    }
    else
        cout<< "Import successful" << endl;

    double R = RateOfReturn(w, r, n);
    double V = FinalValue(S, R);

    ExportResult("result.txt", S, n, w, r, R, V);

    delete[] w;
    delete[] r;

    return 0;
}
