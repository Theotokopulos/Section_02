#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (false)//if not an isogram, return error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)//if not all lowercase, return error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())//if wrong length, return error
	{
		return EGuessStatus::Wrong_Length;
	}
	else//otherwise return OK
	{
		return EGuessStatus::OK;
	}
}

//receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(Fstring Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar]== MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}

	}

	//loop through all letters in the guess
		//compare against the hidden word
	return BullCowCount;
}
