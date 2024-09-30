#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>


using namespace std;

void triangle (int a, int b, int c);

int main (int argc, char * argv[])
{
    int a, b, c;
    
    cout << "Please enter 3 positive integers to represent the lines:";
    if (argc == 1)
    {
        
        cin >> a >> b >> c;
        
        if (a <=0 || b <= 0 || c <= 0 || cin.fail())
        {
            cerr << "Error: INVALID INPUT. Please enter 3 positive integers.";
            return 1;
        }
    }

    else if (argc == 4)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);

        if (a <=0 || b <= 0 || c <= 0)
        {
            cerr << "Error: INVALID INPUT. Must be 3 positvie integers";
            return 1;
        }
    }
    else
    {
        cerr << "Error: Invalid input." << endl;
        return 1;
    }

    triangle (a, b, c);
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
