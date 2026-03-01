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

	// data is stored in the cache in the order it arrives
	// removes the oldest item aka the top of the list
	void doFIFO(const vector<int>& allRequests) {
		// for every request in the requestList  , +1 miss , else do POLICY
		for (int i = 0; i < allRequests.size(); ++i) {
			//FIND returns the position it is in!! aka index!!
			auto it = find(cacheRequests.begin(),cacheRequests.end(), allRequests[i]);
			// if it is within the vector then it is a hit
			if (it != cacheRequests.end()) {
				// yaya hit!
				// do nothing
			}
			else {
				// UPDATE MISSES
				missCount++;
				//check if cache is full
				if (cacheRequests.size() < maxCapacity) {
					// if not full
					//add it to the inner cache list
					cacheRequests.push_back(allRequests[i]);
				}
				else {
					// else do the policy
					// run inner cache policy function
					//CacheObj.doFIFO(allRequests[i]);
					shiftBack(allRequests[i]);
				}
			}
		}
	}

	void doLRU(const vector<int>& allRequests) {
		//it keeps track of the order in which items are accessed.
		// so basically if you have a hit/ you need to move that object to the end of the vector and shift everything else forward
		//similar to the fifo but we ned to do the shift at a hit that makes it different
		for (int i = 0; i < allRequests.size(); ++i) {
			//FIND returns the position it is in!! aka index!!
			auto it = find(cacheRequests.begin(), cacheRequests.end(), allRequests[i]);
			// if it is within the vector then it is a hit
			if (it != cacheRequests.end()) {
				// yaya hit!
				// If found, you can dereference the iterator (*it) to access the value
				//CALL LRU HELPER TO SHIFT
				//CacheObj.LRUShift(it);
				//CacheObj.doLRU(allRequests[i]);
				shiftBack(allRequests[i]);
			}
			else {
				// UPDATE MISSES
				missCount++;
				//check if cache is full
				if (cacheRequests.size() < maxCapacity) {
					// if not full
					//add it to the inner cache list
					cacheRequests.push_back(allRequests[i]);
				}
				else {
					// else do the policy
					// run inner cache policy function
					//CacheObj.doLRU(allRequests[i]);
					shiftBack(allRequests[i]);
				}
			}
		}
	}
};
