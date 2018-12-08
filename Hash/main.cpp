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
#include "reservoir.h"
#include <list>
#include <iterator>

int main()
{
    Storage stor;
    stor.setHashValue();
    stor.readDataBase();
    stor.readBook();
    stor.printCells();
    return 0;
}
