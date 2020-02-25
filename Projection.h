#ifndef __PROJECTION_H__
#define __PROJECTION_H__


// standard libraries

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector> 
// Root related libraries
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH2.h"
#include "TH1.h"
#include "TF1.h"
#include "TGraph.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TLatex.h"
#include "THStack.h"
#include "TROOT.h"
#include "TChain.h"
#include "TTree.h"
#include "TMath.h"
#include "TDirectory.h"
#include "TGraphErrors.h"
#include "TParameter.h"

class Proj_MC {

   private: 
      TGraphErrors* Ep_spectrum;
      TGraphErrors* Eh_spectrum;
      TF1* Func_Ep_spectrum;
      TF1* Func_Eh_spectrum;
      TFile*        Output_file;
      std::string   Input_file_name;
      std::string   Output_file_name;
      TF1*          epair_proba;
      TF1*          Input_spectrum;
      std::string   PairsE_type;
      Int_t         N_iteration;
      Double_t      sigma_exp;
      Double_t      fano_factor;
      
      
      
      

   public: 
      Proj_MC(const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor,Int_t Niteration );
      ~Proj_MC()= default;
      void Init();
      

};



class Proj_Analytic {

   private: 
      

   public: 
      Proj_Analytic (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor );
      ~Proj_Analytic()= default;
      void Init();

};



#endif
