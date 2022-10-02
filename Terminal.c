#include "Terminal.h"
#include"card.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	uint8_t date[11];
	
	printf("Enter the current date\n");
	gets(date);

	if (strlen(date) == 0 || strlen(date) < 10 || strlen(date) > 10)
	{
		return WRONG_DATE;
	}
	else
	{
		strcpy(termData->transactionDate, date);
		return TERM_OK;
	}
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	
	int currentYear = (termData.transactionDate[8] - 48) * 10 + (termData.transactionDate[9] - 48); // 22
	int expiryYear = (cardData.cardExpirationDate[3] - 48) * 10 + (cardData.cardExpirationDate[4] - 48);//23
	int currentmonth = (termData.transactionDate[3] - 48) * 10 + (termData.transactionDate[4] - 48); 
	int expmonth = (cardData.cardExpirationDate[0] - 48) * 10 + (cardData.cardExpirationDate[1] - 48);
		

	if (currentYear > expiryYear)
	{
		return EXPIRED_CARD;
	}

	else if (currentYear == expiryYear && currentmonth > expmonth)
	{
		return EXPIRED_CARD;
	}
	else
		return TERM_OK;
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	float amount;
	printf("Please enter the transaction amount\n");
	scanf("%f",&amount);
	if (amount == 0 || amount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		(termData->transAmount) = amount;
		return TERM_OK;
	}
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{

		return EXCEED_MAX_AMOUNT;
	}
	else
		return TERM_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	float max_amount;
	printf("Please enter max amount\n");
	scanf("%f", &max_amount);
	if (max_amount = NULL || max_amount < 0) {
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = max_amount;
		return TERM_OK;

	}
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{

}