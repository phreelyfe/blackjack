/** Helpers.h
 *	
 *	A re-usable library of helpful console functions.
 *	   
 *	@author		Raymond Thompson
 *	@version	2017.12
 *	@since		3 Dec 2017
 *	@info 		Common helpful functions for cross platform use
*/

#ifndef _CPP_HELPERS

#define _CPP_HELPERS

#include <iostream>
#include <algorithm>

using namespace std;

namespace CPP_Helpers
{
	/** ClearScreen() 	function: determines the os and executes the
	 *					appropriate clear command
	 */
	void ClearScreen()
	{
		// Determine if there is a TERM variable set
		// so we can run the appropriate clear command
		// for that system
		const bool DEFINED = getenv("TERM") ? true : false;
	
		#ifdef POSIX
			// System is POSIX/Linux based
		    system("clear");
		#elif WINDOWS
			// System is windows based
		    system("cls");
		#else
		    // System is likely windows based
		    system("cls");
		#endif
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

	/** ConvertCase() 	function: converts a string to either upper or lower case
	 *	@param			string: either 'upper' or 'lower' representing 
	 * 					the case to convert to
	 *	@param			string: the string to convert
	 *
	 * 	@return			string: the converted string
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
}
#endif