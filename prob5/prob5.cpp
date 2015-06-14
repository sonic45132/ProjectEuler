#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

int main() 
{
	long long num = 20;
	bool multiple = true;
	while(num < 300000000000000)
	{
		for(int i = 2; i < 20; i++)
		{
			if((num % i) != 0)
			{
				multiple = false;
			}
		}
		if(multiple)
		{
			break;
		}
		num += 20;
		multiple = true;
	}

	printf("Smallest multiple: %lld\n", num);
	return 0;
}