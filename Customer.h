#ifndef CUSTOMER
#define CUSTOMER

//A Customer class used by the store class to determine how much credit can be spent in the store.
class Customer {
public:
    //Construct a customer with their credit.
    Customer(int credit);
    //Return that amount of credit available to this customer.
    int showCredit();
private:
    int credit;
};

#endif
