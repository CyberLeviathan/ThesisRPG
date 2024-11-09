#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
//==============================> Classes
struct Player {
	string name;
	double health, maxHealth, attack, defense;
	int goldCoins, lifePotions;
};
struct Enemy {
	string name;
	double health, attack, defense;
	int goldDrop;
};
//==============================> Function prototypes
void introScreen();
void characterCreation(Player& player);
void characterClass(Player& player);
void characterInfo(Player& player);
void fightEnemy(Player& player, Enemy& enemy);
void heal(Player& player);
void shop(Player& player);
void wrongInput(Player& player);
//==============================> Globals
bool isWarrior = false;
bool isMage = false;
bool hasMetTheMilkman = false;
int playerHasSword = 0;
int playerHasStaff = 0;
int playerHasArmor = 0;
bool orcIsDead = false;
bool trollIsDead = false;
bool giantIsDead = false;
bool undeadIsDead = false;
bool lichKingIsDead = false;
char upperLeftCorner = (char)201;
char upperRightCorner = (char)187;
char horizontalLine = (char)205;
char leftVerticalLine = (char)185;
char rightVerticalLine = (char)204;
char verticalLine = (char)186;
char lowerLeftCorner = (char)200;
char lowerRightCorner = (char)188;
//==============================> Generic Arrays
string menuGeneric[] = {" (r) Return to the main menu "};
string battleString[] = { "You have defeated the enemy "};
//==============================> Game Menu Arrays
string menuGame[] = { "Game Menu",
					   " (1) Adventure ",
					   " (2) Stats/Inventory ",
					   " (3) Shop ",
					   " (e) Exit the game "};
//==============================> Shop Menu Arrays
string menuShop[] = { "Shop Menu",
					  " (1) BUY an Iron Sword for 100 gold ",
					  " (2) BUY an Iron Armor for 100 gold ",
					  " (3) BUY a Life Potion for 50 gold ",
                      " (1) BUY a Wooden Staff for 100 gold",
					  " (2) BUY a Cloth Armor for 100 gold "};
//==============================> Player Info Arrays
string playerInfo[] = { "Character Info",
						 " with ",
						 " Health ",
						 " Attack and ",
						 " Defense ",
						 "Life Potions ",
						 "Gold Coins ",};
//==============================> Character Class Arrays
string selectClass[] = { "Select Character Class",
						 " (1) I would like to be a brave ",
						 " (2) I would like to be an arcane ",
						 "Warrior",
					     "Mage"};
