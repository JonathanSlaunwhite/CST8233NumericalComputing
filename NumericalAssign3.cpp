/********************************************************************************************************************************

Name: Jonathan Slaunwhite
Student number: 040939090
assignment numebr: Assignment 3
class: CST 8233
Lab section 303
prof name Hala
Due date 2020-04-08
Date submitted 2020-04-03

*******************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


//helper function for passing varibles to equation
double function(double,double);


/********************************************************************************************************************************
Fuction name:		 Main
Purpose:		     Main Function
In parameters:		 none
Out parmeters:		 0
Author:				 Jonathan Slaunwhite
********************************************************************************************************************************/
int main()
{

	while (1) {//loop forever 

		int option = 0;
		
		do {//loop until valid option is selected

			cout << "Choose the method for solving the ODE:" << endl;
			cout << "1. Euler's Method" << endl;
			cout << "2. Runge-Kutta 4th Order Method" << endl;

			/*menu option choice*/
		
			cin >> option;

		} while (option!=1 && option!=2);
		
		
		double stepsize = 0;

		do{//loop until valid step size is selected

		cout << "Choose step size 'h' (0.8,  0.2, 0.05)" << endl;
		

		cin >> stepsize;
	
	} while (stepsize != 0.8 && stepsize != 0.05 && stepsize != 0.2);
		
		double temp2 = 0;//y at 0 e


		cout << "Time(second)		Exact Temp(C)		Estimated Temp(C)		Percentage Error(%)" << endl;
	

		double temp = 3;//temprature at time 0 equals 3 degrees



		if (option == 1) {//eulers method


			for (double i = stepsize; i < 2; i += stepsize) {


				double exactTemp = 0.1 * cos(4 * i) + 0.2 * sin(4 * i) + 2.9 * exp(-2 * i);//exact calculated value

				double estimated = temp + stepsize * (cos(4 * temp2) - 2 * temp);//formua from other equation using eulars method


				temp = estimated;//set temp to estimated
				temp2 += stepsize;//increment temp2 with the step size

				double percentError = abs(((estimated - exactTemp) / exactTemp) * 100);//find percent error

				cout << std::fixed;//used to set precision x distance away after the decimal point

				cout << std::setprecision(1) << i << "			" << std::setprecision(3) << exactTemp << "			" << estimated << "				" << std::setprecision(2) << percentError << endl;
			}//end of for loop


		}
		else if (option ==2) {//ruta kattas method

		
			//starting varibles 
			double x = 0;
			double y = 3;

			for (double i = stepsize; i < 2; i += stepsize) {


				double exactTemp = 0.1 * cos(4 * i) + 0.2 * sin(4 * i) + 2.9 * exp(-2 * i);//exact answer with formula

				/*forth order kuta k values*/
				double k1 = stepsize * function(x, y);
				double k2 = stepsize * function(x + 0.5 * stepsize, y + 0.5 * k1);
				double k3 = stepsize * function(x + 0.5 * stepsize, y + 0.5 * k2);
				double k4 = stepsize * function(x + stepsize, y + k3);

				//get final used answer 
				y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);;

				//increment the x value with step size
				x = x + stepsize;


				double percentError = abs(((y - exactTemp) / exactTemp) * 100);//find the percent error

				cout << std::fixed;//used to set precision x distance away after the decimal point

				cout << std::setprecision(1) << i << "			"  << std::setprecision(3) << exactTemp << "			" << y << "				"<< std::setprecision(2) << percentError << endl;
			}

		}

		cout << endl;//for formatting 

	}//end of while

}

/********************************************************************************************************************************
Fuction name:		 function
Purpose:			 Return the result of the formula through the perameters x and y input
In parameters:		 x,y
Out parmeters:		 result 
Author:				 Jonathan Slaunwhite
********************************************************************************************************************************/
double function(double x,double y) {

	double result = cos(4 * x) - (2 * y);

	return result;
}
