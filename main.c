#include <stdio.h>
#include <stdlib.h>
typedef int int32_t;
typedef unsigned char uint8_t;


int32_t** dpst_Maxsum = NULL;

int32_t maxCoins(int32_t* nums, int32_t numsSize) {
	int32_t* ars32_numsCopy = (int32_t*)malloc(sizeof(int32_t) * (numsSize + 2));
	int32_t s32_I_left = 0, s32_I_Right=0, s32_Diff = 0, s32_I_Intrest = 0, s32_Maxnum = 0;
	
	if (numsSize == 0)
	{
		return 0;
	}
	else if (numsSize == 1)
	{
		return nums[0];
	}
	else if (numsSize == 2)
	{
		if (nums[0] < nums[1])
		{
			return nums[0] * nums[1] + nums[1];
		}
		else
		{
			return nums[0] * nums[1] + nums[0];
		}
	}
	else
	{
		;
	}
	dpst_Maxsum = (int32_t**)malloc(sizeof(int32_t*) * (numsSize+2));
	memcpy(&(ars32_numsCopy[1]), nums, sizeof(int32_t) * numsSize);
	ars32_numsCopy[0] = 1;
	ars32_numsCopy[numsSize + 1] = 1;
	
	for (int32_t s32_I_row = 0; s32_I_row < numsSize+2; s32_I_row++)
	{
		dpst_Maxsum[s32_I_row] = (int32_t*)malloc(sizeof(int32_t) * (numsSize+2));
		memset(dpst_Maxsum[s32_I_row], 0, sizeof(int32_t) * (numsSize + 2));
	}


	for (s32_Diff = 2; s32_Diff < numsSize+2; s32_Diff++)
	{
		s32_I_left = 0;

		while (1)
		{	
			s32_Maxnum = 0;
			s32_I_Right = s32_I_left + s32_Diff;
			if (s32_I_Right > numsSize + 1)
			{
				break;
			}

			for (s32_I_Intrest = s32_I_left + 1; s32_I_Intrest < s32_I_Right; s32_I_Intrest++)
			{
				dpst_Maxsum[s32_I_left][s32_I_Right]
					= ars32_numsCopy[s32_I_left] * ars32_numsCopy[s32_I_Intrest] * ars32_numsCopy[s32_I_Right]
					+ dpst_Maxsum[s32_I_left][s32_I_Intrest] + dpst_Maxsum[s32_I_Intrest][s32_I_Right];
				if (dpst_Maxsum[s32_I_left][s32_I_Right] >= s32_Maxnum)
				{
					s32_Maxnum = dpst_Maxsum[s32_I_left][s32_I_Right];
				}
			}
			dpst_Maxsum[s32_I_left][s32_I_Right] = s32_Maxnum;

			s32_I_left++;
		}
	}

	return dpst_Maxsum[0][numsSize+1];
}

void main()
{
	int32_t ars32_Balloons[4] = {3,1,5,8};
	printf("Result: %d\n", maxCoins(ars32_Balloons, 4));
}