#include "pr.hpp"
#include <cstdio>
#include <iostream>


void get_filename(char* n)
{
	int check = -2;
	while (check <= 0)
	{
		if (check == -1)
			std::cout << "Try again" << std::endl;
		std::cout<< "Type file name" << std::endl;
		std::cin.getline(n, SIZE);
		for (int i = 0; i < SIZE; ++i)
		{	
			if (n[i] == '\0')
			{
				check = i;
				break;
			}	
			if (n[i] <= ' ')
			{
				check = -1;
				break;
			}
		}
	}
}

int open_file(char* name, int mode)
{
	FILE* rFile = fopen(name, "r");
	if (rFile)
	{
		if (!(mode))
		{
			std::cout << "File already exist" << std::endl;
			fclose(rFile);
			return 1;
		}
	}
	else 
	{
//		std::cout << "-2\n";

		if (mode)
		{
			std::cout << "File doesnt exist" << std::endl;
			return 2;
		}
//			fclose(rFile);
	}
	return 0;
}

void read_and_write(char* cppfile, char* txtfile)
{
//	std::cout << "0\n";
	FILE* rFile = fopen(cppfile, "r");
//	std::cout << "1\n";
	FILE* wFile = fopen(txtfile, "w");
//	std::cout << "2\n";
	char temp[N] = {'\0'};
	while (fgets(temp, N, rFile) != NULL)
	{
		std::cout << temp;
		for (int i = 0; i < N || temp[i] == '\0'; ++i)
		{
			if (temp[i] == '\"')
			{
				while (temp[++i] != '\"')
					fputc(temp[i], wFile);
				fputc('\n', wFile);
			}
//			if (temp[i] == '\'')
//			{
//				while (temp[++i] != '\'')
//				{
//					std::cout << i << std::endl;
//					fputc(temp[i], wFile);
//				}
//				fputc('\n', wFile);
//			}

		}
	}
	fclose(wFile);
	fclose(rFile);
}
