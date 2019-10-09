#ifndef FILE_TRANS_H
#define FILE_TRANS_H
#include <string>
#include <vector>

class FileTransfer{
	public:
	std::string origin_path;
	std::string destiny_path;	
	std::string pattern;
	int period;
        bool recentFirst;
	void readConfigFile(std::string configPath);
	std::vector<std::string> getDirFiles();
	bool matchPattern(std::string fileName);
	bool transferFile(std::string path);
        std::string getRecentFile(std::vector<std::string> files);
};

#endif
