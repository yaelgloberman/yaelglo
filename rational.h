#pragma once
//#pragma once
class Rational
{
private:
	int numerator;
	int denominator;
	void rationalReduction();                       //function that reduces the fraction
public:
	Rational(int x, int y);        //constructor
	Rational(const Rational& v);                    //copy constructor                             
	
	void setDenominator(int);                       //function that sets the value of the denmoinator
	void setNumerator(int);                         //function that sets the value of the Numerator

	int getDenominator();                           //function that returns the value of the denmoinator
	int getNumerator();                             //function that returns the value of the Numerator
	
	void print();                                   //print function
	bool equal(Rational);                           //function that checks if the numbers are equal or not
	Rational add(Rational);                         //dfunction that returns the sum of to rational numbers
	Rational operator+(const Rational& r)const;   //function that retunrning the sum of two numbers
	Rational operator-(const Rational& r) const;
	Rational operator*(const Rational& r) const;
	Rational operator/(const Rational&r)const;
	Rational& operator++();		//prefix
	Rational operator++(int);		//postfix
	Rational& operator--();          //prefix
	Rational operator--(int);      //postfix
	bool operator>=(const Rational& r)const;
	bool operator<=(const Rational& r)const;
	bool operator>(const Rational& r) const;
	bool operator<(const Rational& r) const;
	bool operator==(const Rational& r)const;
	bool operator!=(const Rational& r)const;
};

//
//};
