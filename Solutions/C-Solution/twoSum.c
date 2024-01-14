#include <stdlib.h>
#include <stdio.h>

/**
 * twoSum - Find indices of two numbers in the array that add up to the target.
 * @nums: Pointer to the given array of integers.
 * @numsSize: Number of elements in nums.
 * @target: Specified target sum.
 * @returnSize: Pointer to an integer where the size of the result array is
 *              stored.
 *
 * Return: An array of two integers representing indices of the two numbers
 *          that add up to the target.
 *         If no solution is found, returns NULL.
 *         The returned array must be freed by the caller.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int i, j, *result;

	result = malloc(2 * sizeof(int));
	if (!result)
		return (NULL);

	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize; j++)
		{
			/* Check if the the sum of nums[i] & nums[j] == target */
			/*	and isn't on the same index */
			if (i != j && nums[i] + nums[j] == target)
			{
				result[0] = i; /* Store the index of the first number */
				result[1] = j; /* Store the index of the second number */
				*returnSize = 2; /* Set returnSize to 2 */


				return (result);
			}
		}
	}

	/* If no solution is found, return NULL */
	return (NULL);
}


/* ============================== Test Case ============================== */

/**
 * main - Entry point of the program, contains a test case for the twoSum
 *        function.
 *
 * Return: 0 on successful execution.
 */
int main(void)
{
	int nums[] = {2, 7, 11, 15};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize;

	int *result = twoSum(nums, numsSize, target, &returnSize);

	if (result)
	{
		/* Print the indices of the two numbers */
		printf("Indices: [%d, %d]\n", result[0], result[1]);

		/* Free the allocated memory */
		free(result);
	}
	else
		printf("No solution found.\n");

	return (0);
}
