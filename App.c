#include"App.h"
#include "Terminal.h"
#include"card.h"
#include"Server.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void appStart()
{
	ST_terminalData_t TERM;
	ST_cardData_t CARD;
	ST_transaction_t SERVER;



	EN_cardError_t cardName = getCardHolderName(&CARD);
	EN_cardError_t Exp_Date = getCardExpiryDate(&CARD);
	EN_cardError_t PAN = getCardPAN(&CARD);

	EN_terminalError_t  TRANS_DATE = getTransactionDate(&TERM);
	EN_terminalError_t EXP_DATE = isCardExpired(CARD,TERM);
	if (EXP_DATE == EXPIRED_CARD)
	{
		printf("Declined expired date");
		return;
	}
	EN_terminalError_t GET_TRANS = getTransactionAmount(&TERM);
	EN_terminalError_t Check_am = isBelowMaxAmount(&TERM);
	if (Check_am == EXCEED_MAX_AMOUNT)
	{
		printf("Declined amount exceed limit");
		return;
	}
		SERVER.cardHolderData = CARD;
		SERVER.terminalData = TERM;

		EN_serverError_t VALID_ACC = isValidAccount(&SERVER);
		if (VALID_ACC == DECLINED_STOLEN_CARD)
		{
			printf("Declined invalid account");
			return;
		}
	EN_serverError_t Avb_AM = isAmountAvailable(&SERVER);
	if (Avb_AM == LOW_BALANCE)
	{
		printf("Declined insufficent amount");
		return;

	}

	EN_serverError_t SAVE = saveTransaction(&SERVER);
	EN_transState_t UPDATE = recieveTransactionData(&SERVER);
 }