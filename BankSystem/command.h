#ifndef COMMANDS_H
#define COMMANDS_H



//open account
int open(bankAccount account);

//start account
char* start(char* name);

//finish session
int finish(bankAccount account);

//exit server connection
int exit(bankAccount account);

//remove money command
int debit(float amount, bankAccount account);


//add money command
int credit(float amount, bankAccount account);


//find curr balance
float currentbalance(bankAccount account);



#endif
