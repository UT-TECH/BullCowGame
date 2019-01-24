#include <iostream>
#include<string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;



void intro();
void PlayGame();
void PlayAgain();
FBullCowGame BCgame;
void PrintGameSummery();
int32 SelectWordLenght();



int32 main()
{
	intro();
	PlayGame();
	PlayAgain();
	return 0;
}

void intro() 
{	
	int32 Hiddenwoedlength = BCgame.GetHiddenWordLength();
	std::cout << "WELCOME TO BULLCOW GAME\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "CAN YOU GUESS " << Hiddenwoedlength;
	std::cout << " LETTERS WORD .(NO LETTERS REPEATED)\n";
	
	
}

FText Getguess()
{
	EWordStatus status = EWordStatus::INVALID;
	do
	{
		int32 currenttry = BCgame.GetCurrentTry();
		int32 Triesleft = BCgame.TryLeft();


		FText Guess;
		std::cout << " \n\n ------------------------------------------------------------------"  ;

		std::cout << " \n\n\nTry " << currenttry << "of"<<BCgame.GetMaxTry();
		std::cout << " \nEnter your Guess= " ;


		getline(std::cin, Guess);

		EWordStatus status = BCgame.IfGuessISValid(Guess);
		switch (status)
		{
		case EWordStatus::WRONG_LENGHT:
			std::cout << "Please Enter a Word of " << BCgame.GetHiddenWordLength() << " letters. \n\n";
			break;
		case EWordStatus::NOT_isogram:
			std::cout << "Please Enter a Word Without repeating letters. \n\n";
			break;
		case EWordStatus::LOWERCASE_ONLY:
			std::cout << "Please Enter a Word With LOWERCASE letters. \n\n";
			break;

		default:
			return Guess;
			break;
		}

	} while (status!=EWordStatus::OK);
	
	


	
	
}

  
 
void PlayGame()
{
	BCgame.Reset();
	int32 Maxtry = BCgame.GetMaxTry();

	std::cout << "Max Try is= " << Maxtry << std::endl;

	while ((!BCgame.IsGameWon()) && (BCgame.GetCurrentTry() <= Maxtry))
	{
		FText Guess = Getguess();
		//std::cout << " Your Guess IS= " << Guess;
		FBCcount Bullcowcount = BCgame.SubmitGuess(Guess);
		std::cout << "\n   BULLS= " << Bullcowcount.bulls;
		std::cout << "     COWS= " << (Bullcowcount.cows);		
 	} 
	PrintGameSummery();
	
}

void PlayAgain()
{

	std::cout << "\n\nPLAY AGAIN?? y/n";
	FText response = "";
	getline(std::cin, response);



	if ((response[0] == 'y') || (response[0] == 'Y'))
	{
		main();
	} 
	else
	{
		std::cout << "Exiting Game................";
	}
	 

}

void PrintGameSummery()
{
	if (BCgame.IsGameWon()==true)
	{
		std::cout << "\n\n YOU WON THE GAME!!!!\n\n";
	}
	else
	{
		std::cout << "\n\nYOU LOST.\n\n";
		std::cout << "\n\nDO YOU WANT TO KNOW CORRECT ANSWER? y/n";
		char ShowAnswer;
		FString HiddenWord = BCgame.Reset();
		std::cin >> ShowAnswer;
		if (ShowAnswer == 'y'||ShowAnswer=='Y')
		{
			std::cout << "Word is = " << HiddenWord;
			PlayAgain();

		}
		else
			PlayAgain();



	}
}

int32 SelectWordLenght()
{
	int32 ChooseWordLenght;
	std::cout << "\n\nSelect Word Length.(3-8)";
	std::cin >> ChooseWordLenght;
	if (ChooseWordLenght == 3)
	{
		return ChooseWordLenght;
	}if (ChooseWordLenght == 4)
	{
		return ChooseWordLenght;
	}if (ChooseWordLenght == 5)
	{
		return ChooseWordLenght;
	}if (ChooseWordLenght == 6)
	{
		return ChooseWordLenght;
	}

}


