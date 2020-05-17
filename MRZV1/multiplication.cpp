#include "multiplication.h"

multiplication::multiplication() {
	this->SetVector(1);
	this->SetVector(2);
}

void multiplication::SetVector(int numofvector) {
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
		cout << "continue? y/n\n"; 
		getline(cin, contin);
		getline(cin, contin);
		if (contin == "y") {
			is_end = false;
		}
		else if (contin == "n") {
			is_end = true;
		}
		system("cls");
	} while (!is_end);
}

void multiplication::SeeVector() {
	for (int i = 0; i < firstvect.size(); i++) {
		cout << '[' << i << ']' << '\t' << this->firstvect[i] << '\t' << this->secondvect[i] << '\n';
	}
}

void multiplication::TaktCount() {
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		this->Takt++;
	}
}

void multiplication::Umnogenie() {
	this->Takt = 0;
	this->Takt -= firstvect.size();
	thread tr([this]() {this->TaktCount(); });	
	tr.detach();
	for (int i = 0, j = 0; i < this->firstvect.size() && j < this->secondvect.size(); i++, j++) {
		thread th1();
	}
}

void multiplication::Conveer(long first, long second, int numofPair, int tacts) {
	vector<bitset<6>> nums;
	bitset<6> result;
	cout << "" << endl;
	nums = ToBit(first, second, tacts);
	this->mx4.lock();
	cout << "Pair" << numofPair << "converted to binary";
	cout << "Number of tact: " << this->Takt;
	this->SeeBinary(nums);
	this->mx4.unlock();
	result = this->BinaryMulti(nums[0], nums[1], numofPair, tacts);

}

void multiplication::SeeBinary(vector<bitset<6>> vec) {
	for (auto i = 0; i < vec.size(); i++) {
		cout << "number " << i << " : ";
		cout << vec[i].to_string() << endl;
	}
	cout << endl;
}

bitset<6> multiplication::BinaryMulti(bitset<6> a, bitset<6> b, int numofpair, int tacts) {
	lock_guard<mutex> lock(mx1);
	this_thread::sleep_for(chrono::milliseconds(1000));
	unsigned int t = 0;
	bitset<6> result;
	vector<int>one = translateStrtoInt(a.to_string());
	vector<int>two = translateStrtoInt(b.to_string());

}

vector<int> multiplication::translateStrtoInt(string str) {
	vector<int>vec;
	for (auto i = 0; i < str.size(); i++) {
		if (str[i] == '0') {
			vec.push_back(0);
		}
		else {
			vec.push_back(1);
		}
	}
	return vec;
}

