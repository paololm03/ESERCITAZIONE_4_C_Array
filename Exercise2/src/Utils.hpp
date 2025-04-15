#pragma once

#include <iostream>

using namespace std;

bool ImportData(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r);

double RateOfReturn(const double* w, const double* r, size_t n);

double FinalValue(double S, double R);

void ExportResult(const string& outputFilePath, double S, size_t n, const double* w, const double* r, double R, double V);