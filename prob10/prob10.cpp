#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>

bool is_prime(long long num)
{
	if(num == 2)
		return true;
	else if(num % 2 == 0)
		return false;

	for(long long i = 3; i <= sqrt(num); i += 2)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long sum = 2;
	long long i = 3;
	while(i < 2000000) 
	{
		if(is_prime(i))
		{
			sum += i;
			//printf("Count: %d\n", count);
			//printf("Prime: %lld\n\n", i);
		}

		i += 2;
	}

	printf("Sum: %lld\n", sum);
	return 0;
}