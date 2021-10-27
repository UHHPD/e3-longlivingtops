
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prop(std::vector<int> daten, double mu){
  double likelihood = 1;
  for(int k : daten){
    likelihood *= poisson(mu, k);
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
    
    //a)
    double likelihood_mean;
    likelihood_mean = prop(daten, 3.11538);
    cout << likelihood_mean << endl;
    
    //b)
    ofstream fout("likelihood.txt");
    vector<double> mus;
    vector<double> likelihoods;
    for(double l=0; l<=6; l+=0.1){
      double llh = prop(daten, l);
      fout << l << "\t" << llh << endl;
      mus.push_back(l);
      likelihoods.push_back(llh);
    }  
    fout.close();

    //c)
    //print log likelihood
    ofstream nll("nll.txt");
    vector<double> logLikelihoods;
    for(int i=0; i<mus.size(); ++i){
      double lllh = -2*log(likelihoods[i]);
      nll << mus[i] << "\t\t\t" << lllh << endl;
      logLikelihoods.push_back(lllh);
    }
    nll.close();

    //d)
    //subtract loglikelihood from mean
    ofstream deltanll("deltanll.txt");
    vector<double> shiftedLLLH;
    for (double i : logLikelihoods){
      double deltanll_value = i+2*log(likelihood_mean);
      shiftedLLLH.push_back(deltanll_value);
      deltanll << deltanll_value << endl; 
    }
    deltanll.close();

    
    
}