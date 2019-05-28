#include <iostream>
#include <vector>
#include "StopWatch.h"
#include "Fibonacci.h"


using namespace std;
const int MAX_FIB = 46; // maximum on int32

// Standard recursive version
static int fib_rec(unsigned int n) {
	if (n == 0)
		return 0;
	if (n <= 1) 
		return 1;
	return fib_rec(n - 1) + fib_rec(n - 2);
}


static unsigned int fib_mem1(const unsigned int n, vector<int>& mem) {
	if (n == 0)
		return 0;
	if (n <= 1)
		return 1;
	if (mem.at(n) != 0)
		return mem.at(n);
	const int result = fib_mem1(n - 1, mem) + fib_mem1(n - 2, mem);
	mem.at(n) = result;
	return result;
}

static unsigned int fib_mem(unsigned int n) {
	vector<int> memorize(MAX_FIB);

	return fib_mem1(n, memorize);
}

static unsigned int nFibRecursiveAcc(unsigned int n, unsigned int a, unsigned int b) {
	if (n <= 1)
		return a;
	return nFibRecursiveAcc(n - 1, b, a + b + 1);
}

static unsigned long nFibRecursive2(int n) {
 	return nFibRecursiveAcc(n, 1, 1);
}

static int fib_bottomUp(int n) {
	if (n <= 1)
		return 1;
	vector<int> bottom_up(n + 1);
	bottom_up.at(1) = 1;
	bottom_up.at(2) = 1;

	for (int i = 3; i <= n; i++) {
		bottom_up.at(i) = bottom_up.at(i - 1) + bottom_up.at(i - 2);
	}

	return bottom_up.at(n);
}


int main() {

	const unsigned int fib_n = 45;

	StopWatch sw;

	{
		sw.start();
		int result = fib_rec(fib_n);
		sw.stop();
		cout << "Resursive fibonacci of " << fib_n << ": " << result << endl;
		cout << "Execution time: " << sw.getElapsedTime() << " ms\n";
	}

	{
		sw.start();
		int result = fib_mem(fib_n);
		sw.stop();
		cout << "Memorize fibonacci of " << fib_n << ": " << result << endl;
		cout << "Execution time: " << sw.getElapsedTime() << " ms\n";
	}

	{
		sw.start();
		int result = fib_bottomUp(fib_n);
		sw.stop();
		cout << "Bottom-up fibonacci of " << fib_n << ": " << result << endl;
		cout << "Execution time: " << sw.getElapsedTime() << " ms\n";	
	}

	{
		sw.start();
		int result = fib_tmp(fib_n);
		sw.stop();
		cout << "Template Metaprogramming Fibonacci of " << fib_n << ": " << result << endl;
		cout << "Execution time: " << sw.getElapsedTime() << " ms\n";
	}
	

	cin.get();
	return 0;
}