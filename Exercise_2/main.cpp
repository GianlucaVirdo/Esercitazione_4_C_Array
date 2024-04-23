#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportData(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }

    double rateOfReturn;
    double V;
    ComputeRateOfReturn(S, n, w, r, rateOfReturn, V);

    ExportData(cout, S, n, w, r, rateOfReturn, V);

    string outputFileName = "C:/Users/UNIEURO/Desktop/PCS24/Esercitazione_4_C_Array/result.csv";
    ofstream file;
    file.open(outputFileName);

    if (!file.fail())
    {
        ExportData(file, S, n, w, r, rateOfReturn, V);
    }

    file.close();

    delete[] w;
    delete[] r;

    return 0;
}

