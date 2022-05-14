#include <iostream>
#include <assert.h>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "IndexedList.h"
#include "ListIterator.h"
using namespace std;

int main()
{
    testAll();
    testAllExtended();
    cout << "Finished LI Tests!" << endl;
}