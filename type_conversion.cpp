
/*

#include <iostream>

int main()
{
	using namespace std;
	
	char c1 = 5;
	char c2 = 7;
	
	short s1 = 10;
	short s2 = 15;

	char c3 = 10;

	long double ld1 = 4.;
	double d1;

	double d2 = 5.;
	int i1 = 0;

	long l1 = 10.0;
	char c4 = 5;

	int i2 = 10;
	unsigned int ui1 = 15;

	long l2 = 10;
	unsigned long ul1 = 10;

	long l3 = 12;
	unsigned int ui2 = 15;

	long long ll1 = 15;
	unsigned int ui3 = 20;

	cout << typeid(c1 + c2).name() << "\n\n";	//char olan operandlar int türüne dönüstürülecek. char - char -> islem int.

	cout << typeid(s1 + s2).name() << "\n\n";	//short olan operandlar int türüne dönüstürülecek. short - short -> islem int.

	cout << typeid(c3).name() << "\n\n";		//herhangi bir dönüstürme yok.
	cout << typeid(+c3).name() << "\n\n";		//isaret operatörü. char olan operand int türüne dönüstürülecek. -> islem int.

	cout << typeid(ld1 + d1).name() << "\n\n";	//double olan operand long double türüne dönüstürülecek. long - double -> islem long double.

	cout << typeid(d2 + i1).name() << "\n\n";	//int olan operand double türüne dönüstürülecek. double - int -> islem double.

	cout << typeid(l1 + c4).name() << "\n\n";	//char olan operand int türüne dönüstürülecek. long - int -> islem long.
	
	cout << typeid(i2 + ui1).name() << "\n\n";	//operandlarin derecesi esit. int + unsigned -> islem unsigned int.

	cout << typeid(l2 + ul1).name() << "\n\n";	//operandlarin derecesi farkli fakat isaretsiz tür var. long + unsigned int-> islem unsigned long.

	cout << typeid(l3 + ui2).name() << "\n\n";	//operandlarin derecesi farkli fakat isaretsiz tür var. long (4 byte) + unsigned int (4 byte) -> islem unsigned long.

	cout << typeid(ll1 + ui3).name() << "\n\n";	//operandlarin derecesi farkli fakat isaretsiz tür var. long long (8 byte) + unsigned int (4 byte) -> islem long long.
}

*/