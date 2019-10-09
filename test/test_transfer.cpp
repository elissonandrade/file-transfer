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
	
	string destinyDir = "DestinyTest";
	FileTransfer ft;
	struct dirent *fileTransfered;
	
	if(mkdir("Test",0777) == -1){
		cerr << "Creating a directory was not possible"<<endl
		<<"Run this test with a user with permission to create a directory here"<<endl;
		return 1;
	}
	
	if(mkdir("DestinyTest",0777) == -1){
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
	
	ft.origin_path = "Test";
	ft.destiny_path = destinyDir;
	
	ft.transferFile("test");
	
	
	ifstream file(destinyDir+"/test");
        
        if(file.fail()){
		cout<< "Name of file moved don't match the original"<<endl;
		return 1;
            
        }
	for(int i =0; i < 4; i++){
		if(testFiles[i]!="Test/test"){
			remove(testFiles[i].c_str());
		}
	}
	rmdir("Test");
	string recoveredContent;
	if(getline(file,recoveredContent)){
		if(recoveredContent == "test content Test/test"){
			file.close();
			remove((destinyDir+"/test").c_str());
			rmdir(destinyDir.c_str());
			cout<<"File transfer worked correctly"<<endl;
			return 0;
		}
	}
	file.close();
	remove((destinyDir+"/test").c_str());
	rmdir(destinyDir.c_str());
	cout<<"Content of file tranfered don't match original"<<endl;
	return 1;

}
