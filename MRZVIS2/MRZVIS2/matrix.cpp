#include "matrix.h"
#include <stdio.h>

matrix::matrix(unsigned int p1, unsigned int m1, unsigned int q1) : m(m1), p(p1), q(q1), time(){
	min_time = chrono::milliseconds(0);
	max_time = chrono::milliseconds(0);
	sum_time = chrono::milliseconds(0);
	mult_time = chrono::milliseconds(0);
	minus_time = chrono::milliseconds(0);
	matrixpush(A, p, m);
	matrixpush(B, m, q);
	matrixpush(E, m);
	matrixpush(G, p, q);
	matrixpushC(C, p, q);
}


void matrix::matrixpush(vector<vector<double> >& matr, unsigned int stringsize, unsigned int columnsize) {
	for (int i = 0; i < stringsize; i++) {
		vector<double> temp;
		for (int j = 0; j < columnsize; j++) {
			double tmp = matrix::drand(-1, 1);
			temp.push_back(tmp);
		}
		matr.push_back(temp);
	}
}

void matrix::matrixpush(vector<double>& matr, unsigned int stringsize) {
	for (int i = 0; i < stringsize; i++) {
		double tmp = matrix::drand(-1, 1);
		matr.push_back(tmp);
	}
}

void matrix::matrixpushC(vector<vector<double>>& matr, unsigned int stringsize, unsigned int columnsize) {
	for (int i = 0; i < stringsize; i++) {
		vector<double> temp;
		for (int j = 0; j < columnsize; j++) {
			double tmp = 0;
			temp.push_back(tmp);
		}
		matr.push_back(temp);
	}
}

double matrix::drand(double b, double e)
{
	return b + (rand() % static_cast<int>((e - b) * 1000)) / 1000.;
}


/////////////////////////////////////////////////////////////////////////


double matrix::min(vector<double> vect) {
	time.addtime(min_time);
	double result = 2;
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] < result) result = vect[i];
	}
	return result;
}

double matrix::max(vector<double> vect) {
	time.addtime(max_time);
	double result = -2;
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > result) result = vect[i];
	}
	return result;
}

double matrix::min(double a, double b) {
	time.addtime(min_time);
	return a < b ? a : b;
}

double matrix::max(double a, double b) {
	time.addtime(max_time);
	return a > b ? a : b;
}

double matrix::multiply(double a, double b) {
	time.addtime(mult_time);
	return a * b;
}

double matrix::multiply(double a, double b, double c) {
	time.addtime(mult_time);
	return a * b * c;
}

double matrix::minus(double a, double b)
{
	time.addtime(minus_time);
	return a - b;
}

double matrix::sum(double a, double b) {
	time.addtime(sum_time);
	return a + b;
}

double matrix::multiply(vector<double> vect) {
	time.addtime(mult_time);
	double fin = 1;
	for (int i = 0; i < vect.size(); i++) {
		fin *= vect[i];
	}
	return fin;
}


///////////////////////////////////////////////////////////////////////////


void matrix::cCount(int i, int j){
	double f = fCount(i, j);
	double d = dCount(i, j);
	double g3;
	double g1;
	double d1;
	double fg;
	double fd;
	double mx;
	double d2;
	thread a1([&]() {
		int a = 3;
		int b = G[i][j];
		g3 = multiply(a,b);
		});
	thread b1([&]() {
		d1 = minus(1, d);
		});
	thread a2([&]() {
		fg = multiply(f, G[i][j]);
		});
	a1.join();
	thread b2([&]() {
		g1 = minus(1, G[i][j]);
		});
	b1.join();
	thread b3([&]() {
		fd = sum(f, d);
		});
	a2.join();
	thread a3([&]() {
		g3 = minus(g3, 2);
		});
	b2.join();
	b3.join();
	thread b4([&]() {
		mx = max(fd, 0);
		});
	a3.join();
	thread a4([&]() {
		fg = multiply(fg, g3);
		});
	b4.join();
	thread b5([&]() {
		mx = multiply(4, mx);
		});
	thread b6([&]() {
		d2 = multiply(3, d1);
		});
	a4.join();
	b5.join();
	b6.join();
	thread b7([&]() {
		mx = minus(mx, d2);
		});
	b7.join();
	thread b8([&]() {
		mx = multiply(mx, G[i][j]);
		});
	b8.join();
	thread b9([&]() {
		mx = sum(d1, mx);
		});
	b9.join();
	thread b10([&]() {
		mx = multiply(mx, g1);
		});
	b10.join();
	thread fin([&]() {
		this->C[i][j] = sum(mx, fg);
		});
	fin.join();
}

