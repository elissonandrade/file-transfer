#ifndef FILE_TRANS_H
#define FILE_TRANS_H
#include <string>
#include <vector>

class FileTransfer{
	public:
	std::string origin_path;
	std::string destiny_path;	
	std::string pattern;
	bool isReg;
	void readConfigFile(std::string configPath);
	std::vector<std::string> getDirFiles();
	bool matchPattern(std::string fileName);
	bool transferFile(std::string path);
};

#endif
