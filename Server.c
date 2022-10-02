#include "Terminal.h"
#include"card.h"
#include"Server.h"


uint8_t target = 0;

ST_accountsDB_t  database[255] = 
{ 
	{5000, "1234 1234 1234 1234"},
	{6000, "1234 5678 9123 4567"},
	{7000, "1221 2334 4556 7889"}
};
ST_transaction_t transDB[255] = { 0 };

void fillDB(ST_transaction_t* transDB, uint32_t size)
{
	uint32_t i = 0;
	for (i = 0; i < size; i++)
	{
		strcpy(transDB[i].cardHolderData.cardExpirationDate, "000");
		strcpy(transDB[i].cardHolderData.cardHolderName, "000");
		strcpy(transDB[i].cardHolderData.primaryAccountNumber, "000");

		strcpy(transDB[i].terminalData.transactionDate, "000");

		transDB[i].terminalData.maxTransAmount = 0;
		transDB[i].terminalData.transAmount = 0;

		transDB[i].transactionSequenceNumber = 0;
		transDB[i].transState = 0;
	}
}


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{

	uint8_t isValidCard;
	uint8_t isValidAmount;
	uint8_t Saved;
	
	isValidCard = isValidAccount(&(transData->cardHolderData));
	isValidAmount = isAmountAvailable(&(transData->terminalData));

	if (isValidCard == ACCOUNT_NOT_FOUND)
	{
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}

	if (isValidAmount == LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;

		return DECLINED_INSUFFECIENT_FUND;
	}

	else
	{
		transData->transState = APPROVED;
	}

	Saved = saveTransaction(&transData);
	if (Saved == SAVING_FAILED)
	{
		transData->transState = INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;

	} 
	database[target].balance -= transData->terminalData.transAmount;
	return APPROVED;

	
	
	
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	uint8_t result;
	for (int i = 0; i < 255; i++)
	{
		 result = strcmp(cardData->primaryAccountNumber, database[i].primaryAccountNumber);

		 if (result == 0)
		 {
			 target = i;
			 return Server_OK;
		 }

		 else 
		 {
			 continue;
		 }
			
		 
	}//end loop
		return DECLINED_STOLEN_CARD;
		
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{

	if (termData->transAmount < database[target].balance)
	{
		return LOW_BALANCE;
	}

	else
	{
		return Server_OK;
	}
		

}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{

	
	if (sequence >= 255)
	{
		return SAVING_FAILED;
	}
	else
	{
		transDB[sequence].transactionSequenceNumber = sequence;
		transDB[sequence].cardHolderData = transData->cardHolderData;
		transDB[sequence].terminalData = transData->terminalData;
		transData->transactionSequenceNumber = sequence;
		transDB[sequence].transState = transData->transState;

		sequence++;

		return Server_OK;
	}

	
}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData) 
{

}