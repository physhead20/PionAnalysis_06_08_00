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
TH1F *hDataTrkPitch = (TH1F*)f1->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hDataTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hDataTrkPitch->GetXaxis()->CenterTitle();

hDataTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataTrkPitch->GetYaxis()->CenterTitle(); 

// #############################################
// ### Getting the Pion MC Track Length plot ###
// #############################################
TH1F *hPionMCTrkPitch = (TH1F*)f2->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hPionMCTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hPionMCTrkPitch->GetXaxis()->CenterTitle();

hPionMCTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hPionMCTrkPitch->GetYaxis()->CenterTitle(); 

// #############################################
// ### Getting the Muon MC Track Length plot ###
// #############################################
TH1F *hMuonMCTrkPitch = (TH1F*)f3->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hMuonMCTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hMuonMCTrkPitch->GetXaxis()->CenterTitle();

hMuonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hMuonMCTrkPitch->GetYaxis()->CenterTitle(); 


// #################################################
// ### Getting the Electron MC Track Length plot ###
// #################################################
TH1F *hElectronMCTrkPitch = (TH1F*)f4->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hElectronMCTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hElectronMCTrkPitch->GetXaxis()->CenterTitle();

hElectronMCTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hElectronMCTrkPitch->GetYaxis()->CenterTitle(); 


// #############################################
// ### Getting the Kaon MC Track Length plot ###
// #############################################
TH1F *hKaonMCTrkPitch = (TH1F*)f5->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hKaonMCTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hKaonMCTrkPitch->GetXaxis()->CenterTitle();

hKaonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hKaonMCTrkPitch->GetYaxis()->CenterTitle();


// ###############################################
// ### Getting the Photon MC Track Length plot ###
// ###############################################
TH1F *hPhotonMCTrkPitch = (TH1F*)f6->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hPhotonMCTrkPitch->GetXaxis()->SetTitle("Track Length (cm)");
hPhotonMCTrkPitch->GetXaxis()->CenterTitle();

hPhotonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.5 cm");
hPhotonMCTrkPitch->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralTrkLength     = hPionMCTrkPitch->Integral() ;//* 0.484;
double MuonMCIntegralTrkLength     = hMuonMCTrkPitch->Integral() ;//* 0.022;
double ElectronMCIntegralTrkLength = hElectronMCTrkPitch->Integral() ;//* 0.494;
double KaonMCIntegralTrkLength     = hKaonMCTrkPitch->Integral();//0.00035
double PhotonMCIntegralTrkLength   = hPhotonMCTrkPitch->Integral();//0.00035

// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralTrkLength + MuonMCIntegralTrkLength + ElectronMCIntegralTrkLength + KaonMCIntegralTrkLength + PhotonMCIntegralTrkLength;
double DataIntegralTrkLength = hDataTrkPitch->Integral();

double scaleMCTrkLength = DataIntegralTrkLength/MCIntegralTrkLength;



// ### Scaling by particle species ###
double PionPercentage     = 0.2627;
double MuonPercentage     = 11.2673;
double ElectronPercentage = 0.51504;
double PhotonPercentage   = 0.6755;
double KaonPercentage     = 293.8255;


// ### Scale each particle species ###

// == Scale Pions ===
hPionMCTrkPitch->Sumw2();
hPionMCTrkPitch->Scale(scaleMCTrkLength*(1/PionPercentage));

std::cout<<"# of Pion = "<<hPionMCTrkPitch->Integral()<<std::endl;

// == Scale Muons ===
hMuonMCTrkPitch->Sumw2();
hMuonMCTrkPitch->Scale(scaleMCTrkLength*(1/MuonPercentage));
std::cout<<"# of Muon = "<<hMuonMCTrkPitch->Integral()<<std::endl;

// == Scale Electron ===
hElectronMCTrkPitch->Sumw2();
hElectronMCTrkPitch->Scale(scaleMCTrkLength*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCTrkPitch->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCTrkPitch->Sumw2();
hKaonMCTrkPitch->Scale(scaleMCTrkLength*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCTrkPitch->Integral()<<std::endl;

// == Scale Photon ===
hPhotonMCTrkPitch->Sumw2();
hPhotonMCTrkPitch->Scale(scaleMCTrkLength*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCTrkPitch->Integral()<<std::endl;

std::cout<<std::endl;

std::cout<<"# of data events = "<<hDataTrkPitch->Integral()<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Length");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionMCTrkPitch->SetLineColor(kBlue);
hPionMCTrkPitch->SetLineStyle(0);
hPionMCTrkPitch->SetLineWidth(3);
hPionMCTrkPitch->SetFillColor(kBlue);
hPionMCTrkPitch->SetFillStyle(3006);

hElectronMCTrkPitch->SetLineColor(kRed);
hElectronMCTrkPitch->SetLineStyle(0);
hElectronMCTrkPitch->SetLineWidth(3);
hElectronMCTrkPitch->SetFillColor(kRed);
hElectronMCTrkPitch->SetFillStyle(3006);

hMuonMCTrkPitch->SetLineColor(kGreen+3);
hMuonMCTrkPitch->SetLineStyle(0);
hMuonMCTrkPitch->SetLineWidth(3);
hMuonMCTrkPitch->SetFillColor(kGreen+3);
hMuonMCTrkPitch->SetFillStyle(3006);

hKaonMCTrkPitch->SetLineColor(kPink+3);
hKaonMCTrkPitch->SetLineStyle(0);
hKaonMCTrkPitch->SetLineWidth(3);
hKaonMCTrkPitch->SetFillColor(kPink+3);
hKaonMCTrkPitch->SetFillStyle(3006);

hPhotonMCTrkPitch->SetLineColor(kAzure-9);
hPhotonMCTrkPitch->SetLineStyle(0);
hPhotonMCTrkPitch->SetLineWidth(3);
hPhotonMCTrkPitch->SetFillColor(kAzure-9);
hPhotonMCTrkPitch->SetFillStyle(3007);


hDataTrkPitch->SetLineColor(kBlack);
hDataTrkPitch->SetLineStyle(0);
hDataTrkPitch->SetLineWidth(3);
hDataTrkPitch->SetMarkerStyle(8);
hDataTrkPitch->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCTrkPitch);
hstacked->Add(hPhotonMCTrkPitch);
hstacked->Add(hMuonMCTrkPitch);
hstacked->Add(hElectronMCTrkPitch);
hstacked->Add(hPionMCTrkPitch);


// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataTrkPitch->Draw("E1same");


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
leg->AddEntry(hDataTrkPitch,"Data");
leg->AddEntry(hPionMCTrkPitch,"Pion MC"); 
leg->AddEntry(hMuonMCTrkPitch,"Muon MC");
leg->AddEntry(hElectronMCTrkPitch,"Electron MC");
leg->AddEntry(hPhotonMCTrkPitch, "Photon MC");
leg->AddEntry(hKaonMCTrkPitch,"Kaon MC");
leg->Draw();








}
