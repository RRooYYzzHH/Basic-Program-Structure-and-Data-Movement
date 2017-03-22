#include "stdafx.h"
#include "newHeader.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int parseFile(vector<string> &file, const char *filename) {
	ifstream ifs;
	ifs.open(filename);
	if (ifs.is_open()) {
		while (!ifs.eof()) {
			if (ifs.fail()) {
				ifs.clear();
				return message::fail_after_opening;
			}
			else {
				string str;
				ifs >> str;
				file.push_back(str);
			}
		}
		ifs.close();
		return message::success;
	}
	else {
		return message::can_not_open_file;
	}
}

int usageMessage(const char *programName) {
	try {
		printf("usage: %s input_file.txt", programName);
		cout << endl;
		return message::success_print_usageMessage;
	}
	catch (int error) {
		cout << "Error: " << error << endl;
		return message::fail_print_usageMessage;
	}
}