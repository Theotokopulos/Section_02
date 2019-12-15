#pragma once
#include <string>

using int32 = int;
using Fstring = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength()const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(Fstring)const;
	
	void Reset();
	
	//Counts bulls and cows and increases try # assuming valid guess
	FBullCowCount SubmitValidGuess(Fstring);

private: //inicjalizacja w construktorze
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
	bool bGameIsWon;
};