#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//the entry point for application
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while(bPlayAgain) ;
		return 0;
	
}

//loop
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	while (!BCGame.IsGameWon()&&BCGame.GetCurrentTry()<=MaxTries)
	{
		Ftext Guess = GetValidGuess();

		//submit valid guess, receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		//print the guess back
		std::cout << "Your guess was: " << Guess << "\n\n";
	}

}

//introduce the game
void PrintIntro()
{
	
	std::cout << "Welcome to Bulls ad Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
Ftext GetValidGuess()
{
	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		//get a guess from the player
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		getline(std::cin, Guess);


		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}
		std::cout<<std::endl;
	} while (Status!=EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?(y/n)";
	Ftext Response = "";
	std::getline(std::cin, Response);

	std::cout << "Is it y?:" << (Response[0] =='y');
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
