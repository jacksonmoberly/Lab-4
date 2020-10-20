//**************************
//Jackson Moberly
//C++
//
//Lab 4 Temperature Outputs
//**************************

// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std; // makes it easier to use things like cout and endl over and over

int heading() // function for the scale on top of the data
{
	cout << setw(8) << "-30"; // outputs the value to a certain distance from the last space
	cout << setw(9) << "0"; // outputs the value to a certain distance from the last space
	cout << setw(10) << "30"; // outputs the value to a certain distance from the last space
	cout << setw(10) << "60"; // outputs the value to a certain distance from the last space
	cout << setw(10) << "90"; // outputs the value to a certain distance from the last space
	cout << setw(10) << "120" << endl; // outputs the value to a certain distance from the last space
	return 0; // ends function 
}


int main() // main function
{
	ifstream infile; 
	float temp = 0; // stores the values of the temperatures that are read from the file
	float num;
	
	cout << "Temperatures: " << endl;
	heading(); // function call to output the scale
	string inputfile = ("Temperatures.txt"); // finds the file

	infile.open(inputfile); // opens the file
	while (!infile.eof()) // loop to make sure that all the numbers are inputted until the eof
	{
		infile >> temp; // gets the temperature and stores it
		if (temp < -30 || temp > 120) // sets boundaries of the data
			continue;
		else
		{
			if (temp > 0) // what to do if temperature is larger than 0
			{
				float star = 0; // stores the value for how many stars are supposed to be outputted

				cout << temp << ":" << "\t" << "\t"; // puts the temperature on screen

				while (star <= temp / 3) // basically while the amount of stars is less than the temperature divided by three it will keep going through the loop
				{
					cout << "*"; // outputs star
					star++; // star count rises
				}
				cout << endl;
			}
			else if (temp < 0) // if the temperature is less than 0 then it will do the following
			{
				int star = 0; // stores the value for how many stars are supposed to be outputted

				cout << temp << ":" << "\t" << "\t" << setw(star);
				while (star > temp / 3) // basically the opposite of the one with greater than 
				{
					cout << "*"; // outputs star
					star--; // the star count goes negative
				}
				cout << endl;
			}
			else if (temp == 0) // if the temp is zero
			{
				cout << temp << ":" << endl;// output the temperature but don't add anything else
			}
			else if (!(infile >> num)) // what to do if the input isn't a number
			{
				cout << "Please enter numbers only: " << endl; // outputs the statement and ends the program
				return 0;
			}
			else // if nothing else
			{
				continue; // skip the rest and start over at the beginning of the loop
			}
			
			
		}
		temp++; // temperature value goes up by one
	}
	
	infile.close(); // close the file

	return 0; // end program
}