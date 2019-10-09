#include "FileTransfer.h"
#include <string>
#include <fstream>
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <regex>
#include <sys/stat.h>
#include <time.h>

using namespace std;

void FileTransfer::readConfigFile(string configPath) {
	ifstream configFile(configPath.c_str());
	string cfgLine;
	
	while(getline(configFile,cfgLine)){
		if(cfgLine.substr(0,7).compare("origin=")== 0){
			this->origin_path = cfgLine.substr(7);
		}
		if(cfgLine.substr(0,8).compare("destiny=")== 0){
			this->destiny_path = cfgLine.substr(8);
		}
		if(cfgLine.substr(0,8).compare("pattern=")== 0){
			this->pattern = cfgLine.substr(8);
		}
		if(cfgLine.substr(0,7).compare("period=")== 0){
			//take numeric value from this tag
			this->period = stoi(cfgLine.substr(7));
		}
		if(cfgLine.substr(0,12).compare("recentFirst=")== 0){
			//turn this variable true only if the tag value is y
			this->recentFirst = cfgLine.substr(12,1).compare("y") == 0;
		}
	}
	configFile.close();
}

vector<string> FileTransfer::getDirFiles(){
	vector<string> files;
	
	//open the source(origin) directory
	DIR *source;
	struct dirent *filePresent;
	if((source = opendir(this->origin_path.c_str())) == NULL){
		cerr << "Reading a directory was not possible"<<endl
		<<"Run this test with a user with permissions to read a directory here"<<endl;
		exit( errno);
	}
	
	//read every file and directory
	while((filePresent = readdir(source))!= NULL){
		files.push_back(filePresent->d_name);
	}
	closedir(source);
	return files;
}

bool FileTransfer::matchPattern(string fileName){
	//use ECMA standard of regular expressions
	regex regPattern(this->pattern,regex_constants::ECMAScript);
	
	return regex_search(fileName,regPattern);
}

bool FileTransfer::transferFile(string path){
	return rename((this->origin_path +"/"+ path).c_str(), (this->destiny_path  +"/"+ path).c_str()) == 0;
}

string FileTransfer::getRecentFile(vector<string> files){
	//take first element as reference and compare with the other files
	string recent = files.back();
	struct stat fileStatus;
	stat((this->origin_path+"/"+recent).c_str(),&fileStatus);
	time_t newer = fileStatus.st_mtime;
	files.pop_back();
	
	for(string file :files){
		stat((this->origin_path+"/"+file).c_str(),&fileStatus);
		if(difftime(fileStatus.st_mtime,newer)>0){
			recent = file;
			newer = fileStatus.st_mtime;
		}
	}
	return recent;
}
