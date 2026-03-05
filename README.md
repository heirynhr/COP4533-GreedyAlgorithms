# COP4533-GreedyAlgorithms

**Students:**

Heiryn Hernandez Rojas - 90988659

Maite Chapartegui - 54536135

## Files
Within src folder:
* `cache.cpp` - has the cache struct with policy functions that you call in main.
* `policies.cpp` - holds the main function, input and output and runs all of the policy functions

Within data folder:
* `examplen.txt`: Different input files with a variety of input numbers and capacities
* `examplen.out`: the output with the misses for each function

## Compilation
Our program is written in C++
To compile the code,

1. Clone the repo on your device:
* git clone https://github.com/heirynhr/COP4533-GreedyAlgorithms.git

2. Compile in VSCode (or IDE of your choosing) terminal
* g++ -std=c++17 ./src/policies.cpp -o policies
* ./policies ./data/example2.in
- to change input file, just edit the path in the second command

### Our assumptions:
- Assumed the input file format does not differ from the one that was given
- Assumed a cache must have a capacity of at least 1
- Assumed cache size is small enough to deal with the vectors, does not exceed the vector
## Written Component
