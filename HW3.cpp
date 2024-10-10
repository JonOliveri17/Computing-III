#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPSILON = 0.001;

string triangle (int a, int b, int c);
string triangle (double a, double b, double c);

int main (int argc, char * argv[])
{
    string output;
    if (argc < 2)
    {
        cerr << "ERROR: Make sure to provide the mode (-i for integers, -d for doubles)!" << endl;
        return 1;
    }
    
    if(string(argv[1]) == "-i")
    {
        if (argc == 5)
        {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            int c = atoi(argv[4]);
            
            if (a <=0 || b <= 0 || c <= 0)
            {
                cerr << "ERROR: INVALID INPUT. Must be 3 positvie integers";
                return 1;
            }
            
            output = triangle (a, b, c);
            cout << a << " " << b << " " << c << " " << output << endl;
        }
        else
        {
            cerr << "ERROR, Please provide 3 arguements!" << endl;
            return 1;
        }
    }
    
    else if(string(argv[1]) == "-d")
    {
        if (argc == 5)
        {
            double a = atof(argv[2]);
            double b = atof(argv[3]);
            double c = atof(argv[4]);
            
            if (a <=0 || b <= 0 || c <= 0)
            {
                cerr << "ERROR: INVALID INPUT. Must be 3 positvie numbers";
                return 1;
            }
            cout << fixed << setprecision(5) << a << " " << b << " " << c << " ";
            output = triangle (a, b, c);
            cout << output << endl;
        }
        
        else
        {
            cerr << "ERROR, Please provide 3 arguements!" << endl;
            return 1;
        }
    }
    
    else
    {
        cerr << "ERROR: Make sure to provide the mode (-i for integers, -d for doubles)!" << endl;
        return 1;
    }
    
    return 0;
}
            
string triangle (int a, int b, int c)
{
    if (a > b)
    {
        swap(a, b);
    }
    
    if (b > c)
    {
        swap(b, c);
    }
    
    if (a > c)
    {
        swap(a, c);
    }
    
    if (a + b <= c)
    {
        return "Not a Triangle";
    }
    
    if (a == b && b == c)
    {
        return "Equilateral Triangle";
    }

    if (a == b || b == c)
    {
        if ((a * a) + (b * b) == (c * c))
        {
            return "Right Isosceles Triangle";
        }
        
        else
        {
            return "Isosceles Triangle";
        }
    }
    
    if ((a * a) + (b * b) == (c * c))
    {
        return "Right Scalene Triangle";
    }
    
    else
    {
        return "Scalene Triangle";
    }


}


string triangle (double a, double b, double c)
{
    if (a > b)
    {
        swap(a, b);
    }
    
    if (b > c)
    {
        swap(b, c);
    }
    
    if (a > c)
    {
        swap(a, c);
    }
    
    if (a + b <= c)
    {
        return "Not a Triangle";
    }
    
    if (fabs (a - b) < EPSILON && fabs (b - c) < EPSILON)
    {
        return "Equilateral Triangle";
    }

    if (fabs (a - b) < EPSILON || fabs (b - c) < EPSILON)
    {
        if (fabs((a * a) + (b * b) - (c * c)) < EPSILON)
        {
            return "Right Isosceles Triangle";
        }
        
        else
        {
            return "Isosceles Triangle";
        }
    }
    if (fabs((a * a) + (b * b) - (c * c)) < EPSILON)
    {
        return "Right Scalene Triangle";
    }
    
    else
    {
        return "Scalene Triangle";
    }

}
