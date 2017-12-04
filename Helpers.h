/** Helpers.h
 *	
 *	A re-usable library of helpful console functions.
 *	   
 *	@author				Raymond Thompson
 *	@version			2017.12
 *	@since				3 Dec 2017
 *	@info 				Common helpful functions for cross platform use
 *
 *	@credits			ClearScreen: http://www.dreamincode.net/forums/topic/90898-cross-platform-clear-screen/
 *						PauseConsole: http://www.cplusplus.com/forum/beginner/36318/
 *
*/

#ifndef _CPP_HELPERS

#define _CPP_HELPERS

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h> //For system commands


using namespace std;

namespace CPP_Helpers
{
	//Detect and define which command to use
	#ifndef WIN32
		#define COMMAND "clear" //Clears a linux console screen
	#else
		#define COMMAND "cls" //Clears a windows console screen
	#endif

	/** ClearScreen() 	function: determines the os and executes the
	 *					appropriate clear command
	 */
	void ClearScreen() {
		// Run the appropriate system command
		system( COMMAND );
	}

	/** PauseConsole() 	function: universal press any key function
	 *
	 */
	void PauseConsole()
	{
		cout 	<< "Press any key to exit ...";
		cin.ignore();
		cin.get();
		ClearScreen();
	}

	/** ConvertCase() 	        function: converts a string to either upper or lower case
     *	@param type             either 'upper' or 'lower' representing
	 * 					        the case to convert to
	 *	@param toBeConverted    the string to convert
	 *
	 * 	@return			s: the converted string
	 */
	string ConvertCase(string type, string toBeConverted)
	{
	  	// Copy input string to local var for translation
	  	string s = toBeConverted;
		
		// If the type is equal to 'upper'
		if (type == "upper")
		{
			// Transform the string to upper
		  	transform(s.begin(), s.end(), s.begin(), ::toupper);
		}
		// Else If the type is equal to 'lower'
		else if (type == "lower")
		{
			// Transform the string to lower
		  	transform(s.begin(), s.end(), s.begin(), ::tolower);
		}
		return s;
	}

	/** GetArrayLength()        function: takes an array as an argument and retunrs it's length
     *	@param T 	            takes in a template datatype as the array
	 *
	 * 	@return					N: integer representing the length
	 */
	template <typename T, std::size_t N>
	constexpr std::size_t GetArrayLength (const T(&)[N])
	{ return N; }
}
#endif
