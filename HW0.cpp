//
//  main.cpp
//  HW0
//
//  Created by Jonathan Oliveri on 9/10/24.
//

#include <iostream>
using namespace std;

int main(int argc, char * argv[]) 
{
    cout << "Hello, World!" << endl;
    
    if(argc > 1)
    {
        cout << "Command-Line arguments" << endl;
        for (int i = 1; i < argc; ++i)
        {
            cout << i << ", " << argv[i] << endl;
        }
    }
    else
    {
        cout << "No Command-Line arguments provided." << endl;
    }
    
    return 0;
}
