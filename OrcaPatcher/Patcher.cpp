
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
	const string empty;

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
		filesystem::path NewFileName(Path);
		NewFileName /= Name + "_v4" + Ext;
		out.open(NewFileName,ios_base::trunc);      // открываем файл для записи
		if (!out.is_open())
		{
			cout << "Cannot open file \"" << FullPath.string() << "\"" << endl;
			return;
		}

		bool patched = true;
		string line;
		while (getline(in, line))
		{
			out << line << std::endl;
			if (line.find("VIBRATIONAL FREQUENCIES", 0) != std::string::npos)
			{
				for (int i = 0; i < 4; i++)
				{
					getline(in, line);
					out << line << std::endl;
				}

				bool Patching = true;
				while (Patching)
				{
					getline(in, line);
					if (line == "")
					{
						Patching = false;
						out << line << std::endl;
						break;
					}

					if (line[4] == ':')
					{
						patched = false;
						out << line << std::endl;
						continue;
					}

					line.replace(0, 2, empty);
					size_t start{ line.find(":") };
					line.replace(start, 1, ":  ");
					out << line << std::endl;
				}
			}
		}

		in.close();

		if (patched)
			cout << "Патч файла «" + File + "» завершён" << endl;
		else
			cout << "Патч файла «" + File + "» не выполнен. Файл уже имеет правильную структуру." << endl;

	}
};