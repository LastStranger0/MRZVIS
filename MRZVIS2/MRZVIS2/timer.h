#pragma once

#include <iostream>
#include <bitset>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class timer
{
private:
	chrono::time_point<chrono::steady_clock> start, end;
	chrono::milliseconds add;
	chrono::duration<double> duration;
public:
	timer();
	~timer();
	void getTime();
	void addtime(chrono::milliseconds);
};
