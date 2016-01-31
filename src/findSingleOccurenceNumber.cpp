/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<iostream>

int findSingleOccurenceNumber(int *A, int len) {
	int i, once=0, twice=0,common=0;
	if (A == NULL)
		return -1;
	for (i = 0; i < len; i++)
	{
		twice |= once & A[i];
		once ^= A[i];
		common = ~(once & twice);
		once &= common;
		twice &= common;
	}
	return once;
}