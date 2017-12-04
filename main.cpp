/** C++ BlackJack App - Game.cpp
 *
 *
 *
 *  @author         Raymond T
 *  @author         
 *  @author         
 *  @version        2017.12.03
 *  @since          5 Jan 2014
 *  @description    
 *                  
 *
 *  @credits:      String Conversion: http://www.cplusplus.com/forum/beginner/75634/ 
 *
 */
#include <iostream>
#include <iomanip>
#include <sstream>      // for stringstream
#include <cmath>
#include "Helpers.h"
#include "MyInputValidation.h"

using namespace std;
using namespace CPP_Helpers;
using namespace myValidation;


/** InitializeConsolePreferences() function: sets console defaults
 *
 */
inline void InitializeConsolePreferences()
{
	cout 	<< fixed << setprecision(2);
}

/** DisplayGameplayMenu() function: displays the menu list in the console
 *
 */
string DisplayGameplayMenu();

/** DisplayInstructions() function: displays the menu list in the console
 *
 */
void DisplayInstructions();

/** main() int: primary function of the game
 *
 */
int main()
{
	// Skip flag: will skip steps if truthy
	bool skip = false;
	// Get reference to users choice
	string choice;
	string choices[] = {"A", "B", "C", "D", "E"};
	const int LENGTH_OF_CHOICES = GetArrayLength(choices);
 	
 	// Set up the console
 	InitializeConsolePreferences(); 

 	// Loop the program
	do 
	{
		// Display the gameplay menu and store the choice
		// If skip flag is true ignore this line
		if (!skip) choice = ConvertCase("upper", DisplayGameplayMenu());
		// Reset the skip flag each time
		skip = false;
	
		// Compare choices
		if(choice == choices[0])
		{
			cout 	<< "Chose " << choices[0] << endl;
		}

		else if(choice == choices[1])
		{
			cout 	<< "Chose " << choices[1] << endl;
		}

		else if(choice == choices[2])
		{
			// Show the instructions menu
			DisplayInstructions();
		}

		else if(choice == choices[3])
		{
			cout 	<< "Chose " << choices[2] << endl;
		}

		else if(choice == choices[4])
		{
			cout 	<< "Chose " << choices[3] << endl;
		}

		else 
		{
			// Failed to recognize a correct choice
			// Enable skip to ignore outputting menu next loop
			skip = true;
			// Notify the user
			cout 	<< "Choice not recognized. Try again!...";
			// Get the choice again, this time, loop until correct
			choice = ConvertCase("upper", GetString(choices, LENGTH_OF_CHOICES));
		}
	}
  	while (ConvertCase("upper", choice) != "E");
	
	// Return an successful status			
	return 0;
}

/** DisplayGameplayMenu() function: displays the menu list in the console
 *
 */
string DisplayGameplayMenu()
{
	// Start with a clear console
	ClearScreen();
	// Welcome the user and display the gameplay menu
	cout 	<< "Welcome to Black Jack!" 			<< endl
			<< "What would you like to do?" << endl << endl;
	// Output the menu
	cout 	<< setw(5) << right << "A. " << left << "Begin Game" 				<< endl
			<< setw(5) << right << "B. " << left << "Configure Game Options" 	<< endl
			<< setw(5) << right << "C. " << left << "Read Instructions" 		<< endl
			<< setw(5) << right << "D. " << left << "End Game" 					<< endl
			<< setw(5) << right << "E. " << left << "Exit Program" 		<< endl << endl;

	// Get a choice from the user and return it
	cout 	<< "Choice: ";
	return GetString();
}

/** DisplayInstructions() function: displays the menu list in the console
 *
 */
void DisplayInstructions()
{
	// Clear the console
	ClearScreen();
	// Output
	cout 	<< "Welcome to BlackJack by Group 18" 				<< endl << endl
			<< "The game is simple, continue dealing cards until"		<< endl
			<< "Someone reaches 21 or the dealer goes busts!" 	<< endl << endl;

	// Get any key to exit instructions
	PauseConsole();
}