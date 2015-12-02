#include "bankAccount.h"

//number of accounts initially
accountCount;

//create pointer to list of bank accounts
bankAccount* list;


int i;


void initList(){

	list = malloc(20 * sizeof(bankAccount));
	accountCount = 0;

	return;
}


BankAccount initBankAccount(char* accountName){

	if(accountCount + 1 == 20){
		return -1;
	}
	
	for(i=0; i<accountCount; i++){
		if(list[i]->name == accountName){
			return -1;
		}
	}

	if(accountName == NULL){
		return -1;
	}

	//create mem space for new account
	BankAccount account = malloc(sizeof(struct bankAccount));

	//fill in all the fields
	account->isf = 1;
	account->balance =0.0;

	account->name = malloc(100*sizeof(char));
	strcpy(account->name, accountName);

	return account;
}

void printList(){

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


