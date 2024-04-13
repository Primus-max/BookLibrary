#include "library_utils.h"
#include <iostream>
#include <windows.h>

using namespace std;

// Всё в файле h, это не правильно, но домашнее задание колосально большое, почти весь день ушёл.

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int BOOK_COUNT = 10;
	Book books[BOOK_COUNT] = { 0 };

	createLibrary(books, BOOK_COUNT);
	displayLibrary(books, BOOK_COUNT);

	cout << "Введите автора для поиска книги: ";
	char author[100]{};
	cin >> author;
	Book* findedBookByAuthor = findBookByAuthor(books, BOOK_COUNT, author);

	cout << "Введите название для поиска книги: ";
	char title[100]{};
	cin >> title;
	Book* findedBookByTitle = findBookByTitle(books, BOOK_COUNT, title);
		
	editBook(findedBookByTitle);
	updateBook(books, BOOK_COUNT, *findedBookByTitle);
	cout << "\n\n";
	cout << "Отредактированая книга в библиотеке: " << endl;
	displayLibrary(books, BOOK_COUNT);

	cout << "\n\n";
	cout << "Библиотека отсортирована по названию: " << endl;
	sortByTitle(books, BOOK_COUNT);
	displayLibrary(books, BOOK_COUNT);
	cout << "===================================================== " << endl;
	cout << "\n\n";
	cout << "Библиотека отсортирована по автору: " << endl;
	sortByAutor(books, BOOK_COUNT);
	displayLibrary(books, BOOK_COUNT);
	cout << "===================================================== " << endl;
	cout << "\n\n";
	cout << "Библиотека отсортирована по издателям: " << endl;
	sortByPublishingHouse(books, BOOK_COUNT);
	displayLibrary(books, BOOK_COUNT);
	cout << "===================================================== " << endl;
	cout << "\n\n";
}

