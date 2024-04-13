#include <iostream>
#include <windows.h>
#include "library_utils.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    const int BOOK_COUNT = 10;
    Book books[BOOK_COUNT]={0};

    createLibrary(books, BOOK_COUNT);
}

