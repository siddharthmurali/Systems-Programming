#include "command.h"

int open(bankAccount account){

}

char* start(char* name){

}

int finish(bankAccount account){

}

int exit(bankAccount account){

}

int debit(float amount, bankAccount account){
	int withdrawn=0;

	if(account->balance > amount){
		//error not enough money in bank
	}

	else if(amount <0){
		//error cannot take out neg amount
	}

	else{
		withdrawn = amount;
		account->balance = account->balance - amount;
	}

	return account->balance;

}

int credit(float amount, bankAccount account){

	int deposited=0;

	if(amount <0){
		//error cannot deposit neg amount
	}

	else{
		account->balance = account->balance + amount;
	}

	return account->balance;
}


float currentBalance(bankAccount account){

	return account->balance;
}












