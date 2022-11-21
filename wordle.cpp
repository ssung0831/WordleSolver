// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordle_helper(
    std::string in,
   	std::string floating,
    const std::set<std::string>& dict,
		std::set<std::string>& possibleWords,
		int index);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
		std::set<std::string> possibleWords;
		wordle_helper(in, floating, dict, possibleWords, 0);
		return possibleWords;
    
}

// Define any helper functions here
void wordle_helper(
    std::string in,
    std::string floating,
    const std::set<std::string>& dict,
		std::set<std::string>& possibleWords,
		int index)
{
    // Add your code here


		//counts how many dashes are left in the word
		unsigned int dashCount = 0;
		for(unsigned int i = 0; i < in.size(); i++){
			if(in[i] == '-'){
				dashCount++;
			}
		}

		//base case- if no more dashes, add this word to the set if it is valid
		if(dashCount == 0){
			std::set<std::string>::iterator i = dict.find(in);
			if(i != dict.end()){
				possibleWords.insert(in);
			}
			return;
		}

		//if current index is not at a dash, go onto the next index
		if(in[index] != '-'){
			wordle_helper(in, floating, dict, possibleWords, index +1);
			return;
		}


		//if num of dashes is equal to num of yellow words, try all possible words
		if(dashCount == floating.size()){
			for(unsigned int i = 0; i < floating.size(); i++){
				in[index] = floating[i];
				string newFloating = floating;
				newFloating.erase(i, 1);
				wordle_helper(in, newFloating, dict, possibleWords, index + 1);
			}
		}

		else{
			//iterate through all letters
			for(char c = 'a'; c <= 'z'; c++){
				in[index] = c;
				//c is not a yellow word
				if(floating.find(c) == std::string::npos){
					wordle_helper(in, floating, dict, possibleWords, index + 1);
				}
				else{
					string newFloating = floating;
					newFloating.erase(floating.find(c), 1);
					wordle_helper(in, newFloating, dict, possibleWords, index + 1);
				}
		}
			
		}

    

}