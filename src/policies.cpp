#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cache.cpp"
using namespace std;
// take input from file
// A cache of capacity ( k ) A sequence of ( m ) requests ( r_1, r_2,.., r_m )
// k m
// r1 r2 r3 ... rm

int main(int argc, char** argv) {
	// Read in file information
	if(argc < 2){
		cout << "Invalid input" << endl;
		return 1;
	}
	string filename = argv[1];

	ifstream in(filename);
	if(!in){
		throw runtime_error("Could not open input file");
	}

	//empty file?
	if (in.peek() == ifstream::traits_type::eof()) {
		throw runtime_error("empty file");
	}

	// k and m are on the same line
	int k,m;
	in >> k >> m;

	if(k <= 0){
		throw runtime_error("Invalid 'k' value");
	}

	vector<int> allRequests;
	int currentRequest = 0;
	for (int i = 0; i < m; ++i) {
		if (in >> currentRequest) {
			allRequests.push_back(currentRequest);
		}
		else {
			//umm make sure we get them all?
			throw runtime_error("Didnt read all m requests");
		}
	}
	//create the output file
	//use the name to be the same
	string outputFile;
	size_t lastDot = filename.find_last_of(".");
	if (lastDot != string::npos) {
		outputFile = filename.substr(0,lastDot) + ".out";
	}
	else {
		outputFile = filename + ".out";
	}
	ofstream out(outputFile);

	Cache CacheObj(k);
	CacheObj.doFIFO(allRequests);

	// write the number of misses into the output file
	out << "FIFO:" <<  CacheObj.missCount << endl;
	// RESET CACHE!!!
	CacheObj.resetCache();

	// redo above except do it for the other polciy aka LRU
	CacheObj.doLRU(allRequests);
	// write the number of misses into the output file
	out << "LRU:" <<  CacheObj.missCount << endl;
	//for (int i = 0; i <  CacheObj.cacheRequests.size(); ++i) {
	//	out << "LRU Final list:" <<  CacheObj.cacheRequests[i] << endl;
	//}
	// RESET CACHE!!!
	CacheObj.resetCache();

	// redo above except do it for the other polciy aka OPTFF
	// write the number of misses into the output file
	out << "OPTFF:" <<  CacheObj.missCount << endl;



}

