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
		cout<<"Searching files..."<<endl;
		vector<string> files = ft.getDirFiles();
	
		if(ft.recentFirst){
			vector<string> matches;
			//check every file for a match
			for(string file: files){
					//if the file name macth the pattern
					if(ft.matchPattern(file)){
						//push in the list for transfers
						matches.push_back(file);	
					}
					
			}
			if(matches.size()>0){
				string recent = ft.getRecentFile(matches);
				
				//execute the file transfer, but exit the program if a error happens
				cout<<"Transfering file "<<recent<<endl;
				if(!ft.transferFile(recent)){
						return 1;
				}
			}
		}else{
			//check every file for a match
			for(string file: files){
					//if the file name macth the pattern
					if(ft.matchPattern(file)){
							//execute the file transfer, but exit the program if a error happens
							cout<<"Transfering file "<<file<<endl;
							if(!ft.transferFile(file)){
									return 1;
							}
					}
					
			}
			
		}
		//wait the configured period 
		sleep(ft.period);
	}

}
