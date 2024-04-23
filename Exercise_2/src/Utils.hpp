#pragma once
#include <iostream>

using namespace std;

/// ImporData reads the input data from the data file
bool ImportData(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r);

/// ComputeRateOfReturn computes the rate of return of the portfolio and the final amount of wealth
void ComputeRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V);

/// ExportData prints data on an output stream
void ExportData(ostream& out, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& rateOfReturn, const double& V);

/// Export a vector in a string
string ArrayToString(const size_t& n, const double* const& v);
