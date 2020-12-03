#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <utility>

std::vector<int> parseFile(const std::string filename);

std::pair<int,int> findSum(const std::string filename);

class TempFile
{
public:
    TempFile() : temp_file_name(std::tmpnam(nullptr)), temp_file(temp_file_name)
    {
    }

    ~TempFile()
    {
        temp_file.close();
        remove(temp_file_name.c_str());
    }

    void write(const char *text)
    {
        temp_file << text << std::endl;
    }

    const std::string &getFileName() const { return temp_file_name; }

private:
    const std::string temp_file_name;
    std::ofstream temp_file;
};