/*

#include <stdio.h>
#include <stdlib.h>
#include <random>

#define NPOINTS 100'000'000

int main()
{
	using namespace std;
	mt19937 eng;
	uniform_int_distribution<> dist{ 0, 1 };
	int inside_count = 0;

	for (int i = 0; i < NPOINTS; ++i) {
		double x = dist(eng); 
		double y = dist(eng);
		if (x * x + y * y <= 1.) { 
			++inside_count;
		}
	}

	printf("Pi Sayisi %.12f\n", 4. * inside_count / NPOINTS);
}

*/