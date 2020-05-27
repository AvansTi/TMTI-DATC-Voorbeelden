#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "StopWatch.h"
#include "Fibonacci.h"
#include <functional>
#include <random>
#include <algorithm>
#include "constexprMath.h"




// Standard recursive version
constexpr auto fib_rec(unsigned int n) -> FibType {
	if (n <= 1) return n;

	return fib_rec(n - 1) + fib_rec(n - 2);
}


FibType fib_mem1(const unsigned int n, std::vector<FibType>& mem) {
	if (n <= 1) return n;

	if (mem[n] != 0)
		return mem[n];
	const FibType result = fib_mem1(n - 1, mem) + fib_mem1(n - 2, mem);
	mem[n] = result;
	return result;
}

FibType fib_mem(unsigned int n) {
	std::vector<FibType> memorize(MAX_FIB+1);

	return fib_mem1(n, memorize);
}

FibType fib_binet(int i) {
	if (i <= 1) return i;

	static auto sqrt_5 = sqrt(5.0);
	return static_cast<FibType>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i)) / (std::pow(2, i) * sqrt_5));
}


// Tail recursion approach
constexpr FibType nFibRecursiveAcc(int n, FibType acc = 0, FibType prev = 1) {
	if (n == 0) return acc;
	if (n == 1) return prev;

	return nFibRecursiveAcc(n - 1, prev, acc + prev);
}


// Button-up approach
FibType fib_bottomUp(int n) {

	if (n <= 1) return n;

	std::vector<FibType> bottom_up( n + 1 );
	bottom_up[1] = 1;
	bottom_up[2] = 1;

	for (int i = 3; i <= n; i++) {
		bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2];
	}

	return bottom_up[n];
}


#pragma optimize( "", off )
template<typename Functor>
void benchmark(Functor function, std::array<int, 10000> arr) {

	if (!BenchmarkEnabled)
		return;


	StopWatch sw;
	FibType result = 0;
	for (int i = 0; i < 10000; i++) {
		result += function(arr[i])/10000;
		//std::cout << result << ", ";
	}
	std::cout << result << '\n';
}
#pragma optimize( "", on )


int main() {


	std::cout << "Enter a number: ";
	unsigned int fib_n = 46;
	std::string tmp;
	std::cin >> tmp;
	fib_n = std::stoi(tmp);

	// Initialize random numbers
	std::random_device rnd;  // a source of machine-wide entropy
	std::default_random_engine eng(rnd()); // use it to initialise the psuedo-random engine

	std::array<int, 10000> arr;
	std::uniform_int_distribution<int> uid1(0, MAX_FIB);



	std::generate(arr.begin(), arr.end(), [&] {
		return uid1(eng);
	});


	FibType result = 0;
	double execTime = 0.0;

	{
		auto lambda = [](int n) {return fib_rec(n); };
		//benchmark(lambda, arr);

		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Resursive fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us\n\n";

	{
		auto lambda = [](int n) {return nFibRecursiveAcc(n); };
		benchmark(lambda, arr);
		
		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Tail call optimisation fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us\n\n";

	{
		auto lambda = [](int n) {return fib_mem(n); };
		benchmark(lambda, arr);

		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Memorize fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us\n\n";

	{
		auto lambda = [](int n) {return fib_bottomUp(n); };
		benchmark(lambda, arr);

		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Bottom-up fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us \n\n";

	{
		auto lambda = [](int n) {return fib_binet(n); };
		benchmark(lambda, arr);

		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Binet Fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us\n\n";

	{
		auto lambda = [](int n) {return fib_tmp(n); };
		benchmark(lambda, arr);

		StopWatch sw(false);
		result = lambda(fib_n);
		execTime = sw.stop();
	}
	std::cout << "Template Metaprogramming Fibonacci of " << fib_n << ": " << result << '\n';
	std::cout << "Execution time " << execTime << " us\n\n";
	
	std::cin >> tmp;
	return 0;
}