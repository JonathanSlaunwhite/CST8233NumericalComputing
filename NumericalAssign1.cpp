/********************************************************************************************************************************

Name: Jonathan Slaunwhite
Student number: 040939090
assignment numebr: Assignment 1
class: CST 8233
Lab section 303
prof name Hala 
Due date 2020-02-09
Date submitted 2020-02-09
course and header files in project Assignment1.cpp

*******************************************************************************************************************************/

#include <iostream>
#include <math.h>



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

	cout << "Evaluate the Maclaurin Series approximation to D(t) = exp(t)*cos(t)\n"<<endl;

	double choice = 0;
	
	while (choice != 2) {/*loop if choice is not 1 or 2 */

		cout << "1: Evaluate the series" << endl;
		cout << "2: quit" << endl;

		cin >> choice;

		if (choice == 1) {/*if user wishes to do calcaultions proceed*/

			double number = 0;
			double range = 0;

			cout << "\nEvaluating the series"<<endl;
			
			

			do {/*repeat unti desirered number  is inputted*/

				cout << "Please enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5 or 6): ";
				cin >> number;


			} while (number>6 || number<1);


			do {/*repeat unti desirered number  is inputted*/

				cout << "\nPlease enter the range of t to evaluate in 10 increments (0.0 < t < +4.0): ";
				cin >> range;

			} while (range<0||range>4);

			cout << "\nMACLAURIN SERIES"<<endl;

			double truncation = 0;
			double tempRange = 0;
			double increments = 0;
		

			/*display title of what is being displayed*/
			cout << "t			 D(t) Series		D(t)Exact		 %RExactE		%RSerE"<<endl;
			/*series starting at 0 display*/
			cout << "0.000e+00	    	  1.000e+00		   1.000e+00		   0.000e+00	           0.000e+00" << endl;
			for (int i = 1; i <= 10; ++i) {/*loop 10 times*/


				double tempRange = range * i / 10;//to show the range between 0 to 10
				double tempNumberTrue= exp(tempRange) * cos(tempRange);//;//used to show true value 
				
				double calcualted = 0;
				double truncation = 0;
				


				if (number == 1){/*number of desired terms in series*/
					calcualted = 1;
					truncation = tempRange;
				} else if(number == 2){
					calcualted = 1 + tempRange;
					truncation = -(tempRange * tempRange * tempRange) / 3;
				} else if(number == 3){
					calcualted = 1 + tempRange - (tempRange * tempRange * tempRange) / 3;
					truncation = -(tempRange * tempRange * tempRange * tempRange) / 6;
				}else if(number == 4){
					calcualted = 1 + tempRange - (tempRange * tempRange * tempRange) / 3 - (tempRange * tempRange * tempRange * tempRange) / 6;
					truncation = -(tempRange * tempRange * tempRange * tempRange * tempRange) / 30;
				}else if(number == 5){
					calcualted = 1 + tempRange - (tempRange * tempRange * tempRange) / 3 - (tempRange * tempRange * tempRange * tempRange) / 6 - (tempRange * tempRange * tempRange * tempRange * tempRange) / 30;
					truncation = (tempRange * tempRange * tempRange * tempRange * tempRange * tempRange * tempRange) / 630;
				}else if(number == 6){
					calcualted = 1 + tempRange-(tempRange*tempRange* tempRange) / 3 - (tempRange *tempRange * tempRange * tempRange) / 6 - (tempRange * tempRange * tempRange * tempRange * tempRange) / 30 + (tempRange * tempRange * tempRange * tempRange * tempRange * tempRange * tempRange) / 630;
					truncation = (tempRange * tempRange * tempRange * tempRange * tempRange * tempRange * tempRange * tempRange) / 2520;
				}

				//Exact% Error = 100 * (exact value – series value) / exact value
				double exact =( (tempNumberTrue - calcualted) / tempNumberTrue)*100;
			

				double TrunctionError = 100 * truncation / calcualted;


				/*used to make display number in scintific notation*/
				cout << scientific;
				//cout.precision(5);

				/*display contents of calculations*/
				cout <<tempRange << "	          "	<< calcualted << "	          "<< tempNumberTrue << "	          " <<exact <<"             " << TrunctionError <<endl;

			}

			cout << "\n\n";/*backspace twice and show menu options again*/

		}//end of choice 1 option othereise end of program

	}//end of while loop
}

