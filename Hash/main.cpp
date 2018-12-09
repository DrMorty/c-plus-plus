#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>
#include <vector>           
#include <sstream>          
#include <algorithm>  
#include <list>
#include "stream.h"
#include "reservoir.h"
#include "Hash.h"


int main()
{
    Storage<std::string> stor_1(333);
    readDataBase("lib", &stor);
    stor.print();
    stor.remove("Наполеон");
    saveDataBase("lib", &stor);
    findCell("Россией");
    return 0;
}
