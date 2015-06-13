#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <utility>

long long pent(int i)
{
	return ((i*((3*i)-1))/2);
}

bool check_sum(std::vector<long long>& pents, std::vector<int>& matches)
{
	bool result = false;
	long long sum = pents.back();
	for(int left = 0; left < pents.size()-2; left++)
	{
		for(int right = left+1; right < pents.size()-1; right++)
		{
			if(pents.at(left) + pents.at(right) == sum) 
			{
				result = true;
				matches.push_back(left);
				matches.push_back(right);
			}
		}
	}
	return result;
}

bool check_sub(std::vector<long long>& pents, std::vector<int>& sum_matches, std::vector<int>& matches)
{
	bool result = false;
	for(int i = 0; i < sum_matches.size(); i += 2)
	{
		int j = sum_matches[i];
		int k = sum_matches[i+1];
		long long diff = pents[k] - pents[j];

		int min = 0;
		int max = pents.size()-1;
		int mid = 0;
		while(true)
		{
			mid = (max+min)/2;
			if(diff == pents[mid])
			{
				result = true;
				matches.push_back(j);
				matches.push_back(k);
				break;
			}
			else if(diff < pents[mid]) 
				max = mid-1;
			else
				min = mid+1;

			if((min == max) || (min - max == 1))
				break;

		}

	}
	return result;
}

int main()
{
	long long d;
	std::vector<long long> pents;
	std::vector<int> sum_matches;
	std::vector<int> final_matches;
	pents.push_back(pent(1));
	pents.push_back(pent(2));
	for(int i = 3; i < 1000000; i++)
	{
		pents.push_back(pent(i));
		printf("New pent: %lld\n", pents.back());
		if(check_sum(pents, sum_matches))
		{
			printf("Potential solution: P%d\n", i);
			printf("Sum matches size: %ld\n", sum_matches.size());
			if(check_sub(pents, sum_matches, final_matches))
			{
				printf("A solution found\n");
				break;
			}
			else
			{
				sum_matches.clear();
			}
		}
	}

	printf("D: %lld\n", d);
	return 0;
}