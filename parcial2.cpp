#include <iostream>
#include "parcial2.h"
using namespace std;

int aleatorio(int menor, int mayor)
{
	srand((unsigned) time(0));

	return(menor + (rand() % (mayor - menor)));
}

double seno(int angulo)
{
	return(sin((double)angulo * M_PI/180));
}




