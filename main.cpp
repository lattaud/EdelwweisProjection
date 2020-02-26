#include <iostream>
#include "Projection.h"

using namespace std;

int main(int argc, char** argv) {

	std::cout<<" Projection utilitary "<<std::endl;
	std::string Input_file;
	std::string Proba_type;
	std::string Output_file;
	std::string Simu_Type;
	std::string Fano_factor;
	std::string Sigma_exp;
	std::string Run_auto;
	std::string Verbosity;
	std::string Name_distrib;
	Double_t    Tension; 
	
	
	for(int i =1 ; i < argc ; i++){	
	      if(argv[i][0] == '-'){
	            switch(argv[i][1]){
	                  case 'i' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Input_file = argv[i+1];
	                     } else {
	                        cout << "Input file name missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                  case 'o' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Output_file = argv[i+1];
	                     } else {
	                        cout << "Output file name missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'S' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Simu_Type = argv[i+1];
	                     } else {
	                        cout << "Projection type missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'P' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Proba_type = argv[i+1];
	                     } else {
	                        cout << "Pairs proba type missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'F' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Fano_factor = argv[i+1];
	                     } else {
	                        cout << "Fano factor missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'R' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Sigma_exp = argv[i+1];
	                     } else {
	                        cout << "Experimental resolution missing" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'T' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Name_distrib = argv[i+1];
	                     } else {
	                        cout << "Type of spectrum" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'A' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Run_auto = argv[i+1];
	                     } else {
	                        cout << "Auto mode ? : Auto / Remote" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'v' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Verbosity = argv[i+1];
	                     } else {
	                        cout << "verbosity mode (expect a boolean)" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 't' :
	                     if(i+1<argc && argv[i+1][0]!='-') {
	                             Tension = stod(argv[i+1]);
	                     } else {
	                        cout << "Tension for luke effect" << endl;
	                        exit(1);
	                     }
	                     break;
	                   case 'h' :
	                     std::cout<<" Physics projection program : make sure to have your spectrum ready "<<std::endl;
	                     std::cout<<"use the following option : "<<std::endl;
	                     std::cout<<"-i : Input file that contain your spectrum"<<std::endl;
	                     std::cout<<"-o : Output file name"<<std::endl;
	                     std::cout<<"-S : Projection type, can be MC or Analytic"<<std::endl;
	                     std::cout<<"-P : Probality type for e- pairs creation"<<std::endl;
	                     std::cout<<"-F : Fano factor    for e- pairs creation"<<std::endl;
	                     std::cout<<"-R : Experimental E_{phonon} resolution (keV)"<<std::endl;
	                     std::cout<<"-T : Spectrum type desired"<<std::endl;
	                     std::cout<<"-A : Is automated"<<std::endl;
	                     std::cout<<"-v : verbosity mode"<<std::endl;
	                     std::cout<<"-t : tension for luke effect"<<std::endl;
	                     exit(0);
	                  default:
	                     cout << "unknown command " << argv[i] << " , use the -h command for help" << endl;
	                     exit(1);

	            }
	      
	      }	
	}
	
	if(Simu_Type == "MC"){
	
	      Int_t NitMC = 100000;
	      if(Run_auto != "Auto"){
	         std::cout<<" Enter the desired number of iteration "<<std::endl;
	         cin>>NitMC;
	         std::cout<<" Enter the name of the distribution "<<std::endl;
	         cin>>Name_distrib;
	         std::cout<<" Enter the desired tension for Luke effect "<<std::endl;
	         cin>>Tension;
	      }
	      
	      Proj_MC* Proj_instance = new Proj_MC((Input_file).c_str(),(Output_file).c_str(),(Proba_type).c_str(),stod(Sigma_exp),stod(Fano_factor),  Name_distrib, NitMC, Tension);
	      Proj_instance->Set_verbosity(Verbosity.c_str());
	      Proj_instance->Init();
	      Proj_instance->Write_output();
	      delete Proj_instance;
	}
	
	if(Simu_Type == "Analytic"){
	
	      Proj_Analytic* Proj_instance = new Proj_Analytic((Input_file).c_str(),(Output_file).c_str(),(Proba_type).c_str(),stod(Sigma_exp),stod(Fano_factor));
	      delete Proj_instance;
	}

	std::cout<<" Ending Routine "<<std::endl;
	return 0;	 
}
