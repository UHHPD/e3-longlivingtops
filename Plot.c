#include "TH1F.h"
#include "TH2F.h"
#include <iostream>
#include "TCanvas.h"
#include "TLegend.h"
#include "TFile.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TGraph.h"


#include <fstream>

#include <vector>



void Plot()
{
	TCanvas* c = new TCanvas("c","c",600,600);
	TGraph* gr = new TGraph("likelihood.txt", "%lg\t%lg");
	gr->SetLineWidth(2);
	gr->SetLineColor(600);
	gr->GetHistogram()->GetXaxis()->SetRangeUser(2.5, 4);
	gr->GetHistogram()->GetXaxis()->SetTitle("#mu");
	gr->GetHistogram()->GetYaxis()->SetTitle("L(#mu)");
	gr->GetHistogram()->SetTitle("Likelihood");
   	gr->Draw("AC");
	c->Print("Likelihood.pdf");
}