//==============================> Drawing The Box
string menuBox(int n, char c) {
	string str = "";
	for (int i = 0; i < n; i++)
		str = str + c;
	return str;
}
//==============================> Coloring
void color(int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, y);
}
//==============================> Intro Screen
void introScreen() {
	cout << upperLeftCorner << menuBox(63, horizontalLine) << upperRightCorner << endl;
	color(10);
	cout << "  Welcome to                   _                                       " << endl;
	cout << "      _____  _                (_)         ____  ____   ____            " << endl;
	cout << "     |_   _|| |__    ___  ___  _  ___    |  _ \\|  _ \\ / ___|         " << endl;
	cout << "       | |  | '_ \\  / _ \\/ __|| |/ __|   | |_) | |_) | |  _          " << endl;
	cout << "       | |  | | | ||  __/\\__ \\| |\\__ \\   |  _ <|  __/| |_| |       " << endl;
	cout << "       |_|  |_| |_| \\___||___/|_||___/   |_| \\_\\_|    \\____|       " << endl;
	cout << "                                                                       " << endl;
	cout << "                     by CyberLeviathan a.k.a. Silvestar Donchev        " << endl;
	color(7);
	cout << lowerLeftCorner << menuBox(63, horizontalLine) << lowerRightCorner << endl;
	this_thread::sleep_for(chrono::seconds(2));
	system("CLS");
}
//==============================> Character Creation
void characterCreation(Player& player) {
	color(10);
	cout << "Please enter a name for your character: ";
	color(14);
	cin >> player.name;
	color(7);
}
//==============================> Character Class Logic
void characterClass(Player& player) {
	while (1) {
		char classPick;
		color(10);
		cout << "Who would you like to be in this world, " << player.name << "?" << endl;
		cout << "" << endl;
		color(7);
		cout << upperLeftCorner << menuBox(8, horizontalLine) << leftVerticalLine;
		color(14);
		cout << selectClass[0];
		color(7);
		cout << rightVerticalLine << menuBox(8, horizontalLine) << upperRightCorner << endl;
		color(10);
		cout << selectClass[1];
		color(11);
		cout << selectClass[3] << endl;
		color(10);
		cout << selectClass[2];
		color(13);
		cout << selectClass[4];
		color(7);
		cout << endl;
		cout << lowerLeftCorner << menuBox(40, horizontalLine) << lowerRightCorner << endl;
		cin >> classPick;
		classPick = tolower(classPick);
		switch (classPick) {
		case '1': {
			isWarrior = true;
			player.maxHealth = 120;
			player.health = 120, player.attack = 2, player.defense = 6;
		}return;
		case '2': {
			isMage = true;
			player.maxHealth = 80;
			player.health = 80, player.attack = 6, player.defense = 2;
		}return;
		default: {
			wrongInput(player);
		}
		}
	}
}
void characterInfo(Player& player) {
	cout << upperLeftCorner << menuBox(7, horizontalLine) << leftVerticalLine;
	color(14);
	cout << playerInfo[0];
	color(7);
	cout << rightVerticalLine << menuBox(8, horizontalLine) << upperRightCorner << endl;
	color(10);
	if (isWarrior == true) {
		color(11);
		cout << " " << selectClass[3];
		color(10);
	}
	else if (isMage == true) {
		color(13);
		cout << " " << selectClass[4];
		color(10);
	}
	cout << playerInfo[1];
	color(12);
	cout << player.health << "/" << player.maxHealth;
	color(10);
	cout << playerInfo[2];
	color(7);
	cout << endl;
	color(14);
	cout << " " << player.attack;
	color(10);
	cout << playerInfo[3];
	color(14);
	cout << player.defense;
	color(10);
	cout << playerInfo[4];
	color(7);
	cout << endl;
	color(12);
	cout << " " << playerInfo[5];
	color(7);
	cout << "= " << player.lifePotions << endl;
	color(14);
	cout << " " << playerInfo[6];
	color(7);
	cout << "= " << player.goldCoins << endl;
	color(12);
	cout << menuGeneric[0];
	color(7);
	cout << endl;
	cout << lowerLeftCorner << menuBox(31, horizontalLine) << lowerRightCorner << endl;
	char infoChoice;
	cin >> infoChoice;
	infoChoice = tolower(infoChoice);
	switch (infoChoice) {
	case 'r': {
	}return;
	default: {
			wrongInput(player);
	}
	}
}
//==============================> Healing Logic
void heal(Player& player) {
	if (player.health < player.maxHealth && player.lifePotions >= 1) {
		cout << "You decided to quickly chug a Life Potion and after drinking it.." << endl;
		player.lifePotions -= 1;
		player.health += 50;
		if (player.health > player.maxHealth) {
			player.health = player.maxHealth;
		}
		cout << "You have " << player.health << " HP." << endl;
	}
	else if (player.lifePotions <= 0) {
		cout << player.name << ", you are out of Life Potions! Buy more in the shop." << endl;
	}
	if (player.health >= player.maxHealth) {
		cout << player.name << ", you are at full HP." << endl;
	}
}
//==============================> Battle Logic
void fightEnemy(Player& player, Enemy& enemy) {
	system("CLS");
	cout << upperLeftCorner << menuBox(34, horizontalLine) << leftVerticalLine;
	color(14);
	cout << "BATTLE";
	color(7);
	cout << rightVerticalLine << menuBox(34, horizontalLine) << upperRightCorner << endl;
	color(10);
	cout << " You encounter an enemy ";
	color(12);
	cout << enemy.name;
	color(10);
	cout << " with " << enemy.health << " HP, " << enemy.attack << " Attack and " << enemy.defense << " Defense." << endl;
	color(7);
	cout << lowerLeftCorner << menuBox(76, horizontalLine) << lowerRightCorner << endl;
	color(10);
	while (player.health > 0 && enemy.health > 0) {
		char attackOrDefend;
		color(10);
		cout << endl;
		cout << " (1) Attack!" << endl;
		cout << " (2) Defend!" << endl;
		cout << " (3) Drink a Life Potion!" << endl;
		cout << endl;
		color(7);
		cin >> attackOrDefend;
		color(10);
		switch (attackOrDefend) {
		case '1': {
			system("CLS");
			cout << "You chose to focus on attacking your enemy and after a brutal fight.." << endl;
			enemy.health = enemy.health - (player.attack * 2) / enemy.defense;
			cout << "> " << enemy.name << " has " << enemy.health << " HP left." << endl;
			player.health = player.health - enemy.attack / player.defense;
			cout << "> You have " << player.health << " HP left." << endl;
		} break;
		case '2': {
			system("CLS");
			cout << "You chose to focus on defending yourself and after an intense fight.." << endl;
			enemy.health = enemy.health - player.attack / enemy.defense;
			cout << enemy.name << " has " << enemy.health << " HP left." << endl;
			player.health = player.health - enemy.attack / (player.defense * 2);
			cout << "You have " << player.health << " HP left." << endl;
		} break;
		case '3': {
			system("CLS");
			heal(player);
		} break;
		default: {
			wrongInput(player);
		}
		}
	}
	system("CLS");
	cout << battleString[0];
	color(12);
	cout << enemy.name << "." << endl;
	color(10);
}
//==============================> Shop Logic
void shop(Player& player) {
	while (1) {
		char shopChoice;
		color(7);
		cout << upperLeftCorner << menuBox(12, horizontalLine) << leftVerticalLine;
		color(14);
		cout << menuShop[0];
		color(7);
		cout << rightVerticalLine << menuBox(12, horizontalLine) << upperRightCorner << endl;
		color(10);
		if (isWarrior == true) {
			cout << menuShop[1];
			cout << endl;
			cout << menuShop[2];
		}
		else if (isMage == true) {
			cout << menuShop[4];
			cout << endl;
			cout << menuShop[5];
		}
		cout << endl;
		cout << menuShop[3];
		color(7);
		cout << endl;
		color(12);
		cout << menuGeneric[0] << endl;
		color(7);
		cout << lowerLeftCorner << menuBox(35, horizontalLine) << lowerRightCorner << endl;
		cin >> shopChoice;
		color(10);
		shopChoice = tolower(shopChoice);
		switch (shopChoice) {
		case '1': {
			if (isWarrior == true) { // Checks player class in order to display the appropriate items.
				system("CLS");
				if (player.goldCoins >= 100 && playerHasSword <= 1) {
					player.goldCoins = player.goldCoins - 100;
					player.attack = player.attack + 1;
					playerHasSword = playerHasSword + 1;
					cout << "You bought an Iron Sword and your Attack has been increased by +1." << endl;
					cout << endl;
				}
				else if (player.goldCoins < 100) {
					cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
					cout << endl;
				}
				else if (playerHasSword >= 2) {
					cout << "You are not Roronoa Zoro, you can only carry two swords, dummy." << endl;
					cout << endl;
				}
			}
			else if (isMage == true) { // Checks player class in order to display the appropriate items.
				system("CLS");
				if (player.goldCoins >= 100 && playerHasStaff <= 1) {
					player.goldCoins = player.goldCoins - 100;
					player.attack = player.attack + 1;
					playerHasStaff = playerHasStaff + 1;
					cout << "You bought a Wooden Staff and your Attack has been increased by +1." << endl;
					cout << endl;
				}
				else if (player.goldCoins < 100) {
					cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
					cout << endl;
				}
				else if (playerHasStaff >= 2) {
					cout << "You are not Gandalf, you can only carry two staves, dummy." << endl;
					cout << endl;
				}

			}
		}break;
		case '2': {
			if (isWarrior == true) { // Checks player class in order to display the appropriate items.
				system("CLS");
				if (player.goldCoins >= 100 && playerHasArmor < 1) {
					player.goldCoins = player.goldCoins - 100;
					player.defense = player.defense + 4;
					playerHasArmor = playerHasArmor + 1;
					cout << "You bought an Iron Armor and your defense has been increased by +4." << endl;
					cout << endl;
				}
				else if (player.goldCoins < 100) {
					cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
					cout << endl;
				}
				else if (playerHasArmor >= 1) {
					cout << "You already own an armor, dummy." << endl;
					cout << endl;
				}
			}
			else if (isMage == true) { // Checks player class in order to display the appropriate items.
				system("CLS");
				if (player.goldCoins >= 100 && playerHasArmor < 1) {
					player.goldCoins = player.goldCoins - 100;
					player.defense = player.defense + 1;
					playerHasArmor = playerHasArmor + 1;
					cout << "You bought a Cloth Armor and your defense has been increased by +1." << endl;
					cout << endl;
				}
				else if (player.goldCoins < 100) {
					cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
					cout << endl;
				}
				else if (playerHasArmor >= 1) {
					cout << "You already own an armor, dummy." << endl;
					cout << endl;
				}
			}
		}break;
		case '3': {
			system("CLS");
			if (player.goldCoins >= 50) {
				player.goldCoins = player.goldCoins - 50;
				player.lifePotions = player.lifePotions + 1;
				cout << "You bought a Life Potion. " << "You now have " << player.lifePotions << " Life Potions." << endl;
				cout << endl;
			}
			else if (player.goldCoins < 50) {
				cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
				cout << endl;
			}
		}break;
		case 'r': {
		}return;
		default: {
			wrongInput(player);
		}
		}
	}
}
//==============================> Character Meets NPC Logic
void encounterNPC(Player& player) {
	system("CLS");
	string npcName = "The Milkman";
	hasMetTheMilkman = true;
	while (1) {
		char milkChoice;
		color(13);
		cout << npcName;
		color(10);
		cout << ": Well, hello there, adventurer!" << endl;
		color(13);
		cout << npcName;
		color(10);
		cout << ": Check out my SPECIAL Milk-Infused Amulet which is now for SALE!" << endl;
		cout << endl;
		color(7);
		cout << upperLeftCorner << menuBox(13, horizontalLine) << leftVerticalLine;
		color(14);
		cout << "MILK SHOP";
		color(7);
		cout << rightVerticalLine << menuBox(13, horizontalLine) << upperRightCorner << endl;
		color(10);
		cout << " (1) BUY the Milk Amulet for 100 gold  " << endl;
		color(4);
		cout << menuGeneric[0] << endl;
		color(7);
		cout << lowerLeftCorner << menuBox(37, horizontalLine) << lowerRightCorner << endl;
		color(7);
		cin >> milkChoice;
		color(10);
		milkChoice = tolower(milkChoice);
		switch (milkChoice) {
		case '1': {
			if (player.goldCoins >= 100) {
				player.goldCoins -= 100;
				player.attack += 1;
				player.defense += 1;
				system("CLS");
				cout << "You bought a milk amulet, weirdo." << endl;
				cout << endl;
			}
			else if (player.goldCoins < 100) {
				cout << "You have " << player.goldCoins << " Gold Coins, which are not enough to purchase the selected item." << endl;
				cout << npcName << " stares at you for a moment and walks away disappointed." << endl;
				cout << endl;
			}
		}return;
		case 'r': {
		}return;
		default: {
			wrongInput(player);
		}
		}
	}
}
//==============================> Game Menu drawing, text and coloring
void gameMenu() {
	// Drawing the box around the menu, coloring and calling the appropriate text from an array. 
	// The menu logic can be found in the main() function.
	color(7);
	cout << upperLeftCorner << menuBox(10, horizontalLine) << leftVerticalLine;
	color(14);
	cout << menuGame[0];
	color(7);
	cout << rightVerticalLine << menuBox(10, horizontalLine) << upperRightCorner << endl;
	color(10);
	cout << menuGame[1];
	color(7);
	cout << endl;
	color(10);
	cout << menuGame[2];
	color(7);
	cout << endl;
	color(10);
	cout << menuGame[3];
	color(7);
	cout << endl;
	color(12);
	cout << menuGame[4];
	color(7);
	cout << endl;
	cout << lowerLeftCorner << menuBox(31, horizontalLine) << lowerRightCorner << endl;
}
void wrongInput(Player& player) {
	color(10);
	system("CLS");
	cout << "You must pick one of the specified options, " << player.name << "." << endl;
	color(7);
}
//==============================> Main
int main() {
	// Random number generator and intro.
	srand(time(0));
	introScreen();

	// Character creation.
	Player player{ "Hero", 100, 100, 1, 1, 100, 1 };
	characterCreation(player);
	system("CLS");
	characterClass(player);
	system("CLS");

	// Enemy creation.
	Enemy orc{ "Orc", rand() % 40 + 10, 1, 2, 100 };
	Enemy troll{ "Troll", rand() % 60 + 20, 2, 3, 200 };
	Enemy giant{ "Giant", rand() % 80 + 20, 4, 5, 400 };
	Enemy undead{ "Undead", rand() % 100 + 20, 10, 10, 1000 };
	Enemy lichKing{ "Lich King", rand() % 200 + 20, 20, 20, 4000 };

	// Game menu logic + adventure logic.
	while (player.health > 0) {
		char adventureQuestion;
		gameMenu();
		cin >> adventureQuestion;
		adventureQuestion = tolower(adventureQuestion);
		switch (adventureQuestion) {
		case '1': {
			int npcChance = 1 + rand() % 7; // Generates a number from 1 to 7 as a chance to meet The Milkman NPC below.

			// Battle checks begin here.
			if (orcIsDead == false && player.health > 0) {
				if (npcChance == 7 && hasMetTheMilkman == false) {
					encounterNPC(player);
				}
				else {
					fightEnemy(player, orc);
					if (orc.health <= 0) {
						orcIsDead = true;
						player.goldCoins = player.goldCoins + orc.goldDrop;
					}
				}
			}
			else if (trollIsDead == false && player.health > 0) {
				if (npcChance == 7 && hasMetTheMilkman == false) {
					encounterNPC(player);
				}
				else {
					fightEnemy(player, troll);
					if (troll.health <= 0) {
						trollIsDead = true;
						player.goldCoins = player.goldCoins + troll.goldDrop;
					}
				}
			}
			else if (giantIsDead == false && player.health > 0) {
				if (npcChance == 7 && hasMetTheMilkman == false) {
					encounterNPC(player);
				}
				else {
					fightEnemy(player, giant);
					if (giant.health <= 0) {
						giantIsDead = true;
						player.goldCoins = player.goldCoins + giant.goldDrop;
					}
				}
			}
			else if (undeadIsDead == false && player.health > 0) {
				if (npcChance == 7 && hasMetTheMilkman == false) {
					encounterNPC(player);
				}
				else {
					fightEnemy(player, undead);
					if (undead.health <= 0) {
						undeadIsDead = true;
						player.goldCoins = player.goldCoins + undead.goldDrop;
					}
				}
			}
			else if (lichKingIsDead == false && player.health > 0) {
				if (npcChance == 7 && hasMetTheMilkman == false) {
					encounterNPC(player);
				}
				else {
					fightEnemy(player, lichKing);
					if (lichKing.health <= 0) {
						lichKingIsDead = true;
						player.goldCoins = player.goldCoins + lichKing.goldDrop;
					}
				}
			}
			// Battle checks end here.
			// Call fightEnemy with other enemies as needed.
		}break;
		case '2': {
			system("CLS");
			characterInfo(player); // Shows character stats and inventory.
			system("CLS");
		} break;
		case '3': {
			system("CLS");
			shop(player); // Shows the shop and available items.
			system("CLS");
		} break;
		case 'e': {
		} return 0;
		default: {
			wrongInput(player);
		}break;
		}
		if (giantIsDead == true && trollIsDead == true && orcIsDead == true && undeadIsDead == true && lichKingIsDead == true && player.health > 0) {
			system("CLS");
			cout << "Congratulations, " << player.name << ". " << "You beat the game." << endl;
			break;
		}
		else if (player.health <= 0) {
			system("CLS");
			cout << "You are dead, Gamer. You can restart the game and try again." << endl;
			break;
		}
	}
}