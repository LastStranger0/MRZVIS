#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class matrix
{
public:
	void seematrix(vector < vector<double>>, int a, int b);
	void seematrix(vector<double>, int a);
	void Countc();
	void seematrixC(int a, int b);
	matrix(unsigned int, unsigned int, unsigned int);
	vector<vector<double>> A;
	vector<vector<double>> B;
	vector<double> E;
	vector<vector<double>> G;
	vector<vector<double>> C;


private:
	unsigned int p, m, q;
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
	vector<double> unite(vector<double>, vector<double>);


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

