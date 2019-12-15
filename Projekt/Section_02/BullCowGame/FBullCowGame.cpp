#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon()const { return bGameIsWon; }


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
	bGameIsWon = false;
	return;
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
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();//assuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
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
	if (BullCowCount.Bulls==WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	//loop through all letters in the guess
		//compare against the hidden word
	return BullCowCount;
}
