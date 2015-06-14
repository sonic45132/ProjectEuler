#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

bool isPalindrome(int number)
{
	std::string num = std::to_string(number);
	int size = num.size();
	for(int i = 0; i <= size/2; i++)
	{
		if(num[i] != num[(size-1)-i])
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	int pal = 0;
	for(int i = 1; i < 999; i++)
	{
		for(int j = i+1; j < 1000; j++)
		{
			int prod = i * j;
			if(isPalindrome(prod))
			{
				if(prod > pal)
				{
					pal = prod;
				}
			}
		}
	}
	printf("Palindrome: %d\n", pal);
	return 0;
}