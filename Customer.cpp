#include "Customer.h"


//Construct a customer with their credit.
Customer::Customer(int credit){
    this->credit = credit;
}

//Return that amount of credit available to this customer.
int Customer::showCredit(){
    return this->credit;
}
