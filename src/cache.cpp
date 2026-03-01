#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Cache {
	int maxCapacity =0;
	int missCount = 0;
	vector <int> cacheRequests;
	// need constructor
	Cache(int k) : maxCapacity(k) {}
	void resetCache() {
		cacheRequests.clear();
		missCount = 0;
	}

	void shiftBack(int specificRequest) {
		//for both FIFO and LRU
		// FIFO:so basically if you have a hit/ you need to move that object to the end of the vector and shift everything else forward
		//LRU:  data is stored in the cache in the order it arrives removes the oldest item aka the top of the list
		//LRU: also do this when there is a hit ?? doesnt seem right?? but??
		cacheRequests.erase(cacheRequests.begin());
		cacheRequests.push_back(specificRequest);
	}
	//void doFIFO(int specificRequest) {
		//  data is stored in the cache in the order it arrives
		// removes the oldest item aka the top of the list
		//ERASE() DELETS AND SHIFTS VECTOR ELEMENTS!
		//cacheRequests.erase(cacheRequests.begin());
		// add the new one
		//cacheRequests.push_back(specificRequest);
	//}

	//void doLRU(int specificRequest) {
		//it keeps track of the order in which items are accessed.
		// so basically if you have a hit/ you need to move that object to the end of the vector and shift everything else forward
		//cacheRequests.erase(cacheRequests.begin());
		// add the new one
		//cacheRequests.push_back(specificRequest);
	//}
};
