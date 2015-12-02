#include "bankAccount.h"
#define MAX_ACCOUNTS 20 // The max number of bank accounts that can be created

//number of accounts initially
accountCount;

//create pointer to list of bank accounts
bankAccount* list;

void initList(){

	list = malloc(MAX_ACCOUNTS * sizeof(bankAccount));
	accountCount = 0;

	return;
}


BankAccount initBankAccount(char* accountName){

	//create mem space for new account
	BankAccount account = malloc(sizeof(bankAccount));

	//fill in all the fields
	account->isf = 0;
	account->balance =0;
	account->name = accountName;

	return account;
}

void printList(){

	int i;

	for(i=0; i<accountCount; i++){
		printf("%s\n", list[i]->name);
		printf("The balance for this account is: \n");
		printf("%d", list[i]->balance);
		if(list[i]->isf ==1){
			printf("THE ACCOUNT IS CURRENTLY IN SERVICE\n");
		}
	
		printf("\n");
	}

	return;
}


