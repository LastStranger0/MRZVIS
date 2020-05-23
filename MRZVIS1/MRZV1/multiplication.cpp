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
	//this->Takt -= firstvect.size();
	thread tr([this]() {this->TaktCount(); });	
	tr.detach();
	for (int i = 0, j = 0; i < this->firstvect.size() && j < this->secondvect.size(); i++, j++) {
		thread th1(&multiplication::Conveer, this, firstvect[i], secondvect[i], i, Takt);
		this_thread::sleep_for(chrono::milliseconds(10));
		if (i + 1 == firstvect.size() || j + 1 == secondvect.size()) {
			th1.join();
		}
		else
		{
			th1.detach();
			Takt++;
		}
	}
}

void multiplication::Conveer(long first, long second, int numofPair, int tacts) {
	vector<bitset<6>> nums;
	bitset<6> result;
	cout << "" << endl;
	nums = ToBit(first, second, tacts);
	this->mx4.lock();
	cout << "Pair " << numofPair << " converted to binary" << endl;
	cout << "Number of tact: " << this->Takt << endl;
	this->SeeBinary(nums);
	this->mx4.unlock();
	result = this->BinaryMulti(nums[0], nums[1], numofPair, tacts);
	this->mx4.lock();
	cout << "Pair " << numofPair << " was counted" << endl;
	cout << "Number of tact: " << this->Takt << endl;
	cout << "Result in binary number: " << result.to_string() << endl;
	cout << endl;
	this->mx4.unlock();
	this->mx4.lock();
	this->resultvect.push_back(ToInt(result, tacts));
	cout << "Pair " << numofPair << " converted to decimal" << endl;
	cout << "Number of tact: " << this->Takt << endl;
	cout << "Result in decimal number: " << result.to_ulong() << endl;
	cout << endl;
	mx4.unlock();
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
	unsigned int t = 0;
	bitset<6> result;
	vector<int>one = translateStrtoInt(a.to_string());
	vector<int>two = translateStrtoInt(b.to_string());
	vector<int> temp{ 0,0,0,0,0,0 }, res;
	for (int i = 0; i < two.size(); i++) {
		res = multipl(one, two[i]);
		for (int j = 1; j <= res.size(); j++) {
			temp[temp.size() - j] += res[res.size() - j];
		}
		for (int j = temp.size() - 1; j > 0; j--) {
			if (temp[j] > 1) {
				if (j == 0) {
					temp.insert(temp.begin(), 1);
				}
				else {
					temp[j - 1]++;
				}
				temp[j] = 0;
			}
		}
		if (i + 1 != two.size()) {
			temp.push_back(0);
		}
	}
	result = translateIntToBit(temp);
	while (tacts + 1 > this->Takt) {
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	return result;
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

vector<int> multiplication::multipl(vector<int> vect, int num) {
	vector<int> res;
	for (int i = 0; i < vect.size(); i++) {
		res.push_back(vect[i] * num);
	}
	return res;
}

bitset<6> multiplication::translateIntToBit(vector<int> vect) {
	string str = "";
	while(vect.size()>6){
		vect.erase(vect.begin());
	}
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] == 0) {
			str += '0';
		}
		else {
			str += '1';
		}
	}
	return bitset<6>(str);
}

vector<bitset<6>> multiplication::ToBit(long first, long second, int Tact) {
	lock_guard<mutex> lock(mx2);
	vector<bitset<6>> result;
	result.push_back(bitset<6>(first));
	result.push_back(bitset<6>(second));
	while (Tact + 1 > this->Takt) {
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	return result;
}

long multiplication::ToInt(bitset<6> bit, int tact) {
	lock_guard<mutex> lock(mx3);
	while (tact + 1 > this->Takt) {
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	return bit.to_ulong();
}

void multiplication::SeeResult() {
	for (int i = 0; i < this->resultvect.size(); i++) {
		cout << '[' << i << ']' << '\t' << this->resultvect[i] << '\n';
	}
}