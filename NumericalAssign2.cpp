
/********************************************************************************************************************************

Name: Jonathan Slaunwhite
Student number: 040939090
assignment numebr: Assignment 2
class: CST 8233
Lab section 303
prof name Hala
Due date 2020-03-15
Date submitted 2020-03-05

*******************************************************************************************************************************/

#include <iostream>
#include <math.h>
#include<string.h>
#include<iomanip>
#include<fstream>
#include <sstream> 

using namespace std;

/********************************************************************************************************************************
Fuction name:		 Main
Purpose:		     Main Function
In parameters:		 none
Out parmeters:		 0
Author:				 Jonathan Slaunwhite
********************************************************************************************************************************/
int main()
{
	cout << "LEAST_SQUARES LINEAR REGRESSIO\n"<<endl;

	int option = 0;
	/*Display menu */
	do {

		cout << "MENU" << endl;
		cout << " 1. Exponential Fit" << endl;
		cout << " 2. Quit" << endl;
		cin >> option;


		if (option == 1) {

			ifstream ifile;
			char s[100], fname[20];
			cout << "Enter file name to read and display its content (like file.txt) : ";//get file name
			cin >> fname;
			ifile.open(fname);//open the file
			if (!ifile)//if file can not be opened display error
			{
				cout << "Error in opening file";
				exit(0);
			}

			int counter = 0;
			int records = 0;
			string shoe[50];
			int shoecounter = 0;

			while (ifile.eof() == 0)//while the file has not reached the end of line 
			{

				ifile >> s;//put value of data in varible 

				cout << s << "		";// display varible value 
				shoe[shoecounter] = s;//putdata field data into arrow shoe
				shoecounter++;//increment shoe counter to next index

				if (counter % 2 == 1) {//to format the next lines for displaying the data

					cout << endl;
					records++;//Count the number of records there are 
				}
				counter++;// increment the counter for logical endline placments
			}
			cout << "\n";
			ifile.close();//close file no longer needs to be in use


			records -= 1;//correct to make records match how many data rows there are
			cout << "There are " << records << "records." << endl<<endl;

			/*Calculate least squares */
			double xmean = 0;
			double ymean = 0;
			int counterf = 0;

			/*store the 30 data points from data.txt into their own arrays*/
			int x[15];
			int y[15];

			for (int i = 2; counterf < 15; i += 2) {
				counterf++;//used for for loop
			
				//get data from data.txt into varibles myint1 and myint2
				int myint1 = stoi(shoe[i]);//get data
				int myint2 = stoi(shoe[i + 1]);//get next data field right next to myint1

				//store respective data into their respective arrays x[i] y[i]
				x[i / 2 - 1] = myint1;
				y[i / 2 - 1] = myint2;

				xmean += myint1;
				ymean += myint2;
			}

			//get the mean of the x values and y values 
			xmean = xmean / records;
			ymean = ymean / records;

			double lny[15];//used to store the log of the y values


			for (int i = 0; i < 15; i++) {//loop and get all log y values then put into their own arrays
				lny[i] = log(y[i]);

			}
			double lyy = 0;//ylog value thats going to get all added to itself


			for (int i = 0; i < 15; i++) {//loop used to find the mean of the y log arrays
				lyy += lny[i];

			}

			//Get the mean of the ylog values 
			lyy /= 15;
			lyy = exp(lyy);


			/*least squares find the a and b value from respective varible values*/
			double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
			for (int i = 0; i < 15; i++) {//run 15 times 

				xsum = xsum + x[i];         //all x values added           
				ysum = ysum + lny[i];		//add ylog values added              
				x2sum = x2sum + pow(x[i], 2);//all x squared values added          
				xysum = xysum + x[i] * lny[i];//all x times ylog values added             

			}

			int n = 15;//n is the number of data rows in text file data.txt

			double a = 0;//slope
			double b = 0;//y int

			a = (n * xysum - xsum * ysum) / (n * x2sum - xsum * xsum);//calculate slope
			b = (x2sum * ysum - xsum * xysum) / (x2sum * n - xsum * xsum);//calculate intercept

			b = exp(b);//eulars number times b to get usable b value

			cout << "Linear Regression Fit:  Prognostic_index = "<<b<<"*exp "<<a<<"*days" <<endl;//display regression fit line

			int option2 = 0;
			do {//display menu for extrapolation

				cout << "MENU"<<endl;
				cout << " 1. Extrapolation" << endl;
				cout << " 2. Main menu" << endl;

				cin >> option2;

				if (option2 ==1) {//extrapolate data

					double ext = 0;

					cout << "Please enter the days to extrapolate to: ";
					cin >> ext;//enter data to extrapolate

					double N = b * exp(a*ext);//find the Prognostic
	
					double rateOfDecrease = N * a;//find the rate of decrease

					/*display the results of calculations*/
					cout << "days = "<<ext<<endl;
					cout << "Prognostic_index  = " << N << endl;
					cout << "Rate of decrease = "<< rateOfDecrease<<endl;
					cout << endl;
				}

			}while (option2!=2);

		}
		else if (option == 2) {//if user leaves main program

			//cout << "Exiting have a good day" << endl;
		}
		else {//if user puts in invalud option 
			cout << "Invalid option"<<endl;
		}

	} while (option != 2);

	return 0;
}
