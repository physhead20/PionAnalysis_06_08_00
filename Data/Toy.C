#define Toy_cxx
#include "Toy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

///////////////////////////////// "Matched Track" dE/dX vs z ///////////////////////////////////////////////
TH2D *hdatadEdXvsZRaw = new TH2D("hdatadEdXvsZRaw", "dE/dX vs Raw Z ",200, 0, 100, 200, -20, 80);

void Toy::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0;

// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################
TFile myfile("Toy_ThroughGoingTracks.root","RECREATE");  


//for (Long64_t jentry=0; jentry<nentries;jentry++) 
for (Long64_t jentry=0; jentry<40000;jentry++)
   {
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 500 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      float TempDeDX = 0;
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 
	 TempDeDX     = trkdedx[nTPCtrk][1][nspts];
	 if(TempDeDX < -100){TempDeDX = -10;}
	 //if(trkdedx[nTPCtrk][1][nspts] < 0){continue;}
	 
	 
	 hdatadEdXvsZRaw->Fill(trkxyz[nTPCtrk][1][nspts][2], TempDeDX);
	 
	 //std::cout<<"trkxyz[nTPCtrk][1][nspts][0] = "<<trkxyz[nTPCtrk][1][nspts][2]<<std::endl;
	 //std::cout<<"Track z = "<<trkz[nTPCtrk][nspts]<<std::endl;
	 
	 
	 
	 
	 
	 
	 
	 }//<---End spts loop 
      
      
      
      }//<---end loop over tracks
    

   }//<---End jentry loop
   
   
hdatadEdXvsZRaw->Write();   
}
