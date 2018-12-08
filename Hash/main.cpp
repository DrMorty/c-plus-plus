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
#include "stream.h"
#include <list>


int main()
{
    Storage stor;
    readDataBase("lib", &stor);
    stor.print();
    stor.remove("Наполеон");
    saveDataBase("lib", &stor);
    return 0;
}
