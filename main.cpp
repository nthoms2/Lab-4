/* 
Nolan Thoms
C++ Fall Semester
Lab4 Temperture Output
inputting a files data and using the data to create a weather chart
*/

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

//preconditions: weatherData must be positive and must be valid in order for this function to work
//postconditions: a value for the number of stars needed is created and a loop displays the correct 
//amount of stars
void starCalc(float weatherData);

// preconditions:  WeatherData must be negative and must be valid in order for this function to work
/* postconditions: a value for the number of stars needed is created for the negative data values and 
the numbers of space needed and the numbers of stars needed are outputed on the screen*/
void negStarCalc(float weatherData);

// preconditions: needs a value of count
// postconditions: count is increased in a loop in order to create a specified amount of spaces which are 
//outputed to the screen
void spaces();

int main()
{
	cout << " This is a chart of hourly tempertures for a day" << endl;
	cout << "\t" << "-30         0         30        60        90         120" << endl;
	cout << "\t" << "--------------------------------------------------------" << endl;

	// this section identifies that there is a input file being used and opens it
	ifstream inFile;
	string inFileName = "C:/Users/THOMS3/Documents/C++/lab 4 weather report/weather report.txt";
	inFile.open(inFileName);
	
	// creates float variable used for reading in the information from the file
	float weatherData;
	
	// sees if the program can find the file and if not end the program
	if (!inFile)
	{
		cout << "can't find file!" << endl;

		return 1;
	}

	inFile >> weatherData; // priming read of the file

	// check to make that the data from the file is valid and not a character
	if (!inFile)
	{
		cout << "invalid input, please do not enter characters";

	}

	/* this is the main while loop that takes each piece of data from the input file and assigns it to 
	a specefic part of the loop which determines whether the data is positive, negative, or invalid*/
	while (inFile)
	{
		/* this section checks to see if the data is in the chart and if not says invalid input
		and reads in the next chunk*/
		 if ((weatherData < -30) || (weatherData > 120)) 
		{
			cout << "invalid input";
			cout << "\n";
			inFile >> weatherData;
			if (!inFile)
			{
				cout << "invalid input, please do not enter characters";

			}
		}

		 /* if the number is valid then it moves on and checks to see if the data is positive.
		 if positive then it uses two different loops to calculate where to output the data by moving 
		 it 12 spaces and the out putting the appropriate amount of stars then reads through the next 
		 piece of data which starts at the top  */
		else if(weatherData >= 0)
		{
			cout << fixed << setprecision(3) <<  weatherData << "\t";
			spaces();
			cout << "|";
			starCalc(weatherData);
			cout << "\n";
			inFile >> weatherData;
			if (!inFile)
			{
				cout << "invalid input, please do not enter characters";

			}
		}

		 /* lastly this section of the program checks to see if the data is negative and if negative
		 it then calculates the amount of spaces to push the stars so that they will be on the left side 
		 of the line of the chart and the brings through the next piece of data which starts at the top
		 */
		else if(weatherData < 0)
		{
			cout << fixed << setprecision(3) << weatherData << "\t";
			negStarCalc(weatherData);
			cout << "|" << "\n";
			inFile >> weatherData;
			if (!inFile)
			{
				cout << "invalid input, please do not enter characters";

			}
		}
	

	}


	return 0;
}
// calculates stars for positive data 
void starCalc(float weatherData)
{
	int numStar = ((weatherData / float(3))+.5);
	int count = 1;

	while (count <= numStar)
	{
		count++;
		cout << '*';
	}
}
// creates spaces so the vertical line in the chart is in line with zero for positive numbers
void spaces()
{
	int count2 = 1;
	while (count2 <= 12)
	{
		count2++;
		cout << " ";
		
	}
}
/*calculates stars for the negative data and calculates the amount of spaces to move over the stars*/
void negStarCalc(float weatherData)
{
	int negNumStar = ((-1*(weatherData/3))+.5);
	int count3 = 1;
	int count4 = 1;
	int negSpaces = (12 - negNumStar);

	while (count3 <= negSpaces)
	{
		count3++;
		cout << " ";

	}
	while (count4 <= negNumStar)
	{
		count4++;
		cout << '*';

	}
}

