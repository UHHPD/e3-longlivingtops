#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

int main() {
    using namespace std;
    vector<int> zaehler(11);

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream foutpoi("histpoi.txt");

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    fin.close();
    for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) 
    {
      cout << k << ":" << zaehler [ k ] <<  endl ;
      foutpoi << k << "\t" << zaehler[k] << "\t" << 234*poisson(3.11538,k) << endl;
      fout << k<<"\t" << zaehler [ k ] << endl;
    }
    fout.close();
    foutpoi.close();
}
//Hallo Daniel Hallo Cedric