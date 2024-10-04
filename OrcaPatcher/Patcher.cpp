
#include "OrcaPatcher.h"
#include <iostream>
#include <filesystem> 
#include <fstream>

using namespace std;

class Patcher
{
protected:
	filesystem::path FullPath, NewPath;
	string File, Name, Ext, Path;

public:
	Patcher(string FileName)
	{
		cout << "Patching file \"" << FileName << "\"" << endl;

		FullPath = filesystem::path(FileName);
		File = FullPath.filename().string();
		Name = FullPath.stem().string();
		Ext = FullPath.extension().string();
		Path = FullPath.parent_path().string();


	}

	void Patch()
	{
		if (Path == "" || Ext == "") return;

		ifstream in(FullPath.string());
		ofstream out;
		if (!in.is_open())
		{
			cout << "Cannot open file \"" << FullPath.string() << "\"" << endl;
			return;
		}
		string NewFileName = 
		out.open("hello.txt");      // открываем файл для записи
		if (!out.is_open())
		{
			cout << "Cannot open file \"" << FullPath.string() << "\"" << endl;
			return;
		}

		bool patched = true;
		string line;
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}

		in.close();
	}
};