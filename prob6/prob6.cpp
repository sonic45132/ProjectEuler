#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

int main() 
{
	long long squareSum = 0;
	long long sumSquare = 0;
	for(int i = 1; i <= 100; i++)
	{
		squareSum += (i*i);
		sumSquare += i;
	}
	sumSquare = sumSquare * sumSquare;

	long long diff = sumSquare - squareSum;

	printf("sumSquare: %lld\n", sumSquare);
	printf("squareSum: %lld\n", squareSum);
	printf("Diff: %lld\n", diff);
	return 0;
}