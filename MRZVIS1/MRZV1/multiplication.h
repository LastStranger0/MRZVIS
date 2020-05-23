#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <bitset>
#include <string>
#include <chrono>
#include "timer.h"

using namespace std;

class multiplication
{
private:
	mutex mx1;
	mutex mx2;
	mutex mx3;
	mutex mx4;

	int Takt;

	vector<long> firstvect;
	vector<long> secondvect;
	vector<long> resultvect;

	void SetVector(int);
	void TaktCount();
	void Conveer(long, long, int, int);
	void SeeBinary(vector<bitset<6>>);
	bitset<6> BinaryMulti(bitset<6>, bitset<6>, int, int);
	vector<bitset<6>> ToBit(long, long, int);
	vector<int>multipl(vector<int>, int);
	vector<int> translateStrtoInt(string);
	bitset<6> translateIntToBit(vector<int>);
	long ToInt(bitset<6>, int);
public:
	multiplication();
	void SeeVector();
	void Umnogenie();
	void SeeResult();
};

