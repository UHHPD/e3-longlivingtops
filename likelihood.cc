#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prob(std::vector<int> daten, double mu){
  double likelihood = 1;
  for(int k : daten){
    likelihood = likelihood * poisson(mu, k);
  }
  return likelihood;
}

int main() {
    using namespace std;

    vector<int> daten;
    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();
    double likelihood;
    likelihood = prob(daten, 3.11538);
    cout << likelihood << endl;
}