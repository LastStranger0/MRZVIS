#include "timer.h"

timer::timer() {
	start = chrono::high_resolution_clock::now();
}

void timer::getTime() {
	end = chrono::high_resolution_clock::now();
	float res = (end - start).count()/1000000000;
	res += add.count() / 1000;
	cout << "time passed:" << res << "s" << endl;
}

void timer::addtime(chrono::milliseconds ad) {
	add += ad;
}

timer::~timer() {

}
