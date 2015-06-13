#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int sum = 0;
	int fib_old = 1;
	int fib = 1;
	int tmp = 0;

	while(fib < 4000000)
	{
		tmp = fib;
		fib += fib_old;
		fib_old = tmp;

		if(fib % 2 == 0)
			sum += fib;
	}

	printf("Sum: %d\n", sum);
}