#include <string>
#include <regex>
#include <iostream>
#include "../src/FileTransfer.h"

using namespace std;

int main(){

	FileTransfer ftTraditional;

	ftTraditional.pattern = "test";
	ftTraditional.isReg = false;
	
	if(ftTraditional.matchPattern("test.zip")&&
		ftTraditional.matchPattern("test")&&
		ftTraditional.matchPattern("test14.jpeg")&&
		!ftTraditional.matchPattern("1test.zip")&&
		!ftTraditional.matchPattern("fest")){
		
		FileTransfer ftRegex;
		
		ftRegex.pattern = "test[0-9]";
		ftRegex.isReg = true;
		
		if(!ftRegex.matchPattern("test.zip")&&
			!ftRegex.matchPattern("test")&&
			ftRegex.matchPattern("test14.jpeg")&&
			!ftRegex.matchPattern("1test.zip")&&
			ftRegex.matchPattern("test2")){
				
			cout << "Match pattern is working as intended"<< endl;
			return 0;
		}
			cout << "Regular expression of filenames are not matching"<< endl;
			return 1;
		
	}
	
			cout << "Prefix of filenames are not matching"<< endl;
			return 1;
}
