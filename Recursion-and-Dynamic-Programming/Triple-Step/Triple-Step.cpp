#include<iostream>
#include"time.h"
#include"assert.h"

// This can be solved in many ways. i have coded for 3 different ways

// recursive (top down). This ususally have exponential time complexity
int triple_step_recur(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	return (triple_step_recur(n - 1) + triple_step_recur(n - 2) + triple_step_recur(n - 3));
}

// recursive (top down) with caching. caching reduces runtime to linear time
int triple_step_recur_memo(int n, int*& cache)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (cache[n] == 0)
	{
		cache[n] = (triple_step_recur_memo((n - 1), cache)
			+ triple_step_recur_memo((n - 2), cache)
			+ triple_step_recur_memo((n - 3), cache));
	}
	return cache[n];
}

// using bottom up approach. this looks clearly to be O(n)
int triple_step_bottom_up(int n)
{
	int* cache = new int[n + 1]();
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	for (int i = 4; i <= n; ++i)
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
	return cache[n];
}

int main()
{
	clock_t t1, t2;
	int n = 30;
	t1 = clock();
	std::cout << "\n Num ways = " << triple_step_recur(n);
	t2 = clock();
	std::cout << "\n Time taken by recursive approach is : " << (t2 - t1)<<"s";
	int* cache = new int[n+1]();
	t1 = clock();
	std::cout << "\n Num ways memo = " << triple_step_recur_memo(n,cache);
	t2 = clock();
	std::cout << "\n Time taken by recursive approach with memoization is : " << (t2 - t1) << "s";
	t1 = clock();
	std::cout << "\n Num ways memo = " << triple_step_bottom_up(n);
	t2 = clock();
	std::cout << "\n Time taken by bottom up approach is : " << (t2 - t1) << "s";
	return 0;
}