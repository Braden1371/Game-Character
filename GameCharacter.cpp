//********************************************************************************
//    Braden Harris
//    CS-355
//    Assignment #3
//    9/1/2023
//    Create and implement a GameCharacter class. This class should be 
//    	able to attack and deal damage. Characters can also be compared,
//    	loaded from file, and saved to file.

#include "GameCharacter.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//*********************************************************************************
//   GameCharacter()
//   A constructor for the GameCharacter class that takes parameters
//   	of a string for the character name along with integers for health,
//   	attack, and defense.
//   Return Value: n/a
GameCharacter::GameCharacter(string cName, int health, int aPoints, int dPoints){
	name = cName;
	maxHealth = health;
	healthPoints = health;
	attackPoints = aPoints;
	defensePoints = dPoints;
	isAlive = true;
}

//************************************************************************************
//   getName()
//   A function that retrieves the characters name without changing it.
//   Return Value: string
const string& GameCharacter::getName() const{
	return name;
}

//***************************************************************************************
//   getMaxHealth()
//   A function that retrieves the characters max health without changing it.
//   Return value: integer
int GameCharacter::getMaxHealth() const{ 
	return maxHealth;
}

//***************************************************************************************
//   getHealthPoints()
//   A function that retrieves the characters health without changing it.
//   Return value: integer
int GameCharacter::getHealthPoints() const{
	return healthPoints;
}

//****************************************************************************************
//   getAttackPoints()
//   A function that retrieves the characters attack value without changing it.
//   Return value: integer
int GameCharacter::getAttackPoints() const{
	return attackPoints;
}

//***************************************************************************************
//   getDefensePoints()
//   A function that retrieves the characters defense value without changing it.
//   Return value: integer
int GameCharacter::getDefensePoints() const{
	return defensePoints;
}

//***************************************************************************************
//   getIsAlive()
//   A function that retrieves if the character is still alive
//   Return value: boolean
bool GameCharacter::getIsAlive() const{
	return isAlive;
}

//***************************************************************************************
//   takeDamage()
//   A function that deals damage to the intended target based on the integer parameter
//      that it is passed. Also checks to see if the target is still alive.
//   Return value: void
void GameCharacter::takeDamage(int damage){
	healthPoints -= damage;

	if(healthPoints <= 0)
		isAlive = false;	
}

//****************************************************************************************
//   attack()
//   A function that determines the amount of damage to be dealt to target by finding
//      the difference between the attacker's attack points and the target's defense
//      points.
//   Return value: void
void GameCharacter::attack(GameCharacter& target){
	int damage;

	if(attackPoints > target.getDefensePoints()){
		damage = attackPoints - target.getDefensePoints();
		target.takeDamage(damage);
		cout << target.getName() << " has been attacked by " << name << endl;
		cout << target.getName() << " took " << damage << " damage!" << endl;
	}

	else
		return;

}

//***************************************************************************************
//    overloading the > operator
//    A function that overloads the > operator to be able to handle variables from
//    	the GameCharacter class.
//    Return value: boolean
bool GameCharacter::operator>(const GameCharacter& rhs){
	cout << "Comparing " << name << " to " << rhs.getName() << "..." << endl;

	if(healthPoints > rhs.getHealthPoints())
		return true;

	else
	       	return false;
}

//*************************************************************************************
//    overloading the < operator
//    A function that overloads the < operator to be able to handle variables from 
//    	the GameCharacter class.
//    Return value: boolean
bool GameCharacter::operator<(const GameCharacter& rhs){
	cout << "Comparing " << name << " to " << rhs.getName() << "..." << endl;

	if(healthPoints < rhs.getHealthPoints())
		return true;
	else
		return false;
}

//*************************************************************************************
//    overloading the + operator
//    A function that overloads the + operator to be able to add 2 instances of 
//     GameCharacter together.
//     Return value: GameCharacter
GameCharacter GameCharacter::operator+(GameCharacter& rhs){
	string newName;
	int health, attack, defense;
	cout << "Enter new character name: ";
	cin >> newName;
	cout << endl;
	health = maxHealth + rhs.getMaxHealth();
	attack = (attackPoints + rhs.getAttackPoints()) / 2;
	defense = (defensePoints + rhs.getDefensePoints()) / 2;

	GameCharacter newCharacter(newName, health, attack, defense);
	cout << "New Character created!" << endl;

	return newCharacter;
}

