#include "Projection.h"

using namespace std;


//All method for MC based Projection
Proj_MC::Proj_MC (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor, const std::string & Name_distrib,Int_t Niteration, Double_t voltage  ){
   Input_file_name  = Input_file;
   Output_file_name = Output_file;
   PairsE_type      = Proba_pairs;
   sigma_exp        = sigma_exp;
   fano_factor      = Fano_factor;
   N_iteration      = Niteration;
   Name_spectrum    = Name_distrib;
   Volt             = voltage;

}

void Proj_MC::Init(){

   TFile* INPUT_FILE = TFile::Open(Input_file_name.c_str(),"UPDATE");
   Input_spectrum =  (TF1*) INPUT_FILE->Get(("Spectrum_"+Name_spectrum).c_str());
   Loop_MC();
   INPUT_FILE->Close();
   

}

void Proj_MC::Loop_MC(){

   for(int i = 0 ; i < N_iteration ; i++){
   
        Double_t Er = Input_spectrum->GetRandom();
        Double_t N_epairs = Compute_N_pairs(PairsE_type.c_str());
        Double_t Ep  =  Er + N_epairs * Volt ;
   
   }

}

Double_t Proj_MC::Compute_N_pairs(const std::string Type_proba){

   if(Type_proba == "Poisson"){
      Double_t Npairs ;
      
      
      return Npairs;
   }else{
   
      return 1./3.;
   }

}

void Proj_MC::Set_verbosity(const std::string verbosity){
   if( stoi(verbosity) >= 0 && stoi(verbosity) <=1 ) {
      Is_verbose=stoi(verbosity);
   }else{
      Is_verbose=false;
   }
}

//All method for Analytics Projection
Proj_Analytic::Proj_Analytic (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor ){

}


void Proj_Analytic::Init(){



}
