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

struct Patient    
{
    std::string name = " ";
    std::string surname = " ";
    bool sex = true;
    int age = 0;
    std::string city = " ";
    int visitAmount = 0;
    
};

void show_vector( std::vector<std::string>&vect) 
{
    for (int i = 0 ;i< vect.size(); ++i)
    {
        std::cout<<vect[i];
    }
}

struct DataBase     
{
    std::vector<Patient> patients;
    int length = 0;
};

void split(const std::string &s, char divide, std::vector<std::string> &elems)
{
    
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, divide)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char divide) {
    std::vector<std::string> elems;
    split(s, divide, elems);
    return elems;
}

void readDataBase(std::string filename, DataBase* database)
{
    std::ifstream DATABASE(filename);
    int i = 0;
    while(DATABASE)
    {
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "")
        {
            std::vector<std::string> patientData;
            Patient patient;
            database->patients.push_back(patient);
            patientData = split(str, ' ');
            database->patients[i].name = patientData[0];
            database->patients[i].surname = patientData[1];
            show_vector(patientData);
            i = i + 1;
        }
    }
    database->length = i;
}
void saveDataBase(std::string filename, DataBase* database)
{
    std::ofstream DATABASE(filename);
    
    for (int i = 0; i < database->length; i++)
    {
        DATABASE<< database->patients[i].name <<" "<< database->patients[i].surname<<"\n";
    }
    DATABASE.close();
}

void getInfo(DataBase* database)
{

    for (int currentId = 0; currentId < database->length; currentId++)
        {
            std::cout<< currentId + 1 << "  ";
            std::cout<< database->patients[currentId].name << "   ";
            std::cout<< database->patients[currentId].surname << "   ";
        }
    std::cout<<"Number of patients:  "<< database->length<< "\n";
    
}
void addPatient(DataBase* database, std::string name, std::string surname)
{
    
    int currentId = database->length;
    database->patients[currentId].name = name;
    database->patients[currentId].surname = surname;
    database->length++;
}

int main()
{
        DataBase database;
        int index = -1;
        readDataBase("ambulance.txt", &database);
        int currentAmount = database.length;
        std::cout<<" App for monitoring ambulance patients.\n To print list of patients data press (1).\n To add patient in list press (2).\n To save the commits press (3).\n To exit from the program press (0)"  << std::endl;
        while (index != 0)
        {
            std::cin >> index;
            if (index == 1)
            {
               getInfo(&database); 
            } else if (index == 0)
            
            {
                std::cout << "exit" << std::endl;
            } else if (index == 2)
            
            {
                std::cout<< "Enter name and surname \n";
                std::string name;
                std::string surname;
                std::cin>> name;
                std::cin>> surname;
                addPatient(&database, name, surname);
                
            } else if (index == 3)
            
            {
                saveDataBase("ambulance.txt", &database);
            }
            
        }
        
        return 0;
}
