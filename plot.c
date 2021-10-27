
void plot(){
  // create histogram with 11 bins from -0.5 to 10.5
  TH1D hist ("hist",";␣N", 11 , -0.5 ,10.5);
  // create TTree object and fill with file contents
  TTree t;
  t.ReadFile ("hist.txt","N/I:counts/I");
  // fill histogram with entries in tree
  t.Draw ("N >>hist","counts","HIST");
}
