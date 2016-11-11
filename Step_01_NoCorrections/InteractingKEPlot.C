{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>


// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("./histo_ROOTFILES/Data_PionXSection_histos_noCorrections.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_PionXSection_histos_noCorrections_wScalings.root");
//TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_PionXSection_histos_noCorrections_noScalings.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
//TFile *f3 = new TFile("./histo_ROOTFILES/MuonMC_PionXSection_histos_noCorrections_noScalings.root");
TFile *f3 = new TFile("./histo_ROOTFILES/MuonMC_PionXSection_histos_noCorrections_wScalings.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
//TFile *f4 = new TFile("./histo_ROOTFILES/ElectronMC_PionXSection_histos_noCorrections_noScalings.root");
TFile *f4 = new TFile("./histo_ROOTFILES/ElectronMC_PionXSection_histos_noCorrections_wScalings.root");

// ###################################
// ### Load Kaon Monte Carlo Plots ###
// ###################################
TFile *f5 = new TFile("./histo_ROOTFILES/KaonMC_PionXSection_histos_noCorrections_wScalings.root");



//--------------------------------------------------------------------------------------------------------------
//					Incident Kinetic Energy Plot
//--------------------------------------------------------------------------------------------------------------

// #########################################
// ### Getting the data Incident KE plot ###
// #########################################
TH1F *hDataInteractKE = (TH1F*)f1->Get("hdataInteractingKE");

// ### Labeling the axis ###
hDataInteractKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hDataInteractKE->GetXaxis()->CenterTitle();

hDataInteractKE->GetYaxis()->SetTitle("Events / 50 MeV");
hDataInteractKE->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDataInteractKE->Scale(MuonContaminationScaleFactor);

// ############################################
// ### Getting the Pion MC Incident KE plot ###
// ############################################
TH1F *hPionInteractKE = (TH1F*)f2->Get("hdataInteractingKE");

// ### Labeling the axis ###
hPionInteractKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hPionInteractKE->GetXaxis()->CenterTitle();

hPionInteractKE->GetYaxis()->SetTitle("Events / 50 MeV");
hPionInteractKE->GetYaxis()->CenterTitle(); 

// ############################################
// ### Getting the Muon MC Incident KE plot ###
// ############################################
TH1F *hMuonInteractKE = (TH1F*)f3->Get("hdataInteractingKE");

// ### Labeling the axis ###
hMuonInteractKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hMuonInteractKE->GetXaxis()->CenterTitle();

hMuonInteractKE->GetYaxis()->SetTitle("Events / 50 MeV");
hMuonInteractKE->GetYaxis()->CenterTitle(); 


// ################################################
// ### Getting the Electron MC Incident KE plot ###
// ################################################
TH1F *hElectronInteractKE = (TH1F*)f4->Get("hdataInteractingKE");

// ### Labeling the axis ###
hElectronInteractKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hElectronInteractKE->GetXaxis()->CenterTitle();

hElectronInteractKE->GetYaxis()->SetTitle("Events / 50 MeV");
hElectronInteractKE->GetYaxis()->CenterTitle(); 


// ############################################
// ### Getting the Kaon MC Incident KE plot ###
// ############################################
TH1F *hKaonInteractKE = (TH1F*)f5->Get("hdataInteractingKE");

// ### Labeling the axis ###
hKaonInteractKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hKaonInteractKE->GetXaxis()->CenterTitle();

hKaonInteractKE->GetYaxis()->SetTitle("Events / 50 MeV");
hKaonInteractKE->GetYaxis()->CenterTitle(); 

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralIncKE     = hPionInteractKE->Integral() ;//* 0.484;
double MuonMCIntegralIncKE     = hMuonInteractKE->Integral() ;//* 0.022;
double ElectronMCIntegralIncKE = hElectronInteractKE->Integral() ;//* 0.494;
double KaonMCIntegralTrkIncKE  = hKaonInteractKE->Integral();//0.00035


// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralIncKE + MuonMCIntegralIncKE + ElectronMCIntegralIncKE + KaonMCIntegralTrkIncKE;
double DataIntegralTrkLength = hDataInteractKE->Integral();

double scaleMCIncKE = DataIntegralTrkLength/MCIntegralTrkLength;



// ### Scaling by particle species ###
double PionPercentage     = 0.5235;//0.479;
double MuonPercentage     = 0.9593;//28.83;
double ElectronPercentage = 3.7695;//0.0542;
double PhotonPercentage   = 1;//0.085;
double KaonPercentage     = 546.733;//319.23;//0.0035;


// ### Scale each particle species ###

// == Scale Pions ===
hPionInteractKE->Sumw2();
hPionInteractKE->Scale(scaleMCIncKE*(1/PionPercentage));
std::cout<<"# of Pion = "<<hPionInteractKE->Integral()<<std::endl;

// == Scale Muons ===
hMuonInteractKE->Sumw2();
hMuonInteractKE->Scale(scaleMCIncKE*(1/MuonPercentage));
std::cout<<"# of Muon = "<<hMuonInteractKE->Integral()<<std::endl;

// == Scale Electron ===
hElectronInteractKE->Sumw2();
hElectronInteractKE->Scale(scaleMCIncKE*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronInteractKE->Integral()<<std::endl;

// == Scale Kaon ===
hKaonInteractKE->Sumw2();
hKaonInteractKE->Scale(scaleMCIncKE*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonInteractKE->Integral()<<std::endl;
std::cout<<std::endl;

std::cout<<std::endl;

std::cout<<"# of data events = "<<hDataInteractKE->Integral()<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Length");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionInteractKE->SetLineColor(kBlue);
hPionInteractKE->SetLineStyle(0);
hPionInteractKE->SetLineWidth(3);
hPionInteractKE->SetFillColor(kBlue);
hPionInteractKE->SetFillStyle(3006);

hElectronInteractKE->SetLineColor(kRed);
hElectronInteractKE->SetLineStyle(0);
hElectronInteractKE->SetLineWidth(3);
hElectronInteractKE->SetFillColor(kRed);
hElectronInteractKE->SetFillStyle(3006);

hMuonInteractKE->SetLineColor(kGreen+3);
hMuonInteractKE->SetLineStyle(0);
hMuonInteractKE->SetLineWidth(3);
hMuonInteractKE->SetFillColor(kGreen+3);
hMuonInteractKE->SetFillStyle(3006);

hKaonInteractKE->SetLineColor(kPink+3);
hKaonInteractKE->SetLineStyle(0);
hKaonInteractKE->SetLineWidth(3);
hKaonInteractKE->SetFillColor(kPink+3);
hKaonInteractKE->SetFillStyle(3006);

hDataInteractKE->SetLineColor(kBlack);
hDataInteractKE->SetLineStyle(0);
hDataInteractKE->SetLineWidth(3);
hDataInteractKE->SetMarkerStyle(8);
hDataInteractKE->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonInteractKE);
hstacked->Add(hMuonInteractKE);
hstacked->Add(hElectronInteractKE);
hstacked->Add(hPionInteractKE);

// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataInteractKE->Draw("E1same");


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
leg->AddEntry(hDataInteractKE,"Data");
leg->AddEntry(hPionInteractKE,"Pion MC"); 
leg->AddEntry(hMuonInteractKE,"Muon MC");
leg->AddEntry(hElectronInteractKE,"Electron MC");
leg->AddEntry(hKaonInteractKE,"Kaon MC");
leg->Draw();








}
