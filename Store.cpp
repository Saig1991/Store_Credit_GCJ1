#include "Store.h"
#include <iostream>

//Construct a store.
Store::Store(int numItems){
    this->numStoreItems = numItems;
}

//Search store for two items that add up to the customers credit.
std::queue<int> Store::findObjects(Customer &cust){
    int credit = cust.showCredit();
    std::vector<int>::iterator firstItem = this->store.begin();
    std::queue<int> output;
    bool done = false;

    while(firstItem != this->store.end()){
        // This is the price required for the second item to meet the condition.
        int secondPrice = credit - *firstItem;

        //Start the search for the second item after the first item.
        //We assume that none of the previous items would meet the condition 
        //because they would have been searched already.( this is the structure of the loops).
        std::vector<int>::iterator secondItem = firstItem;
        if(secondItem != this->store.end()) secondItem++;

        while(secondItem != this->store.end()){
            if(*secondItem == secondPrice){
                int firstPos = firstItem - this->store.begin();
                int secondPos = secondItem - this->store.begin();
                firstPos++;
                secondPos++;
                output.push(firstPos);
                output.push(secondPos);
                secondItem = this->store.end();
                done = true;
            } else {
                secondItem++;
            }
        }

        if(!done){
            firstItem++;
        } else {
            firstItem = this->store.end();
        }
    }

    return output;
}


// Add item to store
void Store::addItem(int item){
    this->store.push_back(item);
}
