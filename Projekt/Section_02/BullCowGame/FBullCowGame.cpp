#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES ;

	const Fstring HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon()const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(Fstring)
{
	return false;
}
//receives a valid guess, increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(Fstring)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	BullCowCount BullCowCount;

	//loop through all letters in the guess
		//compare against the hidden word
	return BullCowCount;
}
