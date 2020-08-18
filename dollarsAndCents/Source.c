#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define bill_100 100
#define bill_50 50
#define bill_20 20
#define bill_10 10
#define bill_5 5
#define coin_2 2
#define coin_1 1
#define coin_25 0.25
#define coin_10 0.10
#define coin_5 0.05


#define NUMBER_OF_STRINGS 10


int main(void) {
	double amount = -1;
	double remainder = 0;
	double temp;
	int change[10] = { 0 };
	double denominations[] = { 100,50,20,10,5,2,1,0.25,0.10,0.05 };
	const char *denominationNames[NUMBER_OF_STRINGS] = { "100s", "50s", "20s", "10s", "5s", "twonies", "loonies", "quarters", "dimes", "nickels" };
	
	printf("How much money do you have?\n");
	
	scanf("%lf", &amount);

	temp = ceil(amount * 20) / 20;
	amount = temp;

	for (int i = 0; i < 10; i++) {
		change[i] = amount / denominations[i];
		remainder = fmod(amount, denominations[i]);
		amount = remainder;
	}

	printf("---Your change is:---\n");
	for (int i = 0; i < 10; i++) {
		if(change[i] != 0)
			printf("\n%d %s", change[i], denominationNames[i]);
	}

}  