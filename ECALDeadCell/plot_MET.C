
void plot_MET(int isample=0){

  //
  ///////////////////////////////////////////////////////////////////////////////////////////
  ////Some cosmetic work for official documents. 
  //
  // Set basic style
  //
  //gROOT->LoadMacro("tdrstyle.C");
  //setTDRStyle();

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);
  
// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
  // tdrStyle->SetErrorMarker(20);
  //tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);
  
//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

// For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

// Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->SetHatchesLineWidth(5);
  tdrStyle->SetHatchesSpacing(0.05);

  tdrStyle->cd();

  //----------

  gROOT->LoadMacro("CMS_lumi_v2.C");

  TFile *f2;
  if (isample==0) f2 = TFile::Open("trees_JETHT_Run2015C_V1.root",      "READ");
  if (isample==1) f2 = TFile::Open("trees_HTMHT_Run2015C_V1.root",      "READ");
  if (isample==2) f2 = TFile::Open("trees_SingleMuon_Run2015C_V1.root", "READ");
  if (isample==3) f2 = TFile::Open("trees_QCD_HT2000ToInf_V1.root",     "READ");
  
  if (isample==20) f2 = TFile::Open("trees_JETHT_Run2015C_V2.root",      "READ");
  if (isample==21) f2 = TFile::Open("trees_HTMHT_Run2015C_V2.root",      "READ");
  if (isample==22) f2 = TFile::Open("trees_SingleMuon_Run2015C_V2.root", "READ");
  if (isample==23) f2 = TFile::Open("trees_QCD_HT2000ToInf_V2.root",     "READ");

  if (isample==30) f2 = TFile::Open("trees_JETHT_Run2015C_V3.root",      "READ");
  if (isample==31) f2 = TFile::Open("trees_HTMHT_Run2015C_V3.root",      "READ");
  if (isample==32) f2 = TFile::Open("trees_SingleMuon_Run2015C_V3.root", "READ");
  if (isample==33) f2 = TFile::Open("trees_QCD_HT2000ToInf_V3.root",     "READ");
  if (isample==34) f2 = TFile::Open("trees_JETHT_Run2015CD_V3.root",      "READ");
  if (isample==35) f2 = TFile::Open("trees_HTMHT_Run2015CD_V3.root",      "READ");
  if (isample==36) f2 = TFile::Open("trees_SingleMuon_Run2015CD_V3.root", "READ");

  if (isample==40) f2 = TFile::Open("trees_JETHT_Run2015C_V4.root",      "READ");
  if (isample==41) f2 = TFile::Open("trees_HTMHT_Run2015C_V4.root",      "READ");
  if (isample==42) f2 = TFile::Open("trees_SingleMuon_Run2015C_V4.root", "READ");
  if (isample==43) f2 = TFile::Open("trees_QCD_HT2000ToInf_V4.root",     "READ");

  TH1D *MET, *MET_taggedByECALTP, *MET_taggedByHBHE, *MET_taggedByEEBadSc, *MET_taggedByVtx;
  MET                   = (TH1D*)f2->Get("METPt");
  MET_taggedByECALTP    = (TH1D*)f2->Get("METPt_taggedByECALTP");
  MET_taggedByHBHE      = (TH1D*)f2->Get("METPt_taggedByHBHE");
  MET_taggedByEEBadSc   = (TH1D*)f2->Get("METPt_taggedByEEBadSc");
  MET_taggedByNVtx      = (TH1D*)f2->Get("METPt_taggedByNVtx");

  //
  // Define canvas
  //
  int W = 600;
  int H = 600;
  int H_ref = 600;
  int W_ref = 800;
  float T = 0.08*H_ref;
  float B = 0.12*H_ref;
  float L = 0.12*W_ref;
  float R = 0.08*W_ref;

  TCanvas *canvas = new TCanvas("canvas","canvas",10,10,W,H);

  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetFrameFillStyle(0);
  canvas->SetFrameBorderMode(0);
  canvas->SetLeftMargin( L/W );
  canvas->SetRightMargin( R/W );
  //canvas->SetRightMargin( 0.2 );
  canvas->SetTopMargin( T/H );
  canvas->SetBottomMargin( B/H );
  
  gPad->SetLogy();

  MET->Rebin(5);  
  MET_taggedByECALTP->Rebin(5);
  MET_taggedByHBHE->Rebin(5);
  MET_taggedByEEBadSc->Rebin(5);
  MET_taggedByNVtx->Rebin(5);

  MET->SetLineColor(1);
  MET->GetYaxis()->SetTitleSize(0.05);
  MET->GetYaxis()->SetTitleOffset(1.4);
  MET->GetXaxis()->SetTitleSize(0.05);
  MET->GetXaxis()->SetTitleOffset(0.9);
  MET->GetXaxis()->SetRangeUser(0.,2000.);
  MET->GetXaxis()->SetTitle("MET (GeV)");
  MET->GetYaxis()->SetTitle("Events / 50 GeV");
  MET->Draw();  
  MET_taggedByECALTP->SetLineColor(2);
  MET_taggedByECALTP->Draw("sames");
  MET_taggedByHBHE->SetLineColor(4);
  MET_taggedByHBHE->Draw("sames");
  //MET_taggedByEEBadSc->SetLineColor(6);
  //MET_taggedByEEBadSc->Draw("sames");
  MET_taggedByNVtx->SetLineColor(8);
  MET_taggedByNVtx->Draw("sames");

  //
  // Define legend
  //
  Float_t legendX1 = .45; //.50;
  Float_t legendX2 = .90; //.70;
  Float_t legendY1 = .70; //.65;
  Float_t legendY2 = .85;

  TLegend* catLeg1 = new TLegend(legendX1,legendY1,legendX2,legendY2);
  catLeg1->SetTextSize(0.025);
  catLeg1->SetTextFont(42);
  catLeg1->SetTextSize(0.030);
  catLeg1->SetTextFont(42);
  catLeg1->SetFillColor(0);
  catLeg1->SetLineColor(0);
  catLeg1->SetBorderSize(0);
  catLeg1->AddEntry(MET,"All events","l");
  catLeg1->AddEntry(MET_taggedByECALTP,"Tagged by ECAL TP filter","l");
  catLeg1->AddEntry(MET_taggedByHBHE,"Tagged by HBHE Noise filter","l");
  catLeg1->AddEntry(MET_taggedByNVtx,"N_{vtx} = 0","l");
  catLeg1->Draw();

  if (isample==0) canvas->SaveAs("plot_MET_JETHT_Run2015C_V1.pdf"); 
  if (isample==1) canvas->SaveAs("plot_MET_HTMHT_Run2015C_V1.pdf"); 
  if (isample==2) canvas->SaveAs("plot_MET_SingleMuon_Run2015C_V1.pdf"); 
  if (isample==3) canvas->SaveAs("plot_MET_QCD_HT2000ToInf_V1.pdf"); 

  if (isample==30) canvas->SaveAs("plot_MET_JETHT_Run2015C_V3.pdf"); 
  if (isample==31) canvas->SaveAs("plot_MET_HTMHT_Run2015C_V3.pdf"); 
  if (isample==32) canvas->SaveAs("plot_MET_SingleMuon_Run2015C_V3.pdf"); 
  if (isample==33) canvas->SaveAs("plot_MET_QCD_HT2000ToInf_V3.pdf"); 
  if (isample==34) canvas->SaveAs("plot_MET_JETHT_Run2015CD_V3.pdf"); 
  if (isample==35) canvas->SaveAs("plot_MET_HTMHT_Run2015CD_V3.pdf"); 
  if (isample==36) canvas->SaveAs("plot_MET_SingleMuon_Run2015CD_V3.pdf"); 

  if (isample==40) canvas->SaveAs("plot_MET_JETHT_Run2015C_V4.pdf"); 
  if (isample==41) canvas->SaveAs("plot_MET_HTMHT_Run2015C_V4.pdf"); 
  if (isample==42) canvas->SaveAs("plot_MET_SingleMuon_Run2015C_V4.pdf"); 
  if (isample==43) canvas->SaveAs("plot_MET_QCD_HT2000ToInf_V4.pdf"); 

}
