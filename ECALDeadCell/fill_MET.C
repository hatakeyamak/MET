#include "TROOT.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TPaveStats.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TList.h"
#include "TLegendEntry.h"
#include "string.h"
#include <iostream>
#include "TTreeReader.h"
#include "TChain.h"
#include "TProfile.h"
#include <cmath>
#include "TProfile2D.h"
#include "TH2D.h"

/*

  /SingleMuon/Run2015C-PromptReco-v1/MINIAOD
  /SingleMuon/Run2015C-23Sep2015-v1/MINIAOD
  /SingleMuon/Run2015C_25ns-05Oct2015-v1/MINIAOD
 (/SingleMuon/Run2015C_50ns-05Oct2015-v1/MINIAOD)

 

 */

void fill_MET(int isample=0){

  TChain *chain = new TChain("TreeMaker2/PreSelection");
  if (isample==0)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV1/Run2015C*JetHT*.root");
  if (isample==1)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV1/Run2015C*HTMHT*.root");
  if (isample==2)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV1/Run2015C*SingleMuon*.root");
  if (isample==3)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV1/Spring15.QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");

  if (isample==20)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV2/Run2015C*JetHT*.root");
  if (isample==21)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV2/Run2015C*HTMHT*.root");
  if (isample==22)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV2/Run2015C*SingleMuon*.root");
  if (isample==23)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV2/Spring15*QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");

  if (isample==30)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*JetHT*.root");
  if (isample==31)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*HTMHT*.root");
  if (isample==32)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*SingleMuon*.root");
  if (isample==33)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Spring15*QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");
  if (isample==34){ //chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*JetHT*.root");
                    chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015D*JetHT*.root");}
  if (isample==35){ //chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*HTMHT*.root");
                    chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015D*HTMHT*.root");}
  if (isample==36){ //chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015C*SingleMuon*.root");
                    chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV3/Run2015D*SingleMuon*.root");}

  if (isample==40)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV4/Run2015C*JetHT*.root");
  if (isample==41)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV4/Run2015C*HTMHT*.root");
  if (isample==42)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV4/Run2015C*SingleMuon*.root");
  if (isample==43)  chain->Add("/data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV4/Spring15*QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");

  TTreeReader *tReader;
  tReader = new TTreeReader((TTree *)chain);
  
  TFile *f2;
  if (isample==0) f2 = TFile::Open("trees_JETHT_Run2015C_V1.root",      "RECREATE");
  if (isample==1) f2 = TFile::Open("trees_HTMHT_Run2015C_V1.root",      "RECREATE");
  if (isample==2) f2 = TFile::Open("trees_SingleMuon_Run2015C_V1.root", "RECREATE");
  if (isample==3) f2 = TFile::Open("trees_QCD_HT2000ToInf_V1.root",     "RECREATE");

  if (isample==20) f2 = TFile::Open("trees_JETHT_Run2015C_V2.root",      "RECREATE");
  if (isample==21) f2 = TFile::Open("trees_HTMHT_Run2015C_V2.root",      "RECREATE");
  if (isample==22) f2 = TFile::Open("trees_SingleMuon_Run2015C_V2.root", "RECREATE");
  if (isample==23) f2 = TFile::Open("trees_QCD_HT2000ToInf_V2.root",     "RECREATE");

  if (isample==30) f2 = TFile::Open("trees_JETHT_Run2015C_V3.root",      "RECREATE");
  if (isample==31) f2 = TFile::Open("trees_HTMHT_Run2015C_V3.root",      "RECREATE");
  if (isample==32) f2 = TFile::Open("trees_SingleMuon_Run2015C_V3.root", "RECREATE");
  if (isample==33) f2 = TFile::Open("trees_QCD_HT2000ToInf_V3.root",     "RECREATE");
  if (isample==34) f2 = TFile::Open("trees_JETHT_Run2015D_V3.root",      "RECREATE");
  if (isample==35) f2 = TFile::Open("trees_HTMHT_Run2015D_V3.root",      "RECREATE");
  if (isample==36) f2 = TFile::Open("trees_SingleMuon_Run2015D_V3.root", "RECREATE");

  if (isample==40) f2 = TFile::Open("trees_JETHT_Run2015C_V4.root",      "RECREATE");
  if (isample==41) f2 = TFile::Open("trees_HTMHT_Run2015C_V4.root",      "RECREATE");
  if (isample==42) f2 = TFile::Open("trees_SingleMuon_Run2015C_V4.root", "RECREATE");
  if (isample==43) f2 = TFile::Open("trees_QCD_HT2000ToInf_V4.root",     "RECREATE");

  TTreeReaderValue<Double_t> getMETPt(*tReader, "METPt");
  TTreeReaderValue<Double_t> getMETPtclean(*tReader, "METPtclean");

  TTreeReaderValue<Int_t>    getEcalDeadCellTriggerPrimitiveFilter(*tReader, "EcalDeadCellTriggerPrimitiveFilter");
//TTreeReaderValue<Bool_t>   getHBHEIsoNoiseFilter(*tReader, "HBHEIsoNoiseFilter");
  TTreeReaderValue<Bool_t>   getHBHEIsoNoiseFilter(*tReader, "HBHENoiseFilter");
  TTreeReaderValue<Bool_t>   getHBHENoiseFilter(*tReader, "HBHENoiseFilter");
  TTreeReaderValue<Int_t>    getEEBadScFilter(*tReader, "eeBadScFilter");
  TTreeReaderValue<Int_t>    getNVtx(*tReader, "NVtx");
//TTreeReaderValue<Bool_t>   getCSCTightHaloFilter(*tReader, "CSCTightHaloFilter");

  //chain->Draw("METPt");
  //chain->Draw("METPtclean");
  //chain->Draw("EcalDeadCellTriggerPrimitiveFilter");

  int events = chain->GetEntries();
  std::cout << events << std::endl;

  TH1F *METPt                       = new TH1F("METPt",       "METPt",        5000, 0., 50000.);
  TH1F *METPtclean                  = new TH1F("METPtclean",  "METPtclean",   5000, 0., 50000.);

  TH1F *METPt_taggedByECALTP        = new TH1F("METPt_taggedByECALTP",       "METPt_taggedByECALTP",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByECALTP   = new TH1F("METPtclean_taggedByECALTP",  "METPtclean_taggedByECALTP",   5000, 0., 50000.);

  TH1F *METPt_taggedByHBHE          = new TH1F("METPt_taggedByHBHE",         "METPt_taggedByHBHE",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByHBHE     = new TH1F("METPtclean_taggedByHBHE",    "METPtclean_taggedByHBHE",   5000, 0., 50000.);

  TH1F *METPt_taggedByHBHEIso       = new TH1F("METPt_taggedByHBHEIso",       "METPt_taggedByHBHEIso",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByHBHEIso  = new TH1F("METPtclean_taggedByHBHEIso",  "METPtclean_taggedByHBHEIso",   5000, 0., 50000.);

  TH1F *METPt_taggedByEEBadSc       = new TH1F("METPt_taggedByEEBadSc",       "METPt_taggedByEEBadSc",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByEEBadSc  = new TH1F("METPtclean_taggedByEEBadSc",  "METPtclean_taggedByEEBadSc",   5000, 0., 50000.);

  TH1F *METPt_taggedByNVtx          = new TH1F("METPt_taggedByNVtx",          "METPt_taggedByNVtx",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByNVtx     = new TH1F("METPtclean_taggedByNVtx",     "METPtclean_taggedByNVtx",   5000, 0., 50000.);

  TH1F *METPt_taggedByCSCTight      = new TH1F("METPt_taggedByCSCTight",      "METPt_taggedByCSCTight",        5000, 0., 50000.);
  TH1F *METPtclean_taggedByCSCTight = new TH1F("METPtclean_taggedByCSCTight", "METPtclean_taggedByCSCTight",   5000, 0., 50000.);

  TH1F *ECALTPFilter                = new TH1F("ECALTPFilter",      "ECALTPFilter",       10, 0., 10.);
  TH1F *HBHENoiseFilter             = new TH1F("HBHENoiseFilter",   "HBHENoiseFilter",    10, 0., 10.);
  TH1F *HBHEIsoNoiseFilter          = new TH1F("HBHEIsoNoiseFilter","HBHEIsoNoiseFilter", 10, 0., 10.);
  TH1F *EEBadScFilter               = new TH1F("EEBadScFilter",     "EEBadScFilter",      10, 0., 10.);
  TH1F *NVtx                        = new TH1F("NVtx",              "NVtx",               10, 0., 10.);
  /*
  TH1F *CSCTightHaloFilter          = new TH1F("CSCTightHaloFilter","CSCTightHaloFilter", 10, 0., 10.);
  */

  int nEvents=0;
  //for (int i = 0; i < events; i++) {
  while(tReader->Next()){
    //chain->GetEntry(i);
    nEvents++;
    if (nEvents%10000 == 0) {
      // A very simple progress indicator
      // Print the entry number every thousandth time
      cout << nEvents << endl;
    }
    //std::cout << *getMETPt << " " << *getMETPtclean << " " << getEcalDeadCellTriggerPrimitiveFilter << std::endl;

    ECALTPFilter->Fill(*getEcalDeadCellTriggerPrimitiveFilter);
    HBHENoiseFilter->Fill(*getHBHENoiseFilter);
    HBHEIsoNoiseFilter->Fill(*getHBHEIsoNoiseFilter);
    EEBadScFilter->Fill(*getEEBadScFilter);
    NVtx->Fill(*getNVtx);
    /*
    CSCTightHaloFilter->Fill(*getCSCTightHaloFilter);
    */

    METPt->Fill(*getMETPt);
    METPtclean->Fill(*getMETPtclean);

    if (*getEcalDeadCellTriggerPrimitiveFilter==0){
      METPt_taggedByECALTP->Fill(*getMETPt);
      METPtclean_taggedByECALTP->Fill(*getMETPtclean);
    }
    if (!*getHBHENoiseFilter){
      METPt_taggedByHBHE->Fill(*getMETPt);
      METPtclean_taggedByHBHE->Fill(*getMETPtclean);
    }
    if (!*getHBHEIsoNoiseFilter){
      METPt_taggedByHBHEIso->Fill(*getMETPt);
      METPtclean_taggedByHBHEIso->Fill(*getMETPtclean);
    }
    if(*getEEBadScFilter==0){
      METPt_taggedByEEBadSc->Fill(*getMETPt);
      METPtclean_taggedByEEBadSc->Fill(*getMETPtclean);
    }
    if(*getNVtx==0){
      METPt_taggedByNVtx->Fill(*getMETPt);
      METPtclean_taggedByNVtx->Fill(*getMETPtclean);
    }
    /*
    if(!*getCSCTightHaloFilter==0){
      METPt_taggedByCSCTight->Fill(*getMETPt);
      METPtclean_taggedByCSCTight->Fill(*getMETPtclean);
    }
    */

  }

  f2->Write();

}

/*
******************************************************************************
*Chain   :TreeMaker2/PreSelection: /data3/store/user/hatake/ntuples/SusyRA2Analysis2015/Run2ProductionV4/Run2015C_25ns-05Oct2015-v1.JetHT_16_RA2AnalysisTree.root *
******************************************************************************
******************************************************************************
*Tree    :PreSelection: PreSelection                                           *
*Entries :    49328 : Total =       369104152 bytes  File  Size =  109719332 *
*        :          : Tree compression factor =   3.36                       *
******************************************************************************
*Br    0 :RunNum    : RunNum/i                                               *
*Entries :    49328 : Total  Size=     198357 bytes  File Size  =       1806 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 109.57     *
*............................................................................*
*Br    1 :LumiBlockNum : LumiBlockNum/i                                      *
*Entries :    49328 : Total  Size=     198423 bytes  File Size  =       1977 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 100.11     *
*............................................................................*
*Br    2 :EvtNum    : EvtNum/l                                               *
*Entries :    49328 : Total  Size=     396243 bytes  File Size  =     193500 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   2.04     *
*............................................................................*
*Br    3 :bestPhoton : vector<TLorentzVector>                                *
*Entries :    49328 : Total  Size=     695226 bytes  File Size  =      78796 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.81     *
*............................................................................*
*Br    4 :BTags     : BTags/I                                                *
*Entries :    49328 : Total  Size=     198346 bytes  File Size  =      11815 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  16.75     *
*............................................................................*
*Br    5 :BTagsclean : BTagsclean/I                                          *
*Entries :    49328 : Total  Size=     198401 bytes  File Size  =      11836 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  16.72     *
*............................................................................*
*Br    6 :CaloMETPhi : CaloMETPhi/D                                          *
*Entries :    49328 : Total  Size=     396311 bytes  File Size  =     383395 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.03     *
*............................................................................*
*Br    7 :CaloMETPt : CaloMETPt/D                                            *
*Entries :    49328 : Total  Size=     396294 bytes  File Size  =     226059 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.75     *
*............................................................................*
*Br    8 :CSCTightHaloFilter : CSCTightHaloFilter/O                          *
*Entries :    49328 : Total  Size=      50034 bytes  File Size  =        467 *
*Baskets :        2 : Basket Size=      32000 bytes  Compression= 106.03     *
*............................................................................*
*Br    9 :DeltaPhi1 : DeltaPhi1/D                                            *
*Entries :    49328 : Total  Size=     396294 bytes  File Size  =     342567 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.16     *
*............................................................................*
*Br   10 :DeltaPhi1clean : DeltaPhi1clean/D                                  *
*Entries :    49328 : Total  Size=     396379 bytes  File Size  =     342327 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.16     *
*............................................................................*
*Br   11 :DeltaPhi2 : DeltaPhi2/D                                            *
*Entries :    49328 : Total  Size=     396294 bytes  File Size  =     281215 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.41     *
*............................................................................*
*Br   12 :DeltaPhi2clean : DeltaPhi2clean/D                                  *
*Entries :    49328 : Total  Size=     396379 bytes  File Size  =     280916 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.41     *
*............................................................................*
*Br   13 :DeltaPhi3 : DeltaPhi3/D                                            *
*Entries :    49328 : Total  Size=     396294 bytes  File Size  =     120143 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   3.29     *
*............................................................................*
*Br   14 :DeltaPhi3clean : DeltaPhi3clean/D                                  *
*Entries :    49328 : Total  Size=     396379 bytes  File Size  =     119763 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   3.30     *
*............................................................................*
*Br   15 :DeltaPhi4 : DeltaPhi4/D                                            *
*Entries :    49328 : Total  Size=     396294 bytes  File Size  =      58680 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   6.74     *
*............................................................................*
*Br   16 :DeltaPhi4clean : DeltaPhi4clean/D                                  *
*Entries :    49328 : Total  Size=     396379 bytes  File Size  =      58528 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   6.76     *
*............................................................................*
*Br   17 :EcalDeadCellTriggerPrimitiveFilter :                               *
*         | EcalDeadCellTriggerPrimitiveFilter/I                             *
*Entries :    49328 : Total  Size=     198665 bytes  File Size  =       1974 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 100.34     *
*............................................................................*
*Br   18 :eeBadScFilter : eeBadScFilter/I                                    *
*Entries :    49328 : Total  Size=     198434 bytes  File Size  =       1834 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 107.92     *
*............................................................................*
*Br   19 :ElectronCharge : vector<int>                                       *
*Entries :    49328 : Total  Size=     694898 bytes  File Size  =      79723 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.71     *
*............................................................................*
*Br   20 :Electrons : vector<TLorentzVector>                                 *
*Entries :    49328 : Total  Size=     705290 bytes  File Size  =      88476 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.96     *
*............................................................................*
*Br   21 :GenDeltaPhi : vector<double>                                       *
*Entries :    49328 : Total  Size=     694106 bytes  File Size  =      77294 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.97     *
*............................................................................*
*Br   22 :GenMinDeltaPhiEta24 : vector<double>                               *
*Entries :    49328 : Total  Size=    2278958 bytes  File Size  =     123614 *
*Baskets :       78 : Basket Size=      32000 bytes  Compression=  18.42     *
*............................................................................*
*Br   23 :GenMinDeltaPhiEta5 : vector<double>                                *
*Entries :    49328 : Total  Size=    2278876 bytes  File Size  =     124080 *
*Baskets :       78 : Basket Size=      32000 bytes  Compression=  18.35     *
*............................................................................*
*Br   24 :GenMinDeltaPhiIndexEta24 : vector<int>                             *
*Entries :    49328 : Total  Size=    1486945 bytes  File Size  =     100754 *
*Baskets :       53 : Basket Size=      32000 bytes  Compression=  14.74     *
*............................................................................*
*Br   25 :GenMinDeltaPhiIndexEta5 : vector<int>                              *
*Entries :    49328 : Total  Size=    1486888 bytes  File Size  =     100644 *
*Baskets :       53 : Basket Size=      32000 bytes  Compression=  14.76     *
*............................................................................*
*Br   26 :HBHEIsoNoiseFilter : HBHEIsoNoiseFilter/O                          *
*Entries :    49328 : Total  Size=      50034 bytes  File Size  =        740 *
*Baskets :        2 : Basket Size=      32000 bytes  Compression=  66.91     *
*............................................................................*
*Br   27 :HBHENoiseFilter : HBHENoiseFilter/O                                *
*Entries :    49328 : Total  Size=      50016 bytes  File Size  =        911 *
*Baskets :        2 : Basket Size=      32000 bytes  Compression=  54.34     *
*............................................................................*
*Br   28 :HT        : HT/D                                                   *
*Entries :    49328 : Total  Size=     396175 bytes  File Size  =     232737 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.70     *
*............................................................................*
*Br   29 :HTclean   : HTclean/D                                              *
*Entries :    49328 : Total  Size=     396260 bytes  File Size  =     232756 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.70     *
*............................................................................*
*Br   30 :HTJetsMask : vector<bool>                                          *
*Entries :    49328 : Total  Size=    1047107 bytes  File Size  =     303435 *
*Baskets :       39 : Basket Size=      32000 bytes  Compression=   3.45     *
*............................................................................*
*Br   31 :isoElectronTracks : isoElectronTracks/I                            *
*Entries :    49328 : Total  Size=     198478 bytes  File Size  =       4389 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  45.10     *
*............................................................................*
*Br   32 :IsolatedElectronTracksVeto : vector<TLorentzVector>                *
*Entries :    49328 : Total  Size=     745084 bytes  File Size  =     124143 *
*Baskets :       30 : Basket Size=      32000 bytes  Compression=   5.99     *
*............................................................................*
*Br   33 :IsolatedMuonTracksVeto : vector<TLorentzVector>                    *
*Entries :    49328 : Total  Size=     707447 bytes  File Size  =      90828 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.78     *
*............................................................................*
*Br   34 :IsolatedPionTracksVeto : vector<TLorentzVector>                    *
*Entries :    49328 : Total  Size=     830571 bytes  File Size  =     184082 *
*Baskets :       33 : Basket Size=      32000 bytes  Compression=   4.51     *
*............................................................................*
*Br   35 :isoMuonTracks : isoMuonTracks/I                                    *
*Entries :    49328 : Total  Size=     198434 bytes  File Size  =       2539 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  77.96     *
*............................................................................*
*Br   36 :isoPionTracks : isoPionTracks/I                                    *
*Entries :    49328 : Total  Size=     198434 bytes  File Size  =       7669 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  25.81     *
*............................................................................*
*Br   37 :JetID     : JetID/O                                                *
*Entries :    49328 : Total  Size=      49956 bytes  File Size  =       1370 *
*Baskets :        2 : Basket Size=      32000 bytes  Compression=  36.12     *
*............................................................................*
*Br   38 :Jets      : vector<TLorentzVector>                                 *
*Entries :    49328 : Total  Size=   23284519 bytes  File Size  =   11957972 *
*Baskets :      739 : Basket Size=      32000 bytes  Compression=   1.95     *
*............................................................................*
*Br   39 :Jets_bDiscriminatorCSV : vector<double>                            *
*Entries :    49328 : Total  Size=    3519903 bytes  File Size  =    1528947 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   2.30     *
*............................................................................*
*Br   40 :Jets_bDiscriminatorMVA : vector<double>                            *
*Entries :    49328 : Total  Size=    3519903 bytes  File Size  =     290717 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=  12.10     *
*............................................................................*
*Br   41 :Jets_chargedEmEnergyFraction : vector<double>                      *
*Entries :    49328 : Total  Size=    3520629 bytes  File Size  =     463131 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   7.60     *
*............................................................................*
*Br   42 :Jets_chargedHadronEnergyFraction : vector<double>                  *
*Entries :    49328 : Total  Size=    3521113 bytes  File Size  =    1762427 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   2.00     *
*............................................................................*
*Br   43 :Jets_chargedHadronMultiplicity : vector<int>                       *
*Entries :    49328 : Total  Size=    2107726 bytes  File Size  =     666203 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   3.16     *
*............................................................................*
*Br   44 :Jets_chargedMultiplicity : vector<int>                             *
*Entries :    49328 : Total  Size=    2107270 bytes  File Size  =     666029 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   3.16     *
*............................................................................*
*Br   45 :Jets_electronMultiplicity : vector<int>                            *
*Entries :    49328 : Total  Size=    2107346 bytes  File Size  =     335511 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   6.28     *
*............................................................................*
*Br   46 :Jets_hadronFlavor : vector<int>                                    *
*Entries :    49328 : Total  Size=    2106738 bytes  File Size  =     241833 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   8.70     *
*............................................................................*
*Br   47 :Jets_jetArea : vector<double>                                      *
*Entries :    49328 : Total  Size=    3518693 bytes  File Size  =     853990 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   4.12     *
*............................................................................*
*Br   48 :Jets_muonEnergyFraction : vector<double>                           *
*Entries :    49328 : Total  Size=    3520024 bytes  File Size  =     401628 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   8.76     *
*............................................................................*
*Br   49 :Jets_muonMultiplicity : vector<int>                                *
*Entries :    49328 : Total  Size=    2107042 bytes  File Size  =     304213 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   6.92     *
*............................................................................*
*Br   50 :Jets_neutralEmEnergyFraction : vector<double>                      *
*Entries :    49328 : Total  Size=    3520629 bytes  File Size  =    1993840 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   1.76     *
*............................................................................*
*Br   51 :Jets_neutralHadronEnergyFraction : vector<double>                  *
*Entries :    49328 : Total  Size=    3521113 bytes  File Size  =    1855633 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   1.90     *
*............................................................................*
*Br   52 :Jets_neutralHadronMultiplicity : vector<int>                       *
*Entries :    49328 : Total  Size=    2107726 bytes  File Size  =     579889 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   3.63     *
*............................................................................*
*Br   53 :Jets_neutralMultiplicity : vector<int>                             *
*Entries :    49328 : Total  Size=    2107270 bytes  File Size  =     673592 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   3.13     *
*............................................................................*
*Br   54 :Jets_partonFlavor : vector<int>                                    *
*Entries :    49328 : Total  Size=    2106738 bytes  File Size  =     241833 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   8.70     *
*............................................................................*
*Br   55 :Jets_photonEnergyFraction : vector<double>                         *
*Entries :    49328 : Total  Size=    3520266 bytes  File Size  =    1874695 *
*Baskets :      117 : Basket Size=      32000 bytes  Compression=   1.88     *
*............................................................................*
*Br   56 :Jets_photonMultiplicity : vector<int>                              *
*Entries :    49328 : Total  Size=    2107194 bytes  File Size  =     658868 *
*Baskets :       72 : Basket Size=      32000 bytes  Compression=   3.20     *
*............................................................................*
*Br   57 :Leptons   : Leptons/I                                              *
*Entries :    49328 : Total  Size=     198368 bytes  File Size  =       2576 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  76.82     *
*............................................................................*
*Br   58 :METFilters : METFilters/I                                          *
*Entries :    49328 : Total  Size=     198401 bytes  File Size  =       4945 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  40.02     *
*............................................................................*
*Br   59 :METPhi    : METPhi/D                                               *
*Entries :    49328 : Total  Size=     396243 bytes  File Size  =     243157 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.63     *
*............................................................................*
*Br   60 :METPhiclean : METPhiclean/D                                        *
*Entries :    49328 : Total  Size=     396328 bytes  File Size  =     249856 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.58     *
*............................................................................*
*Br   61 :METPt     : METPt/D                                                *
*Entries :    49328 : Total  Size=     396226 bytes  File Size  =     226560 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.75     *
*............................................................................*
*Br   62 :METPtclean : METPtclean/D                                          *
*Entries :    49328 : Total  Size=     396311 bytes  File Size  =     243427 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.63     *
*............................................................................*
*Br   63 :MHT       : MHT/D                                                  *
*Entries :    49328 : Total  Size=     396192 bytes  File Size  =     368462 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.07     *
*............................................................................*
*Br   64 :MHT_Phi   : MHT_Phi/D                                              *
*Entries :    49328 : Total  Size=     396260 bytes  File Size  =     377132 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.05     *
*............................................................................*
*Br   65 :MHT_Phiclean : MHT_Phiclean/D                                      *
*Entries :    49328 : Total  Size=     396345 bytes  File Size  =     377095 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.05     *
*............................................................................*
*Br   66 :MHTclean  : MHTclean/D                                             *
*Entries :    49328 : Total  Size=     396277 bytes  File Size  =     368452 *
*Baskets :       13 : Basket Size=      32000 bytes  Compression=   1.07     *
*............................................................................*
*Br   67 :MHTJetsMask : vector<bool>                                         *
*Entries :    49328 : Total  Size=    1047150 bytes  File Size  =     284280 *
*Baskets :       39 : Basket Size=      32000 bytes  Compression=   3.68     *
*............................................................................*
*Br   68 :minDeltaPhiNames : vector<string>                                  *
*Entries :    49328 : Total  Size=    2377725 bytes  File Size  =     114637 *
*Baskets :       81 : Basket Size=      32000 bytes  Compression=  20.72     *
*............................................................................*
*Br   69 :MuonCharge : vector<int>                                           *
*Entries :    49328 : Total  Size=     694298 bytes  File Size  =      78217 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.87     *
*............................................................................*
*Br   70 :Muons     : vector<TLorentzVector>                                 *
*Entries :    49328 : Total  Size=     697498 bytes  File Size  =      81192 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.58     *
*............................................................................*
*Br   71 :nAllVertices : nAllVertices/I                                      *
*Entries :    49328 : Total  Size=     198423 bytes  File Size  =      48136 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=   4.11     *
*............................................................................*
*Br   72 :NeutrinoLorentzVector : vector<TLorentzVector>                     *
*Entries :    49328 : Total  Size=     694426 bytes  File Size  =      77591 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.94     *
*............................................................................*
*Br   73 :NeutrinoMotherPdg : vector<int>                                    *
*Entries :    49328 : Total  Size=     694298 bytes  File Size  =      77325 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.97     *
*............................................................................*
*Br   74 :NeutrinoPdg : vector<int>                                          *
*Entries :    49328 : Total  Size=     694106 bytes  File Size  =      77294 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.97     *
*............................................................................*
*Br   75 :NJets     : NJets/I                                                *
*Entries :    49328 : Total  Size=     198346 bytes  File Size  =      33635 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=   5.88     *
*............................................................................*
*Br   76 :NJetsclean : NJetsclean/I                                          *
*Entries :    49328 : Total  Size=     198401 bytes  File Size  =      33663 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=   5.88     *
*............................................................................*
*Br   77 :nTAPElectronTracks : nTAPElectronTracks/I                          *
*Entries :    49328 : Total  Size=     198489 bytes  File Size  =      14393 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  13.75     *
*............................................................................*
*Br   78 :nTAPMuonTracks : nTAPMuonTracks/I                                  *
*Entries :    49328 : Total  Size=     198445 bytes  File Size  =       6892 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  28.72     *
*............................................................................*
*Br   79 :nTAPPionTracks : nTAPPionTracks/I                                  *
*Entries :    49328 : Total  Size=     198445 bytes  File Size  =      41731 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=   4.74     *
*............................................................................*
*Br   80 :NumPhotons : NumPhotons/I                                          *
*Entries :    49328 : Total  Size=     198401 bytes  File Size  =       1776 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 111.43     *
*............................................................................*
*Br   81 :NVtx      : NVtx/I                                                 *
*Entries :    49328 : Total  Size=     198335 bytes  File Size  =      47441 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=   4.17     *
*............................................................................*
*Br   82 :PDFids    : vector<int>                                            *
*Entries :    49328 : Total  Size=     693946 bytes  File Size  =      77183 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.98     *
*............................................................................*
*Br   83 :PDFweights : vector<double>                                        *
*Entries :    49328 : Total  Size=     694074 bytes  File Size  =      77349 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.96     *
*............................................................................*
*Br   84 :photon_genMatched : vector<double>                                 *
*Entries :    49328 : Total  Size=     917842 bytes  File Size  =     157137 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   5.83     *
*............................................................................*
*Br   85 :photon_hadTowOverEM : vector<double>                               *
*Entries :    49328 : Total  Size=     917920 bytes  File Size  =     265948 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   3.45     *
*............................................................................*
*Br   86 :photon_hasPixelSeed : vector<double>                               *
*Entries :    49328 : Total  Size=     917920 bytes  File Size  =     174049 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   5.27     *
*............................................................................*
*Br   87 :photon_isEB : vector<double>                                       *
*Entries :    49328 : Total  Size=     917608 bytes  File Size  =     175349 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   5.23     *
*............................................................................*
*Br   88 :photon_nonPrompt : vector<bool>                                    *
*Entries :    49328 : Total  Size=     694266 bytes  File Size  =      77463 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.95     *
*............................................................................*
*Br   89 :photon_passElectronVeto : vector<double>                           *
*Entries :    49328 : Total  Size=     918076 bytes  File Size  =     173443 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   5.29     *
*............................................................................*
*Br   90 :photon_pfChargedIso : vector<double>                               *
*Entries :    49328 : Total  Size=     917920 bytes  File Size  =     310874 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   2.95     *
*............................................................................*
*Br   91 :photon_pfChargedIsoRhoCorr : vector<double>                        *
*Entries :    49328 : Total  Size=     918193 bytes  File Size  =     376271 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   2.44     *
*............................................................................*
*Br   92 :photon_pfGammaIso : vector<double>                                 *
*Entries :    49328 : Total  Size=     917842 bytes  File Size  =     317396 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   2.89     *
*............................................................................*
*Br   93 :photon_pfGammaIsoRhoCorr : vector<double>                          *
*Entries :    49328 : Total  Size=     918115 bytes  File Size  =     377367 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   2.43     *
*............................................................................*
*Br   94 :photon_pfNeutralIso : vector<double>                               *
*Entries :    49328 : Total  Size=     917920 bytes  File Size  =     284737 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   3.22     *
*............................................................................*
*Br   95 :photon_pfNeutralIsoRhoCorr : vector<double>                        *
*Entries :    49328 : Total  Size=     918193 bytes  File Size  =     327833 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   2.80     *
*............................................................................*
*Br   96 :photon_sigmaIetaIeta : vector<double>                              *
*Entries :    49328 : Total  Size=     917959 bytes  File Size  =     298911 *
*Baskets :       35 : Basket Size=      32000 bytes  Compression=   3.07     *
*............................................................................*
*Br   97 :photonCands : vector<TLorentzVector>                               *
*Entries :    49328 : Total  Size=    2482122 bytes  File Size  =    1131651 *
*Baskets :       84 : Basket Size=      32000 bytes  Compression=   2.19     *
*............................................................................*
*Br   98 :RJetDeltaPhi : vector<double>                                      *
*Entries :    49328 : Total  Size=    1687903 bytes  File Size  =    1127645 *
*Baskets :       59 : Basket Size=      32000 bytes  Compression=   1.50     *
*............................................................................*
*Br   99 :RJetMinDeltaPhiEta24 : vector<double>                              *
*Entries :    49328 : Total  Size=    2279040 bytes  File Size  =     895324 *
*Baskets :       78 : Basket Size=      32000 bytes  Compression=   2.54     *
*............................................................................*
*Br  100 :RJetMinDeltaPhiEta5 : vector<double>                               *
*Entries :    49328 : Total  Size=    2278958 bytes  File Size  =     917798 *
*Baskets :       78 : Basket Size=      32000 bytes  Compression=   2.48     *
*............................................................................*
*Br  101 :RJetMinDeltaPhiIndexEta24 : vector<int>                            *
*Entries :    49328 : Total  Size=    1487002 bytes  File Size  =     206269 *
*Baskets :       53 : Basket Size=      32000 bytes  Compression=   7.20     *
*............................................................................*
*Br  102 :RJetMinDeltaPhiIndexEta5 : vector<int>                             *
*Entries :    49328 : Total  Size=    1486945 bytes  File Size  =     201098 *
*Baskets :       53 : Basket Size=      32000 bytes  Compression=   7.39     *
*............................................................................*
*Br  103 :ScaleWeights : vector<double>                                      *
*Entries :    49328 : Total  Size=     694138 bytes  File Size  =      77295 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.97     *
*............................................................................*
*Br  104 :selectedIDElectrons : vector<TLorentzVector>                       *
*Entries :    49328 : Total  Size=     808706 bytes  File Size  =     168664 *
*Baskets :       32 : Basket Size=      32000 bytes  Compression=   4.79     *
*............................................................................*
*Br  105 :selectedIDElectrons_mediumID : vector<bool>                        *
*Entries :    49328 : Total  Size=     696429 bytes  File Size  =     108409 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   6.42     *
*............................................................................*
*Br  106 :selectedIDElectrons_MiniIso : vector<double>                       *
*Entries :    49328 : Total  Size=     708980 bytes  File Size  =     116121 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.10     *
*............................................................................*
*Br  107 :selectedIDElectrons_MT2Activity : vector<double>                   *
*Entries :    49328 : Total  Size=     709112 bytes  File Size  =     116381 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.08     *
*............................................................................*
*Br  108 :selectedIDElectrons_MTW : vector<double>                           *
*Entries :    49328 : Total  Size=     708848 bytes  File Size  =     109005 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.49     *
*............................................................................*
*Br  109 :selectedIDIsoElectrons_mediumID : vector<bool>                     *
*Entries :    49328 : Total  Size=     694920 bytes  File Size  =      86853 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   7.99     *
*............................................................................*
*Br  110 :selectedIDIsoElectrons_MT2Activity : vector<double>                *
*Entries :    49328 : Total  Size=     696234 bytes  File Size  =      84203 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.26     *
*............................................................................*
*Br  111 :selectedIDIsoElectrons_MTW : vector<double>                        *
*Entries :    49328 : Total  Size=     695978 bytes  File Size  =      83230 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.35     *
*............................................................................*
*Br  112 :selectedIDIsoElectrons_PTW : vector<double>                        *
*Entries :    49328 : Total  Size=     695978 bytes  File Size  =      84011 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.27     *
*............................................................................*
*Br  113 :selectedIDIsoMuons_MT2Activity : vector<double>                    *
*Entries :    49328 : Total  Size=     695162 bytes  File Size  =      80200 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.66     *
*............................................................................*
*Br  114 :selectedIDIsoMuons_MTW : vector<double>                            *
*Entries :    49328 : Total  Size=     694906 bytes  File Size  =      79687 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.71     *
*............................................................................*
*Br  115 :selectedIDIsoMuons_PTW : vector<double>                            *
*Entries :    49328 : Total  Size=     694906 bytes  File Size  =      79995 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.68     *
*............................................................................*
*Br  116 :selectedIDMuons : vector<TLorentzVector>                           *
*Entries :    49328 : Total  Size=     739526 bytes  File Size  =     118883 *
*Baskets :       30 : Basket Size=      32000 bytes  Compression=   6.21     *
*............................................................................*
*Br  117 :selectedIDMuons_MiniIso : vector<double>                           *
*Entries :    49328 : Total  Size=     700248 bytes  File Size  =      96162 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.27     *
*............................................................................*
*Br  118 :selectedIDMuons_MT2Activity : vector<double>                       *
*Entries :    49328 : Total  Size=     700380 bytes  File Size  =      96139 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.28     *
*............................................................................*
*Br  119 :selectedIDMuons_MTW : vector<double>                               *
*Entries :    49328 : Total  Size=     700116 bytes  File Size  =      92745 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.54     *
*............................................................................*
*Br  120 :slimJet   : vector<TLorentzVector>                                 *
*Entries :    49328 : Total  Size=   32715990 bytes  File Size  =   16835985 *
*Baskets :     1038 : Basket Size=      32000 bytes  Compression=   1.94     *
*............................................................................*
*Br  121 :slimJet_slimJetID : vector<bool>                                   *
*Entries :    49328 : Total  Size=    1194826 bytes  File Size  =     272379 *
*Baskets :       44 : Basket Size=      32000 bytes  Compression=   4.38     *
*............................................................................*
*Br  122 :slimJetJECdown : vector<TLorentzVector>                            *
*Entries :    49328 : Total  Size=   32723284 bytes  File Size  =   16851747 *
*Baskets :     1038 : Basket Size=      32000 bytes  Compression=   1.94     *
*............................................................................*
*Br  123 :slimJetJECdown_slimJetID : vector<bool>                            *
*Entries :    49328 : Total  Size=    1195162 bytes  File Size  =     289285 *
*Baskets :       44 : Basket Size=      32000 bytes  Compression=   4.13     *
*............................................................................*
*Br  124 :slimJetJECup : vector<TLorentzVector>                              *
*Entries :    49328 : Total  Size=   32721200 bytes  File Size  =   16835110 *
*Baskets :     1038 : Basket Size=      32000 bytes  Compression=   1.94     *
*............................................................................*
*Br  125 :slimJetJECup_slimJetID : vector<bool>                              *
*Entries :    49328 : Total  Size=    1195066 bytes  File Size  =     271367 *
*Baskets :       44 : Basket Size=      32000 bytes  Compression=   4.40     *
*............................................................................*
*Br  126 :TagLeptonHighPT : TagLeptonHighPT/I                                *
*Entries :    49328 : Total  Size=     198456 bytes  File Size  =       2349 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression=  84.27     *
*............................................................................*
*Br  127 :TAPElectronTracks : vector<TLorentzVector>                         *
*Entries :    49328 : Total  Size=    1088370 bytes  File Size  =     341563 *
*Baskets :       41 : Basket Size=      32000 bytes  Compression=   3.18     *
*............................................................................*
*Br  128 :TAPElectronTracks_activity : vector<double>                        *
*Entries :    49328 : Total  Size=     743908 bytes  File Size  =     154134 *
*Baskets :       30 : Basket Size=      32000 bytes  Compression=   4.82     *
*............................................................................*
*Br  129 :TAPElectronTracks_chg : vector<int>                                *
*Entries :    49328 : Total  Size=     719082 bytes  File Size  =     120406 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   5.96     *
*............................................................................*
*Br  130 :TAPElectronTracks_mT : vector<double>                              *
*Entries :    49328 : Total  Size=     743704 bytes  File Size  =     179837 *
*Baskets :       30 : Basket Size=      32000 bytes  Compression=   4.13     *
*............................................................................*
*Br  131 :TAPElectronTracks_trkiso : vector<double>                          *
*Entries :    49328 : Total  Size=     743840 bytes  File Size  =     161473 *
*Baskets :       30 : Basket Size=      32000 bytes  Compression=   4.60     *
*............................................................................*
*Br  132 :TAPMuonTracks : vector<TLorentzVector>                             *
*Entries :    49328 : Total  Size=     807722 bytes  File Size  =     168316 *
*Baskets :       32 : Basket Size=      32000 bytes  Compression=   4.79     *
*............................................................................*
*Br  133 :TAPMuonTracks_activity : vector<double>                            *
*Entries :    49328 : Total  Size=     708719 bytes  File Size  =     107823 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.56     *
*............................................................................*
*Br  134 :TAPMuonTracks_chg : vector<int>                                    *
*Entries :    49328 : Total  Size=     701486 bytes  File Size  =      97642 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   7.17     *
*............................................................................*
*Br  135 :TAPMuonTracks_mT : vector<double>                                  *
*Entries :    49328 : Total  Size=     708521 bytes  File Size  =     116426 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.08     *
*............................................................................*
*Br  136 :TAPMuonTracks_trkiso : vector<double>                              *
*Entries :    49328 : Total  Size=     708653 bytes  File Size  =     110479 *
*Baskets :       29 : Basket Size=      32000 bytes  Compression=   6.41     *
*............................................................................*
*Br  137 :TAPPionTracks : vector<TLorentzVector>                             *
*Entries :    49328 : Total  Size=    8830502 bytes  File Size  =    4505805 *
*Baskets :      283 : Basket Size=      32000 bytes  Compression=   1.96     *
*............................................................................*
*Br  138 :TAPPionTracks_activity : vector<double>                            *
*Entries :    49328 : Total  Size=    1711802 bytes  File Size  =     756293 *
*Baskets :       60 : Basket Size=      32000 bytes  Compression=   2.26     *
*............................................................................*
*Br  139 :TAPPionTracks_chg : vector<int>                                    *
*Entries :    49328 : Total  Size=    1202890 bytes  File Size  =     298536 *
*Baskets :       44 : Basket Size=      32000 bytes  Compression=   4.03     *
*............................................................................*
*Br  140 :TAPPionTracks_mT : vector<double>                                  *
*Entries :    49328 : Total  Size=    1711418 bytes  File Size  =    1222396 *
*Baskets :       60 : Basket Size=      32000 bytes  Compression=   1.40     *
*............................................................................*
*Br  141 :TAPPionTracks_trkiso : vector<double>                              *
*Entries :    49328 : Total  Size=    1711674 bytes  File Size  =     892822 *
*Baskets :       60 : Basket Size=      32000 bytes  Compression=   1.92     *
*............................................................................*
*Br  142 :TriggerNames : vector<string>                                      *
*Entries :    49328 : Total  Size=   78222271 bytes  File Size  =    3108108 *
*Baskets :     2467 : Basket Size=      32000 bytes  Compression=  25.15     *
*............................................................................*
*Br  143 :TriggerPass : vector<int>                                          *
*Entries :    49328 : Total  Size=   10793156 bytes  File Size  =     604140 *
*Baskets :      345 : Basket Size=      32000 bytes  Compression=  17.85     *
*............................................................................*
*Br  144 :TriggerPrescales : vector<int>                                     *
*Entries :    49328 : Total  Size=   10794901 bytes  File Size  =     364625 *
*Baskets :      345 : Basket Size=      32000 bytes  Compression=  29.59     *
*............................................................................*
*Br  145 :ZNum      : ZNum/I                                                 *
*Entries :    49328 : Total  Size=     198335 bytes  File Size  =       1654 *
*Baskets :        7 : Basket Size=      32000 bytes  Compression= 119.63     *
*............................................................................*
*Br  146 :Zp4       : vector<TLorentzVector>                                 *
*Entries :    49328 : Total  Size=     693978 bytes  File Size  =      77203 *
*Baskets :       28 : Basket Size=      32000 bytes  Compression=   8.98     *
*............................................................................*
*/
