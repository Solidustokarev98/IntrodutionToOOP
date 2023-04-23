#include<iostream>
using namespace std;

class Fraction
{
	int integer;		//Целое число
	int numerator;		//Числитель
	int denominator;	//Знаменатель

	public:
		int get_integer()const
		{
			return integer;
		}	
		int get_numerator()const
		{
			return numerator;
		}
		int get_denominator()const
		{
			return denominator;
		}	

		void set_integer(int integer)
		{
			this->integer = integer;
		}	
		void set_numerator(int numerator)
		{
			this->numerator = numerator;
		}
		void set_denominator(int denominator)
		{
			if (denominator == 0)	denominator = 1;
				this->denominator = denominator;
		}

		Fraction()
		{
			this->integer = 0;
			this->numerator = 0;
			this->denominator = 1;
			cout << "DefaultConstruct:\t" << this << endl;
		}
		
		Fraction(int integer)
		{
			this->integer = integer;
			this->numerator = 0;
			this->denominator = 1;
		}

		Fraction(int numerator, int denominator)
		{
			this->integer = 0;
			this->numerator = numerator;
			set_denominator(denominator);
		}

		Fraction(int integer, int numerator, int denominator)
		{
			this->integer = integer;
			this->numerator = numerator;
			set_denominator(denominator);
			cout << "Constructor:\t" << this << endl;
		}

		Fraction(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyConstructor:" << this << endl;
		}

		~Fraction()
		{
		
			cout << "Destructor:\t" << this << endl;
		}

		Fraction& operator=(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssignment:" << this << endl;
			return *this;
		}
		Fraction& to_improper()
		{
			numerator += integer * denominator;
			integer = 0;
			return *this;
		}

		Fraction& to_proper()
		{
			integer += numerator / denominator;
			numerator %= denominator;
			return *this;
		}

		Fraction inverted()const
		{
			Fraction inverted = *this;
			inverted.to_improper();
			inverted.numerator ^= inverted.denominator;
			inverted.denominator ^= inverted.numerator;
			inverted.numerator ^= inverted.denominator;
			return inverted;
		}

		void print()const
		{
			if (integer) cout << integer;
			if (numerator)
			{
				if (integer)cout << "(";
				cout << numerator << "/" << denominator;
				if (integer)cout << ")";
			}
			else if (integer == 0)cout << 0;
			cout << endl;
		}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
/*	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/

	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	return result;*/

	//Прямо в return создавем временный безымянный объект типа Fraction
	//Временные безымянные объекты существуют в пределах одного выражения, и удаляются из памяти позавершении выражения
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

		/*left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
		return left * right.inverted();
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef  CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B=5;
	B.print();

	Fraction C(1,2);
	C.print();

	Fraction D(2,3,4);
	D.print();
#endif //  CONSTRUCTORS_CHECK

	Fraction A(2,3,4);
	A.print();
	
	Fraction B(3,4,5);
	B.print();
	
	Fraction C=A*B;
	C.print();
	
	Fraction D = A / B;
	D.print();
}