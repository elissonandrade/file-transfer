#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>  

using namespace std;

int main(){

	ofstream config("test.cfg");
	
	config<<"origin=A"<<endl;
	config<<"destiny=B"<<endl;
	config<<"pattern=test"<<endl;
	config<<"regex=y"<<endl;
	config.close();
	
	FileTransfer ft;
	ft.readConfigFile("test.cfg");
	
	if(ft.origin_path == "A" && ft.destiny_path == "B" && ft.pattern == "test" && ft.isReg){
		cout<<"Reading of the config file worked."<<endl;
		return 0;
	} else{
		cout<<"Reading of the config file failed!"<<endl;
		return 1;
	}
	
}
