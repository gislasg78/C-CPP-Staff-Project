//obtaining file size.
#include <iostream>
#include <fstream>

#define	V_ZERO	0

int main()
	{
		char *memblock = nullptr;
		std::string strFileName {};
		std::streampos begin{}, end{}, size{};

		std::cout << "Program to determine the size of a given file." << std::endl;
		std::cout << "Enter a file name: ";
		std::cin >> strFileName;

		std::ifstream myfile(strFileName, std::ios::in | std::ios::binary);

		if (myfile.is_open())
			{
				myfile.seekg(V_ZERO, std::ios::beg);
				begin = myfile.tellg();

				myfile.seekg (V_ZERO, std::ios::end);
				end = myfile.tellg();

				myfile.seekg(V_ZERO, std::ios::end);
				size = myfile.tellg();

				memblock = new char [size];

				myfile.seekg(V_ZERO, std::ios::beg);
				myfile.read(memblock, size);
				myfile.close();

				std::cout << std::endl << "Requested file information." << std::endl;
				std::cout << "File: [" << strFileName << "]." << std::endl;
				std::cout << "Size: [" << (end - begin) << "] = [" << size << "] bytes." << std::endl;
				std::cout << "The entire file content is in memory." << std::endl;

				delete[] memblock;
			}

		return V_ZERO;
	}
