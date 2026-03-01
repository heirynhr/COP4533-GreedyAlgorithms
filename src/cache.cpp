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

	void doFIFO(int specificRequest) {
		//  data is stored in the cache in the order it arrives
		// removes the oldest item aka the top of the list
		//ERASE() DELETS AND SHIFTS VECTOR ELEMENTS!
		cacheRequests.erase(cacheRequests.begin());
		// add the new one
		cacheRequests.push_back(specificRequest);
	}

	void doLRU(int specificRequest) {
		//it keeps track of the order in which items are accessed.
		// so basically if you have a hit/ you need to move that object to the end of the vector and shift everything else forward
		cacheRequests.erase(cacheRequests.begin());
		// add the new one
		cacheRequests.push_back(specificRequest);
	}
};
