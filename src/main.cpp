#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include "FileTransfer.h"
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	
	FileTransfer ft;
	
	string config;
	
	config = argc >1 ? argv[1]: "transfer.cfg";
	
	
	while(true){
		//read paths from config file
		ft.readConfigFile(config);
		
		//read origin directory
		vector<string> files = ft.getDirFiles();
		
		//check every file for a match
		for(string file: files){
			//if the file name macth the pattern
			if(ft.matchPattern(file)){
				//execute the file transfer, but exit the program if a error happens
				if(!ft.transferFile(file)){
					return 1;
				}
			}
			
		}
		//wait 60 seconds
		sleep(60);
	}

}
