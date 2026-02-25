#include <fstream>
#include <iostream>
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

	//TODO: NEED TO DEAL WITH INPUT K AND M HERE!!
	// create cache structure with a class/ struct?
	// this would:
	// keep track of the maximun capcity k
	// need to have a vector or something of all the requests maybe?

	// k and m are on the same line
	int k,m;
	in >> k >> m;

	if(k <= 0){
		throw runtime_error("Invalid 'k' value");
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

}

