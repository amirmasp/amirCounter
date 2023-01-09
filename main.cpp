#include "counter.cpp"
#include <thread>
#include <chrono>

int main() { 
   using namespace std::literals::chrono_literals;

   // Patameter n is tunable
   long long int n = 300000000 ;

   // number will be incremented from countFunc on thread t2
   int* number = new int();
   *number = 0;

   auto start = std::chrono::high_resolution_clock::now();
  
   // countFunc() is implemented inside counter.cpp
   std::thread t2(countFunc, number, n);

   // Seconds are tunable
   std::this_thread::sleep_for(1s);
   
   // Concurrency: thread t2 joins thread t1. Thread t1 is main thread
   t2.join();
  
   auto end = std::chrono::high_resolution_clock::now();

   // Calculate time
   std::chrono::duration<float> duration = end - start;
   std::cout << duration.count() << "s " << std::endl;
   std::cout << "TM M counted " << *number; 
	std::cout << " times in " << duration.count() << " second\n";

   delete[] number;

	return 0;
}










