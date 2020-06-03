#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	
	matrix m(2, 2, 2);
	m.settimer(1000, 2000, 1500, 2000, 800);
	m.Countc();
	m.seematrix(m.getA());
	m.seematrix(m.getB());
	m.seematrix(m.getE());
	m.seematrix(m.getG());
	m.seematrixC();
	m.seetimer();
}
