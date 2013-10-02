#ifndef NumberToText_h
#define NumberToText_h

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <map> 

using namespace std; 
	
	/**CHUNK_SIZE - user input is  split into chunks of 3*/ 
	const int CHUNK_SIZE = 3; 
	
	/**initialization procedures take place here*/
	void init(); 
		
	/**the application runs from here*/ 
	void run(); 
	
	/**fill the numStringMap object with the 
		mappings from numbers to strings */
		void createMappings(); 

	/**takes a string and returns the last three 
	   chars. returns the whole string if only 
	   three chars are contained in input string */
		//string nextChunk(string str, int chunkSize); 
		string nextChunk(const string& str, int chunkSize); 

	/**iterates chunks of three chars in the string
		calling the appropriate function on each 
		chunk*/
		//void iterChunks(string str, int pos); 
		void iterChunks(const string& str, int pos); 

	/**process a chunk of three digit number string 
		returning its equivalent in words */ 
		string processChunk(string chunk); 
		
	/** takes a number and returns its equivalent in 
		words */
		string numToString(int num); 
		
	/** iterates the chunkMap... */ 
		//string chunkMapToStr(map<int, string> m); 
		string chunkMapToStr(map<int, string>& m); 
 
#endif