#include "Projection.h"

using namespace std;


//All method for MC based Projection
Proj_MC::Proj_MC (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor,Int_t Niteration  ){
   Input_file_name  = Input_file;
   Output_file_name = Output_file;
   PairsE_type      = Proba_pairs;
   sigma_exp        = sigma_exp;
   fano_factor      = Fano_factor;
   N_iteration      = Niteration;


}

void Proj_MC::Init(){



}

//All method for Analytics Projection
Proj_Analytic::Proj_Analytic (const std::string &Input_file, const std::string &Output_file, const std::string &Proba_pairs, Double_t sigma_exp ,Double_t Fano_factor ){

}


void Proj_Analytic::Init(){



}
