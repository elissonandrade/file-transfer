#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
using namespace std;

int main(){
	
	FileTransfer ft;
	//create directory and fill with dummy files
	if(mkdir("Test",0777) == -1){
		cerr << "Creating a directory was not possible"<<endl
		<<"Run this test with a user with permission to create a directory here"<<endl;
		return 1;
	}
	
	string testFiles[4] = {"Test/test", "Test/compute.zip","Test/non-traditional.txt","Test/example.jpg"};
	for(string file : testFiles){
		ofstream testFile(file);
		testFile<<"test content "<<file<< endl;
		testFile.close();
	}
	
	//configure FileTransfer object to read from directory
	ft.origin_path = "Test";
	
	//get the newest file in the list
	string recent = ft.getRecentFile({"test", "compute.zip","non-traditional.txt","example.jpg"});
	
	//erase dummy files and directory
	for(int i =0; i < 4; i++){
			remove(testFiles[i].c_str());
	}
	rmdir("Test");
	
	//check if the newest file is indeed the one created last
	if(recent == "example.jpg"){
		cout<<"More recent file recieved"<<endl;
		return 0;
	}else{
		cout<<"Unexpected file "<<recent<<" recieved"<<endl;
		return 1;
	}

}
