#pragma once
#include <string>
#include <cstdlib>
#include <list>
#include <iostream>
#include "Hash.h"
#include <iterator>

template <typename Type>
class Storage
{
     Storage (int number);
    ~Storage ();
    int cell_count;
    std::list<Type>** storage;
    int findCell(std::string book_name);
    void removeString(std::string data);
    void appendString(std::string data);
    void print();
}

template <typename Type>
Storage<Type>::Storage (int number)
{
    cell_count = number;
    storage = new std::list<Type>*[number];
}

template <typename Type>
Storage<Type>::~Storage()
{
    for (int i = 0; i < cell_count; i++)
    {
        storage[i]->clear();
    }
    delete[]storage;
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
void Storage::appendString(std::string data)
{
    int index = abs((int)(comp_hash(data) % cell_count));
    storage[index].push_back(data); 
}

void Storage::remove(std::string data)
{
    int index = abs((int)(comp_hash(data) % cell_count));
    std::remove(storgae[index]
}


std::string Storage::findCell(std::string data)
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
template <typename Type>
void Storage<Type>::remove(Type data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    auto it = std::find(storage[index]->begin(), storage[index]->end(), data);
    if (it != storage[index]->end())
    {
        storage[index]->erase(it);
        std::cout << "Data has been removed" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}
#endif
