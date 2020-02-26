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
   Random_instance  = new TRandom3(0);
   Ep_spectrum      = new TH1D(("Spectrum_"+Name_spectrum+"_Ephonon_smeared").c_str(),("Spectrum_"+Name_spectrum+"_Ephonon_smeared").c_str(),100000,0.,100);
   Bin_Ep_width = 1./100.;

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
        Double_t N_epairs = Compute_N_pairs(PairsE_type.c_str(), Er);
        Double_t Ep  =  Er + N_epairs * Volt ;
        Ep = Reso_vs_Ep(Ep);
        Ep_spectrum->Fill(Ep,1./Bin_Ep_width);
        
   }

}

Int_t Proj_MC::Compute_N_pairs(const std::string Type_proba, Double_t Er){

   Int_t Npairs ;
   Double_t epsilon ;
   if(Name_spectrum=="Gamma") epsilon = 3.;
   if(Name_spectrum=="Neutron") epsilon = Quenching_function(Er,QUENCHING);      
   if(Type_proba == "Poisson"){      
      Random_instance->SetSeed(0);
      Npairs = Random_instance->Poisson(Er/epsilon);      
      return Npairs;
   }else if (Type_proba == "Fano"){
   // This is probably a biased method. it does not take properly fano into account.                     
      Npairs = Int_t (Random_instance->Gaus(Er/epsilon,std::sqrt(fano_factor*(Er/epsilon))));      
      return Npairs;
   }

}

Double_t Proj_MC::Quenching_function(Double_t Er , const std::string type_quenching){

   if(type_quenching == "EDW3") return 0.16* std::pow(Er, 0.18); 
   if(type_quenching == "Lindart") return 1.; 


}
void Proj_MC::Set_verbosity(const std::string verbosity){
   if( stoi(verbosity) >= 0 && stoi(verbosity) <=1 ) {
      Is_verbose=stoi(verbosity);
   }else{
      Is_verbose=false;
   }
}


Double_t Proj_MC::Reso_vs_Ep(Double_t Ep){

   Double_t Ep_smeared;   
   Ep_smeared =  Random_instance->Gaus(Ep,std::sqrt(pow(0.04,2)/*+pow(0.02*Ep,2)*/));
   return Ep_smeared;
}

void Proj_MC::Write_output(){


      Output_file = new TFile("Output_spectrum","RECREATE");
      Ep_spectrum->Write();      
      Output_file->Close();


}

//All method for Analytics Projection
Proj_Analytic::Proj_Analytic (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor ){

}


void Proj_Analytic::Init(){



}
