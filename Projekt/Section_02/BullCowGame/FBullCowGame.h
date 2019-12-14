#pragma once
#include <string>

using int32 = int;

using Fstring = std::string;

class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(Fstring);

private: //inicjalizacja w construktorze
	int32 MyCurrentTry;
	int32 MyMaxTries;
};