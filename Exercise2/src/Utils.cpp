#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportData(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "Failed to open file." << endl;
        return false;
    }

    string line;

    // leggo S
    getline(file, line);
    istringstream s_line(line.substr(line.find(';') + 1));
    s_line >> S;

    // leggo n
    getline(file, line);
    istringstream n_line(line.substr(line.find(';') + 1));
    n_line >> n;

    // salto la riga con w;r
    getline(file, line);

    w = new double[n];
    r = new double[n];

	// costruisco i vettori w;r
    for (size_t i = 0; i < n; ++i)
    {
        getline(file, line);
        size_t sep = line.find(';');
        istringstream w_stream(line.substr(0, sep));
        istringstream r_stream(line.substr(sep + 1));
        w_stream >> w[i];
        r_stream >> r[i];
    }

    file.close();
    return true;
}

	// tasso di ritorno R
double RateOfReturn(const double* w, const double* r, size_t n)
{
    double R = 0.0;

    for (size_t i = 0; i < n; ++i)
    {
        R += w[i] * r[i];
    }

    return R;
}

	// formula per valore finale
double FinalValue(double S, double R)
{
    return S * (1.0 + R);
}

	// scrivo risultati su file output
void ExportResult(const string& outputFilePath, double S, size_t n, const double* w, const double* r, double R, double V)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr << "Failed to write result file." << endl;
        return;
    }

    file << fixed << setprecision(2);

    file << "S = " << S << ", n = " << n << endl;

    file << "w = [ ";
    for (size_t i = 0; i < n; ++i)
    {
        file << w[i] << " ";
    }
    file << "]" << endl;

    file << "r = [ ";
    for (size_t i = 0; i < n; ++i)
    {
        file << r[i] << " ";
    }
    file << "]" << endl;

    file << fixed << setprecision(4);
    file << "Rate of return of the portfolio: " << R << endl;

    file << fixed << setprecision(2);
    file << "V: " << V << endl;

    file.close();
}