#include "TH1F.h"
#include "TH2F.h"
#include <iostream>
#include "TCanvas.h"
#include "TLegend.h"
#include "TFile.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TPaveText.h"




void Hist()
{
  TH1F* hist = new TH1F("hist",";N", 11 , -0.5 ,10.5);
  hist->SetStats(0);
  
  TH1F* hist2 = new TH1F("hist2",";N", 11 , -0.5 ,10.5);
  hist2->SetStats(0);
  
  hist->GetXaxis()->SetTitle("Goals per Game");
  hist->GetYaxis()->SetTitle("Number of Games");
  hist->SetLineWidth(5);
  hist->SetLineColor(600);
  
  hist2->SetMarkerStyle(8);
  hist2->SetMarkerSize(2);
  hist2->SetMarkerColor(628);
  hist2->SetLineWidth(5);
  hist2->SetLineColor(628);

  
  
  TCanvas* c = new TCanvas("c","c",600,600);
  TTree* u = new TTree();
  u->ReadFile("histpoi.txt","N/I:counts/I:third/D");
  u->Draw ("N>>hist","counts","HIST");
  u->Draw ("N>>hist2","third","HIST SAME");
  
  
  TLegend* legend = new TLegend(0.68, 0.74, 0.95, 0.9);
  legend->SetBorderSize(0);
  legend->SetFillStyle(0);
  legend->SetTextFont(30);
  //legend->SetHeader("Legend");
  legend->AddEntry(hist,"Data","l");
  legend->AddEntry(hist2,"Poisson","l");
  legend->Draw();


  
  c->Print("Hist2.pdf");
}
