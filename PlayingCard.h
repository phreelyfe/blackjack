/** PlayingCard.h
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

#ifndef _PLAYING_CARD

#define _PLAYING_CARD

#include <iostream>
#include <stdio.h>
#include <stdlib.h> //For system commands
#include "Helpers.h"


using namespace std;
using namespace CPP_Helpers;


class PlayingCard
{
/***************************************************************************
 *  PRIVATE CLASS VARIABLE DECLARATIONS
 ***************************************************************************/
private:
	// Define the suits being used
	const string SUITS[]: {"Hearts", "Spades", "Clubs", "Diamonds"};
	const MAXIMUM_SUITS: GetArrayLength(SUITS);
	// Define the ranks being used
	const string RANKS[]: { 			// 13 Ranks minus the joker 
		"Ace", "2", "3", "4", "5",
		"6", "7", "8", "9", "10",
		"Jack", "Queen", "King"
	};
	const MAXIMUM_RANKS: GetArrayLength(RANKS);

/***************************************************************************
 *  PUBLIC CLASS VARIABLE DECLARATIONS
 ***************************************************************************/
public:
	int suit;
	int rank;
	bool faceUp;
	
	/***************************************************************************
     *  CLASS OPERATOR OVERLOADS
     ***************************************************************************/
    operator string() const;

	/***************************************************************************
     *  CLASS CONSTRUCTORS
     ***************************************************************************/

    /** PlayingCard() 		constructor: default constructor
     */
	PlayingCard()
	{
		// Set a random Suit and Rank
		// and turn card face down
		SetSuit( GetRandomSuit() );
		SetRank( GetRandomRank() );
		SetFaceUp( false );
	}

	/** PlayingCard() 		constructor: default constructor
	 * 	@param 				string: the rank string
	 *	@param 				string: the suit string
     */
	PlayingCard(string rank, string suit)
	{
		
	}

	/***************************************************************************
     *  CLASS GETTER METHODS
     ***************************************************************************/

	/** Suit() 		function: returns the suit
     * @return      int: 
     */
	int Suit() const { return suit; }

	/** SuitName()	function: returns the suit name
     * @return      string: represents the name of the current suit
     */
	string SuitName() const { return SUITS[ suit ]; }

	/** Rank() 		function: returns the rank
     * @return      int: 
     */
	int Rank() const { return rank; }

	/** RankName()	function: returns the rank name
     * @return      string: represents the name of the current rank
     */
	string RankName() const { return SUITS[ suit ]; }
	
	/** FaceUp()	function: returns true if the card is face up
     * @return      bool: true if the face is up, false if not
     */
	bool FaceUp() const { return faceUp; }

	/** NumberOfSuits()	function: returns true if the card is face up
     * @return      int: represents the number of suits available
     */
	int NumberOfSuits() const { return MAXIMUM_SUITS; }

	/** NumberOfRanks()	function: returns true if the card is face up
     * @return      int: represents the number of ranks available
     */
	int NumberOfRanks() const { return MAXIMUM_SUITS; }


	/***************************************************************************
     *  CLASS SETTER METHODS
     ***************************************************************************/

	/** SetSuit() 		function: returns the suit
     * @return      	int: 
     */
	void SetSuit(string suitToBeSet);

	/** SetRank() 		function: returns the rank
     * @return      	int: 
     */
	void SetRank(string rankToBeSet);

	/** SetFaceUp()	function: returns true if the card is face up
     * @return      bool: true if the face is up, false if not
     */
	void SetFaceUp( bool faceUp );

	/** PlayingCard::Set()		function: modifies a chosen parameter with a value
	 * @param      				string: parameter name to modify
	 * @param      				string: value of the parameter to modify
	 */
	void Set(string parameter, string value);

	/***************************************************************************
     *  CLASS METHODS
     ***************************************************************************/

	/** GetRandomNumber()	function: returns true if the card is face up
     * @return      		int: true if the face is up, false if not
     */
	int GetRandomNumber( const int MINIMUM, const int MAXIMUM );

	/** GetRandomSuit()		function: returns true if the card is face up
     * @return      		int: true if the face is up, false if not
     */
	int GetRandomSuit();

	/** GetRandomRank()		function: returns true if the card is face up
     * @return      		int: true if the face is up, false if not
     */
	int GetRandomRank();

}


/***************************************************************************
 *  CLASS FUNCTION PROTOTYPE DEFINITIONS
 ***************************************************************************/

/** string()	function: returns a stringified version of this card
 * @return      string: represents a string version of this card
 */
PlayingCard::operator string() const
{
    stringstream strOut;
    strOut  << *(this).Rank() << " of " << *(this).Suit();

    return strOut.str();
}

/** PlayingCard::Set()		function: modifies a chosen parameter with a value
 * @param      				string: parameter name to modify
 * @param      				string: value of the parameter to modify
 */
PlayingCard::Set(string parameter, string value)
{
	// If chain to detemrine whether we should set
	// either the suit or the rank

	// Set suit
	if (ConvertCase("lower", parameter) == "suit")
		*(this).SetSuit( value );
	// Set rank
	if (ConvertCase("lower", parameter) == "rank")
		*(this).SetRank( value );

	// By default card is face down
	*(this).SetFaceUp( false );
}






#endif
