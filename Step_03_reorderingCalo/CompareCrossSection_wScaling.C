{

// ############################
// ### Constants ###
// ############################
float rho = 1400; //Argon density in kg/m^3
float molar_mass = 39.9; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.02e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m (from mean of track pitch)


// ################################
// ###     Load MC Plots        ###
// ################################

// ====================================
// === Monte Carlo with no scalings ===
// ====================================
TFile *f1 = new TFile("./histo_ROOTFILES/DataNew_PionXSection_histos_reorderingOnly.root");


// ===============================================
// === Monte Carlo with beam spectrum scalings ===
// ===============================================
TFile *f2 = new TFile("./histo_ROOTFILES/PionMC_NewMatch_wScalings_dEdXScale_Reordering.root");


TH1F* MCCrossSectionNoScaling = (TH1F*)f1->Get("fCrossSection");
TH1F* MCXSectionwScaling = (TH1F*)fCrossSection->Clone();

TH1F* MCCrossSectionwScaling = (TH1F*)f2->Get("fCrossSection");


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Cross-Section");
c01->SetTicks();
c01->SetFillColor(kWhite);

MCXSectionwScaling->SetLineColor(kAzure+2);
MCCrossSectionNoScaling->Draw("histo");
MCXSectionwScaling->Draw("histosame");


MCCrossSectionwScaling->Sumw2();
MCCrossSectionwScaling->Scale(-1);

TH1D *Difference = new TH1D("Difference", "Cross Section", 40, 0 , 2000);

TH1D *Ratio = new TH1D("Ratio", "Cross Section", 40, 0 , 2000);

Difference->Add(MCCrossSectionNoScaling, MCCrossSectionwScaling);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Difference");
c02->SetTicks();
c02->SetFillColor(kWhite);

Ratio->Divide(Difference, MCCrossSectionNoScaling);
Ratio->Draw("histo");

// #######################################################################
// ###### Grabbing the number of bins from the cross-section plot ########
// #######################################################################
int nbinsMC = fCrossSection->GetNbinsX();






// ##############################
// ### Loop over all the bins ###
// ##############################
for(int nbins = 1; nbins < nbinsMC; nbins++)
   {
   std::cout<<"# = "<<MCCrossSectionNoScaling->GetBinContent(nbins)<<std::endl;
   
   
   
   
   }//<---End nbins loop



}
