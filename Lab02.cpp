/*
    Sam       - Insert fuction
    Mohammed  - Conversion funtion
    Jonathan  - Main funtion alond with comments
    Christina - Output function

*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double OZ_TO_POUNDS = 1.0 / 16;  //Constant Conversion for ounces to pounds
const double POUNDS_TO_KILOS = 0.45359237;  //Constant Conversion for pounds to kilograms

void insert(int& pounds, double& ounces);   //Takes user input of pounds and ounces
void conversion(const int pounds, const double ounces, int& kilograms, double& grams);  //takes the user input and converts pounds and ounces to kilograms and grams
void output(int pounds, double ounces, int kilograms, double grams);    //Outputs the following input and the conversions

int main(int argc, char* argv[])
{
    int pounds = 0; double ounces = 0; int kilograms = 0; double grams = 0;  //initializing variables
   
    insert(pounds, ounces);                            //Collecting user input
    conversion(pounds, ounces, kilograms, grams);      //Converting input
    output(pounds, ounces, kilograms, grams);          //Outputing input and conversion respectfully
 
    return 0;
}


void insert(int& pounds, double& ounces)
{
    //Prompts the user input for pounds, and also checks to make sure that the input is valid and not a negative number
    while ((cout << "Please enter the number of pounds: ") && (!(cin >> pounds) || pounds <= 0))
    {
        cout << "Thats not a number greater than 0! Please try again... ";  //Provides an error message
        cin.clear();   //Clears input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    //Promts the uuser input for ounces, and provides an error message if it is not valid (negative number)
    while ((cout << "Please enter the number of ounces: ") && (!(cin >> ounces) || ounces <= 0))
    {
        cout << "Thats not a number greater than 0! Please try again... "; //Provides an error message
        cin.clear();  //Clears input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }
}

void conversion(const int pounds, const double ounces, int& kilograms, double& grams) //converting pounds&ounces to kilograms&grams
{
    double totalKg; double totalPounds;    //Storing Kilograms and pounds as doubles
    totalPounds = static_cast<double>(pounds)+ (ounces * OZ_TO_POUNDS);  //Converts ounces to pounds, and adds the conversion to the inital amount of pounds
 
    totalKg = totalPounds * POUNDS_TO_KILOS;  //Converting pounds to kilograms and stores it as double TotalKilograms
    kilograms = static_cast<int>(floor(totalKg));  //Seperates the whole number
    grams = static_cast<double>(totalKg - kilograms) * 1000;  //gets remaining grams from the seperating above

}

void output(const int pounds, const double ounces, const int kilograms, const double grams) //Used to display converting weight
{
    //Outputting the input as Pounds and Ounces
    cout << pounds << " pounds and ";
    cout << fixed << setprecision(8) << ounces << " ounces converts to" << endl;
    
    //Outputting the conversion as Kilograms and Grams
    cout << kilograms << " kilograms and ";
    cout << fixed << setprecision(8) << grams << " grams" << endl;
}

