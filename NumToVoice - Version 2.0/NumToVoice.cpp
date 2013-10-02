#include <iostream> 
#include <string> 

#include "NumToVoice.h" 
#include "NumberToText.h" 

using namespace std; 
	
	string error_msg = ""; 
	
	map<string, Mix_Chunk*> sounds; 
	
	int main(int argc, char* args[]) 
	{  
		freopen("CON", "w", stdout); 
		if(!soundInit()) 
			{ cout << "error initializing: " << error_msg << '\n'; } 
		if(!loadSounds()) 
			{ cout << "error initializing: " << error_msg << '\n'; } 
		
		//run("one one one"); 
		init(); ///numtotext init and run
		run(); 
		
		cleanUp(); 
		
		return 0; 
	} 
	
	void run(string input) 
	{ 
		string word; 
		istringstream iss(input, istringstream::in); 
		int chann; 
		while( iss >> word ) 
		{
			/**if( Mix_PlayChannel( -1, sounds[word], 0 ) == -1 ) 
			{ cout << "Error: Sound play failure." << '\n';  } 
			//SDL_Delay( 1000 ); 
			SDL_Delay( 800 ); //0.8 sec delay betw words */ 
			chann = Mix_PlayChannel( -1, sounds[word], 0 ); 
			if( chann == -1 ) 
			{ cout << "Error: Sound play failure." << '\n';  } 
			else { while(Mix_Playing(chann)); } 	//wait for the sound to finish playing 
			SDL_Delay( 200 ); //0.2 sec delay betw words 
		} 
	} 
	
	bool soundInit() 
	{ 
		error_msg = ""; 	//clear previous error message 
		if( SDL_Init( SDL_INIT_AUDIO ) == -1 ) 
		{ 
			error_msg += "Failed to initialize sound(s). "; 
			return false; 
		} 
		if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
		{ 
			error_msg += ""; 
			return false; 
		} 
			
		return true; 
	} 
	
	
	bool loadSounds() 
	{ 
		error_msg = ""; 	//clear previous error message 
		
		sounds["zero"] = Mix_LoadWAV( "./sounds/zero.wav" ); 
		sounds["one"] = Mix_LoadWAV( "./sounds/one.wav" ); 
		sounds["two"] = Mix_LoadWAV( "./sounds/two.wav" ); 
		sounds["three"] = Mix_LoadWAV( "./sounds/three.wav" ); 
		sounds["four"] = Mix_LoadWAV( "./sounds/four.wav" ); 
		sounds["five"] = Mix_LoadWAV( "./sounds/five.wav" ); 
		sounds["six"] = Mix_LoadWAV( "./sounds/six.wav" ); 
		sounds["seven"] = Mix_LoadWAV( "./sounds/seven.wav" ); 
		sounds["eight"] = Mix_LoadWAV( "./sounds/eight.wav" ); 
		sounds["nine"] = Mix_LoadWAV( "./sounds/nine.wav" ); 
		sounds["ten"] = Mix_LoadWAV( "./sounds/ten.wav" ); 
		sounds["eleven"] = Mix_LoadWAV( "./sounds/eleven.wav" ); 
		sounds["twelve"] = Mix_LoadWAV( "./sounds/twelve.wav" ); 
		sounds["thirteen"] = Mix_LoadWAV( "./sounds/thirteen.wav" ); 
		sounds["fourteen"] = Mix_LoadWAV( "./sounds/fourteen.wav" ); 
		sounds["fifteen"] = Mix_LoadWAV( "./sounds/fifteen.wav" ); 
		sounds["sixteen"] = Mix_LoadWAV( "./sounds/sixteen.wav" ); 
		sounds["seventeen"] = Mix_LoadWAV( "./sounds/seventeen.wav" ); 
		sounds["eighteen"] = Mix_LoadWAV( "./sounds/eighteen.wav" ); 
		sounds["nineteen"] = Mix_LoadWAV( "./sounds/nineteen.wav" ); 
		
		sounds["twenty"] = Mix_LoadWAV( "./sounds/twenty.wav" ); 
		sounds["thirty"] = Mix_LoadWAV( "./sounds/thirty.wav" ); 
		sounds["forty"] = Mix_LoadWAV( "./sounds/forty.wav" ); 
		sounds["fifty"] = Mix_LoadWAV( "./sounds/fifty.wav" ); 
		sounds["sixty"] = Mix_LoadWAV( "./sounds/sixty.wav" ); 
		sounds["seventy"] = Mix_LoadWAV( "./sounds/seventy.wav" ); 
		sounds["eighty"] = Mix_LoadWAV( "./sounds/eighty.wav" ); 
		sounds["ninety"] = Mix_LoadWAV( "./sounds/ninety.wav" ); 
		
		sounds["hundred"] = Mix_LoadWAV( "./sounds/hundred.wav" ); 
		sounds["thousand"] = Mix_LoadWAV( "./sounds/thousand.wav" ); 
		sounds["million"] = Mix_LoadWAV( "./sounds/million.wav" ); 
		sounds["billion"] = Mix_LoadWAV( "./sounds/billion.wav" ); 
		sounds["trillion"] = Mix_LoadWAV( "./sounds/trillion.wav" ); 
		
		if( sounds.empty() ) 
		{ 
			error_msg += "Sounds could not be loaded. "; 
			return false; 
		} 
		return true; 
	} 

	
	void cleanUp() 
	{ 
		std::map<std::string, Mix_Chunk*>::iterator iter; 
		for (iter = sounds.begin(); iter != sounds.end(); ++iter) 
			Mix_FreeChunk( iter->second ); 
		//Mix_FreeChunk( sounds["one"] ); 
		sounds.clear(); 
		Mix_CloseAudio(); 
		SDL_Quit(); 
	} 