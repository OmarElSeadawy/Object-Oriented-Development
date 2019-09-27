#include "sortedarr.h"
#include <iostream>

int main()
{
    try
    {
        sortedarr s = sortedarr(4);
        sortedarr x;
        x = sortedarr(4);
        
        s.setat(0,3);
        s.setat(1,2);
        s.setat(2,1);
        s.setat(4,15);
        x.setat(0,15);
        x.setat(1,15);
        x.setat(2,15);
        x.setat(3,15);
        x.setat(4,15);
    }
    catch (int a)
    {
        if(a == -1)
            std::cout << "Out of Bound Exception Caught\n";
    }
    

    return 0;
}