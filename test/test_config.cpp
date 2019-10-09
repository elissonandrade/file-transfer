#include "../src/FileTransfer.h"
#include <iostream>
#include <fstream>  

using namespace std;

int main(){
        //creat simple, but comple config file
	ofstream config("test.cfg");
	
	config<<"origin=A"<<endl;
	config<<"destiny=B"<<endl;
	config<<"pattern=test"<<endl;
	config<<"period=15"<<endl;
	config<<"recentFirst=y"<<endl;
	config.close();
	
	//reads the config file
	FileTransfer ft;
	ft.readConfigFile("test.cfg");
	
    //check is the values where as expected
	if(ft.origin_path == "A" && ft.destiny_path == "B" && ft.pattern == "test" && ft.period == 15 && ft.recentFirst){
		cout<<"Reading of the config file worked."<<endl;
		return 0;
	} else{
		
		//if the value were wrong, print all of them
		cout<<"Reading of the config file failed!"<<endl<<
		"Origin path is "<<ft.origin_path<<", destiny path is"<<
		ft.destiny_path<<", pattern is "<<ft.pattern<<
		", the search period is "<<ft.period<<
		"and files come"<<(ft.recentFirst?" in order":" together")<<endl;
		return 1;
	}
	
}
