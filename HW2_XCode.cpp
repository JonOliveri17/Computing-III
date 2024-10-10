#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPSILON = 0.001;

void triangle (int a, int b, int c);
void triangle (double a, double b, double c);

int main (int argc, char * argv[])
{
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
            
            triangle (a, b, c);
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
            double a = atoi(argv[2]);
            double b = atoi(argv[3]);
            double c = atoi(argv[4]);
            
            if (a <=0 || b <= 0 || c <= 0)
            {
                cerr << "ERROR: INVALID INPUT. Must be 3 positvie numbers";
                return 1;
            }
            triangle (a, b, c);
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
            
void triangle (int a, int b, int c)
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
        cout << a << " " << b << " " << c << " Not a Triangle" << endl;
        return;
    }
    if (a == b && b == c)
    {
        cout << a << " " << b << " " << c << " Equilateral Triangle" << endl;
        return;
    }

    if (a == b || b == c)
    {
        if ((a * a) + (b * b) == (c * c))
        {
            cout << a << " " << b << " " << c << " Right Isololeses Triangle" << endl;
        }
        else
        {
            cout << a << " " << b << " " << c << " Isololese Triangle" << endl;
        }

        return;
    }
    if ((a * a) + (b * b) == (c * c))
    {
        cout << a << " " << b << " " << c << " Right Scalene Triangle" << endl;
        return;
    }
    else
    {
        cout << a << " " << b << " " << c << " Scalene Triangle" << endl;
        return;
    }


}


void triangle (double a, double b, double c)
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

    cout << fixed << setprecision(5);
    
    if (a + b <= c)
    {
        cout << a << " " << b << " " << c << " Not a Triangle" << endl;
        return;
    }
    
    if (fabs (a - b) < EPSILON && fabs (b - c) < EPSILON)
    {
        cout << a << " " << b << " " << c << " Equilateral Triangle" << endl;
        return;
    }

    if (fabs (a - b) < EPSILON || fabs (b - c) < EPSILON)
    {
        if (fabs((a * a) + (b * b) - (c * c)) < EPSILON)
        {
            cout << a << " " << b << " " << c << " Right Isololeses Triangle" << endl;
        }
        else
        {
            cout << a << " " << b << " " << c << " Isololese Triangle" << endl;
        }

        return;
    }
    if (fabs((a * a) + (b * b) - (c * c)) < EPSILON)
    {
        cout << a << " " << b << " " << c << " Right Scalene Triangle" << endl;
        return;
    }
    else
    {
        cout << a << " " << b << " " << c << " Scalene Triangle" << endl;
        return;
    }

}
