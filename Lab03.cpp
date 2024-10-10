/*
    Presenter: Sam
    Manager: Mohammed
    Reflector: Jonathan
    Recorder: Cristina
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Making the conversions constant
const double DRAMS_TO_GRAMS = 1.7718451953125;  //conversion for drams to grams
const double DRAMS_TO_AV_POUNDS = 1.0 / 256.0;  //conversion for drams to Avoirdupois pounds
const double DRAMS_TO_TROY_POUNDS = 1.0 / 96.0; //conversion for drams to troy pounds

class Mass //Class used to respresent all the weight measurements
{
private:
    double grams;
    double avPounds;
    double troyPounds;
    double drams;


public:
    Mass() : grams(0), avPounds(0), troyPounds(0), drams(0) {} // Initializing the default constructor
    Mass(double iGrams, double iAvPounds, double iTroyPounds) : grams(iGrams), avPounds(iAvPounds), troyPounds(iTroyPounds), drams(iGrams * (1.0 / DRAMS_TO_GRAMS)) {}
    
    //getting access to the private members of the class
    double getGrams(void) const
    {
        return grams;
    }
    double getAvPounds(void) const
    {
        return avPounds;
    }
    double getTroyPounds(void) const
    {
        return troyPounds;
    }
    double getDrams(void) const
    {
        return drams;
    }
    //Modifying and setting the values of the private data variables
    void setGrams(double newValue) { grams = newValue; }
    void setAvPounds(double newValue) { avPounds = newValue; }
    void setTroyPounds(double newValue) { troyPounds = newValue; }
    void setDrams(double newValue) { drams = newValue; }

};


void convert(Mass& obj, int type); //Function that takes care of all the conversion types based off of the type of input that is given

int main(int argc, char* argv[])
{
    Mass obj = Mass(); //initializing the mass object
    double grams;      //initializing grams
    double avPounds;   //initializing avoirdupois pounds
    double troyPounds; //initializing troy pounds
    int i;
    
    //loop used to prompt the user for the type of conversion they want
    do
    {
        //Asking for input, the type of mass, and making sure that the input is in bounds
        while ((cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ") && (!(cin >> i)) || ((i < 0) || (i > 3)))
        {
            cout << "Thats not an input option! Please try again... " << endl;; //error return statement
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
   

        switch (i)
        {
        //when the user enters 0, the program will say thank you and successfully exit the program
        case 0:
            cout << "Thanks for using the mass conversion program!";
            break;
        //When the user types in 1 for Avoirdupois pounds, this case 1 takes care of the other conversions
        case 1:
            cout << "Please enter a mass in Avoirdupois pounds: ";  //Getting the initial mass in Avoirdupois pounds
            cin >> avPounds;
            cout << endl;
            obj.setAvPounds(avPounds);  //Setting the input to avPounds
            obj.setDrams(avPounds * (1.0 / DRAMS_TO_AV_POUNDS));  //calculates the drams from the intial avPounds input
            convert(obj, i);     //performs conversion
            cout << "Mass in Avoirdupois pounds is " << obj.getAvPounds() << endl << "Mass in Troy Pounds: " << obj.getTroyPounds() << endl << "Mass in grams is " << obj.getGrams() << endl;  //Creates an output with all of the successful conversions
            break;
        //When the user types in 2 for Troy pounds, this case 2 takes care of the other conversions
        case 2:
            cout << "Please enter a mass in Troy pounds: "; //Getting the initial mass in troy pounds
            cin >> troyPounds;
            cout << endl;
            obj.setTroyPounds(troyPounds); //Setting the input to troyPounds
            obj.setDrams(troyPounds * (1.0 / DRAMS_TO_TROY_POUNDS)); //calculates the drams from the initial troyPounds input
            convert(obj, i);  //performs conversion
            cout << "Mass in Avoirdupois pounds is " << obj.getAvPounds() << endl << "Mass in Troy Pounds: " << obj.getTroyPounds() << endl << "Mass in grams is " << obj.getGrams() << endl; //Creates an output with all of the successful conversions

            break;
        //When the user types in 3 for grams, this case 3 takes care of the other conversions
        case 3:
            cout << "Please enter a mass in grams: "; //Getting the initial mass in grams
            cin >> grams;
            cout << endl;
            obj.setGrams(grams);   //Setting the input to grams
            obj.setDrams(grams * (1.0 / DRAMS_TO_GRAMS));  //calculates the drams from the initial grams input
            convert(obj, i);  //performs conversion
            cout << "Mass in Avoirdupois pounds is " << obj.getAvPounds() << endl << "Mass in Troy Pounds: " << obj.getTroyPounds() << endl << "Mass in grams is " << obj.getGrams() << endl; //Creates an output with all of the successful conversions

            break;

        default:

            break;  //Any other inputs just break and exit
        }
    } while (i != 0);  //Creates a loop until the user enters 0 to exit


    return 0;
}

void convert(Mass& obj, int type)  //performs a conversion based off of the type of input
{
    double drams;
 switch (type)  //Perform the conversion based off of the type the user input gave
 {
//Case 1 takes care of all of the conversions when the user inputs 1, which is Avoirdupois pounds initially
 case 1:
     
     obj.setGrams(obj.getDrams() *DRAMS_TO_GRAMS);                //Converts Drams to Grams
     obj.setTroyPounds(obj.getDrams() * DRAMS_TO_TROY_POUNDS);    //Converts Drams to Troy pounds
     break;
//Case 2 takes care of all of the conversions when the user inputs 2, which is Troy pounds initially
 case 2:
     obj.setAvPounds(obj.getDrams() * DRAMS_TO_AV_POUNDS);        //Converts Drams to Avoirdupois pounds
     obj.setGrams(obj.getDrams() * DRAMS_TO_GRAMS);               //Converts Drams to Grams
     break;
//Case 3 takes care of all of the conversions when the user inputs 3, which is grams initially
 case 3:

     obj.setAvPounds(obj.getDrams() * DRAMS_TO_AV_POUNDS);        //Converts Drams to Avoirdupois pounds
     obj.setTroyPounds(obj.getDrams() * DRAMS_TO_TROY_POUNDS);    //Converts Drams to Troy pounds
     break;
 }
}
