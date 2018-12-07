#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>
#include <vector>       
#include <sstream>          
#include <algorithm>        
#include <cassert>


#define assertrtEqual assert(abs(a-b) <= 0.00000001) ; std::cout << a << std::endl << b << std::endl;
#define assertNotequal assert(abs(a-b) >=0.00000001) ; std::cout << a << std::endl << b << std::endl;
#define assertZero assert(a - 0.00000001 <= 0.00000001) ; std::cout << a << std::endl;
#define assertNotZero assert(a - 0.00000001 > 0.00000001) ; std::cout << a << std::endl;

bool assert_equal(float a,float b)
{
    float zero = 0.000000001;
    a = b-a;
    if (abs(a) <= zero)
        return true;
    else
        return false;
    
}

bool assert_notequal(float a,float b)
{
    float zero = 0.000000001;
    a = b-a;
    if (abs(a) > zero) 
        return true; 
    else
        return false;
}
bool assert_zero (float a)
{
    float zero = 0.000000001;
    a = a - zero
    if (abs(a) <= zero)
        return true;
    else
        return false;
}
bool assert_notzero (float a)
{
    float zero = 0.000000001;
    a = a - zero
    if (abs(a) > zero)
        return true;
    else
        return false;
}
int main()
{
   int a, b;
   std::cout<<"Enter a" <<std::endl
   std::cin>>a;
   std::cout<<"Enter b" <<std::endl 
   std::cin>>b;
   
   assertrtEqual(a, b);
   assertNotequal(a, b);
   assertZero(a);
   assertNotZero(a);
    return 0;
}