double matrix::fCount(int i, int j)
{
	double coun = 1;
	for (int k = 0; k < m; k++) {
		double firstvar;
		double e2;
		double third;
		double fo;
		double ek;
		double finvar;
		thread maxim([&]() {
			double a = 1 - A[i][k];
			double b = B[k][j];
			firstvar = max(a,b);
			});
		thread t([&]() {
			e2 = multiply(2, E[k]);
			});
		thread thir([&]() {
			third = max((1 - B[k][j]), A[i][k]);
			});
		t.join();
		thread m([&]() {
			e2 = minus(e2, 1);
			});
		m.join();
		thread mult([&]() {
			e2 = multiply(firstvar, e2, E[k]);
			});
		maxim.join();
		thread a([&]() {
			fo = multiply(4, firstvar);
			});
		thir.join();
		thread b2([&]() {
			ek = minus(1, E[k]);
			});
		a.join();
		thread a2([&]() {
			fo = minus(fo, 2);
			});
		mult.join();
		b2.join();
		a2.join();
		thread a3([&]() {
			fo = multiply(fo, E[k]);
			});
		a3.join();
		thread a4([&]() {
			fo = sum(1, fo);
			});
		a4.join();
		thread a5([&]() {
			fo = multiply(fo, third, ek);
			});
		a5.join();
		thread fina([&]() {
			finvar = sum(fo, e2);
			});
		fina.join();
		thread cou([&]() {
			coun = multiply(coun, finvar);
			});
		cou.join();
	}
	return coun;
}

double matrix::dCount(int i, int j) {
	double res = 1;
	double temp;
	for (int k = 0; k < m; k++) {
		thread a1([&]() {
			temp = min(A[i][k], B[k][j]);
			});
		a1.join();
		thread a2([&]() {
			temp = minus(1, temp);
			});
		a2.join();
		thread a3([&]() {
			res = multiply(res, temp);
			});
		a3.join();
	}
	return res;
}

void matrix::Countc() {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			cCount(i, j);
		}
	}
}


///////////////////////////////////////////////////////////


void matrix::seematrix(vector<vector<double>> matr, int a, int b) {
	for (int i = 0; i < a; i++) {
		cout << "[ ";
		for (int j = 0; j < b; j++) {
			cout << matr[i][j] << " ";
		}
		cout << " ]" << endl;
	}
}

void matrix::seematrix(vector<double> matr, int a) {
	cout << "[ ";
	for (int i = 0; i < a; i++) {
		cout << matr[i] << " ";
	}
	cout << " ]" << endl;
}

void matrix::seematrixC() {
	for (int i = 0; i < C.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < C[i].size(); j++) {
			cout << C[i][j] << " ";
		}
		cout << " ]" << endl;
	}
}

void matrix::seematrix(vector<vector<double>> matr) {
	for (int i = 0; i < matr.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < matr[i].size(); j++) {
			cout << matr[i][j] << " ";
		}
		cout << " ]" << endl;
	}
	cout << endl;
}

void matrix::seematrix(vector<double> matr) {
	cout << "[ ";
	for (int i = 0; i < matr.size(); i++) {
		cout << matr[i];
	}
	cout << " ]" << endl;
	cout << endl;
}

void matrix::settimer(int sum, int minus, int multiply, int min, int max) {
	this->sum_time = chrono::milliseconds(sum);
	this->minus_time = chrono::milliseconds(minus);
	this->mult_time = chrono::milliseconds(multiply);
	this->min_time = chrono::milliseconds(min);
	this->max_time = chrono::milliseconds(max);
}

void matrix::seetimer() {
	time.getTime();
}

vector<vector<double> >matrix::getA() {
	return A;
}

vector<vector<double> >matrix::getB() {
	return B;
}

vector<double> matrix::getE() {
	return E;
}

vector<vector<double> >matrix::getG() {
	return G;
}