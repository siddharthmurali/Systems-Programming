#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>


struct BankAccount{
	string name;
	float balance;
	int isf; 
};
typedef struct BankAccount* BankAccount;

#endif
