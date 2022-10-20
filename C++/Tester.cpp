#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>

using namespace std;

int main () {
    int* pValue = new int;
    *pValue = 45;
    pValue = new int;
   // delete pValue;

}