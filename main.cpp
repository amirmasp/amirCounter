#include "counter.cpp"
#include <thread>
#include <chrono>

int main() { 
   using namespace std::literals::chrono_literals;

   // Patameter n is tunable
   long long int n = 300000000 ;

   // Allocating heap memory
   int* number = new int();

   // var number will be incremented from countFunc 
   *number = 0;

   auto start = std::chrono::high_resolution_clock::now();
  
   // countFunc() is embedded inside counter.cpp
   std::thread t2(countFunc, number, n);

   // Seconds are tunable.
   // main thread sleeps for 1 second
   // while thread t2 is working on .
   std::this_thread::sleep_for(1s);
   
   // Concurrency
   // Thread t2 joins to thread t1 after 1 second. 
   // t1 is the main thread
   t2.join();
  
   auto end = std::chrono::high_resolution_clock::now();

   // Calculates time
   std::chrono::duration<float> duration = end - start;

   // Print
   std::cout << duration.count() << "s " << std::endl;
   std::cout << "TM M counted " << *number; 
	std::cout << " times in " << duration.count() << " second\n";

   // Deallocating memory
   delete[] number;

	return 0;
}










