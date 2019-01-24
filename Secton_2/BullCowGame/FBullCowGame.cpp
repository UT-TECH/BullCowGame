#include "FBullCowGame.h"
#include<map>
#define TMap std::map

using int32 = int;

int32 FBullCowGame::GetCurrentTry() const{return Currenttry;}
int32 FBullCowGame::TryLeft() const{return TriesLeft;}
int32 FBullCowGame::GetHiddenWordLength() const { int32 Hiddenwordlenght = HiddenWord.length(); return Hiddenwordlenght; }
bool FBullCowGame::IsGameWon() const{return bIsGameWon;}

FBCcount FBullCowGame::SubmitGuess(FString Guess)
{
	Currenttry++;
	FBCcount BullCowCount;
	int32 hindderwordlenght = HiddenWord.length();
	int32 Guesslength = Guess.length();
	 

	for (int32 i = 0; i < hindderwordlenght; i++) 
	{
		for (int32 j = 0; j < hindderwordlenght; j++)
		{
			if (HiddenWord[j] == Guess[i]) 
			{
				if (i==j)
				{
					BullCowCount.bulls++;

				}
			}	
		}
				
	}
	BullCowCount.cows = hindderwordlenght - BullCowCount.bulls;

	if (BullCowCount.bulls==hindderwordlenght)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;

	}


	return BullCowCount;
}




 


FBullCowGame::FBullCowGame()
{
	Reset();
}

FString FBullCowGame::Reset()
{
	 Currentscore;
	 Currenttry = 1;
	 bIsGameWon = false;
	 const FString HIDDEN_WORD = "kite";
	 HiddenWord = HIDDEN_WORD;
	 return HIDDEN_WORD;
}



EWordStatus FBullCowGame::IfGuessISValid(FString Guess)
{
	if (!IsIsogram(Guess) )
	{
		return EWordStatus::NOT_isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EWordStatus::LOWERCASE_ONLY;

	}
	else if (GetHiddenWordLength()!=Guess.length())
	{
		return EWordStatus::WRONG_LENGHT;
	}
	else if (false)
	{
		return EWordStatus::NUMBERS_NOT_ALLOWED;
	}else

        return EWordStatus::OK;
}

 
bool FBullCowGame::IsIsogram(FString Guess) const
{
	// a loop to check all letters is its repeating or not
	if (GetHiddenWordLength()<2)
	{
		return true;

	}
	TMap<char, bool> LetterSeen;

	for (auto letter : Guess)
	{
		letter = tolower(letter);
		if (LetterSeen[letter])
		{
			return false;
		}
		else
		{
			LetterSeen[letter] = true;
		}
		

	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{

	TMap<char, bool> EnteredWord;
	TMap<char, bool> Uppercase;


	for (auto letter : Guess)
	{
		for (auto Uletter : Guess)
		{
			Uletter = toupper(Uletter);
			if (EnteredWord[letter] == Uppercase[Uletter])
			{
				if (letter==Uletter) 
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}

	}

	return true;
	
}

FString FBullCowGame::WordDictionary(int32 ChooseWordLenght)
{
	if (ChooseWordLenght==3)
	{
		HiddenWord = "cat";
 		return HiddenWord;
	}if (ChooseWordLenght == 4)
	{
		HiddenWord = "kite";
		return HiddenWord;
	}if (ChooseWordLenght == 5)
	{
		const FString HIDDEN_WORD = "plant";
		HiddenWord = HIDDEN_WORD;

		return HiddenWord;
	}if (ChooseWordLenght == 6)
	{
		const FString HIDDEN_WORD = "zombie";
		HiddenWord = HIDDEN_WORD;

		return HiddenWord;
	}if (ChooseWordLenght == 7)
	{
		const FString HIDDEN_WORD = "isogram";
		HiddenWord = HIDDEN_WORD;

		return HiddenWord;
	}if (ChooseWordLenght == 8)
	{
		const FString HIDDEN_WORD = "organism";
		HiddenWord = HIDDEN_WORD;

		return HiddenWord;
	}

}

int32 FBullCowGame::GetMaxTry() const
{ 
	TMap<int32, int32>WordLenghthMaxTryCombination{ {3,5}, {4,6} ,{5,7}, {6,8} ,{7,9}, {8,10} };
	
	return WordLenghthMaxTryCombination[HiddenWord.length()];

}
