#include "NumberToText.h" 
#include "NumToVoice.h" 

using namespace std; 
	
/* 
 * numStringMap -> holds mappings from numbers to their equivalents in words 
 * chunkMap		-> holds the 3-digit chunks from user input 
 * arr_Deg		-> holds the place value of corresponding chunks 
*/
	map<int, string> 	numStringMap, 
						chunkMap; 
	string arr_Deg[] = { "", "thousand ", "million ", "billion ", "trillion " }; 

	/*** MAIN ***/
/**
int main()
{ 
	init(); 
	run(); 
	
	return 0;
} 
*/


void run() 
{ 
	string input = "", output=""; 
	do{ 
		cout << "enter a number > "; 
		getline( cin, input, '\n' ); 
		cout << "You entered " << input << '\n'; 
		iterChunks(input, 0); 
		
		output = chunkMapToStr(chunkMap); 
		cout << output << '\n'; 
		run(output); //NumToVoice->run to play appr. sounds
		chunkMap.clear(); 
	}while(input != ""); 
	
	cout << "bye :)" << '\n';
} 


void init() 
{ 
	createMappings(); 
} 


void iterChunks(const string& str, int pos) 
{ 
	string chunk = nextChunk(str, CHUNK_SIZE); //3 is the chunk size 
	if(!chunk.empty()) 
	{ 
		chunkMap[pos] = processChunk(chunk); 
		
		iterChunks( str.substr(0, str.size() - chunk.size()), pos+1 ); 
	} 
} 


string nextChunk(const string& str, int chunkSize) 
{ 
	if(str.empty() || str.size() <= chunkSize) 
		{ return str; } 
	int len = str.size(); 
	return str.substr(len - chunkSize, len-1); 
} 


string processChunk(string numStr) 
{ 
	int num = atoi(numStr.c_str()); 
	
	return numToString(num); 
} 


string numToString(int num) 
{ 
	string val = ""; 
	
	if(num < 20) 
		{ return numStringMap[num]; } 
	if(num < 100) 
	{ 
		int mod_10 = num % 10; 
		val += numStringMap[num - mod_10]; 
		if(mod_10 != 0) 
			{ val += numStringMap[mod_10]; } 
		return val; 
	} 
	if(num < 1000) 
	{ 
		int mod_100 = num % 100; 
		val += numStringMap[ (num - mod_100) / 100]; 
		val += "hundred "; 
		if(mod_100 != 0) 
			{ val += numToString(mod_100); }
	} 
	
	return val; 
} 


string chunkMapToStr(map<int, string>& m) 
{ 
	string result = ""; 
	bool b_noZero = false; 	//if this is true, then the word 'zero' 
							//is not added at the last if statement 
	
	/** 5 is the length of arr_Deg array */
	for(int i=5; i>0; i--) 
	{ 
		if( m.count(i) > 0 ) 	
		{ 
			if((m.find(i)->second).compare("zero ") != 0) 
			{
				b_noZero = true; 
				result += m.find(i)->second; 
				result += arr_Deg[i]; 
			} 
		} 
	} 
	
	if( m.count(0) > 0 ) 
	{
		if((m.find(0)->second).compare("zero ") == 0) 
			{ result += b_noZero ? "" : m.find(0)->second; } 
		else { result += m.find(0)->second; } 
	} 
	
	return result; 
} 


void createMappings() 
{ 
	numStringMap[0] = "zero "; 		numStringMap[1] = "one "; 
	numStringMap[2] = "two "; 		numStringMap[3] = "three "; 
	numStringMap[4] = "four "; 		numStringMap[5] = "five "; 
	numStringMap[6] = "six "; 		numStringMap[7] = "seven "; 
	numStringMap[8] = "eight "; 	numStringMap[9] = "nine "; 
	numStringMap[10] = "ten "; 		numStringMap[11] = "eleven "; 
	numStringMap[12] = "twelve "; 	numStringMap[13] = "thirteen "; 
	numStringMap[14] = "fourteen "; numStringMap[15] = "fifteen "; 
	numStringMap[16] = "sixteen "; 	numStringMap[17] = "seventeen "; 
	numStringMap[18] = "eighteen "; numStringMap[19] = "nineteen "; 
	
	numStringMap[20] = "twenty "; 	numStringMap[30] = "thirty "; 
	numStringMap[40] = "forty "; 	numStringMap[50] = "fifty "; 
	numStringMap[60] = "sixty "; 	numStringMap[70] = "seventy "; 
	numStringMap[80] = "eighty "; 	numStringMap[90] = "ninety "; 
} 