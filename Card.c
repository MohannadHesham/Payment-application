
#include "card.h"
#define _CRT_SECURE_NO_WARNING

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t name[25];

	printf("Please Enter Your name that is written on the card\n");
	gets(name);

	if (strlen(name)==0 || strlen(name)<20 || strlen(name)>25)	
	{
		return WRONG_NAME;
	}
	else
	{
		strcpy(cardData->cardHolderName, name);
		return card_OK;
	}

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t date[6];
	printf("Enter the expiry date as MM/YY : \n");
	gets(date);

	if (strlen(date) == 0 || strlen(date) < 5 || strlen(date) > 5)
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		strcpy(cardData->cardExpirationDate, date);
		return card_OK;
	}

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t PAN[20];
	printf("Enter primary account number\n");
	gets(PAN);

	if (strlen(PAN) == 0 || strlen(PAN) < 16 || strlen(PAN) > 19)
	{
		return WRONG_PAN;
	}
	else
	{
		strcpy(cardData->primaryAccountNumber, PAN);
		return card_OK;
	}
}
