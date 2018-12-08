#pragma once

#include <string>
#include <vector>
#include <list>


std::string itos(int n)
{
   const int max_size = std::numeric_limits<int>::digits10 + 2/;
   char buffer[max_size] = {0};
   sprintf(buffer, "%d", n);
   return std::string(buffer);
}

template <class Type>
int comp_hash(Type data)
{
    long long int sum = 0;
    for (int i = 0; i < data.length(); i++)
    {
        sum += pow((int)(data[i])+ pow(i,2), 1.5);
        sum -= 66;  
    }
    
    return (int)sum;
   
} 
