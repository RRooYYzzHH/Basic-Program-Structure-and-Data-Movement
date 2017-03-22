// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "newHeader.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	const char *programName = argv[command_line_argument::programName];

	// Check the arguments numbers
	if (argc != command_line_argument::expectedArguments) {
		int error = usageMessage(programName);
		if (error == message::fail_print_usageMessage) {
			cout << "Error: Failed to print usage message!" << endl;
		}
		else {
			cout << "Printed usage message!" << endl;
		}
		return error;
	}

	// Parse the input file
	const char *filename = argv[command_line_argument::fileName];
	vector<string> file;
	int parse = parseFile(file, filename);

	// Check the return value
	if (parse == message::can_not_open_file) {
		cout << "Error: Can't open file!" << endl;
		return parse;
	}
	else if (parse == message::fail_after_opening) {
		cout << "Error: File opened, but there is an error when reading the file!" << endl;
		return parse;
	}

	vector<int> fileDigit;

	for (string s : file) {
		int length = s.length();
		char tmp[1024];
		strcpy_s(tmp, s.c_str());
		int judge = 1;
		for (int i = 0; i < length; i++) {
			if (!isdigit(tmp[i])) {
				judge = 0;
				break;
			}
		}
		if (judge == 0) {
			cout << s << endl;
		}
		else {
			stringstream ss;
			int num;
			ss << s;
			ss >> num;
			fileDigit.push_back(num);
		}
	}
	for (int integer : fileDigit) {
		cout << integer << endl;
	}
	return message::success;
}

