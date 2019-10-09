#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>

using namespace std;

int main(){
        //create directory and filled with dummy files
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
	
	//read directory using FileTransfer object
	FileTransfer ft;
	ft.origin_path = "Test";
	
	vector<string> recoveredFiles = ft.getDirFiles();
        
        //check if all files created are listed
	bool allMacth = true;
	for(string name: testFiles){
		for(int i =0; i < recoveredFiles.size(); i++){
                    cout <<recoveredFiles[i]<<endl;
			if(name.substr(5) == recoveredFiles[i]){
				break;
			}
			if(i ==recoveredFiles.size()-1){
				allMacth = false;
			}
		}
	}
	//erase dummy files and directory
	for(int i =0; i < recoveredFiles.size(); i++){
		if(recoveredFiles[i]!=".." && recoveredFiles[i]!=".."){
			remove(("Test/"+recoveredFiles[i]).c_str());
		}
	}
	rmdir("Test");
        
        //check if any file created was not listed
	if(allMacth){
		cout << "Function that read from the directory is working as intended"<<endl;
		return 0;
	} else {
		cout << "Function that read from the directory is not working as intended"<<endl;
		return 1;
	}
	
}
