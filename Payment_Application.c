#define _CRT_SECURE_NO_WARNING
#include "card.h"
#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include "Server.h"

int main() {

	appStart();
	
	//ST_terminalData_t TERM;
	//ST_cardData_t CARD;
	//EN_transState_t SERVER;

	
/*
while (1)
	{
		//EN_cardError_t x = getCardHolderName(&CARD);
		//printf("\n%d\n", x);
		//EN_cardError_t y = getCardExpiryDate(&CARD);
		//printf("\n%d\n", y);
		//EN_cardError_t z = getCardPAN(&CARD);
		//printf("\n%d\n", z);

		//EN_terminalError_t m = getTransactionDate(&TERM);
		//printf("\n%d\n", m);
		//EN_terminalError_t n = getTransactionAmount(&TERM);
		//printf("\n%d\n", n);
		//EN_terminalError_t b = setMaxAmount(&TERM);
		//printf("\n%d\n", b);
		//EN_terminalError_t a = isBelowMaxAmount(&TERM);
		//printf("\n%d\n", a);
	
		//EN_terminalError_t s = isCardExpired(CARD,TERM);
		//printf("\n%d\n", s);
		EN_transState_t f = isValidAccount(&SERVER);
		printf("\n%c/n", f);
		EN_transState_t u = isAmountAvailable(&SERVER);
		printf("\n%d/n", u);
		EN_transState_t k = recieveTransactionData(&SERVER);
		printf("\n%d/n", k);*/

//	}

	return 0;
}