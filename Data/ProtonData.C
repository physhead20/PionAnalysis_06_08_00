#define ProtonData_cxx
#include "ProtonData.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// RAW WCTRK MOMENTUM HISTORGRAM (MeV) /////////////////////////////////////////
TH1D *hdataRawWCTRKMomentum = new TH1D("hdataRawWCTRKMomentum", "Raw WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Events with and without WC Tracks //////////////////////////////////////////
///////////////////////////////  0 = No WCTrack Exists, 1 = WCTrack Exists   ///////////////////////////////////
TH1D *hdataWCTrackExist = new TH1D("hdataWCTrackExist", "Existance of WCTrack", 2, 0, 2);

/////////////////////////////////// Full TOF for the data sample, no cuts //////////////////////////////////////
TH1D *hdataTOFNoCuts = new TH1D("hdataTOFNoCuts", "Time of Flight (No Cuts)", 120, 0, 120);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOFCuts = new TH2D("hdataWCTrackMomentumVSTOFCuts", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hdataTPCTheta = new TH1D("hdataTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hdataTPCPhi = new TH1D("hdataTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hdataWCTheta = new TH1D("hdataWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hdataWCPhi = new TH1D("hdataWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkX = new TH1D("hdataDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkY = new TH1D("hdataDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hdataAlpha = new TH1D("hdataAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Number of Matched Tracks ////////////////////////////////////////////////
TH1D *hdataNMatchTPCWCTrk = new TH1D("hdataNMatchTPCWCTrk", "Number of matched TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialX = new TH1D("hdataTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialY = new TH1D("hdataTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hdataMatchedWCTRKMomentum = new TH1D("hdataMatchedWCTRKMomentum", "Matched WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInitialKEMomentum = new TH1D("hdataInitialKEMomentum", "Pion Initial Momentum (MeV)", 500, 0, 2500); 

/////////////////////////////////// Initial Kinetic Energy (MeV) Unweighted /////////////////////////////////////////////
TH1D *hdataInitialKEMomentumUnWeighted = new TH1D("hdataInitialKEMomentumUnWeighted", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hdataProtondEdX = new TH1D("hdataProtondEdX", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX  /////////////////////////////////////////////////////
TH1D *hdataProtondQdX = new TH1D("hdataProtondQdX", "Matched Track dQ/dX", 15000, 0, 15000);

/////////////////////////////////// "Matched Track" dQ/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hdataProtondQdXFixed = new TH1D("hdataProtondQdXFixed", "Matched Track dQ/dX", 15000, 0, 15000);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hdataProtonRR = new TH1D("hdataProtonRR", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hdataProtonTrkPitch = new TH1D("hdataProtonTrkPitch", "Matched Track Pitch", 1000, 0, 5);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hdataProtondEdXvsRR = new TH2D("hdataProtondEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hdataProtondEdXvsRRFix = new TH2D("hdataProtondEdXvsRRFix", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hdataProtondEdXFixed = new TH1D("hdataProtondEdXFixed", "Matched Track dE/dX", 200, 0, 50);

//////////////////////////////// "Low Momentum Track" PIDA (no cuts) ///////////////////////////////////////
TH1D *hdataLowMomentumTrkPIDA = new TH1D("hdataLowMomentumTrkPIDA", "Low Momentum PIDA", 30, 0, 30);

/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);

///////////////////////////////// Fixed Points X vs Z ///////////////////////////////////////////////
TH2D *hdataFixedCaloPointZX = new TH2D("hdataFixedCaloPointZX", "Fixed Points X vs Z",180, 0, 90, 90, 0, 45);

///////////////////////////////// Fixed Points X vs Z ///////////////////////////////////////////////
TH2D *hdataFixedCaloPointZY = new TH2D("hdataFixedCaloPointZY", "Fixed Points Y vs Z",180, 0, 90, 80, -20, 20);


//---------------------------------------------------------------------------------------------------------------------
//						STOPPING PROTON SAMPLE
//---------------------------------------------------------------------------------------------------------------------
///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hStoppedProtondEdXvsRR = new TH2D("hStoppedProtondEdXvsRR", "dE/dX vs Residual Range for stopped protons",200, 0, 100, 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hStoppedProtondEdX = new TH1D("hStoppedProtondEdX", "Stopped Proton dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hStoppedProtonRR = new TH1D("hStoppedProtonRR", "Stopped Proton Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hStoppedProtonTrkPitch = new TH1D("hStoppedProtonTrkPitch", "Stopped Proton Track Pitch", 1000, 0, 5);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hStoppedProtonRemainingKE = new TH1D("hStoppedProtonRemainingKE", "Proton Remaining Kinetic Energy (MeV)", 500, -1000, 1000);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hNearbyProtonTrackDeltaX = new TH1D("hNearbyProtonTrackDeltaX", "#Delta X Nearby Proton Tracks", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hNearbyProtonTrackDeltaY = new TH1D("hNearbyProtonTrackDeltaY", "#Delta Y Nearby Proton Tracks", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hNearbyProtonTrackDeltaZ = new TH1D("hNearbyProtonTrackDeltaZ", "#Delta Z Nearby Proton Tracks", 160, -40, 40);

// ===================================================================================================================
// ====================================       END HISTOGRAMS AREA           ==========================================
// ===================================================================================================================
void ProtonData::Loop()
{

if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// 					  Putting Flexible Cuts here
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// ### Putting in the particle mass that is being simulated here ###
// ###    which is used when calculating the energy loss before  ###
// ###                       entering the TPC                    ###

float particle_mass = 938.28; //<---Mass of Pion in MeV


// ##########################################################
// ### Preliminary TOF Cut (sets the bounds for TOF Reco) ###
// ##########################################################
double LowerTOFGoodReco = 0;
double UpperTOFGoodReco = 90;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 450.0; //<--(MeV)
double HighWCTrkMomentum  = 1100;//<--(MeV)

double LowerTOF = 28.0; //<--(ns)
double HighTOF  = 55.0; //<--(ns)

// #####################################################
// ### Number of centimeters in Z we require a track ###
// ### to have a space point within (default = 2 cm) ###
// #####################################################
double FirstSpacePointZPos = 2.0;


// ########################################################
// ### Delta X Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaXLowerBound = -4.0;
double DeltaXUpperBound = 6.0;

// ########################################################
// ### Delta Y Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaYLowerBound = -5.0;
double DeltaYUpperBound = 5.0;

// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;

// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;


// ########################################################################
// ### Definition of the upstream part of the TPC where we restrict the ###
// ###             number of tracks which can be present                ###
// ########################################################################
int UpperPartOfTPC = 14.0;

// #####################################################
// ### Number of tracks allowed in the upstream part ###
// #####################################################
int nLowZTracksAllowed = 4;


// #################################################################################
// ### Making shower Cut (ShortTkLength) and the number of short tracks we allow ###
// #################################################################################
double ShortTkLength = 5.0;
int nShortTracksAllowed = 2;


// #################################################   
// ### True  = Use the momentum based weighting  ###
// ### False = Don't weight events               ###
// #################################################
bool UseEventWeight = false;


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###  associated with ordering of the calo points   ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_Reordering = true; 


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###   associated with large dE/dX fluctuations     ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_ExtremeFluctuation = true;     

// ########################################################
// ###   Choose whether or not to fix the calo problems ###
// ### associated with slightly large dE/dX fluctuations###
// ###                                                  ###
// ### True  = Use the fix                              ###
// ### False = Don't use the fix                        ###
// ########################################################
bool FixCaloIssue_LessExtremeFluctuation = true;  


// ##########################################################
// ### Choose whether to remove identified stopping pions ###
// ###                                                    ###
// ### True  = Remove stoppping tagged tracks             ###
// ### False = Don't remove stopping tagged tracks        ###
// ##########################################################
bool RemoveStopping = false;




// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################
//TFile myfile("Data_Proton_histos_noCorrections.root","RECREATE");
TFile myfile("Data_Proton_histos_AllCorrections.root","RECREATE");
// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false;     

// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------

// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 40.; //MeV

// ### The assumed mass of the incident particle (here we assume a pion) ###
float mass = 938.28;

// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nTOFHits = 0, nEventsStopProton = 0;;

// #######################################################
// ### Providing an index for the Matched WC/TPC track ###
// #######################################################
int MatchWCTrackIndex[10] = {0};

// ###############################
// ### Looping over all events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<20000;jentry++) 
   {
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;

   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 1000 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
   //=======================================================================================================================
   //						Wire Chamber Track Cuts
   //=======================================================================================================================
   // ########################################
   // ### Skipping events with no WC Track ###
   // ########################################
   if(nwctrks < 1){ hdataWCTrackExist->Fill(0); continue;}
   
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      hdataRawWCTRKMomentum->Fill(wctrk_momentum[numWCTrk]);
      
      }//<---End loop over WCTrk
      
   // ### Counting Events w/ WC Track ###
   hdataWCTrackExist->Fill(1);
   nEvtsWCTrack++;   


   //=======================================================================================================================
   //						 TOF Event Selection (ns)
   //=======================================================================================================================
   
   bool tofGood = true;
   // ################################################
   // ### If no TOF obeject exists, skip the event ###
   // ################################################
   if(ntof < 1){continue;}
   // ### Loop over all the TOF objects ###
   for(int mmtof = 0; mmtof < ntof; mmtof++)
      {
      // ### Requiring there exists a good TOF recorded ###
      if(tofObject[mmtof] < LowerTOFGoodReco || tofObject[mmtof] > UpperTOFGoodReco)
         {tofGood = false;}
      
      hdataTOFNoCuts->Fill(tofObject[mmtof]);
      
      
      
      
      }//<---End mmtof
   if(ntof>0){nTOFHits++;}
   
   if(!tofGood){continue;}
   nEvtsTOF++;
   
   
   //=======================================================================================================================
   //						 Putting in a GOOD TPC Cut (looking for nhits > 0
   //=======================================================================================================================
   
   // ### Skip the event if no hits are reconstructed in the TPC ###
   if(nhits < 1){continue;}
   nEvntsTPC++;



   // ======================================================================================================================
   //						  Particle ID Filter
   // ======================================================================================================================
   
   bool GoodPID = false;
       
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      
      // ### Checking the number of TOF objects ###
      int TOFObject = numWCTrk;
      hdataWCTrackMomentumVSTOF->Fill(wctrk_momentum[numWCTrk] , tofObject[TOFObject]);
      // ### If we have more WCObjects the TOF, put in protection ### 
      if(TOFObject > ntof){TOFObject = ntof -1;}
      
      // ### Only keeping events that fall into the WCTrk Momentum and TOF range ###
      if(wctrk_momentum[numWCTrk] > LowerWCTrkMomentum && wctrk_momentum[numWCTrk] < HighWCTrkMomentum && 
         tofObject[TOFObject] > LowerTOF && tofObject[TOFObject] < HighTOF)
         {
	 
	 hdataWCTrackMomentumVSTOFCuts->Fill(wctrk_momentum[numWCTrk], tofObject[TOFObject]);
	 
	 GoodPID = true;}
      
      
      }//<---end numWCTrk
   if(!GoodPID){continue;}
   
   nEvtsPID++;


   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[500] = {false};
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      float tempZpoint = 100;
      ThisTrackHasLowZPoint = false;
      // ########################################################
      // ### Looping over the trajectory points for the track ###
      // ########################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	 // ################################################################################ 
         // ### Tracking the lowest Z point that is inside fiducial boundries of the TPC ###
	 // ################################################################################
	 if( trjPt_Z[nTPCtrk][ntrjpts] < tempZpoint  && trjPt_Z[nTPCtrk][ntrjpts] > ZLowerFid && 
	     trjPt_Z[nTPCtrk][ntrjpts] < ZUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid &&
	     trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid )
	     
	    {tempZpoint = trjPt_Z[nTPCtrk][ntrjpts];}//<---End looking for the most upstream point
        
	 // ### Only passing events with a track that has ###
	 // ###  a spacepoint within the first N cm in Z  ### 
	 // ###    And requiring it to be inside the TPC  ###
	 if(tempZpoint < FirstSpacePointZPos)
	    {TrackSptsZCut = true;
	     ThisTrackHasLowZPoint = true;}
	 }//<---End looping over ntrjpts	
	 
      // ### Filling the most upstream spacepoint for this track ###
      hdataUpstreamZPos->Fill(tempZpoint);
      
      // ### Recording that this track is a "good Track if ###
      // ###  it has a space point in the first N cm in Z  ###
      if(ThisTrackHasLowZPoint){ PreLimTrackIndex[nTPCtrk] = true;}
      	 
      }//<---End nTPCtrk loop
      
   // ###############################################
   // ### Skipping events that don't have a track ###
   // ###   in the front of the TPC (Z) Position  ###
   // ###############################################
   if(!TrackSptsZCut){continue;}
   // ### Counting Events w/ front face TPC Track ###
   nEvtsTrackZPos++;


   //=======================================================================================================================
   //					Cutting on the number of tracks in the upstream TPC
   //=======================================================================================================================
   
   int nLowZTracksInTPC = 0;
   // ################################################################
   // ### Initializing variables for study of low Z track location ###
   // ################################################################
   bool LowZTrackInTPC = false;
   
   
   // #################################################################
   // ### Only keeping events if there is less than N tracks in the ###
   // ###    first ## cm of the TPC (to help cut out EM Showers     ###
   // #################################################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
     {
     // ### Start by assuming this track is not in the ###
     // ###          low Z part of the TPC             ###
     LowZTrackInTPC = false;
           
     // ########################################################
     // ### Looping over the trajectory points for the track ###
     // ########################################################
     for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
        {
	 
	// ##################################################
	// ### Count this track if it has a spacepoint in ###
	// ###       the low Z region of the TPC          ###
	// ##################################################
	if(trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	   {  
	   if(trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && 
	      trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid)
	       {LowZTrackInTPC = true;}
		
           }//<---End counting if 
	
        }//<---End ntrjpts loop
      
     // ##################################################################
     // ### If the track was in the "UpperPartOfTPC", bump the counter ###
     // ##################################################################
     if(LowZTrackInTPC)
        {
	
	nLowZTracksInTPC++;
	}//<---End counting track in the Upstream part

     }//<---End nTPCtrk
    
    
     
    // ### Skipping the event if there are too many ###
    // ###       low Z tracks in the event          ###
    if(nLowZTracksInTPC > nLowZTracksAllowed || nLowZTracksInTPC == 0){continue;}  
    
    // ### Counting the event if it passes ###
    nLowZTrkEvents++;   


   // ===========================================================================================================================================
   // 						Vetoing Shower Like Events 
   // ===========================================================================================================================================   
   
   int nShortTrks = 0;
   // ###############################
   // ### Looping over TPC tracks ###
   // ###############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### If the track is shorter than our cut ###
      if(trklength[nTPCtrk] < ShortTkLength)
         {
	 nShortTrks++;
	 
	 }
	 
      }//<---End nTPCtrk
   
   // ### Skipping the event if there are too many short tracks ###
   if(nShortTrks > nShortTracksAllowed){continue;}
   
   // ### Bumping the counter ###
   nNonShowerEvents++;
   
   
   //=======================================================================================================================
   //						Uniquely matching one WC Track to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   MatchWCTrackIndex[0] = 0;
   MatchWCTrackIndex[1] = 0;
   MatchWCTrackIndex[2] = 0;
   MatchWCTrackIndex[3] = 0;
   MatchWCTrackIndex[4] = 0;
   MatchWCTrackIndex[5] = 0;
   MatchWCTrackIndex[6] = 0;
   MatchWCTrackIndex[7] = 0;
   MatchWCTrackIndex[8] = 0;
   
   // #############################################
   // ### Loop over all the wire chamber tracks ###
   // #############################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      
      // ### Grab the WCTrack Theta ###;
      hdataWCTheta->Fill(wctrk_theta[mwctrk]* (180.0/3.141592654));
      
      // ### Grabbing the WCTrack Phi ###
      hdataWCPhi->Fill(wctrk_phi[mwctrk]* (180.0/3.141592654));
      
      // ####################################
      // ### Loop over all the TPC Tracks ###
      // ####################################
      for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
         {
	 // ############################################
         // ###   Only looking at tracks which have  ###
         // ### a point in the first N cm of the TPC ###
         // ############################################
         if(!PreLimTrackIndex[nTPCtrk]){continue;}
	 
	 // === Set a dummy variables for the most upstream point ===
	 float FirstSpacePointZ = 999;
	 float FirstSpacePointY = 999;
         float FirstSpacePointX = 999;
	 
	 float TempTrj_X = 999;
         float TempTrj_Y = 999;
         float TempTrj_Z = 999;
	 // ###############################################################
         // ### Looping over the trajectory points for the prelim-track ###
         // ###############################################################
         for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
            {
	    
	    // ### Recording this tracks upstream most X, Y, Z location, ###
	    // ###       which is inside the fiducial boundary           ###
	    if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	       trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	       trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	       {
	       
	       // ######################################
	       // ### Record the most upstream point ###
	       // ######################################
	       FirstSpacePointZ = trjPt_Z[nTPCtrk][ntrjpts];
	       FirstSpacePointY = trjPt_Y[nTPCtrk][ntrjpts];
	       FirstSpacePointX = trjPt_X[nTPCtrk][ntrjpts];
	       
	       TempTrj_X = pHat0_X[nTPCtrk][ntrjpts];
	       TempTrj_Y = pHat0_Y[nTPCtrk][ntrjpts];
	       TempTrj_Z = pHat0_Z[nTPCtrk][ntrjpts];
	       
	       
	       }//<---End finding the most upstream point
	    }//<---End ntrjpts loop
	 
	 // ###################################################
         // ### Vectors for angles between TPC and WC Track ###
         // ###################################################
         TVector3 z_hat(0,0,1);
         TVector3 p_hat_0;
      
         // ### Setting the vector for the matched track ###
         // ###      most upstream trajectory point      ###
         p_hat_0.SetX(TempTrj_X);
         p_hat_0.SetY(TempTrj_Y);
         p_hat_0.SetZ(TempTrj_Z); //<--Note: since at this point we only have one unique match
      			          //         only having one entry should be fine
	 			  
	 // ===============================================================================================================
         // 				Calculating Theta and Phi for this TPC Track
         // ===============================================================================================================
         // ### Calculating the Theta for the TPC Track ###
         float tpcTheta = acos(z_hat.Dot(p_hat_0)/p_hat_0.Mag());  
         hdataTPCTheta->Fill(tpcTheta* (180.0/3.141592654));
   
         // ### Using same convention as WCTrack to calculate phi ###
         float phi = 0;
         //Calculating phi (degeneracy elimination for the atan function)
         //----------------------------------------------------------------------------------------------
         if( p_hat_0.Y() > 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X()); }
         else if( p_hat_0.Y() > 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
         else if( p_hat_0.Y() < 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
         else if( p_hat_0.Y() < 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+6.28318; }
         else if( p_hat_0.Y() == 0 && p_hat_0.X() == 0 ){ phi = 0; }//defined by convention
         else if( p_hat_0.Y() == 0 )
            {
            if( p_hat_0.X() > 0 ){ phi = 0; }

            else{ phi = 3.141592654; }

            }
         else if( p_hat_0.X() == 0 )
            {
            if( p_hat_0.Y() > 0 ){ phi = 3.141592654/2; }
            else{ phi = 3.141592654*3/2; }

            }
         //----------------------------------------------------------------------------------------------
   
         // ### Using TPC Phi ###
         float tpcPhi = phi; 
         hdataTPCPhi->Fill(tpcPhi* (180.0/3.141592654));
      
         // ===============================================================================================================            
         // ===============================================================================================================
	 
	 // #######################################################
	 // ### Defining unit vectors for the WC and TPC tracks ###
	 // #######################################################
	 TVector3 theUnitVector_WCTrack;
         TVector3 theUnitVector_TPCTrack;
	 
	 // === WCTrack Unit Vector ===
         theUnitVector_WCTrack.SetX(sin(wctrk_theta[mwctrk])*cos(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetY(sin(wctrk_theta[mwctrk])*sin(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetZ(cos(wctrk_theta[mwctrk]));
    
         // === TPC Track Unit Vector ===
         theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
         theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
         theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
	 // ##########################################################################
	 // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
	 // ##########################################################################
	 DeltaX_WC_TPC_Track = FirstSpacePointX - (wctrk_XFaceCoor[mwctrk]* 0.1);//<---Note: *0.1 to convert to cm
	 DeltaY_WC_TPC_Track = FirstSpacePointY - (wctrk_YFaceCoor[mwctrk]* 0.1);
	 
	 
	 hdataTrkInitialX->Fill(FirstSpacePointX);
      
         hdataTrkInitialY->Fill(FirstSpacePointY);
	 
	 
	 // ###########################################################
         // ### Calculating the angle between WCTrack and TPC Track ###
         // ###########################################################
         float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
	 // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
	 hdataDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
	 hdataDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
	 hdataAlpha->Fill(alpha);
	 
	 // ###########################################################################
	 // ### If this TPC track matches this Wire Chamber Track, bump the counter ###
	 // ###########################################################################
	 if( DeltaX_WC_TPC_Track >  DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound && 
	     DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound &&
	     alpha < alphaCut )
	    {
	    // ### Counting the matched tracks ###
	    nMatchedTracks++;
	    
	    // ### Setting the index of this track to true ###
	    MatchTPC_WVTrack[nTPCtrk] = true;
	    
	    // ### Setting the WCTrack Index = 1 if this WCTrack was matched ###
	    MatchWCTrackIndex[mwctrk] = 1;
	    }  
	 
	 }//<---end nTPCtrk loop
      
      
      }//<---End loop over wire chamber tracks
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hdataNMatchTPCWCTrk->Fill(nMatchedTracks);
   
   // #####################################################
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   // #####################################################
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;



   // =========================================================================================================================================
   //						Recording information about the Wire Chamber Track
   // =========================================================================================================================================
   
   // ---   First grab the tracks "initial" momentum which we take from ---
   // --- the momentum of the wire chamber track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   float momentum = 999;
   
   // ###################################################
   // ### Grabbing the Wire Chamber Track Information ###
   // ###################################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      // ### Skip this WCTrack if it isn't the matched one ###
      if(MatchWCTrackIndex[mwctrk] < 1 || MatchWCTrackIndex[mwctrk] > 1){continue;}
      
      
      hdataMatchedWCTRKMomentum->Fill(wctrk_momentum[mwctrk]);//Momentum of the matched track
      momentum =wctrk_momentum[mwctrk];
      
      }//<---End mwctrk
   
   
   // ###   Calculating the initial Kinetic Energy    ###
   // ### KE = Energy - mass = (p^2 + m^2)^1/2 - mass ###
   float kineticEnergy = pow( (momentum*momentum) + (mass*mass) ,0.5) - mass;
   
   // ### The kinetic energy is that which we calculated ###
   // ###       minus the calculated energy loss         ###
   kineticEnergy -= entryTPCEnergyLoss;
  
   double InitialKinEnAtTPC = 0.;
   InitialKinEnAtTPC = kineticEnergy;
   
   // ###############################################
   // ### Filling the initial kinetic energy plot ###
   // ###############################################
   hdataInitialKEMomentum->Fill(kineticEnergy, 1);
   hdataInitialKEMomentumUnWeighted->Fill(kineticEnergy);


   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double Protondedx[1000]={0.};
   double Protondqdx[1000]={0.};
   double Protonresrange[1000]={0.};
   double Protonpitchhit[1000]={0.};
   int nProtonSpts = 0;
   
   float ProtonSptsX[1000];
   float ProtonSptsY[1000];
   float ProtonSptsZ[1000];
   
   // ################################################
   // ### Creating a flag for through going tracks ###
   // ################################################
   bool ThroughGoingTrack[1000]={false};
   
   
   // ###########################################
   // ### Creating a flag for stopping tracks ###
   // ###########################################
   bool StoppingParticle[1000] = {false};
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Recording the track length ###
      hRecoLength->Fill(trklength[nTPCtrk]);
      
      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 89.0)
         {ThroughGoingTrack[nTPCtrk] = true;}




      // =================================================================
      // === ADD A CHECK TO SEE IF THERE IS ANOTHER TRACK NEAR THE END ===
      // === OF THIS TRACK....IF THERE IS, THEN DON'T USE THIS TRACK   ===
      // =================================================================
      
      bool TrackToNearBy = false;
      for(int aa = ntracks_reco; aa > nTPCtrk; aa --)
         {
	 
	 
	 hNearbyProtonTrackDeltaX->Fill(abs(trkvtxx[aa] - trkendx[nTPCtrk]));
	 hNearbyProtonTrackDeltaY->Fill(abs(trkvtxy[aa] - trkendy[nTPCtrk]));
	 hNearbyProtonTrackDeltaZ->Fill(abs(trkvtxz[aa] - trkendz[nTPCtrk]));
	 
	 
	 if((abs(trkvtxx[aa] - trkendx[nTPCtrk]) < 3) &&
	    (abs(trkvtxy[aa] - trkendy[nTPCtrk]) < 3) &&
	    (abs(trkvtxz[aa] - trkendz[nTPCtrk]) < 3))
	    {TrackToNearBy = true;}

	 }//<---end aa loop
      
      for(int bb = 0; bb < nTPCtrk; bb ++)
         {
	 
	 
	 hNearbyProtonTrackDeltaX->Fill(abs(trkvtxx[bb] - trkendx[nTPCtrk]));
	 hNearbyProtonTrackDeltaY->Fill(abs(trkvtxy[bb] - trkendy[nTPCtrk]));
	 hNearbyProtonTrackDeltaZ->Fill(abs(trkvtxz[bb] - trkendz[nTPCtrk]));
	 
	 
	 if((abs(trkvtxx[bb] - trkendx[nTPCtrk]) < 3) &&
	    (abs(trkvtxy[bb] - trkendy[nTPCtrk]) < 3) &&
	    (abs(trkvtxz[bb] - trkendz[nTPCtrk]) < 3))
	    {TrackToNearBy = true;}

	 }//<---end aa loop
      
      if(TrackToNearBy){/*std::cout<<"Track too close to the 'proton'"<<std::endl;*/continue;}
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         Protondedx[nProtonSpts]     = trkdedx[nTPCtrk][1][nspts];
	 Protondqdx[nProtonSpts]     = trkdqdx[nTPCtrk][1][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(Protondedx[nProtonSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {Protondedx[nProtonSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(Protondedx[nProtonSpts] < 0)
	    {continue;}
	    
	 Protonresrange[nProtonSpts] = trkrr[nTPCtrk][1][nspts];
         Protonpitchhit[nProtonSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 ProtonSptsX[nProtonSpts] = trkx[nTPCtrk][nspts];
	 ProtonSptsY[nProtonSpts] = trky[nTPCtrk][nspts];
	 ProtonSptsZ[nProtonSpts] = trkz[nTPCtrk][nspts];
	 
	 // ### Histogramming the dE/dX ###
	 hdataProtondEdX->Fill(Protondedx[nProtonSpts]);
	 // ### Histogramming the residual range ###
	 hdataProtonRR->Fill(Protonresrange[nProtonSpts]);
	 // ### Histogramming the Pitch ###
	 hdataProtonTrkPitch->Fill(Protonpitchhit[nProtonSpts]);
	 
	 // ### Histogramming the dQdX ###
	 hdataProtondQdX->Fill(Protondqdx[nProtonSpts] );
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hdataProtondEdXvsRR->Fill(Protonresrange[nProtonSpts], Protondedx[nProtonSpts]);
	 
	 nProtonSpts++;

	 
	 }//<---End spacepoints loop
      
      // #####################################################
      // ### Check to see if this track is consistent with ###
      // ###          being from a stopping track 	   ###
      // #####################################################
      if(InitialKinEnAtTPC < 300)
         {
	 // ### Filling the  tracks PIDA value ###
	 hdataLowMomentumTrkPIDA->Fill(trkpida[nTPCtrk][1]);
	 
	 // ##########################################
	 // ###  If the PIDA is between 9 and 13   ###
	 // ##########################################
	 if(trkpida[nTPCtrk][1] >= 8 && trkpida[nTPCtrk][1] <= 13)
	    {
	    
	    //### Setting the last energy points variable ###
	    double lastDeltaE = 0;
	    
	    // ### Loop over the last five points of the track ###
	    if(nProtonSpts >= 5)
	       {
	       for(int nlastspts = nProtonSpts - 1; nlastspts > nProtonSpts - 5; nlastspts--)
	          {
		  // ### Add up the energy in the last 5 points ###
		  lastDeltaE += (Protonpitchhit[nlastspts] * Protondedx[nlastspts]);

	          }//<---End nlastspts loop

	       }//<---End only looking if the track has 5 points
	    
	    // ### IF the Delta E is between 7 and 25, tag as a stopping track ###
	    if(lastDeltaE >= 10 && lastDeltaE <= 30)
	       {
	       // ### Only setting the flag if we are tagging events ###
	       if(RemoveStopping)
	          {StoppingParticle[nTPCtrk] = true;}
	       
	       }
	    
	    
	    }//<---End looking at 9 < PIDA < 13
	 }//<---End looking at low momentum tracks
      
      
      }//<---End nTPCtrk loop 
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered = false;
   int ReorderedCount = 0;
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nProtonSpts-1; caloPoints++)
         {
	 // ###           If this points Residual Range is smaller than the       ###
	 // ### next point, then things may be out of wack and we want to reorder ###
	 if(Protonresrange[caloPoints] < Protonresrange[caloPoints+1])
	    {
	    // #######################################################
	    // ### Set a flag that this might have to be reordered ###
	    // #######################################################
	    HasToBeReordered = true;
	    
	    // ### counting the points that are out of order ###
	    ReorderedCount++;
	    }

         }//<---End caloPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   if(HasToBeReordered && ( (nProtonSpts - ReorderedCount) == 1))
      {
      
      // ### Temp Variables for fixing ###
      double tempRR[1000] = {0.};
      double tempdEdX[1000] = {0.};
      double tempdQdX[1000] = {0.};
      double tempPitch[1000] = {0.};
      
      double tempx[1000] = {0.};
      double tempy[1000] = {0.};
      double tempz[1000] = {0.};
      
      // ### Start at the last point ###
      for(int aa = nProtonSpts; aa > -1; aa--)
         {
	 // ##########################################
	 // ### Skip the point if it is at the end ###
	 // ##########################################
	 if(Protonresrange[aa] == 0){continue;}
	 
	 // ### Reorder the points ###
	 tempRR[bb] = Protonresrange[aa];
	 tempdEdX[bb]     = Protondedx[aa];
	 tempdQdX[bb]     = Protondqdx[aa];
	 tempPitch[bb] = Protonpitchhit[aa];
	 
	 tempx[bb] = ProtonSptsX[aa];
	 tempy[bb] = ProtonSptsY[aa];
	 tempz[bb] = ProtonSptsZ[aa];
	 
	 bb++;
	 }//<---end aa 
      
      // ###########################
      // ### Now swap the points ###
      // ###########################
      for(int reorder = 0; reorder < nProtonSpts; reorder++)
         {
	 Protonresrange[reorder] = tempRR[reorder];
	 Protondedx[reorder]     = tempdEdX[reorder];
	 Protondqdx[reorder]     = tempdQdX[reorder];
	 Protonpitchhit[reorder] = tempPitch[reorder];
	 
	 ProtonSptsX[reorder] = tempx[reorder];
	 ProtonSptsY[reorder] = tempy[reorder];
	 ProtonSptsZ[reorder] = tempz[reorder];
	 
	 }//<---End reorder loop
      
      
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered && VERBOSE)
      {
      for(int caloPoints = 0; caloPoints < nProtonSpts; caloPoints++)
         {
	 std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<Protonresrange[caloPoints]<<", dE/dX = "<<Protondedx[caloPoints]<<std::endl;
      
      
         }//<---End caloPoints
      std::cout<<std::endl;	 
      }//<---Putting in a print to make sure things are reordered correctly   
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   
   
   
   // ####################################################################
   // ### Fix the calorimetry issues associated with huge fluctuations ###
   // ###            by extrapolating through the points               ###
   // ####################################################################
   if(FixCaloIssue_ExtremeFluctuation)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nProtonSpts; caloPoints++)
         {
	 
	 // ###################################################
	 // ### If the dE/dX is large and at the end of the ###
	 // ###  track as expected with a proton attached   ###
	 // ###################################################
	 if(Protondedx[caloPoints] > 40. && caloPoints == (nProtonSpts-1) )
	    {
	    // ##########################################################
	    // ### Set this point equal to the previous point's dE/dX ###
	    // ##########################################################
	    
	    hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	    hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
	    
	    Protondedx[caloPoints] = Protondedx[caloPoints - 1];
	    
	    
	    }//<---End large and at the end of the track
	 
	 // ############################################################
	 // ### Else, if it is a large dE/dX but not the first point ###
	 // ############################################################
	 else if(Protondedx[caloPoints] > 40. && caloPoints < (nProtonSpts-1) && caloPoints > 0.)
	    {
	    
	    // #################################################################
	    // ### Then just average between the previous and the next point ###
	    // #################################################################
	    
	    hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	    hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
	    
	    Protondedx[caloPoints] = ( (Protondedx[caloPoints - 1] + Protondedx[caloPoints + 1]) / 2.);
	    
	    }//<--End large and not at the end of the track
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for big fluctuations

// ---------------------------------------------------------------------------------------------------------------------------------------
   
   // ##############################################################################
   // ### Fix the calorimetry issues associated with slightly large fluctuations ###
   // ###                 by extrapolating through the points                    ###
   // ##############################################################################
   if(FixCaloIssue_LessExtremeFluctuation)
      {
      for(int caloPoints = 0; caloPoints < nProtonSpts; caloPoints++)
         {
	 // ### If dE/dX > 15 and more than 10cm from the end of the track and isn't the first or last point ###
	 if(Protondedx[caloPoints] > 15. && Protonresrange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nProtonSpts-1) )
	    {
	    
	    // ### Check to see if the previous point is greater than 15 ###
	    if(Protondedx[caloPoints-1] > 15.)
	       {
	       // ### Check to see if the next point is greater than 15 ###
	       if(Protondedx[caloPoints+1] > 15. )
	          {
		  // ### Go 2 points before and after ###
		  hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	          hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
		  
		  Protondedx[caloPoints] = ( (Protondedx[caloPoints - 2] + Protondedx[caloPoints + 2]) / 2.);
		  }
	       else
	          {
		  // ### Go 2 points before and one point after ###
		  
		  hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	          hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
		  
		  Protondedx[caloPoints] = ( (Protondedx[caloPoints - 2] + Protondedx[caloPoints + 1]) / 2.);
		  }
	        }
	    else if(Protondedx[caloPoints-1] <= 15.)
	       {
	       if(Protondedx[caloPoints+1] > 15. )
	          {
		  
		  hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	          hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
		  
		  Protondedx[caloPoints] = ( (Protondedx[caloPoints - 1] + Protondedx[caloPoints+2]) / 2.);
		  }
	       else
	          {
		  
		  hdataFixedCaloPointZX->Fill(ProtonSptsZ[caloPoints], ProtonSptsX[caloPoints], Protondedx[caloPoints]);
	          hdataFixedCaloPointZY->Fill(ProtonSptsZ[caloPoints], ProtonSptsY[caloPoints], Protondedx[caloPoints]);
		  
		  Protondedx[caloPoints] = ( (Protondedx[caloPoints - 2] + Protondedx[caloPoints + 1]) / 2.);
		  }
	       }
	   else Protondedx[caloPoints] = ( (Protondedx[caloPoints - 1] + Protondedx[caloPoints+1]) / 2.);
	   }
	
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for less big fluctuations   
   
   
   
   // ##########################################
   // ### Filling the fixed dE/dX vs RR plot ###
   // ##########################################
   for(int caloPoints = 0; caloPoints < nProtonSpts; caloPoints++)
      {
      
      hdataProtondEdXvsRRFix->Fill(Protonresrange[caloPoints], Protondedx[caloPoints]);
      hdataProtondQdXFixed->Fill(Protondqdx[caloPoints]);
      hdataProtondEdXFixed->Fill(Protondedx[caloPoints]);
      
      }//<---End Fix
   
 


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #################################################################
// ### Deciding whether or not this looks like a stopping proton ###
// #################################################################

int nStopProtons = 0;
int protonTrkNumber = -1;

   // #########################################
   // ### Loop over the tracks in the event ###
   // #########################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      
      // ### Skipping events which are non-stopping ###
      if(ThroughGoingTrack[nTPCtrk]){continue;}
      
      // ### Setting a boolian for low ionizing tracks and ###
      // ###   tracks which get too close to the boundary  ###
      
      bool LowIonizingTrack = false;
      bool CloseToTheEdge = false;
      // ############################################
      // ### Loop over all the calorimetry points ###
      // ############################################
      for(int npoints = 0; npoints < nProtonSpts; npoints++)
         {
	 if(Protondedx[npoints] < 4.0 && Protonresrange[npoints]< 16)
	    {LowIonizingTrack = true;}
   
	 
	 if(ProtonSptsX[npoints] > 38 || ProtonSptsX[npoints] < 5 || ProtonSptsY[npoints] > 15 || 
	    ProtonSptsY[npoints] < -15|| ProtonSptsZ[npoints] > 85)
	    {CloseToTheEdge = true;}
	 
	 }//<---End npoints loop
      
      // ### Skip this track if it is minimum ionizing or too close to the edge
      if(LowIonizingTrack || CloseToTheEdge)
         {continue;}
      
      
      protonTrkNumber = nTPCtrk;
      nStopProtons++;
      }//<---End nTPCtrk loop


   // ##################################################
   // ### Skip events which are not stopping protons ###
   // ##################################################
   if(nStopProtons != 1){continue;}

   nEventsStopProton++;


   // ==================================================================================================================
   // ===============				ANALYZING STOPPED PROTONS 				================
   // ==================================================================================================================


   
   // ############################################
   // ### Loop over all the calorimetry points ###
   // ############################################
   for(int npoints = 0; npoints < nProtonSpts; npoints++)
      {
      hStoppedProtondEdXvsRR->Fill(Protonresrange[npoints], Protondedx[npoints]);
      
      hStoppedProtondEdX->Fill(Protondedx[npoints]);
      hStoppedProtonRR->Fill(Protonresrange[npoints]);
      hStoppedProtonTrkPitch->Fill(Protonpitchhit[npoints]);
      
      
      // ################################################
      // ### Subtracting the energy loss in this step ###
      // ################################################
      float energyLossInStep = Protondedx[npoints] * Protonpitchhit[npoints];
      
      // #######################################################
      // ### Removing that kinetic energy from the histogram ###
      // #######################################################
      kineticEnergy -= energyLossInStep;
      
      
      }//<---End npoints loop
   

   hStoppedProtonRemainingKE->Fill(kineticEnergy);   
   //std::cout<<std::endl;
   //std::cout<<"Run = "<<run<<", SubRun = "<<subrun<<", Event = "<<event<<std::endl;
   //std::cout<<std::endl;




   
   }//<---End jentry loop

// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 0   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ WC Track                                 = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ TOF Object                               = "<<nTOFHits<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with Proton               = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"### Number of Events w/ ONE WC Track Matched                     = "<<nEvtsWCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )              ###"<<std::endl;
std::cout<<"###                 and alpha less the "<<alphaCut<<" degrees                      ###"<<std::endl;
std::cout<<"-------------------------------------------------------------------------"<<std::endl;
std::cout<<"### Number of Events where the proton track is stopping in the TPC = "<<nEventsStopProton<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<std::endl; 
std::cout<<std::endl; 

// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================
hdataRawWCTRKMomentum->Write();  
hdataWCTrackExist->Write(); 
hdataTOFNoCuts->Write();
hdataWCTrackMomentumVSTOF->Write();
hdataWCTrackMomentumVSTOFCuts->Write();
hdataUpstreamZPos->Write();
hdataTPCTheta->Write();
hdataTPCPhi->Write();
hdataWCTheta->Write();
hdataWCPhi->Write();
hdataDeltaWCTrkX->Write();
hdataDeltaWCTrkY->Write();
hdataAlpha->Write();
hdataNMatchTPCWCTrk->Write();
hdataTrkInitialX->Write();
hdataTrkInitialY->Write();
hdataMatchedWCTRKMomentum->Write();
hdataInitialKEMomentum->Write();
hdataInitialKEMomentumUnWeighted->Write();
hdataProtondEdX->Write();
hdataProtonRR->Write();
hdataProtonTrkPitch->Write();
hdataProtondEdXvsRR->Write();
hdataLowMomentumTrkPIDA->Write();
hdataProtondEdXvsRRFix->Write();
hdataProtondEdXFixed->Write();
hdataFixedCaloPointZX->Write();
hdataFixedCaloPointZY->Write();
hStoppedProtondEdXvsRR->Write();
hStoppedProtondEdX->Write();
hStoppedProtonRR->Write();
hStoppedProtonTrkPitch->Write();
hStoppedProtonRemainingKE->Write();
hNearbyProtonTrackDeltaX->Write();
hNearbyProtonTrackDeltaY->Write();
hNearbyProtonTrackDeltaZ->Write();
hRecoLength->Write();
hdataProtondQdXFixed->Write();
hdataProtondQdX->Write();
   
}
