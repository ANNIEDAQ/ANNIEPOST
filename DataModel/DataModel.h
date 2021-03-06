#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <map>
#include <string>
#include <vector>
#include <stdint.h>

#include "TTree.h"
#include "PMTData.h"
#include "SplitTree.h"
#include "RunInformation.h"
#include "MRDTree.h"
#include "PulseTree.h" //to be included
#include "TrigData.h"

#include "Store.h"
#include "Logging.h"

#include <zmq.hpp>

class DataModel {


 public:
  
  DataModel();
  TFile* tmpfile;
  TTree* GetTTree(std::string name);
  void AddTTree(std::string name,TTree *tree);
  void DeleteTTree(std::string name);

  Store vars;
  Logging *Log;

  zmq::context_t* context;

  std::string outfile;

  TChain* PMTDataChain;
  TChain* RunInformationChain;
  TChain* MRDChain;
  TChain* TrigChain;
  PMTData* WaterPMTData;
  SplitTree* splittree;
  MRDTree* MRDData;
  RunInformation* RunInformationData;
  PulseTree* PulseData;
  TrigData* TriggerData;
  
  std::map<std::string,TTree*> m_trees; 
  
 private:
  
};



#endif
