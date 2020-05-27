#pragma once

#include <array>
#include <utility>
#include <cstdint>


using FibType = uint64_t;
//constexpr const int MAX_FIB = 47; // maximum on uint32_t
constexpr const int MAX_FIB = 93; // maximum on uint64_t
constexpr const bool BenchmarkEnabled = true;


template<int I>
struct Fib {
	static const FibType val = Fib<I - 1>::val + Fib<I - 2>::val;
};

template<>
struct Fib<0> {
	static const FibType val = 0;
};

template<>
struct Fib<1> {
	static const FibType val = 1;
};

template<size_t ... I>
constexpr FibType fib_impl(std::index_sequence<I...>, const int i) {
	constexpr std::array<FibType, sizeof...(I)> a
		= { Fib<I>::val... };
	return a[i];
}

constexpr FibType fib_tmp(const int i) {
	return fib_impl(std::make_index_sequence<MAX_FIB>(), i);
}
