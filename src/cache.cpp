#include <vector>
#include <map>
#include <queue>
#include <algorithm>

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

	void doOPTFF(const vector<int>& allRequests){
		// need to build list of each requests next use
		// as we iterate through the requests we need to know the next time request x appears in the requests
		// need to visualize this:
			// allRequests = [1, 2, 1, 3]
			// next_request = [2, 4, 4, 4] *use m to signify that item doesnt appear again in the requests
			// so basically 1's next use is in index 2, and the rest of the items dont appear again

		vector<int> next_request;
		// iterate through requests in reverse
		map<int, int> last_seen;
		for(int i = allRequests.size() - 1; i >= 0; --i){
			int curr = allRequests[i];

			// check if this request has already been seen to the right
			if(last_seen.count(curr) == 1){
				// if item already exists as a key, this means it has been visited in the array already and exists in the future
				// store requests future occurence
				next_request[i] = last_seen[curr];
			}
			else{
				last_seen[curr] = i;
			}
		}

		// now we need to evict the item whose next req is furthertest in the future or never occurs again
		// what if multiple never occur again...
		
		// perform actual algorithm now
		// use map for easier lookup
		map<int, int> cache;
		for(int i = 0; i < allRequests.size(); ++i){
			int curr = allRequests[i];

			if(cache.count(curr) == 1){
				// hit, item is currently in cache and need to update its next req value
				cache[curr] = next_request[i];
			}
			else{
				missCount++;
				if(cache.size() < maxCapacity){
					// point to the cache entry with the largest next use value
					auto evict = max_element(cache.begin(), cache.end(),
                        [](const pair<int,int>& a, const pair<int,int>& b) {
                            return a.second < b.second;
                		});

						// remove item from cache
						cache.erase(evict);
						cache[curr] = next_request[i];
				}
			}
		}

	}
};
