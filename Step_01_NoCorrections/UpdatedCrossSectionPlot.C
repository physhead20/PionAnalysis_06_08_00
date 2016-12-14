{

#include <math.h>
// ############################
// #######   Constants  #######
// ############################
float rho = 1400; //Argon density in kg/m^3
float molar_mass = 39.9; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.02e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m (from mean of track pitch)

// ############################
// ###   Load Data Plots    ###
// ############################
TFile *f1 = new TFile("./histo_ROOTFILES/DataNew_NewTOF_NewMatch_PionXSection_histos_noCorrections.root");

// ####################################
// ### Grab the relevant histograms ###
// ####################################

// --- Incident Kinetic Energy Histo ---
TH1F* hDataInc = (TH1F*)f1->Get("hdataIncidentKE");
// --- Interacting Kinetic Energy Histo ---
TH1F* hDataInt = (TH1F*)f1->Get("hdataInteractingKE");
// --- Cross-Section Plot from file ---
TH1F* DataCrossSection = (TH1F*)f1->Get("fCrossSection");

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ==========================================================================================================
// 			SCALING THE INCIDENT HISTOGRAM FOR THE MUON CONTAMINATION
// ==========================================================================================================
hDataInc->Scale(MuonContaminationScaleFactor);


const Int_t nBins = 19;
Double_t edges[nBins+1] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1200, 1600};

TH1* hVariableBinCrossSection = new TH1D("hVariableBinCrossSection", "Cross-Section", nBins, edges);


float data_numerator;
float data_denomenator;
float datasigbinom;

float VariableCrossSection[40] = {0.};
float VariableCrossSectionError[40] = {0.};

int counter = 0;

// ################################################################
// ### Loop over the data histograms to get all the information ###
// ################################################################
for(int i = 1; i <= hDataInc->GetNbinsX(); i++)
   {
   
   // ####################################################
   // ### Getting the numerator and denomenator values ###
   // ####################################################
   data_numerator   = hDataInt->GetBinContent(i);
   data_denomenator = hDataInc->GetBinContent(i);
   
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = ((data_numerator/data_denomenator)/(number_density)/(slab_width)) * (1e28);
   
   // ### Calculating the binomial error on this bin ###
   datasigbinom = sqrt(data_numerator/(data_denomenator*data_denomenator)*(1-data_numerator/data_denomenator));
   datasigbinom = datasigbinom/number_density/slab_width*1e28; //data binomial stat error in barns
   
   // ### Putting in protection for dividing by zero ###
   if(data_denomenator == 0){TempCrossSection = 0; datasigbinom = 0;}
   
   VariableCrossSection[counter]      = TempCrossSection;
   VariableCrossSectionError[counter] = datasigbinom;
   counter++;
   
   std::cout<<"i = "<<(i-1)*50<<" cross-section = "<<TempCrossSection<<" +/-"<<datasigbinom<<std::endl;
   
   }//End getting data from bins


// ########################################################
// ### Putting the variable binning into the histograms ###
// ########################################################
hVariableBinCrossSection->SetBinContent(1,VariableCrossSection[0]);
hVariableBinCrossSection->SetBinError(1,VariableCrossSectionError[0]);

hVariableBinCrossSection->SetBinContent(2,VariableCrossSection[1]);
hVariableBinCrossSection->SetBinError(2,VariableCrossSectionError[1]);

hVariableBinCrossSection->SetBinContent(3,VariableCrossSection[2]);
hVariableBinCrossSection->SetBinError(3,VariableCrossSectionError[2]);

hVariableBinCrossSection->SetBinContent(4,VariableCrossSection[3]);
hVariableBinCrossSection->SetBinError(4,VariableCrossSectionError[3]);

hVariableBinCrossSection->SetBinContent(5,VariableCrossSection[4]);
hVariableBinCrossSection->SetBinError(5,VariableCrossSectionError[4]);

hVariableBinCrossSection->SetBinContent(6,VariableCrossSection[5]);
hVariableBinCrossSection->SetBinError(6,VariableCrossSectionError[5]);

hVariableBinCrossSection->SetBinContent(7,VariableCrossSection[6]);
hVariableBinCrossSection->SetBinError(7,VariableCrossSectionError[6]);

hVariableBinCrossSection->SetBinContent(8,VariableCrossSection[7]);
hVariableBinCrossSection->SetBinError(8,VariableCrossSectionError[7]);

hVariableBinCrossSection->SetBinContent(9,VariableCrossSection[8]);
hVariableBinCrossSection->SetBinError(9,VariableCrossSectionError[8]);

