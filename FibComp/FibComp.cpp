/*
 * FibComp.cpp
 *
 * Compares the times for recursive and iterative Fibonacci solutions.
 * Writes times for Fib(n) to fib_times.dat
 *
 *  Created on: Jun 26, 2019
 *      Author: alex
 */

#include <iostream>
#include <fstream>
#include <ctime>
using std::cout; using std::cin;

// Iterative Fibonacci solution
unsigned long long fib_iter(int n) {

	// Keep track of Fib(i-2), Fib(i-1), Fib(i)
	unsigned long long past, prev, curr;
	past = prev = curr = 1;

	// Calculate Fib(i)
	for (int i = 3; i <= n; ++i) {
		past = prev;
		prev = curr;
		curr = past + prev;
	}

	// Return Fib(n)
	return curr;

}

// Standard recursive Fibonacci solution
unsigned long long fib_recur(int n) {

	// Base case
	if (n == 1 || n == 0) return 1;

	// Return Fib(n)
	return fib_recur(n-1) + fib_recur(n-2);

}

// Driver for comparison.
// Theoretically, an unsigned long long can fit up to Fib(93)
// The recursive version begins to take inordinate amounts of time around Fib(40)
int main() {

	// Compare times to calculate up to Fib(MAX_FIB) and open (tab-separated) file
	const int MAX_FIB = 93;
	std::ofstream file;
	file.open("fib_times.dat");
	file << "Iterative" << "\t" << "Recursive" << std::endl;

	// Time Fib(1) to Fib(MAX_FIB)
	for (int i = 1; i <= MAX_FIB; ++i) {

		clock_t start = clock();
		fib_iter(i);
		double total_iter_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

		start = clock();
		fib_recur(i);
		double total_recur_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

		// Print (tab-separated) values to file
		file << total_iter_time << "\t" << total_recur_time << std::endl;

		cout << "Iterative Fibonacci takes " << total_iter_time << " s to calculate F(" << i << ")\n";
		cout << "Recursive Fibonacci takes " << total_recur_time << " s to calculate F(" << i << ")\n";
		cout << "\n";

	};

}
