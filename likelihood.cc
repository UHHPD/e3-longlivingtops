
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prop(vector<int> daten, double mu){
  double likelihood = 1;
  for(int k : daten){
    likelihood *= poisson(mu, k);
  }
  return likelihood;
}

double lambda(vector<int> daten, double mean){
      double prod=1;
      for (int i=0; i<234; ++i){
        prod *= poisson(mean,daten[i])/poisson(daten[i],daten[i]);
      }
    return prod;
}

int main() 
{

    vector<int> daten;
    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();
    
    //a)
    double mean = 3.11538;
    double likelihood_mean;
    likelihood_mean = prop(daten, mean);
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
    for (int i=0; i<logLikelihoods.size(); ++i){
      double deltanll_value = logLikelihoods[i]+2*log(likelihood_mean);
      shiftedLLLH.push_back(deltanll_value);
      deltanll << mus[i] << "\t" << deltanll_value << endl; 
    }
    deltanll.close();

    //e)
    
    //ofstream chi2("chi2.txt")
    cout << "Lambda: " << -2*log(lambda(daten, mean)) << endl;
    double z = (-2*log(lambda(daten, mean))-233)/sqrt(2*233);
    cout << "z: " << z << endl;
    
}