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
TFile *f1 = new TFile("../Step_03_reorderingCalo/histo_ROOTFILES/DataNew_PionXSection_histos_reorderingOnly.root");

 TH1F* hMCIncNoFix = (TH1F*)f1->Get("hdataIncidentKE");
 TH1F* hMCIntNoFix = (TH1F*)f1->Get("hdataInteractingKE");
 TH1F* MCCrossSectionNoFix = (TH1F*)f1->Get("fCrossSection");
 TH1F* MCCrossSysNoFix = (TH1F*)fCrossSection->Clone();
 MCCrossSysNoFix->SetName("MCCrossSysNoFix");

 
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
 double MCstat = hMCIntNoFix->GetBinContent(8);
 std::cout << MCstat << std::endl;
 MCstat = (sqrt(MCstat))/MCstat;
 std::cout << MCstat << std::endl;

 std::cout << "MC cross section" << std::endl;

 for (int i = 1; i <= nbinsMC; i++ ) {
   MCn = hMCIntNoFix->GetBinContent(i); 
   MCN = hMCIncNoFix->GetBinContent(i);
   MCsigbinom = sqrt((MCn/(MCN*MCN))*(1-(MCn/MCN)));

   if( MCN == 0 )continue; //Temporary fix to ensure no divide by zero 
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = (MCn/MCN)/(number_density)/(slab_width);
   
   crossSection = TempCrossSection * (1e28); //To put this into barns
   MCCrossSectionNoFix->SetBinContent(i,crossSection);

   MCsigbinom = sqrt(MCn/(MCN*MCN)*(1-MCn/MCN));
   MCsigbinom = MCsigbinom/number_density/slab_width*1e28; //MC binomial stat error in barns
//
//   MCCrossSection->SetBinError(i,MCsigbinom);
   MCCrossSectionNoFix->SetBinError(i, MCstat*crossSection); // use flat stat uncertainty


   MCsysstat = dEdxuncertsq + mucontamsq + WCmomuncertsq + Eflatuncertsq; //sum of squares of syserrs
   //   MCsysstat = MCsysstat + MCsigbinom*MCsigbinom; // Add in MC stat err squared
   MCsysstat = MCsysstat*crossSection;
   MCsysstat = MCsysstat + MCstat*MCstat;
   MCsysstat = sqrt(MCsysstat); // sqrt of sum of squares = total err

   std::cout << crossSection << " +/- " << MCstat*crossSection << "(stat) +/- " << MCsysstat << std::endl;


   MCCrossSysNoFix->SetBinContent(i,crossSection);
   MCCrossSysNoFix->SetBinError(i,MCsysstat);   
 }// end loop over MC bins




// ===============================================
// === Monte Carlo with beam spectrum scalings ===
// ===============================================
TFile *f2 = new TFile("./histo_ROOTFILES/DataNew_NewTOF_NewMatch_PionXSection_histos_reordering_FixExtremeAndSmallFluctuation.root");

 TH1F* hMCInc = (TH1F*)f2->Get("hdataIncidentKE");
 TH1F* hMCInt = (TH1F*)f2->Get("hdataInteractingKE");
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
TCanvas *c02 = new TCanvas("c02", "Difference");
c02->SetTicks();
c02->SetFillColor(kWhite);

MCCrossSection->SetLineColor(kBlack);
MCCrossSection->Draw();
MCCrossSectionNoFix->SetLineColor(kAzure+2);
MCCrossSectionNoFix->Draw("same");


TH1F* DifferenceNoFix = (TH1F*)MCCrossSectionNoFix->Clone();
TH1F* DifferencewFix = (TH1F*)MCCrossSection->Clone();

TH1D *Difference = new TH1D("Difference", "Cross Section", 40, 0 , 2000);

TH1D *Ratio = new TH1D("Ratio", "Cross Section", 40, 0 , 2000);

DifferencewFix->Sumw2();
DifferencewFix->Scale(-1);


Difference->Add(DifferenceNoFix, DifferencewFix);

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Ratio");
c03->SetTicks();
c03->SetFillColor(kWhite);

Ratio->Divide(Difference, DifferenceNoFix);
Ratio->Draw("histo");

}
