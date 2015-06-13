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
	int count = 1;
	long long i = 3;
	while(count < 10001) 
	{
		if(is_prime(i))
		{
			count++;
			//printf("Count: %d\n", count);
			//printf("Prime: %lld\n\n", i);
		}

		i += 2;
	}

	printf("10001st prime: %lld\n", i-2);
	return 0;
}