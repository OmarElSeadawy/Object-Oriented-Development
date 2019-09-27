#ifndef SORTEDARR_H
#define SORTEDARR_H
#include <iostream>

class sortedarr;
std::ostream& operator<<(std::ostream&, const sortedarr&);

class sortedarr
{   
    uint32_t *arr;
    int sz;

    void swap(uint32_t *a, uint32_t *b)
    {
        uint32_t temp = *a;
        *a = *b;
        *b = temp;
    }

    void bubbleSort()
    { 
        int i, j; 
        for (i = 0; i < sz-1; i++)           
            for (j = 0; j < sz-i-1; j++)  
                if (arr[j] > arr[j+1]) 
                    swap(&arr[j], &arr[j+1]);
    }



    public:

    sortedarr(int s = 1):sz(s),arr(new uint32_t [s]){ std::cout<<"Constructed Arr\n";}     //Int Constructor
    ~sortedarr(){ std::cout<<"Array Destruct\n"; if(arr) delete [] arr; else std::cout << "Array already deleted\n "; }            //Destructor
    sortedarr(const sortedarr& a):arr(a.arr),sz(a.sz)            //Copy Constructor
    {
        std::cout<< "Copy Constructor Called \n";
    }
    sortedarr(sortedarr&& a):arr(a.arr),sz(a.sz)               //Move Constructor
    {
        std::cout<< "Move Constructor Called \n";
    }

    sortedarr& operator=(const sortedarr& a)
    {
        std::cout << "Operator Overload = Called\n";
        arr = a.arr;
        return *this;
    }
    
    sortedarr& operator=(sortedarr&& a)
    {
        std::cout << "Move Assignment Operator = Called\n";
        arr = a.arr;
        return *this;
    }

    // Overloading [] Operator
    uint32_t operator[](int i) const 
    { 
        if ((i >= sz) || (i < 0))
            throw -1;    
        else     
            return arr[i];   
     }

    uint32_t & operator[](int i)
        {
            if ((i >= sz) || (i < 0)) 
                throw -1;    
            else     
                return arr[i];   
        } 

    //Overloading == Operator
    bool operator==(sortedarr& a) {
        std::cout << "Calling == Operator \n";  
        if(sz != a.sz)
            return false;
        else
        {
            for(int i=0; i<sz; i++)
            {
                if(arr[i] != a.arr[i])
                    return false;
            }

            return true;
        }
        return true;
    }
    
    friend std::ostream& operator<<(std::ostream& o, sortedarr& a)
    {
        o << "Output Operator\n";
        a.bubbleSort();
        o << "Size of Array is : " << a.sz << std::endl;
        for(int i=0; i<a.sz;i++)
        {
            o << "Index : [" << i << "] Has value : " << a.arr[i] << std::endl;
        }
        return o;
    }    

    void setat(int index, uint32_t val)
    {
        if(index >= sz)
        {
            std::cout << "Invalid Index at setat\n";
            throw -1;
        }
        else
        {
            arr[index] = val;
            std::cout << "Inserted Value " << val << "  At Index : " << index << "\n";
        }
        
    }

    const uint32_t getat(int index)
    {
        if ((index >= sz) || (index < 0))
        {
            throw -1;
        }
        else
        {
            bubbleSort();
            std::cout << "Getat Function \n";
            return arr[index];
        }
    }


};

#endif