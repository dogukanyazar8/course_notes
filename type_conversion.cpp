
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

	cout << typeid(c1 + c2).name() << "\n\n";	//char olan operandlar int t�r�ne d�n��t�r�lecek. char - char -> i�lem int.

	cout << typeid(s1 + s2).name() << "\n\n";	//short olan operandlar int t�r�ne d�n��t�r�lecek. short - short -> i�lem int.

	cout << typeid(c3).name() << "\n\n";		//herhangi bir d�n��t�rme yok.
	cout << typeid(+c3).name() << "\n\n";		//i�aret operat�r�. char olan operand int t�r�ne d�n��t�r�lecek. -> i�lem int.

	cout << typeid(ld1 + d1).name() << "\n\n";	//double olan operand long double t�r�ne d�n��t�r�lecek. long - double -> i�lem long double.

	cout << typeid(d2 + i1).name() << "\n\n";	//int olan operand double t�r�ne d�n��t�r�lecek. double - int -> i�lem double.

	cout << typeid(l1 + c4).name() << "\n\n";	//char olan operand int t�r�ne d�n��t�r�lecek. long - int -> i�lem long.
	
	cout << typeid(i2 + ui1).name() << "\n\n";	//operandlarin derecesi e�it. int + unsigned -> i�lem unsigned int.

	cout << typeid(l2 + ul1).name() << "\n\n";	//operandlarin derecesi farkl� fakat i�aretsiz t�r var. long + unsigned int-> i�lem unsigned long.
 
	cout << typeid(l3 + ui2).name() << "\n\n";	//operandlarin derecesi farkl� fakat i�aretsiz t�r var. long (4 byte) + unsigned int (4 byte) -> i�lem unsigned long.

	cout << typeid(ll1 + ui3).name() << "\n\n";	//operandlarin derecesi farkl� fakat i�aretsiz t�r var. long long (8 byte) + unsigned int (4 byte) -> i�lem long long.
}

*/