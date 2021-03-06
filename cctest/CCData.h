//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct 25 05:16:53 2016 by ROOT version 5.34/34
// from TTree CCData/CCData
// found on file: /data/output/DataR320S1p10.root
//////////////////////////////////////////////////////////

#ifndef CCData_h
#define CCData_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class CCData {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          Trigger;
   UInt_t          OutNumber;
   vector<string>  *Type;
   vector<unsigned int> *Value;
   vector<unsigned int> *Slot;
   vector<unsigned int> *Channel;
   ULong64_t       TimeStamp;

   // List of branches
   TBranch        *b_Trigger;   //!
   TBranch        *b_OutN;   //!
   TBranch        *b_Type;   //!
   TBranch        *b_Value;   //!
   TBranch        *b_Slot;   //!
   TBranch        *b_Channel;   //!
   TBranch        *b_TimeStamp;   //!

   CCData(TTree *tree=0);
   virtual ~CCData();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CCData_cxx
CCData::CCData(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data/output/DataR320S1p10.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data/output/DataR320S1p10.root");
      }
      f->GetObject("CCData",tree);

   }
   Init(tree);
}

CCData::~CCData()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CCData::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CCData::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CCData::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Type = 0;
   Value = 0;
   Slot = 0;
   Channel = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

      fChain->SetBranchAddress("Trigger", &Trigger, &b_Trigger);
   fChain->SetBranchAddress("OutNumber", &OutNumber, &b_OutN);
   fChain->SetBranchAddress("Type", &Type, &b_Type);
   fChain->SetBranchAddress("Value", &Value, &b_Value);
   fChain->SetBranchAddress("Slot", &Slot, &b_Slot);
   fChain->SetBranchAddress("Channel", &Channel, &b_Channel);
   fChain->SetBranchAddress("TimeStamp", &TimeStamp, &b_TimeStamp);
   Notify();
}

Bool_t CCData::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CCData::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CCData::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CCData_cxx
