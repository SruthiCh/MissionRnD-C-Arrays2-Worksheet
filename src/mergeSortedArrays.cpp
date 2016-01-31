/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
}output;

int compare(char*date1, char*date2)
{
	int value1 = 0, value2 = 0, i;
	for (i = 6; i < 10; i++)
	{
		value1 = (value1 * 10) + (date1[i] - '0');
		value2 = (value2 * 10) + (date2[i] - '0');
	}
	if (value1 < value2) return 0;
	else if (value1 > value2) return 2;
	else
	{
		value1 = ((date1[3] - '0') * 10) + (date1[4] - '0');
		value2 = ((date2[3] - '0') * 10) + (date2[4] - '0');
		if (value1 < value2) return 0;
		else if (value1 > value2) return 2;
		else
		{
			value1 = ((date1[0] - '0') * 10) + (date1[1] - '0');
			value2 = ((date2[0] - '0') * 10) + (date2[1] - '0');
			if (value1 < value2) return 0;
			else if (value1 > value2) return 2;
			else return 1;
		}
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i=0, j=0, k=-1;
	if(A==NULL||B==NULL)
	  return NULL;
	struct transaction *newArray = (struct transaction*) malloc((ALen + BLen)*sizeof(struct transaction));
	while(i < ALen && j < BLen)
	{
		if (compare(A[i].date, B[j].date) <= 1)
			newArray[++k] = A[i++];
		else
			newArray[++k] = B[j++];
	}
	if (i == ALen && j != BLen)
		while (j < BLen)
			newArray[++k] = B[j++];
	else if (j == BLen&&i != ALen)
		while (i < ALen)
			newArray[++k] = A[i++];
	return newArray;
}