//****************************************************************
//    Braden Harris
//    CS-355
//    Assignment #3
//    9/1/2023
//    Create and implement a GameCharacter class. This class
//    	should be able to attack and deal damage. Characters
//    	can be compared, loaded from file, and saved to file.
    	
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>
using namespace std;

class GameCharacter{
	private:
		string name;
		int maxHealth;
		int healthPoints;
		int attackPoints;
		int defensePoints;
		bool isAlive;

	public:
		GameCharacter(string cName, int health, int aPoints, int dPoints);
		const string& getName()const;
		int getMaxHealth() const;
		int getHealthPoints() const;
		int getAttackPoints() const;
		int getDefensePoints() const;
		bool getIsAlive() const;
		void takeDamage(int damage);
		void attack(GameCharacter& target);
		bool operator>(const GameCharacter& rhs);
		bool operator<(const GameCharacter& rhs);
		GameCharacter operator+(GameCharacter& rhs);
		friend ostream& operator<<(ostream&, GameCharacter);
		bool saveToFile(string filename) const;
		GameCharacter loadFromFile(string filename) const;

};
#endif
