#pragma once
#include <string> 
#include <iostream> 
using namespace std; 

class Rational
{
private:
	int numerator;
	int denominator;

	// Precondition: Int function named GCD, accepts two int arguments.
	// Postcondition: utilizes recursion to find and return the greatest common divisor
	int GCD(int numer, int denom)
	{
		if (numer % denom == 0)
		{
			return denom;
		}
		else
			return GCD(denom, numer % denom);
	}

	// Precondition: void function named normalize.
	// Postcondition: utilizes the GCD function to find the greatest common divisor and then 
	// if there is a negative number in the denominator it swaps the negative sign to the top. 
	void normalize()
	{
		// Declare variable, hold the greatest common divisor
		int gcd = 0;
		// Find the greatest common divisor
		gcd = GCD(numerator, denominator);
		// Divide the numerator and denominator by GCD.
		numerator /= gcd;
		denominator /= gcd;
		// Checks if the denominator is negative, moves the sign to the numerator
		if (denominator < 0)
		{
			numerator *= -1;
			denominator = abs(denominator);
		}
	}
	
public:
	Rational() : numerator(0), denominator(1) // Default constructor
	{}

	class DivideByZero {};		//Exception Class thrown when divide by 0
	class InvalidSubscript {};	//Excpetion Class thrown when accessing invalid index

	// Constructor with arguments
	Rational(int n, int d)
	{
		if (d == 0)
			divideByZeroError();
		else
		{
			numerator = n;
			denominator = d;
			normalize();
		}
	}

	// Precondition: Void function named checkBounds, accepts two int arguments.
	// Postcondition: Throws an exception if the index is less than 0 or greater than or equal to the size.
	void checkBounds(int index, int size)
	{
		if (index < 0 || index >= size)
			throw InvalidSubscript();
	}

	// Mutators
	
	// Precondition: Void function named setNumerator, accepts int argument
	// Postcondition: Assigns the numerator member to int n, calls normalize after.
	void setNumerator(int n)
	{
		numerator = n;
	}

	// Precondition: Void function named setDenominator, accepts int argument
	// Postcondition: Assigns the denominator member to int d, calls normalize after
	void setDenominator(int d)
	{
		if (d == 0)
			divideByZeroError();
		else
		{
			denominator = d;
			normalize();
		}
	}

	// Accessors
	
	// Precondition: Int function called getNumerator, constant
	// Postcondition: returns the numerator value
	int getNumerator() const
	{
		return numerator;
	}

	// Precondition: Int function called getDenominator, constant
	// Postcondition: Returns the denominator value 
	int getDenominator() const
	{
		return denominator;
	}

	// Precondition: Bool function called operator ==, accepts a constant Rational object
	// Postcondition: Returns true or false depending on the cross multiplication values.
	bool operator == (const Rational& obj) 
	{
		// Finds the values of the cross multiplication
		int leftCrossMult = numerator * obj.getDenominator();			//n1 * d2
		int rightCrossMult = obj.getNumerator() * denominator;			//n2 * d1
		// If they are the same return true, if not return false.
		if (leftCrossMult == rightCrossMult)
			return true;
		else
			return false;
	}

	// Precondition: Bool function called operator <, accepts a constant Rational object
	// Postcondition: Returns true or false depending on the cross multiplication values.
	bool operator < (const Rational& obj) 
	{
		// Finds the values of the cross multiplication
		int leftCrossMult = numerator * obj.getDenominator();			//n1 * d2
		int rightCrossMult = obj.getNumerator() * denominator;			//n2 * d1
		// If the left is less than the right return true, if not return false
		if (leftCrossMult < rightCrossMult)
			return true;
		else
			return false;
	}

	// Precondition: Void function named divideByZeroError
	// Postcondition: Throws the class exception DivideByZero()
	void divideByZeroError()
	{
		throw DivideByZero();
	}

	// Precondition: Friend function named ostream operator <<, accepts ostream variable and rational object arguments
	// Postcondition: 
	friend ostream& operator <<(ostream& out, const Rational& obj)
	{
		// Displays the numerator and denominator
		out << obj.numerator << "/" << obj.denominator;
		// Return the display
		return out;
	}
};
