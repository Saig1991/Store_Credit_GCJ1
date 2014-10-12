#ifndef STORE_H
#define STORE_H

#include "queue"

public class Store {
public:    
    //Construct the store its number of items.
    Store(int numItems)
    //Searches the store with the constraint from the customer to find the two objects.
    std::queue<int> findObjects(Customer &cust)
    // Remove item from Store.
    removeFrontItem();
    // Add item to store
    addItem(int item);
private:
    std::queue<int> store
};

#endif
