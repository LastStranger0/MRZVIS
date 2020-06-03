#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include "timer.h"


using namespace std;

class matrix
{
public:
	void seematrix(vector < vector<double>>, int a, int b);
	void seematrix(vector<double>, int a);
	void Countc();
	void seematrixC();
	void seematrix(vector<vector<double>>);
	void seematrix(vector<double>);
	matrix(unsigned int, unsigned int, unsigned int);
	vector<vector<double>> getA();
	vector<vector<double>> getB();
	vector<double> getE();
	vector<vector<double>> getG();
	void settimer(int sum, int minus, int multiply, int min, int max);
	void seetimer();

private:
	vector<vector<double>> A;
	vector<vector<double>> B;
	vector<double> E;
	vector<vector<double>> G;
	vector<vector<double>> C;
	unsigned int p, m, q;
	timer time;
	chrono::milliseconds sum_time;
	chrono::milliseconds minus_time;
	chrono::milliseconds mult_time;
	chrono::milliseconds min_time;
	chrono::milliseconds max_time;

	/////////////////////////////////////переменные

	double min(vector<double>);
	double min(double, double);
	double max(vector<double>);
	double max(double, double);
	double multiply(double, double);
	double multiply(double, double, double);
	double multiply(vector<double>);
	double minus(double, double);
	double sum(double, double);


	//////////////////////////////////////атомарные функции

	double fCount(int i, int j);
	void cCount(int i, int j);
	double dCount(int i, int j);

	//////////////////////////////////////функции подсчёта матрицы С

	void matrixpush(vector<vector<double>>&, unsigned int, unsigned int);
	void matrixpush(vector<double>&, unsigned int);
	void matrixpushC(vector<vector<double>>&, unsigned int, unsigned int);
	double drand(double, double);

	/////////////////////////////////////функции заполнения матрицы

};

