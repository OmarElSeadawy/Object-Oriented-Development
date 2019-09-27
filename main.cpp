// g++ main.cpp -o main -fno-elide-constructors
#include "sortedarr.h"
#include <iostream>

int main()
{
    try
    {

        //Normal Constructor
        std::cout << "TESTING NORMAL CONSTRUCTOR\n";
        sortedarr s(3);
        std::cout << std::endl;

        //Move Constructor
        std::cout << "TESTING MOVE CONSTRUCTOR\n";
        sortedarr q = sortedarr(4);
        std::cout << std::endl;
        
        //Copy Constructor
        std::cout << "TESTING COPY CONSTRUCTOR\n"; 
        sortedarr z = s;
        std::cout << std::endl;
        
        //Move Assignment Operator
        std::cout << "TESTING MOVE Assignment Operator\n";
        sortedarr x;
        x = sortedarr(4);
        std::cout << std::endl;

        //Testing SetAt
        std::cout << "Testing SetAt Function\n";
        s.setat(0,3);
        s.setat(1,2);
        s.setat(2,1);
        std::cout << std::endl;

        //Testing GetAt (Shows that S is sorted)
        std::cout << "Testing GetAt Function\n";
        std::cout << s.getat(0) << '\n';

        //Testing [] Operator
        std::cout << "Testing [] Operator\n";
        std::cout << s[0] << '\n';

        //Testing == Operator
        std::cout << "Testing == Operator\n";
        std::cout << (s == x) << '\n';
        std::cout << (s == s) << '\n';

        //Testing << Operator
        std::cout << s << '\n';

        //Testing Exception Handling
        std::cout << s.getat(50) << '\n';    
    }
    catch (int a)
    {
        if(a == -1)
            std::cout << "Out of Bound Exception Caught\n";
    }
    

    std::cout << "END OF TESTS\n";
    return 0;
}