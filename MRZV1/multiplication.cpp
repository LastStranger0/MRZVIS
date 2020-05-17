#include "multiplication.h"

multiplication::multiplication() {
	this->setvector(1);
	this->setvector(2);
}

void multiplication::setvector(int numofvector) {
	bool is_end = false;
	do {
		string contin;
		int a;
		cout << "write number for " << numofvector << " massive\n";
		cin >> a;
		if (numofvector == 1) {
			this->firstvect.push_back(a);
		}
		else if (numofvector == 2) {
			this->secondvect.push_back(a);
		}
		while (contin != "y" || contin != "n") {
			cout << "continue? y/n"; 
			getline(cin, contin);
			if (contin == "y") {
				is_end = false;
			}
			else if (contin == "n") {
				is_end = true;
			}
			system("cls");
		}
	} while (!is_end);
}
