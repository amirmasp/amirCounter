# Experiment : HOW Fast Would You Count Up? 
## Problem
How many times your TM (your personal Computer) can 
count in a limited time (Assume for 1 Second)?

## Answer
The main executable counts approximately 600 million times
in a 2nd thread! (1st thread is the Main thread):
"TM Main counted 600000000 times in 1.0003 second!"
#### Note 0: Human being can count up to 10 in the same amount of time!    

## Instruction to run the program
`$ g++ main.cpp -o main -pthread -std=c++14`

`$ ./main`

  

## Compilation Process
Compiation flow chart:
```mermaid
graph TD;
    Preprocessor-->Compiler;
    Compiler-->Assembler ;
    Assembler-->Linker;
    
```
### Source Code
`main.cpp`


written by "AmirM"

 Note1: counter.cpp code is embedded into main.cpp source code. 

### Preprocessor
A Preprocessor function Transforms the source code `main.cpp` into a preprocessed code
`main.i`

`$ g++ -E main.cpp > main.i`

This file is much larger than source file.

`$ ls -l main.i`
`size: 999555`




### Compiler


### Assembler


### Linker



   main.cpp: The Source code       
    
|                |
|  Preprocessor  |    $ g++ -E main.cpp > main.i 
|  (precompiler) |    
|________________|      
        |
        |
       \|/
        |
      main.i   // The preprocessed code
        |      // $ ls -l main.i
        |      size: 999555
       \|/
        |
__________________
|                |
|   Compiler     |    $ g++ -S main.cpp  
|                |  
|________________|

        |
        |
       \|/
        |
      main.s   // The Assembly code
        |      // $ ls -l main.s 
        |      size: 106546
       \|/
        |
__________________
|                |
|   Assembler    |   // $ g++ -C main.cpp  
|                |  // Note2: In our experiment we use <thread> library, so use this command:
|________________|  //$ g++ -C main.cpp -pthread -std=c++14

        |
        |
       \|/
        |
      a.out   // Object code (the machine code, binary code)
        |     // ls -l a.out
        |     size: 36464
       \|/
        |
__________________
|                |
|     Linker     |    // The Linker links source files and libraries
|                |    // and produces final executable file, main. 
|________________|

        |
        |
       \|/
        |
      main     // The Executable (The Runnable File)
               // $ ls -l main
               size: 36672 
