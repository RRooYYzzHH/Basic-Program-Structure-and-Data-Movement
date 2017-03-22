#ifndef NEWHEADER_H
#define NEWHEADER_H

#include <vector>
#include <string>

using namespace std;

//create enumeration (pro.6)
enum command_line_argument { programName, fileName, expectedArguments = 2};
enum message { success = 0, can_not_open_file = 1, fail_print_usageMessage = 2, success_print_usageMessage = 3, fail_after_opening = 4 };

// Function prototypes
int parseFile(vector<string> &file, const char *filename);
int usageMessage(const char *programName);

#endif