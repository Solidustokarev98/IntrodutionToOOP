//Не смог пока что перегрузить операторы сравнения
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

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

		//Constructors:
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

		//Operators:
		Fraction& operator=(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssignment:" << this << endl;
			return *this;
		}
		Fraction& operator*=(const Fraction& other)
		{
			int a = 2;
			int b = 3;
			a *= b;
			a /= b;
			//a == 2;
			return *this = *this*other;
		}
		Fraction& operator/=(const Fraction& other)
		{
			return *this = *this/other;
		}
		Fraction& operator+=(const Fraction& other)
		{
			return *this = *this+other;
		}
		Fraction& operator-=(const Fraction& other)
		{
			return *this = *this-other;
		}
		//Операторы сравнения (Нужно доработать)
		bool operator==(const Fraction& other)
		{
			
		}	
		bool operator!=(const Fraction& other)
		{
			
		}
		bool operator>(const Fraction& other)
		{
			
		}	
		bool operator<(const Fraction& other)
		{
			
		}	
		bool operator>=(const Fraction& other)
		{
			
		}	
		bool operator<=(const Fraction& other)
		{
			
		}

		//				Increment/Decrement:
		Fraction& operator++()	//Prefix increment
		{
			to_proper();
			integer++;
			return *this;
		}
		Fraction operator++(int)//Postfix (Suffix) increment
		{
			//Всегда принимает один и только один параметр типа 'int', и только 'int'
			//Это позволяет компилятору на уровне перегрузки функций отличить постфиксный инкремент от префиксного
			to_proper();
			Fraction old = *this;
			integer++;
			return old;
		}	
		Fraction& operator--()	//Prefix increment
		{
			to_proper();
			integer--;
			return *this;
		}
		Fraction operator--(int)//Postfix (Suffix) increment
		{
			//Всегда принимает один и только один параметр типа 'int', и только 'int'
			//Это позволяет компилятору на уровне перегрузки функций отличить постфиксный инкремент от префиксного
			to_proper();
			Fraction old = *this;
			integer--;
			return old;
		}

		//Methods:
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
		Fraction& reduce()
		{
			int more, less, rest;
			if (numerator > denominator)more = numerator, less = denominator;
			else less = numerator, more = denominator;
			do
			{
				rest = more % less;
				more = less;
				less = rest;
			} while (rest);
			int GCD = more;
			numerator /= GCD;
			denominator /= GCD;
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
	/*Fraction result;
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
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() - right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_CHECK
//#define INCREMENT_CHECK

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

#ifdef ARITHMETICAL_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2;
	double b = 5;
	double c = a * b;
	Fraction C = A * B;
	A.print();
	B.print();
	C.print();
	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif //  ARITHMETICAL_CHECK

#ifdef INCREMENT_CHECK
	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif //  INCREMENT_CHECK
	Fraction A(2, 3, 4);

	cout << A << endl;
}