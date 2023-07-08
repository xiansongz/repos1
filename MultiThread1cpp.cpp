
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

using std::istringstream;
using std::string;
using std::cout;

// Driver Code
float sub1(int n)
{
	int i;
	float sum = 0;
	for (i = 0; i < n; i++) {
		sum += i * i;
	}
	return sum;
}
int main22()
{
    auto start = std::chrono::high_resolution_clock::now();
	
	int n=1000, i, i0,i1,i2;
	cout << "enter i " << n << "\n";
	std::cin >> i1;
	n *= i1;
	float sum = sub1(n);	
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate the duration in milliseconds
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	// Print the runtime
	std::cout << "Elapsed time123: " << duration << " milliseconds" << std::endl;

	cout << "sum77777= " << sum << "n= "  << n << "\n";
	std::cin >> i1;
    return 0;
}


// Function to be executed by each thread
DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    int threadId = reinterpret_cast<int>(lpParam);
    std::cout << "Thread " << threadId << " is running" << std::endl;

    // Perform some work...

    std::cout << "Thread " << threadId << " is exiting" << std::endl;

    return 0;
}
 
int main() {
    const int numThreads = 3;
    HANDLE threads[numThreads];

    // Create multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = CreateThread(NULL, 0, ThreadFunction, reinterpret_cast<LPVOID>(i), 0, NULL);
        if (threads[i] == NULL) {
            std::cerr << "Failed to create thread " << i << std::endl;
            return 1;
        }
    }

    // Wait for all threads to finish
    WaitForMultipleObjects(numThreads, threads, TRUE, INFINITE);

    // Close thread handles
    for (int i = 0; i < numThreads; ++i) {
        CloseHandle(threads[i]);
    }

    return 0;
}