hVariableBinCrossSection->SetBinContent(10,VariableCrossSection[9]);
hVariableBinCrossSection->SetBinError(10,VariableCrossSectionError[9]);

hVariableBinCrossSection->SetBinContent(11,VariableCrossSection[10]);
hVariableBinCrossSection->SetBinError(11,VariableCrossSectionError[10]);

hVariableBinCrossSection->SetBinContent(12,VariableCrossSection[11]);
hVariableBinCrossSection->SetBinError(12,VariableCrossSectionError[11]);

hVariableBinCrossSection->SetBinContent(13,VariableCrossSection[12]);
hVariableBinCrossSection->SetBinError(13,VariableCrossSectionError[12]);

hVariableBinCrossSection->SetBinContent(14,VariableCrossSection[13]);
hVariableBinCrossSection->SetBinError(14,VariableCrossSectionError[13]);

hVariableBinCrossSection->SetBinContent(15,VariableCrossSection[14]);
hVariableBinCrossSection->SetBinError(15,VariableCrossSectionError[14]);

hVariableBinCrossSection->SetBinContent(16,VariableCrossSection[15]);
hVariableBinCrossSection->SetBinError(16,VariableCrossSectionError[15]);


float bin17 = (VariableCrossSection[16] + VariableCrossSection[17]) / 2;
hVariableBinCrossSection->SetBinContent(17,bin17);
float bin17error = sqrt( (VariableCrossSectionError[16]*VariableCrossSectionError[16]) + (VariableCrossSectionError[17]*VariableCrossSectionError[17]) );
hVariableBinCrossSection->SetBinError(17,bin17error);

float bin18 = (VariableCrossSection[18] + VariableCrossSection[19] + VariableCrossSection[20] + VariableCrossSection[21] + VariableCrossSection[22] + VariableCrossSection[23]) / 6;
hVariableBinCrossSection->SetBinContent(18,bin18);
float bin18error = (sqrt( pow(VariableCrossSectionError[18],2) + pow(VariableCrossSectionError[19],2) + pow(VariableCrossSectionError[20],2)+
                         pow(VariableCrossSectionError[21],2) + pow(VariableCrossSectionError[22],2) + pow(VariableCrossSectionError[23],2) ) )/ 6;
hVariableBinCrossSection->SetBinError(18,bin18error);

float bin19 = (VariableCrossSection[24] + VariableCrossSection[25] + VariableCrossSection[26] + VariableCrossSection[27] + VariableCrossSection[28] + VariableCrossSection[29] + 
               VariableCrossSection[30] + VariableCrossSection[31]) / 8;
hVariableBinCrossSection->SetBinContent(19,bin19);
float bin19error = (sqrt( pow(VariableCrossSectionError[24],2) + pow(VariableCrossSectionError[25],2) + pow(VariableCrossSectionError[26],2)+
                          pow(VariableCrossSectionError[27],2) + pow(VariableCrossSectionError[28],2) + pow(VariableCrossSectionError[29],2) + 
                          pow(VariableCrossSectionError[30],2) + pow(VariableCrossSectionError[31],2)) )/ 8;
hVariableBinCrossSection->SetBinError(19,bin19error);



