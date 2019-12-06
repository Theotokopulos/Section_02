#include <iostream>
#include <string>

using namespace std;


void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

//the entry point for application
int main()	
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
	return 0;
}

//loop
void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		//print the guess back
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}

}

//introduce the game
void PrintIntro()
{
	
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls ad Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}
string GetGuess()
{

	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?";
	string Response = "";
	getline(cin, Response);

	cout << "Is it y?:" << (Response[0] =='y');
	cout << endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
