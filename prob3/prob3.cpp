#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>

bool is_prime(long long num)
{
	if(num % 2 == 0)
		return false;

	for(long long i = 3; i < sqrt(num); i += 2)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}

void factor(long long in, std::vector<long long>& factors)
{
	long long new_num = 0;

	if(is_prime(in))
	{
		factors.push_back(in);
		return;
	}

	for(long long i = 2; i < sqrt(in); i++) 
	{
		if(is_prime(i)) 
		{
			if(in%i == 0) 
			{
				new_num = in/i;
				factors.push_back(i);
				factor(new_num, factors);
				break;
			}
		}
	}
}

int main() 
{
	long long input = 600851475143;
	std::vector<long long> factors;

	factor(input, factors);

	std::sort(factors.begin(), factors.end());
	printf("Largest factor: %lld\n", factors.back());
	for(std::vector<long long>::size_type i = 0; i != factors.size(); i++)
	{
		printf("%lld\n", factors[i]);
	}

}