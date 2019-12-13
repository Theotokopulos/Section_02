#include <iostream>
#include <string>



void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

//the entry point for application
int main()
{
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
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string Guess = GetGuess();
		//print the guess back
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

}

//introduce the game
void PrintIntro()
{
	
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls ad Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
std::string GetGuess()
{

	//get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?(y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);

	std::cout << "Is it y?:" << (Response[0] =='y');
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
