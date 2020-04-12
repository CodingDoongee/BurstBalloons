#include <stdio.h>
#include <stdlib.h>

typedef int int32_t;
typedef unsigned char uint8_t;

int dpars32_solutionBook[23000][40] = { 0 };

int ListCmp(int* nums, int numsSize, int* pars32_solutionBook)
{
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != pars32_solutionBook[i])
		{
			return 0;
		}
	}
	return 1;
}

int RecurMaxCoins(int* parr32_List, int numsSize, int dpars32_solutionBook[23000][40], int* ps32_numSolutions)
{
	int s32_RetVal = 0, s32_MaxVal = 0, NumNewListMember = 0;
	//int* ars32_NewList = (int*)malloc(sizeof(int)*(numsSize-1));
	int ars32_NewList[40] = { 0 };

	if (numsSize == 0)
	{
		return 0;
	}
	else if (numsSize == 1)
	{
		return parr32_List[0];
	}
	else
	{
		for (int i = 0; i < *ps32_numSolutions; i++)
		{
			if (ListCmp(parr32_List, numsSize, dpars32_solutionBook[i]))
			{
				return dpars32_solutionBook[i][numsSize];
			}
			else
			{
				;
			}
		}
	}
	memset(ars32_NewList, 0, sizeof(int) * (numsSize - 1));
	for (int i = 0; i < numsSize; i++)
	{
		NumNewListMember = 0;
		for (int j = 0; j < numsSize; j++)
		{
			if (j != i)
			{
				ars32_NewList[NumNewListMember] = parr32_List[j];
				NumNewListMember++;
			}
			else
			{
				continue;
			}
		}

		if (i == 0)
		{
			s32_RetVal = (parr32_List[0] * parr32_List[1] + RecurMaxCoins(ars32_NewList, numsSize - 1, dpars32_solutionBook, ps32_numSolutions));
		}
		else if (i == numsSize - 1)
		{
			s32_RetVal = (parr32_List[numsSize - 2] * parr32_List[numsSize - 1] + RecurMaxCoins(ars32_NewList, numsSize - 1, dpars32_solutionBook, ps32_numSolutions));
		}
		else
		{
			s32_RetVal = (parr32_List[i - 1] * parr32_List[i] * parr32_List[i + 1] + RecurMaxCoins(ars32_NewList, numsSize - 1, dpars32_solutionBook, ps32_numSolutions));
		}
		if (s32_RetVal > s32_MaxVal)
		{
			s32_MaxVal = s32_RetVal;
		}
	}

	//dpars32_solutionBook[*ps32_numSolutions] = malloc(sizeof(int)*(numsSize + 1));
	memcpy(dpars32_solutionBook[*ps32_numSolutions], parr32_List, sizeof(int) * numsSize);
	dpars32_solutionBook[*ps32_numSolutions][numsSize] = s32_MaxVal;
	(*ps32_numSolutions)++;

	//free(ars32_NewList);

	return s32_MaxVal;
}

unsigned int Factorial(int num)
{
	unsigned int retVal = 1;
	for (int i = 2; i < num + 1; i++)
	{
		retVal = retVal * i;
	}
	return retVal;
}


int maxCoins(int* nums, int numsSize)
{
	//int** dpars32_solutionBook = NULL;
	
	int s32_MaxVal = 0, s32_NumSolution = 0;
	int* OrganizedNumsTemp = NULL;
	int* OrganizedNums = NULL;
	int OrganizedNumsSize = 0;
	OrganizedNumsTemp = (int*)malloc(sizeof(int) * numsSize);

	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == 0)
		{
			continue;
		}
		else
		{
			OrganizedNumsTemp[OrganizedNumsSize] = nums[i];
			OrganizedNumsSize++;
		}
	}
	OrganizedNums = (int*)malloc(sizeof(int) * OrganizedNumsSize);
	memcpy(OrganizedNums, OrganizedNumsTemp, sizeof(int) * OrganizedNumsSize);
	//dpars32_solutionBook = (int**)malloc(sizeof(int*)*23000);

	s32_MaxVal = RecurMaxCoins(OrganizedNums, OrganizedNumsSize, dpars32_solutionBook, &s32_NumSolution);

	free(OrganizedNumsTemp);
	free(OrganizedNums);
	//free(dpars32_solutionBook);

	return s32_MaxVal;
}

void main()
{
	int32_t ars32_Balloons[4] = { 3,1,5,8 };
	printf("Result: %d\n", maxCoins(ars32_Balloons, 4));
}