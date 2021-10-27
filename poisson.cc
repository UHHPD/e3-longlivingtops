#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

int main() {
    using namespace std;
    vector<int> zaehler(11);

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    fin.close();
    for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) 
    {
      cout << k << ":" << zaehler [ k ] <<  endl ;
      fout << k<<"\t" << zaehler [ k ] << endl;
    }
    fout.close();
}
//Hallo Daniel Hallo Cedric