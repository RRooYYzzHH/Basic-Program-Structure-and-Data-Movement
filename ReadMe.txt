========================================================================
    CSE 332 Lab0 : Basic C++ Program Structure and Data Movement
		By Zihao Yang (445432) zihao.yang@wustl.edu
========================================================================
1. Brief summary of my program:
     the function of program is to open the txt file and print the content of this file(lists all the 
strings with non-numeric characters and then all the integer values). Also, my program can deal will
differents kinds of errors during the whole process.

2. The way to run my program is:
      first create a txt file and put this file into project debug folder. And then use the command
line "Lab0.exe fileName" to run my program   


3. There are totally five differents kinds of message:
   (1) success = 0: the main function will return 0 if there is no error
   (2) can_not_open_file = 1: the main function will return 1 if it can't open the file.
   (3) fail_print_usageMessage = 2: the main function will return 2 if it calls the usage function
              and fail to print the usage message
   (4) success_print_usageMessage = 3: the main function will return 3 if it calls the usage function
              and success to print the usage message
   (5) fail_after_opening = 5: the main function will return 4 if it fails after opening the file

4. I ran 4 differents cases: (the file name is "input_file.txt")

   Case one:  the command line were: "Lab0.exe" 
        My program will call the usage message function and my program will return 2 or 3. The reason
        is that there is no input argument, so my program will call the usage message function.
   Case two:  the command line were: "Lab0.exe file.txt"
        My program will return the value 1. The reason is that there is no file called "file.txt".
        My program cannot open the file, so it will give us the value 1
   Case three:  the command line were: "Lab0.exe input_file.exe" and the file is corrupt.
        My program will return the value 5. The reason is that although my program can find and then
        open the "input_file.txt" file, my program will fail (ifs.fail()) after opening the file due the corruption
        of this file. 
   Case fout:  the command line were: "Lab0.exr input_file.exe"
        My program will return 0. This means that there is no error during the execution.

5. During my implementation, the first difficult is to deal with enumeration declaration,
function declaration and function defination. After some trials, I found that I can declare a function
in header file, and implement this function in the corresponding source file. The second difficult is to
use the I/O stream. I knew that I can use the "open" operation to open the file, but I didn't know
how to take out the content of this file. Therefore, I looked through the textbook, and finally found
the method. The last difficult is to deal with the error message.