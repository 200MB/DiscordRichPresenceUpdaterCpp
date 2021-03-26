#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <windows.h>
using namespace std;
void color(int i,string text) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, i);
		cout << text;
	
}
void convert(string*time) {
	color(12, "awaiting your input...");
	cout << endl;
	int timezone;
	double timezone1;
	cin >> timezone;
	timezone1 = timezone;
	if (timezone >= 3600) {
		cout << "minutes-" << timezone / 60 << ":" << timezone - (timezone / 60) * 60;
	}
	cout << endl; color(12,"1.convert a different one 2.set this one :");
	int pop;
	cin >> pop;
	if (pop == 1) {
		convert(time);
	}
	else {
		*time = "StartTimestamp=" + to_string(timezone);
	}
}
int main() {
	//-----------------------------path input------------------------------//
	string path;
	string path_b;
	color(12, "please specify the path of the config:");
	cin >> path;
	color(12, "now input the backup text file path:");
	cin >> path_b;
	//-----------------------------end path input------------------------------//
	
	
	
	
	//-------------------------------vector input-------------------------
	ifstream ifs(path_b);
	ofstream ofs(path,ofstream::out|ofstream::trunc);
	vector<string>config;
	string line;
	while (getline(ifs, line)) {
		config.push_back(line);
	}
	//---------------------------end of vector input-------------------------
	



	
	
	
	//----------------------------------check----------------------------//
	if (config.size() == 0) {
		color(12, "Error,please make sure you entered you file path correctly");
		exit(EXIT_FAILURE);
	}
	else {
		color(12, "Now type the amount of words you want this program to cycle through:");
	}
	//-------------------------------end of check----------------------------//
	




    //------------------------------input words----------------------------//
	vector<string>loopsource;
	string words;
	int howmany;
	cin >> howmany;
	color(12, "Ok now input the words (they must have at least 3 or more characters)");
	cout << endl;
	int g=1;
	while (g <= howmany) {
		cin >> words; 
		if (words.size() < 3) {
			color(12, "this word has less than 3 characters");cout << endl;
		}
		else {
         loopsource.push_back(words);
		 g++;
		}
	}
	//---------------------------end of input words--------------------------//
	color(12, "Here's how it'll show up in the status box");cout << endl;
	color(12, "State:"); cout << endl;
	color(12, "Details:"); cout << endl;
	color(12, "Time:"); cout << endl;
	color(12, "time goes? 1.forward 2.backwards :");
	
	
	//Time set
	int choice;
	cin >> choice;
	if (choice == 1) {
		
		string time = "StartTimestamp=0";
		config[25].erase(config[25].begin(), config[25].end());
		config[25].append("\r");
		config[25].append(time);
		ofs.open(path, iostream::out | iostream::trunc);
		for (auto x : config) {
			ofs << "\r" << x << endl;
		}
		ofs.close();
	}
	else if (choice == 2) {
		color(12, "where should the time start from (in seconds) :");
		color(12, "1.convert seconds to minutes or just input any number except 1");
		string time = "StartTimestamp=";
		string outofideas;
		cin >> outofideas;
		if ( outofideas == "1") {
			convert(&time);
		}
		else {
			time = "StartTimestamp=" + outofideas;
		}
		config[25].erase(config[25].begin(), config[25].end());
		config[25].append("\r");
		config[25].append(time);
		ofs.open(path, iostream::out | iostream::trunc);
		for (auto x : config) {
			ofs << "\r" << x << endl;
		}
		ofs.close();
	}
	
	
	//Time set end
	
	
	
	//-----------------------------the updater-------------------------------//
	color(12, "Now which one should these inputted words loop throuth? 1.State 2.Details  :");
	cin >> choice;
	if (choice == 2) {
		string De = "Details=";
		int i = 0;
		while (true) {
			if (i + 1 == loopsource.size()+1) {
				cout << "\r" << i << endl;
				ofs.open(path, iostream::out | iostream::trunc);
				config[24].erase(begin(config[24]), end(config[24]));
				string f = De + loopsource[i];
				config[24].append(f);
				for (auto x : config) {
					ofs << "\r" << x << endl;
				}
				f.clear();
				i = 0;
				ofs.close();
			}
			else {
				cout << "\r" << i;
				ofs.open(path, iostream::out | iostream::trunc);
				config[24].erase(begin(config[24]), end(config[24]));
				string f = De + loopsource[i];
				config[24].append(f);
				for (auto x : config) {
					ofs << "\r" << x << endl;
				}
				f.clear();
				Sleep(5000);
				i++;
				ofs.close();
			}
		}
	}
	else if (choice == 1) {
		string St = "State=";
		int i = 0;
		while (true) {
			if (i + 1 == loopsource.size()) {
				cout << "\r" << i;
				ofs.open(path, iostream::out | iostream::trunc);
				config[23].erase(begin(config[23]), end(config[23]));
				string f = St + loopsource[i];
				config[23].append(f);
				for (auto x : config) {
					ofs << "\r" << x << endl;
				}
				f.clear();
				i = 0;
				ofs.close();
			}
			else {
				cout << "\r" << i;
				ofs.open(path, iostream::out | iostream::trunc);
				config[23].erase(begin(config[23]), end(config[23]));
				string f = St + loopsource[i];
				config[23].append(f);
				for (auto x : config) {
					ofs << "\r" << x << endl;
				}
				f.clear();
				Sleep(5000);
				i++;
				ofs.close();
			}
	}
	}

		
	
	
	//--------------------------end of the updater-------------------------------//
}


