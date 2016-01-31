/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int check(char*date1, char*date2)
{
	int value1 = 0, value2 = 0,i;
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int low = 0, high = len, mid, i,flag1,flag2;
	flag1 = check(Arr[0].date, date);
	if (flag1 == 2) return len;
	flag1 = check(Arr[len-1].date, date);
	if (flag1 == 2)
	{
		while (low <= high)
		{
			mid = (low + high) / 2;
			flag1 = check(Arr[mid].date, date);
			if (flag1 == 2)
			{
				flag2 = check(Arr[mid - 1].date, date);
				if (flag2 != 2) return len - mid;
				else high = mid;
			}
			else
				low = mid;
		}
	}
	else return 0;
}
