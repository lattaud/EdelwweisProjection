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
#include "TRandom.h"
#include "TRandom3.h"

class Proj_MC {

   private: 
      TH1D* Ep_spectrum;
      TH1D* Eh_spectrum;
      TF1* Func_Ep_spectrum;
      TF1* Func_Eh_spectrum;
      TFile*        Output_file;
      std::string   Input_file_name;
      std::string   Output_file_name;
      TF1*          epair_proba;
      TF1*          Input_spectrum;
      std::string   PairsE_type;
      std::string   Name_spectrum;
      Int_t         N_iteration;
      Double_t      sigma_exp;
      Double_t      fano_factor;
      bool          Is_verbose;
      Double_t      Volt;
      std::string   QUENCHING = "EDW3";
      TRandom3 *    Random_instance;
      Double_t      Bin_Ep_width;
      
      
      

   public: 
      Proj_MC(const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor, const std::string & Name_distrib,Int_t Niteration, Double_t voltage );
      ~Proj_MC()= default;
      void Init();
      void Loop_MC();
      void Write_to_file();
      void Set_verbosity(const std::string verbosity);
      Int_t Compute_N_pairs(const std::string Type_proba, Double_t Er);
      Double_t Quenching_function(Double_t Er , const std::string type_quenching);
      Double_t Reso_vs_Ep(Double_t Ep);
      void Write_output();
      

};



class Proj_Analytic {

   private: 
      

   public: 
      Proj_Analytic (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor );
      ~Proj_Analytic()= default;
      void Init();

};



#endif
