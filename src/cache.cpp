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


};
