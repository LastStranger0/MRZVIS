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

	void setvector(int);
public:
	multiplication();
};