//***********************************************************************************
//    overloading the << operator
//    A function the overloads the << operator to be able to display instances of 
//    	GameCharacter.
//    Return value: ostream
ostream& operator<<(ostream& os, GameCharacter rhs){
	os << endl << "Displaying character information: " << endl;
	os << "Name: " << rhs.getName() << endl;
	os << "Health: " << rhs.getHealthPoints() << endl;
	os << "Attack Points: " << rhs.getAttackPoints() << endl;
	os << "Defense Points: " << rhs.getDefensePoints() << endl;
	
	if (rhs.getIsAlive() == 1)
		os << "Is alive?: Character is alive!" << endl << endl;
	else
		os << "Is alive?: Character has pershied in battle!" << endl << endl;

	return os;
}

//**************************************************************************************
//    saveToFile()
//    A function that saves an instance of GameCharacter to a text file. Also returns
//    	true if file could be successfully opened.Takes in a string parameter for the
//    	file name.
//    Return value: boolean
bool GameCharacter::saveToFile(string filename) {
	ofstream outFile(filename);

	if(outFile.fail()){
		cout << "Failed to open output file." << endl;
		return false;
	}

	lastSaveTime = time(0);
	tm *save = localtime(&lastSaveTime);
	outFile << name << endl;
	outFile << maxHealth << endl;
	outFile << attackPoints << endl;
	outFile << defensePoints << endl;
	outFile << save->tm_wday << endl;
	outFile << save->tm_mon << endl;
	outFile << save->tm_mday << endl;
	outFile << save->tm_hour << endl;
	outFile << save->tm_min << endl;
	outFile << save->tm_sec << endl;
	outFile << save->tm_year << endl;
	
	cout << "Saving " << name << "'s information to file" << endl;

	return true;
}

//************************************************************************************
//    loadFromFile()
//    A function that loads a GameCharacter from a file. Takes in a string parameter
//    	for the file name.
//    Return value: GameCharacter
GameCharacter GameCharacter::loadFromFile(string filename) {
	ifstream inFile(filename);

	if(inFile.fail()){
		cout << "Failed to open input file." << endl;
	}
	string name, save;
	int health, attack, defense;	

	inFile >> name;
	inFile >> health;
	inFile >> attack;
	inFile >> defense;

	struct tm saveOnFile;
	inFile >> saveOnFile.tm_wday;
        inFile >> saveOnFile.tm_mon; 
	inFile >> saveOnFile.tm_mday; 
	inFile >> saveOnFile.tm_hour; 
	inFile >> saveOnFile.tm_min;
        inFile >> saveOnFile.tm_sec;
	inFile >> saveOnFile.tm_year;

	GameCharacter newCharacter(name, health, attack, defense);
	time_t previousSave = mktime(&saveOnFile);
	newCharacter.setLastSave(previousSave);

	cout << "Loading character information from file..." << endl;

	return newCharacter;
}

//******************************************************************************************
//	displayDateOfLastSave()
//	A function that displays the date and time the character was saved last, without
//	  changing any values.
//	 Return value: void
void GameCharacter::displayDateTimeOfLastSave() const{
	if (lastSaveTime){
		char* saveTime = ctime(&lastSaveTime);
		cout << name << " was last saved: " << saveTime << endl;
	}

	else
		cout << "Character has not been saved!" << endl;
}

//*****************************************************************************************
//	displayTimeSinceLastSave()
//	A function that takes the difference from the last save and the time now.
//	Return Value: void
void GameCharacter::displayTimeSinceLastSave() const{
	time_t timeNow = time(0);
	//struct tm now  = (&timeNow);
	double timeDiff = difftime(lastSaveTime, timeNow);

	cout << "Time difference: " << timeDiff << " seconds" << endl;
}

//*******************************************************************************************
//	setLastSave()
//	A function that is a helper for the loadFromFile function. It sets the time 
//	  of the last save from file. It takes a time_t type variable.
//	Return value: void
void GameCharacter::setLastSave(time_t lastSave) {
	lastSaveTime = lastSave;
}
