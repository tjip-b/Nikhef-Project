// This is the main program
int readtree() {

    // we first load the file
    TFile f ("/data/nikhefproject/lectures/week1/mystery_file.root");
    
    // we list wat is inside the file to show that hits_tree is the tree
    f.ls();
    
    // we now make a pointer to the tree
    TTree *MyTree; //= hits_tree;
    f.GetObject("hits_tree" ,MyTree);
    
    // we can make a layout of everything the tree contains using the following command, but I do not yet know what the use is of this.
    //MyTree->MakeCode();

    // To get a better of what the Tree contains we use the following command, which shows the outline.
    MyTree->Print();
    
    // we want to loop through all the entries so we want to find how many entries the tree contains.
    Int_t nentries = (Int_t)MyTree->GetEntries();
    
    // to see what a specific branch contains, we use the following command
    MyTree->Scan("hit_global_x");

    // we loop through all the entries
    for (Int_t i = 0; i<nentries; i++){
        
        // and show what each entry consists of
        MyTree->Show(i); 
    }

    // we end by drawing a histogram.
    MyTree->Draw("log(genpart_energy)");
    return(0);

}
