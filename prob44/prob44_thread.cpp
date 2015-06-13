#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <map>
#include <utility>

struct pair
{
	int j;
	int k;
};

long long pent(int i)
{
	return ((i*((3*i)-1))/2);
}

bool check_sum(std::vector<long long>& pents, std::multimap<long long, pair>& sums, std::vector<pair>& matches)
{
	bool result = false;
	auto range = sums.equal_range(pents.back());
	for(auto it = range.first; it != range.second; ++it)
	{
		matches.push_back(it->second);
		result = true;
	}
	return result;
}

bool check_sub(std::vector<long long>& pents, std::vector<pair>& sum_matches, std::vector<pair>& matches)
{
	bool result = false;
	for(int i = 0; i < sum_matches.size(); i += 1)
	{
		int j = sum_matches[i].j;
		int k = sum_matches[i].k;

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
				matches.push_back(sum_matches[i]);
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

void calc_sums(std::vector<long long>& pents, std::multimap<long long, pair>& sums)
{
	long long new_pent = pents.back();
	long long sum = 0;
	for(int i = 0; i < pents.size()-1; i++)
	{
		sum = new_pent + pents[i];
		pair tmp = {i , pents.size()-1};
		sums.emplace(sum, tmp);
	}
}

void clear_map(std::vector<long long>& pents, std::multimap<long long, pair>& sums)
{
	long long high = pents.back();
	auto end_it = sums.upper_bound(high);
	sums.erase(sums.begin(), end_it);
}

int main()
{
	long long d;
	std::vector<long long> pents;
	std::multimap<long long, pair> sums = {{3, {1, 2}}};
	std::vector<pair> sum_matches;
	std::vector<pair> final_matches;

	pents.push_back(pent(1));
	pents.push_back(pent(2));
	for(int i = 3; i < 1000000; i++)
	{
		pents.push_back(pent(i));
		printf("New pent: %lld\n", pents.back());
		if(pent(i) == 8602840) {
			printf("Dumb!!!\n");
		}
		calc_sums(pents, sums);
		if(check_sum(pents, sums, sum_matches))
		{
			printf("Potential solution: P%d\n", i);
			printf("Sum matches size: %ld\n", sum_matches.size());
			if(check_sub(pents, sum_matches, final_matches))
			{
				printf("A solution found\n");
				for(int i = 0; i < final_matches.size(); i++)
				{
					pair tmp = final_matches[i];
					if(d == 0 || pents[tmp.k] - pents[tmp.j] < d)
						d = pents[tmp.k] - pents[tmp.j];
				}
				break;
			}
			else
			{
				sum_matches.clear();
			}
		}
		if(i%1000 == 0)
		{
			clear_map(pents, sums);
		}
	}

	printf("D: %lld\n", d);
	return 0;
}