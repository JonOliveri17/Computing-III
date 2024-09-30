#include <iostream>
#include <cstdlib>

using namespace std;

double calculateInstallmentLoan(double, int, double);
int main(int argc, char* argv[])
{
    double annualRate;     //Interest rate as a decimal
    int amount;            //Amount you want from the loan
    double periodInYears;  //Years as a double
    double periodInMonths; //Months as a double
    double faceValue;      //Total amount of loan using interest as well

        //Prompting user for the interest rate as an integer
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%)" << endl << "(enter 0 to quit): ";
        cin >> annualRate;
        annualRate /= 100; // Converting to decimal
    
        while (annualRate != 0) //Creates a loop until user types in "0"
        {
            cout << endl << "Please enter the amount you would like to recieve: "; //Prompting for the loan amount
            cin >> amount;
            
            cout << endl << "Please enter loan period in months: "; //Prompting for the period in months
            cin >> periodInMonths;
            periodInYears = periodInMonths / 12; //CHanging the months to years as a decimal
        
            faceValue = calculateInstallmentLoan(annualRate, amount, periodInYears);  // Gets the total amount of the loan
            
            //Output formatting
            std::cout.setf(std::ios::fixed);
            std::cout.setf(std::ios::showpoint);
            std::cout.precision(2);
            
            //Displaying the results using the inputs given
            cout << "The total amount of your loan (including interest at " << annualRate << "% per annum) is $" << faceValue << "." << endl
                << "Your monthly payment for " << periodInMonths << " months will be $" << faceValue / periodInMonths << endl;
            
            //Now reprompting the user
            cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%)" << endl << "(enter 0 to quit): ";
            cin >> annualRate;
            annualRate /= 100; //Makes percentage into a decimal
        }
        return 0;
}


double calculateInstallmentLoan(double annualRate, int amount, double periodInYears)
{
    double total = (double) (amount) / (1 - annualRate * periodInYears); //First, 1 - (Annual rate times the amount of years) which is the compund interest, and then you take the inital amount and then divide it by that.

    return total; //returning what the calculations gave you
}
