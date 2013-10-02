#ifndef NumToVoice_h 
#define NumToVoice_h  

#include <sstream> 
#include <map> 

#include "SDL/SDL.h" 
#include "SDL/SDL_mixer.h" 

using namespace std; 

	bool soundInit();  
	bool loadSounds(); 
	void cleanUp(); 
	void run(string input); 


#endif 