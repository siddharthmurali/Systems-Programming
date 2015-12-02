#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "utils.h"


//Start bank accounts list
void initList();

//Create new bank account
BankAccount initBankAccount(char* accountName);

//print all bank accounts
void printList();

#endif
