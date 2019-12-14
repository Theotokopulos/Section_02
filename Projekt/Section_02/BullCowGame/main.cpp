#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
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
	for (int32 count = 1; count <= MaxTries; count++)
	{
		Ftext Guess = GetGuess();

		//submit valid guess, receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		//print the guess back
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
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
Ftext GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	//get a guess from the player
	std::cout << "Try "<<CurrentTry<<". Enter your guess: ";
	Ftext Guess = "";
	getline(std::cin, Guess);
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
