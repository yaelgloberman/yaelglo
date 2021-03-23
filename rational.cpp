//Yael globerman 324023175
//sadna c++
//exercise 3 question 1 
#include <iostream>
#include <cmath>
#include"rational.h"
using namespace std;
Rational::Rational(int x = 1, int y = 1)
{
	numerator = x;
	denominator = y;
	if (denominator == 0)
	{
		denominator = 1;
		cout << "ERROR\n";
	}
}
Rational::Rational(const Rational& r)        //copy constructor
{
	denominator = r.denominator;
	numerator = r.numerator;
}
void Rational::print()                                    //print function
{
	rationalReduction();
	if (denominator == 1 || numerator == 0)
		cout << numerator;
	else
	{
		cout << numerator << '/' << denominator << " ";
	}
}
void Rational::setNumerator(int x)
{
	numerator = x;
}
int Rational::getNumerator()
{
	return numerator;
}
void Rational::setDenominator(int y)               //function that sets the value of the denmoinator
{
	denominator = y;
	if (y == 0)                                    //if the number is 0 the function sets instaead 1
		denominator = 1;
}
int Rational::getDenominator()
{
	return denominator;
}
void Rational::rationalReduction()          //function that reduces the fraction
{
	int i;
	if (denominator == numerator)
	{
		numerator = 1;
		denominator = 1;
	}
	else
	{
		if (denominator > numerator)
			i = abs(denominator);
		else
			i = abs(numerator);
		for (; i > 0; i--)
		{
			if (denominator < 0 && numerator < 0)
			{
				numerator = abs(numerator);
				denominator = abs(denominator);
			}
			if (numerator % i == 0 && denominator % i == 0)
			{
				numerator /= i;
				denominator /= i;
				break;
			}
		}
	}
}
bool Rational::equal(Rational x)      //checks if the fractions are equal
{
	Rational r1;
	r1.numerator = numerator;
	r1.denominator = denominator;
	if (r1.numerator < 0 && r1.denominator < 0 || x.denominator < 0 && x.numerator < 0)           //  if the firs fraction is negitive num or the sec fraction is negiticve were doubeking them by -1 to make them positive
	{
		r1.numerator *= -1;
		r1.denominator *= -1;
	}
	r1.rationalReduction();             //reducing the Fraction
	x.rationalReduction();              //reducing the Fraction
	if (x.numerator == r1.numerator && x.denominator == r1.denominator || x.denominator == r1.numerator && x.numerator == r1.denominator)            //cheching if the numerator of one fraction is the same as the other one and etc to the denominator
		return true;
	else
		return false;
}

Rational Rational::add(Rational y)               //Summed up the two fractions
{
	Rational sum;
	Rational r2;
	r2.numerator = numerator;
	r2.denominator = denominator;
	r2.rationalReduction();                      //reducing the Fraction 
	y.rationalReduction();                         //reducing the Fraction
	sum.numerator = r2.numerator * y.denominator + r2.denominator * y.numerator;            //Multiply the numerator by the denominator 
	if (sum.numerator == 0)
	{
		sum.denominator = 1;
	}
	else
	{
		sum.denominator = r2.denominator * y.denominator;                             //  Multiply the denominator by the denominator
		sum.rationalReduction();                                                   // //reducing the Fraction
	}
	return sum;
}
Rational Rational::operator+(const Rational& r)const
{
	int x = numerator * r.denominator + r.numerator * denominator;
	int y = denominator * r.denominator;
	Rational temp(x, y);
	temp.rationalReduction();
	return temp;
}
Rational Rational:: operator-(Rational r)
{
	int x = (numerator * r.getDenominator()) - (r.getNumerator() * denominator);
	int y = denominator * r.getDenominator();
	Rational temp(x, y);
	temp.rationalReduction();
	return temp;
}
Rational Rational::operator*(Rational r)
{
	int x = numerator * r.getNumerator();
	int y = denominator * r.getDenominator();
	Rational tmp(x, y);
	tmp.rationalReduction();
	return tmp;
}
Rational Rational::operator/(const Rational& r1) const
{
	Rational Temporary = *this;
	Temporary.numerator *= r1.denominator;
	Temporary.denominator *= r1.numerator;
	Temporary.rationalReduction();
	return Temporary;
}
//Rational Rational ::operator/(const Rational& r)const
//{
//	int x = numerator * abs(r.denominator);
//	int y = denominator * r.numerator;
//	if (r.denominator < 0)
//	{
//		y *= -1;
//	}
//	Rational tmp(x, y);
//	tmp.rationalReduction();
//	return tmp;
//}
Rational& Rational:: operator++()
{
	numerator += denominator;
	return *this;
}
Rational Rational:: operator++(int r)
{
	Rational temp(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational Rational:: operator--()
{
	numerator -= denominator;
	return *this;
}
Rational Rational:: operator--(int r)
{
	Rational temp(numerator, denominator);
	numerator -= denominator;
	return temp;
}
bool Rational:: operator<=(const Rational& r)const
{
	return ((numerator / denominator) <= (r.numerator / r.denominator));
}
bool Rational:: operator>=(const Rational& r)const
{
	return !((numerator / denominator) <= (r.numerator / r.denominator));
}
bool Rational:: operator>(Rational r)
{
	return ((numerator / denominator) > (r.numerator / r.denominator));
}

bool Rational::operator==(const Rational& r)const
{
	return ((numerator == r.numerator) && (denominator == r.denominator));
}
bool Rational:: operator!=(const Rational& r)const
{
	return !(*this == r);
}
