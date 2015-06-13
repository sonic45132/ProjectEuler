#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int sum = 0;
	int input = 0;
	scanf("%d", &input);
	
	for(int i  = 0; i < input; i++) 
	{
		if((i % 5 == 0) || (i % 3 == 0))
		{
			sum += i;
		}
	}

	printf("Sum for %d: %d\n", input, sum);
}