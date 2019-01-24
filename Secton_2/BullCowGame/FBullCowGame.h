#include<string>
#include<map>
#define TMap std::map

using int32 = int;
using FString = std::string;

struct FBCcount
{
	int32 bulls =0;
	int32 cows  =0;

};

enum EWordStatus
{   
	INVALID,
	OK,
	NOT_isogram,
	NUMBERS_NOT_ALLOWED,
	LOWERCASE_ONLY,
	WRONG_LENGHT

};

class FBullCowGame
{
public:
	FBullCowGame();
	FString Reset();
	int32 GetMaxTry() const;
	int32 GetCurrentTry() const;
	int32 TryLeft() const;

	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus IfGuessISValid(FString);
	FBCcount SubmitGuess(FString);
	
	


private:
	int32 Currentscore;
	int32 Maxtry;
	int32 Currenttry;
	FString HiddenWord;
	int32 Hiddenwordlenght;
	bool bIsGameWon;
	bool IsIsogram(FString) const ;
	bool IsLowercase(FString)const;
	int32 TriesLeft;
	FString WordDictionary(int32);
	FString SelectedWordIS;

};							

 