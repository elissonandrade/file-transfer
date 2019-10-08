#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

int main(){

	if(mkdir("Test",0777) == -1){
		cerr << "Creating a directory was not possible"<<endl
		<<"Run this test with a use with permission to create a directory here"<<endl;
		return 1;
	}
	
	string testFiles[4] = {"Test/test", "Test/compute.zip","Test/non-traditional.txt","Test/example.jpg"};
	for(string file : testFiles){
		ofstream testFile(file);
		testFile.close();
	}
	
	FileTransfer ft;
	ft.origin_path = "Test";
	
	vector<string> recoveredFiles = ft.getDirFiles();
	bool allMacth = true;
	for(string name: recoveredFiles){
		for(int i =0; i < 4; i++){
			if(name == testFiles[i].substr(4)){
				break;
			}
			if(i ==3){
				allMacth = false;
			}
		}
	}
	
	if(allMacth){
		cout << "Function that read from the directory is working as intended"<<endl;
		return 0;
	} else {
		cout << "Function that read from the directory is not working as intended"<<endl;
		return 1;
	}
	
}
