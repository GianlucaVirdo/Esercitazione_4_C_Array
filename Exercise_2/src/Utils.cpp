#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

bool ImportData(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "File open failed"<< endl;
        return false;
    }

    string line;
    if (!file.eof())
    {
        getline(file, line, ';');
        getline(file,line);
    }

    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    if (!file.eof())
    {
        getline(file, line, ';');
        getline(file,line);
    }

    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    getline(file,line);

    w = new double[n];
    r = new double[n];

    for (size_t i = 0; i < n; ++i)
    {
        if (!getline(file, line, ';'))
        {
            cerr << "Failed to read w[" << i << "]" << endl;
            return false;
        }

        istringstream convertW;
        convertW.str(line);
        convertW >> w[i];

        if (convertW.fail())
        {
            cerr << "Failed to convert w[" << i << "]" << endl;
            return false;
        }

        if (!getline(file, line))
        {
            cerr << "Failed to read r[" << i << "]" << endl;
            return false;
        }

        istringstream convertR;
        convertR.str(line);
        convertR >> r[i];

        if (convertR.fail())
        {
            cerr << "Failed to convert r[" << i << "]" << endl;
            return false;
        }
    }

    file.close();

    return true;
}


void ComputeRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V)
{
    rateOfReturn = 0;

    for (size_t i = 0; i < n; ++i)
    {
        rateOfReturn += w[i] * r[i];
    }

    V = (1 + rateOfReturn) * S;
}


void ExportData(ostream& out, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& rateOfReturn, const double& V)
{
    out << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    out << "w = " << ArrayToString(n, w) << endl;
    out << "r = " << ArrayToString(n, r) << endl;
    out << "Rate of return of the portfolio: " << fixed << setprecision(4) << rateOfReturn << endl;
    out << "V: " << fixed << setprecision(2) << V << endl;
}

string ArrayToString(const size_t& n, const double* const& v)
{

    ostringstream toString;
    toString << "[ ";
    for (size_t i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
