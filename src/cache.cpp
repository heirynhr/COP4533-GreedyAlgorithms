#include <vector>
#include <map>

using namespace std;

struct Cache {
	int capacity;
	// needs to keep track of the eviction Process
	// we can either have a cache for each policy orrrrr we can have a singular cache and then depending on the policy variable it calls the particular structure.
}

//orrr

struct FIFOCache {
	int capacity;
};
