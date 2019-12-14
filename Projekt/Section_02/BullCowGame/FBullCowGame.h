#pragma once
#include <string>

using int32 = int;
using Fstring = std::string;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(Fstring);

	//Counts bulls and cows and increases try # assuming valid guess
	BullCowCount SubmitGuess(Fstring);

private: //inicjalizacja w construktorze
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
};