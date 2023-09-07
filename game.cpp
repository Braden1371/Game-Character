//*********************************************************************
//    Braden Harris
//    CS-355
//    Assignment #3
//    9/1/2023
//    Create and implement a GameCharacter class. This class should be 
//    	able to attack and deal damage. Characters can be compared,
//    	loaded from file, and saved to file.

#include "GameCharacter.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	GameCharacter player1("Dave", 100, 80, 45);
	GameCharacter player2("Shawn", 100, 75, 50);

	//display characters before any attacks
	cout << player1;
	cout << player2;

	//player1 attacks player2
	player1.attack(player2);
	cout << player2;

	//add players together to create a new player
	GameCharacter player3 = player1 + player2;

	//display new  character
	cout << player3;

	player2.attack(player3);
	cout << player3;

	player1.attack(player3);
	cout << player3;

	//compare characters
	if(player1 > player3)
		cout << player1.getName() << " is stronger than " << player3.getName() << endl << endl;
		
	else 
		cout << player1.getName() << " is not stronger than " << player3.getName() << endl << endl;


	if(player2 < player1)
		cout << player2.getName() << " is stronger than " << player1.getName() << endl << endl;

	else
		cout << player2.getName() << " is not stronger than " << player1.getName() << endl << endl;

	//save character to file
	bool saveSuccess = player3.saveToFile("character.txt");
	if(saveSuccess == true)
		cout << "Character " << player3.getName() << " saved successfully!" << endl << endl;

	else
		cout << "Character " << player3.getName() << " failed to save!" << endl << endl;


	player3 = player3.loadFromFile("character.txt");
	cout << player3;

	return 0;
}
