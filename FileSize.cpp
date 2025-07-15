//obtaining file size.
#include <iostream>
#include <fstream>

#define	V_ZERO	0

int main()
	{
		std::string strFileName {};
		std::streampos begin, end;

		std::cout << "Program to determine the size of a given file." << std::endl;
		std::cout << "Enter a file name: ";
		std::cin >> strFileName;

		std::ifstream myfile(strFileName, std::ios::binary);

		if (myfile.is_open())
			{
				myfile.seekg(V_ZERO, std::ios::beg);
				begin = myfile.tellg();

				myfile.seekg (V_ZERO, std::ios::end);
				end = myfile.tellg();

				myfile.close();

				std::cout << std::endl << "Requested file information." << std::endl;
				std::cout << "File: [" << strFileName << "]." << std::endl;
				std::cout << "Size: [" << (end - begin) << "] bytes." << std::endl;
			}

		return V_ZERO;
	}
