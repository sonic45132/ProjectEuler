#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

// int collatz(int num)
// {
// 	if(num == 1)
// 		return 1;

// 	if(num%2==0)
// 		return (1 + collatz((num/2)));
// 	else
// 		return (1 + collatz(((3 * num) + 1)));
// }

int main() 
{
	int longchain = 0;
	int number = 0;
	int tmp = 1;
	long long collatz = 0;
	for(int i = 999999; i > 0; i--)
	{
		//printf("Curr: %d\n", i);
		collatz = i;
		while(collatz > 1)
		{
			if(collatz%2==0)
				collatz = (collatz/2);
			else
				collatz = ((collatz*3)+1);

			tmp++;
		}
		//printf("chain: %d\n\n", tmp);
		if(tmp > longchain)
		{
			//printf("longest: %d\n", tmp);
			longchain = tmp;
			number = i;
		}

		tmp = 1;
	}


	printf("Number: %d\n", number);
	return 0;
}