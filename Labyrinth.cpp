#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool spell=false;
    bool pot=false;
    bool wand=false;
    for(int x=0;x<=moves.length();x++){
    	
    	//Check for item
    	if(start->whatsHere==Item::SPELLBOOK){
    		spell=true;
    	}
    	else if(start->whatsHere==Item::POTION){
    		pot=true;
    	}
    	else if(start->whatsHere==Item::WAND){
    		wand=true;
    	}
    	
    	if(x==moves.length()){
    		//Just we can check for items on the last move as well
    		break;
    	}
    	char dir=moves[x];
    	
    	//Make move
    	if(dir=='N'){
    		if(start->north!=nullptr){
    			start=start->north;
    		}
    	}
    	else if(dir=='E'){
    		if(start->east!=nullptr){
    			start=start->east;
    		}
    	}
    	else if(dir=='S'){
    		if(start->south!=nullptr){
    			start=start->south;
    		}
    	}
    	else if(dir=='W'){
    		if(start->west!=nullptr){
    			start=start->west;
    		}
    	}
    }
    //std::cout<<spell<<" "<<pot<<" "<<wand<<std::endl;
    if(spell&&pot&&wand){
    	return true;
    }
    return false;
}
