/** Header_Template.h
 *	
 *	Example template of a standard header file.
 *	   
 *	@author				Raymond Thompson
 *	@version			2017.12
 *	@since				3 Dec 2017
 *	@info 				Example template of a standard header file
 *
 *	@credits			
 *
*/

#ifndef _CLASS_NAME

#define _CLASS_NAME

#include <iostream>
#include <stdio.h>
#include <stdlib.h> //For system commands


using namespace std;

class Class_Name
{
private:
	
public:
	// Default Constructor
	Class_Name() {}

	// Getter
	Get() const;

	// Setter
	Set();
}

// Prototype Get
Class_Name::Get() {}

// Prototype Set
Class_Name::Set() {}

#endif