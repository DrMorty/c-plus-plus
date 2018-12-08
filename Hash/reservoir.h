#pragma once
#include <string>
#include <cstdlib>
#include <list>
#include "book.h"
class Storage
{
    int cell_count = 400;
    std::list<Book>* storage = new std::list<Book> [400];
    int findCell(std::string book_name);
    void removeString(std::string data);
    void appendString(std::string data);
    void print();
}
void Storage::print()
{
    std::list<Book>::iterator iter_1;
    for ( int i = 0; i < cell_count; i++)
    {
        if (storage[i].empty() == 0)
        {
            std::cout << "[" << i << "]  " << "|" << storage[i].size() << "|  ";
            for (iter_1 = storage[i].begin(); iter_1!= storage[i].end(); iter_1++)
            {
                std::cout << iter_1->data << ",  ";
            }
            std::cout << std::endl;
        }
    }
}


std::string Storage::find(std::string data)
{
    int index = abs((int)(comp_hash(data) % cell_count));
    std::list<Book>::iterator iter_1;
    for (iter_1 = storage[index].begin() ;iter_1 != storage[index].end(); iter_1++ )
    {
        if (data == iter_1->data)
        {
            std::cout << "True" << std::endl;
            return data;
        }
    }
}

#endif