// ############################
// ### Load MC Plots        ###
// ############################
//TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_PionXSection_histos_noCorrections_noScalings.root");
TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_NewMatch_noCorrections_wScalings.root");
 
 TH1F* hMCInc = (TH1F*)f2->Get("hdataIncidentKEunweighted");
 TH1F* hMCInt = (TH1F*)f2->Get("hdataInteractingKEunweighted");
 TH1F* MCCrossSection = (TH1F*)f2->Get("fCrossSection");
 TH1F* MCCrossSys = (TH1F*)fCrossSection->Clone();
 MCCrossSys->SetName("MCCrossSys");

 
 int nbinsMC = fCrossSection->GetNbinsX();
 float MCsigbinom;
 float MCsysstat;
 float MCn;
 float MCN;
 float MCp;
 
 //Systematic errors taken from Jonathan's slide
 float dEdxuncert = 0.05;
 float dEdxuncertsq = dEdxuncert*dEdxuncert;
 float mucontam = 0.03;
 float mucontamsq = mucontam*mucontam;
 float WCmomuncert = 0.03;
 float WCmomuncertsq = WCmomuncert*WCmomuncert;
 float Eflatuncert = 0.035;
 float Eflatuncertsq = Eflatuncert*Eflatuncert;

 //MC statistical error should be flat (before momentum reweighting)
 //Take peak value of hMCInc histo as proxy for real MC stats
 //In truth, should use the unweighted MC histo to get stat err instead
 double MCstat = hMCInt->GetBinContent(8);
 std::cout << MCstat << std::endl;
 MCstat = (sqrt(MCstat))/MCstat;
 std::cout << MCstat << std::endl;

 std::cout << "MC cross section" << std::endl;

 for (int i = 1; i <= nbinsMC; i++ ) {
   MCn = hMCInt->GetBinContent(i); 
   MCN = hMCInc->GetBinContent(i);
   MCsigbinom = sqrt((MCn/(MCN*MCN))*(1-(MCn/MCN)));

   if( MCN == 0 )continue; //Temporary fix to ensure no divide by zero 
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = (MCn/MCN)/(number_density)/(slab_width);
   
   crossSection = TempCrossSection * (1e28); //To put this into barns
   MCCrossSection->SetBinContent(i,crossSection);

   MCsigbinom = sqrt(MCn/(MCN*MCN)*(1-MCn/MCN));
   MCsigbinom = MCsigbinom/number_density/slab_width*1e28; //MC binomial stat error in barns
//
//   MCCrossSection->SetBinError(i,MCsigbinom);
   MCCrossSection->SetBinError(i, MCstat*crossSection); // use flat stat uncertainty


   MCsysstat = dEdxuncertsq + mucontamsq + WCmomuncertsq + Eflatuncertsq; //sum of squares of syserrs
   //   MCsysstat = MCsysstat + MCsigbinom*MCsigbinom; // Add in MC stat err squared
   MCsysstat = MCsysstat*crossSection;
   MCsysstat = MCsysstat + MCstat*MCstat;
   MCsysstat = sqrt(MCsysstat); // sqrt of sum of squares = total err

   std::cout << crossSection << " +/- " << MCstat*crossSection << "(stat) +/- " << MCsysstat << std::endl;


   MCCrossSys->SetBinContent(i,crossSection);
   MCCrossSys->SetBinError(i,MCsysstat);   
 }// end loop over MC bins


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Track Length");
c01->SetTicks();
c01->SetFillColor(kWhite);
c01->cd();
gStyle->SetOptStat(0);

 MCCrossSys->SetFillColor(kAzure-5);
 MCCrossSys->SetLineColor(kAzure-5);
 MCCrossSys->SetMarkerStyle(1);
 MCCrossSys->SetMarkerColor(kAzure-5);
 MCCrossSys->SetTitle("");
 MCCrossSys->GetXaxis()->SetTitle("Reconstructed Kinetic Energy (MeV)");
 MCCrossSys->GetXaxis()->SetTitleFont(42);
 MCCrossSys->GetXaxis()->SetTitleSize(0.04);
 MCCrossSys->GetXaxis()->CenterTitle();
 MCCrossSys->GetYaxis()->SetTitle("Total #pi^{#minus} cross section, #sigma_{TOT} (barns)");
 MCCrossSys->GetYaxis()->CenterTitle();
 MCCrossSys->GetYaxis()->SetTitleFont(42);
 MCCrossSys->GetYaxis()->SetTitleSize(0.04);

 MCCrossSection->SetTitle("");
 MCCrossSection->SetFillColor(kAzure-9);
 MCCrossSection->SetLineColor(kAzure-9);
 MCCrossSection->SetMarkerStyle(1);
 MCCrossSection->SetMarkerColor(kAzure-9);
 MCCrossSection->GetXaxis()->SetTitle("");
 MCCrossSection->GetYaxis()->SetTitle("");

 hVariableBinCrossSection->SetMarkerStyle(8);
 hVariableBinCrossSection->SetMarkerSize(0.85);
 hVariableBinCrossSection->SetMarkerColor(kBlack);
 hVariableBinCrossSection->SetLineColor(kBlack);
 hVariableBinCrossSection->SetLineWidth(2);
 hVariableBinCrossSection->SetTitle("");
 hVariableBinCrossSection->GetXaxis()->SetTitle("");
 hVariableBinCrossSection->GetYaxis()->SetTitle("");

 MCCrossSys->SetAxisRange(0,1600.);
 MCCrossSys->SetMaximum(3.5);
 MCCrossSys->SetMinimum(0);
 MCCrossSys->Draw("e2");
 MCCrossSection->Draw("e2same");
 hVariableBinCrossSection->Draw("e1same");
 
// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,"");

TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hVariableBinCrossSection,"Data, stat");
leg->AddEntry(MCCrossSys,"MC syst + stat"); 
leg->AddEntry(MCCrossSection,"MC central value");
leg->Draw();

//hVariableBinCrossSection->Draw();
}//<---End File
