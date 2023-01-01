#include <iostream>

void countFunc(int* ptrToInt, size_t times) {  	
    // The thread t1 increments an integer n times
 	while(times > 0) {
		*ptrToInt += 1;
    times-- ;
	} 
}