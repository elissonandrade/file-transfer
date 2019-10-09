#include <string>
#include <regex>
#include <iostream>
#include "../src/FileTransfer.h"

using namespace std;

int main(){
	FileTransfer ftRegex;
	//create regular expression that macthes some file names with extensions
	ftRegex.pattern = "test[0-9]*[.][a-z]{3}";
	
	//check multiple file names again a regular expression
	if(ftRegex.matchPattern("test.zip")&&
			!ftRegex.matchPattern("test")&&
			ftRegex.matchPattern("test14.jpeg")&&
			ftRegex.matchPattern("1test.zip")&&
			!ftRegex.matchPattern("test2")){
					
			cout << "Match pattern is working as intended"<< endl;
			return 0;
	}
	cout << "Regular expression of filenames are not matching"<< endl;
	return 1;
}
