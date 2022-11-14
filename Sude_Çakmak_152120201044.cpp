#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	ifstream inputfile1, inputfile2;
	ofstream outfile;

	int i, counter1 = 0, counter2 = 0;
	double score = 0, counter = 0;
	double sum = 0;
	double average1, average2;
	double avg1, avg2, sum1 = 0, sum2 = 0;

	string courseid1, courseid2;

	inputfile1.open("group1.TXT");
	inputfile2.open("group2.TXT");

	if (!inputfile1)
	{
		cout << "Cannot open the input file.";
		return 1;
	}

	if (!inputfile2)
	{
		cout << "Cannot open the input file.";
		return 1;
	}

	cout << "Please open the ''student.txt'' file." << endl << endl;

	outfile.open("student.txt");

	outfile << fixed << showpoint;
	outfile << setprecision(2);

	outfile << setw(29) << "Bar Graph" << endl;
	outfile << "Course" << setw(11) << "Course";

	for (i = 0; i <= 100; i = i + 10)
	{
		if (i == 100)
		{
			outfile << setw(5) << i << " ";
		}
		else
		{
			outfile << setw(4) << i << " ";
		}
	}

	outfile << endl << "ID" << setw(18) << "Average  ";

	for (i = 0; i <= 10; i++)
	{
		if (i == 10)
		{
			outfile << "|";
		}
		else
		{
			outfile << setfill('.');
			outfile << "|" << setw(5);
		}
	}

	outfile << setfill(' ');
	outfile << endl;

	while (inputfile1 && inputfile2)
	{
		if (!inputfile1.eof())
		{
			inputfile1 >> courseid1;
			counter1++;
			outfile << courseid1 << " ";
			inputfile1 >> score;

			sum = 0;
			counter = 0;

			while (score != -999)
			{
				counter++;
				sum = sum + score;
				average1 = sum / (counter);
				inputfile1 >> score;
			}

			outfile << setw(12) << average1 << " " << setw(4);

			for (i = 1; i <= average1 / 2; i++)
			{
				outfile << "*";
			}

			outfile << endl;
			sum1 = sum1 + average1;
		}

		if (!inputfile2.eof())
		{
			inputfile2 >> courseid2;

			if (courseid2 != courseid1)
			{
				outfile << endl;
				outfile << courseid2 << " ";
			}

			counter2++;
			inputfile2 >> score;

			sum = 0;
			counter = 0;

			while (score != -999)
			{
				counter++;
				sum = sum + score;
				average2 = sum / (counter);
				inputfile2 >> score;
			}

			if (courseid2 != courseid1)
			{
				outfile << setw(12) << average2 << " " << setw(4);
			}
			else
			{
				outfile << setw(16) << average2 << " " << setw(4);
			}


			for (i = 1; i <= average2 / 2; i++)
			{
				outfile << "#";
			}

			sum2 = sum2 + average2;
			outfile << endl << endl;
		}

		if (inputfile1.eof() && inputfile2.eof())
			break;
	}

	outfile << endl;

	avg1 = sum1 / counter1;
	avg2 = sum2 / counter2;

	outfile << "Group 1  --  ****" << endl;
	outfile << "Group 2  --  ####" << endl;
	outfile << "Avg for group 1: " << avg1 << endl;
	outfile << "Avg for group 2: " << avg2 << endl;

	inputfile1.close();
	inputfile2.close();
	outfile.close();

	system("pause");

	return 0;
}
