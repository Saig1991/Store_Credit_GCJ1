#include <iostream>
#include <fstream>
#include <queue>
#include "Store"
#include "Customer"

int main(int argc, char* argv[]){
     
    if(argc != 2){
        std::cout << "Please enter input file name as command line input" << std::endl;
        std::cout << "Usage: ./program [input file name] " << std::endl;
    } else {
        //Read in input file.
        std::string inputFileName = argv[1];
        std::ifstream ifs;
        ifs.open(inputFileName.c_str(), std::ifstream::in); 

        //Ensure file can be opened.
        if(ifs.is_open()){
            int N = 0;
            ifs >> N;
            //Read through every test case and display the output.
            for(int i = 0; i < N; i++){
                int storeCredit = 0;
                ifs >> storeCredit;

                int numStoreItems = 0;
                ifs >> numStoreItems;

                //Create Store for this test case.
                Store newStore(numStoreItems);
                //Create customer for this test case.
                Customer newCust(StoreCredit);
                
                //Iterate through all the items in this store instance and create the store object.
                for( int j = 0; j < numStoreItems; j++){
                    int item = 0;
                    ifs >> item;
                    newStore.addItem(item);
                }
                
                //get output.
                std::queue<int> output = newStore.findObjects(newCust);

                //Display output to the std output.
                std::cout << "Case #";
                std::cout << i+1;
                std::cout << ": ";
                std::cout << output.front();
                output.pop();
                std::cout << output.front() << std::endl;
                output.pop();
                ifs.close();
            }
        } else{
            std::cout << "Error: Couldn't open input file" << std::endl;

        }
    }

    
    

    return 0;
}
