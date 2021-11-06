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



void Plot2()
{
	TCanvas* c = new TCanvas("c","c",600,600);
	c->cd();
	TPad* pad= new TPad("pad","pad",0.01,0.00,0.99,0.99);
	pad->SetLeftMargin(0.15);
	pad->Draw();
	pad->cd();



	TGraph* gr = new TGraph("nll.txt", "%lg\t%lg");
	gr->SetLineWidth(2);
	gr->SetLineColor(600);
	gr->GetHistogram()->GetYaxis()->SetRangeUser(880, 1450);
	gr->GetHistogram()->GetXaxis()->SetRangeUser(1, 5.9);
	gr->GetHistogram()->GetXaxis()->SetTitle("#mu");
	gr->GetHistogram()->GetYaxis()->SetTitle("-2ln(L(#mu))");
	gr->GetHistogram()->SetTitle("LogLikelihood 2c");
   	gr->Draw("AC");
	c->Print("Likelihood_2c.pdf");
}
