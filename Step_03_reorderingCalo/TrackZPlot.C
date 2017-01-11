{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>


// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("./histo_ROOTFILES/DataNew_PionXSection_histos_reorderingOnly.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_NewMatch_wScalings_dEdXScale_Reordering.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
TFile *f3 = new TFile("./histo_ROOTFILES/MuonMC_NewMatch_wScalings_dEdXScale_Reordering.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
TFile *f4 = new TFile("./histo_ROOTFILES/ElectronMC_NewMatch_wScalings_dEdXScale_Reordering.root");

// ###################################
// ### Load Kaon Monte Carlo Plots ###
// ###################################
TFile *f5 = new TFile("./histo_ROOTFILES/KaonMC_NewMatch_wScalings_dEdXScale_Reordering.root");

// #####################################
// ### Load Photon Monte Carlo Plots ###
// #####################################
TFile *f6 = new TFile("./histo_ROOTFILES/PhotonMC_NewMatch_wScalings_dEdXScale_Reordering.root");

//--------------------------------------------------------------------------------------------------------------
//					Track Length
//--------------------------------------------------------------------------------------------------------------

// ##########################################
// ### Getting the data Track Length plot ###
// ##########################################
TH1F *hDataTrkLength = (TH1F*)f1->Get("hRecoLength");

// ### Labeling the axis ###
hDataTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hDataTrkLength->GetXaxis()->CenterTitle();

hDataTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataTrkLength->GetYaxis()->CenterTitle(); 

// #############################################
// ### Getting the Pion MC Track Length plot ###
// #############################################
TH1F *hPionMCTrkLength = (TH1F*)f2->Get("hRecoLength");

// ### Labeling the axis ###
hPionMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hPionMCTrkLength->GetXaxis()->CenterTitle();

hPionMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hPionMCTrkLength->GetYaxis()->CenterTitle(); 

// #############################################
// ### Getting the Muon MC Track Length plot ###
// #############################################
TH1F *hMuonMCTrkLength = (TH1F*)f3->Get("hRecoLength");

// ### Labeling the axis ###
hMuonMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hMuonMCTrkLength->GetXaxis()->CenterTitle();

hMuonMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hMuonMCTrkLength->GetYaxis()->CenterTitle(); 


// #################################################
// ### Getting the Electron MC Track Length plot ###
// #################################################
TH1F *hElectronMCTrkLength = (TH1F*)f4->Get("hRecoLength");

// ### Labeling the axis ###
hElectronMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hElectronMCTrkLength->GetXaxis()->CenterTitle();

hElectronMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hElectronMCTrkLength->GetYaxis()->CenterTitle(); 


// #############################################
// ### Getting the Kaon MC Track Length plot ###
// #############################################
TH1F *hKaonMCTrkLength = (TH1F*)f5->Get("hRecoLength");

// ### Labeling the axis ###
hKaonMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hKaonMCTrkLength->GetXaxis()->CenterTitle();

hKaonMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hKaonMCTrkLength->GetYaxis()->CenterTitle();


// ###############################################
// ### Getting the Photon MC Track Length plot ###
// ###############################################
TH1F *hPhotonMCTrkLength = (TH1F*)f6->Get("hRecoLength");

// ### Labeling the axis ###
hPhotonMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hPhotonMCTrkLength->GetXaxis()->CenterTitle();

hPhotonMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hPhotonMCTrkLength->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralTrkLength     = hPionMCTrkLength->Integral() ;//* 0.484;
double MuonMCIntegralTrkLength     = hMuonMCTrkLength->Integral() ;//* 0.022;
double ElectronMCIntegralTrkLength = hElectronMCTrkLength->Integral() ;//* 0.494;
double KaonMCIntegralTrkLength     = hKaonMCTrkLength->Integral();//0.00035
double PhotonMCIntegralTrkLength   = hPhotonMCTrkLength->Integral();//0.00035

// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralTrkLength + MuonMCIntegralTrkLength + ElectronMCIntegralTrkLength + KaonMCIntegralTrkLength + PhotonMCIntegralTrkLength;
double DataIntegralTrkLength = hDataTrkLength->Integral();

double scaleMCTrkLength = DataIntegralTrkLength/MCIntegralTrkLength;



// ### Scaling by particle species ###
double PionPercentage     = 0.3027;
double MuonPercentage     = 9.3495;
double ElectronPercentage = 1.2633;
double PhotonPercentage   = 1.6621;
double KaonPercentage     = 341.448;


// ### Scale each particle species ###

// == Scale Pions ===
hPionMCTrkLength->Sumw2();
hPionMCTrkLength->Scale(scaleMCTrkLength*(1/PionPercentage));

std::cout<<"# of Pion = "<<hPionMCTrkLength->Integral()<<std::endl;

// == Scale Muons ===
hMuonMCTrkLength->Sumw2();
hMuonMCTrkLength->Scale(scaleMCTrkLength*(1/MuonPercentage));
std::cout<<"# of Muon = "<<hMuonMCTrkLength->Integral()<<std::endl;

// == Scale Electron ===
hElectronMCTrkLength->Sumw2();
hElectronMCTrkLength->Scale(scaleMCTrkLength*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCTrkLength->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCTrkLength->Sumw2();
hKaonMCTrkLength->Scale(scaleMCTrkLength*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCTrkLength->Integral()<<std::endl;

// == Scale Kaon ===
hPhotonMCTrkLength->Sumw2();
hPhotonMCTrkLength->Scale(scaleMCTrkLength*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCTrkLength->Integral()<<std::endl;

std::cout<<std::endl;

std::cout<<"# of data events = "<<hDataTrkLength->Integral()<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Length");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionMCTrkLength->SetLineColor(kBlue);
hPionMCTrkLength->SetLineStyle(0);
hPionMCTrkLength->SetLineWidth(3);
hPionMCTrkLength->SetFillColor(kBlue);
hPionMCTrkLength->SetFillStyle(3006);

hElectronMCTrkLength->SetLineColor(kRed);
hElectronMCTrkLength->SetLineStyle(0);
hElectronMCTrkLength->SetLineWidth(3);
hElectronMCTrkLength->SetFillColor(kRed);
hElectronMCTrkLength->SetFillStyle(3006);

hMuonMCTrkLength->SetLineColor(kGreen+3);
hMuonMCTrkLength->SetLineStyle(0);
hMuonMCTrkLength->SetLineWidth(3);
hMuonMCTrkLength->SetFillColor(kGreen+3);
hMuonMCTrkLength->SetFillStyle(3006);

hKaonMCTrkLength->SetLineColor(kPink+3);
hKaonMCTrkLength->SetLineStyle(0);
hKaonMCTrkLength->SetLineWidth(3);
hKaonMCTrkLength->SetFillColor(kPink+3);
hKaonMCTrkLength->SetFillStyle(3006);

hPhotonMCTrkLength->SetLineColor(kAzure-9);
hPhotonMCTrkLength->SetLineStyle(0);
hPhotonMCTrkLength->SetLineWidth(3);
hPhotonMCTrkLength->SetFillColor(kAzure-9);
hPhotonMCTrkLength->SetFillStyle(3007);


hDataTrkLength->SetLineColor(kBlack);
hDataTrkLength->SetLineStyle(0);
hDataTrkLength->SetLineWidth(3);
hDataTrkLength->SetMarkerStyle(8);
hDataTrkLength->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCTrkLength);
hstacked->Add(hPhotonMCTrkLength);
hstacked->Add(hMuonMCTrkLength);
hstacked->Add(hElectronMCTrkLength);
hstacked->Add(hPionMCTrkLength);


// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataTrkLength->Draw("E1same");


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
leg->AddEntry(hDataTrkLength,"Data");
leg->AddEntry(hPionMCTrkLength,"Pion MC"); 
leg->AddEntry(hMuonMCTrkLength,"Muon MC");
leg->AddEntry(hElectronMCTrkLength,"Electron MC");
leg->AddEntry(hPhotonMCTrkLength, "Photon MC");
leg->AddEntry(hKaonMCTrkLength,"Kaon MC");
leg->Draw();








}
