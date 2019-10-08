#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

int main(){
	
	string destinyDir = "DestinyTest";
	FileTransfer ft;
	DIR *destiny;
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
	
	if((destiny = opendir(destinyDir.c_str())) == NULL){
		cerr << "Reading a directory was not possible"<<endl
		<<"Run this test with a user with permissions to read a directory here"<<endl;
		return errno;
	}
	
	fileTransfered = readdir(destiny);
	if(fileTransfered->d_name != "test"){
		cout<< "Name of file tranfered don't match original"<<endl;
		return 1;
	}
	
	ifstream file(destinyDir+"/"+fileTransfered->d_name);
	string recoveredContent;
	if(getline(file,recoveredContent)){
		if(recoveredContent == "test content test"){
			cout<<"File transfer worked correctly"<<endl;
			return 0;
		}
	}
		cout<<"Content of file tranfered don't match original"<<endl;
		return 1;

}
