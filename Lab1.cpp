﻿// Lab1.cpp
// Addison Dugal
// Reads a file and stores number data

#include "stdafx.h"
#include <fstream>
using std::ifstream;
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;

int main()
{
	ifstream file;
	string filename;
	int count = 0;
	double first = 0, second = 0, secondlast = 0, last = 0;

	cout << "Enter a filename. \n";
	cin >> filename;
	file.open(filename);
	if (file.is_open())
	{
		double temp = 0, lasttemp = 0; //lasttemp stores previous temp val for second-to-last
		while (!file.eof())
		{
			file >> temp;
			if (!file.fail())
			{
				count++;
				if (count == 1) //Stores first and last values
				{first = temp;}
				if (count==2)
				{second = temp;}
				secondlast = lasttemp;//lasttemp is stored before next file read, and is transferred to secondlast before it changes
				lasttemp = temp;
			}
			else //go through whitespace/junk
			{
				file.clear();
				file.ignore();
			}
		}
		last = temp;
	}
	file.close();
	cout << "Count: " << count << "\nFirst: " << first << "\nSecond: " << second << "\nSecond-to-last: " << secondlast << "\nLast: " << last;
	cin >> filename; //This line is completely unnecessary but my test run window would close immediately, so I added this so it would continue running and I could check the results
	return 0;
}

