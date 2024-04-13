#pragma once
#include <cstdlib>
#include <random>
#include <iostream>
#include <algorithm>
#include <cstring>  

using namespace std;
//Random random;

const int TOTAL_GENRES = 5;

enum Genre {
	Novel,
	Detective,
	ScienceFiction,
	Fantasy,
	Adventure,
};

const char* genreNames[TOTAL_GENRES] = {
	 "Роман",
	"Детектив",
	"Научная фантастика",
	"Фэнтези",
	"Приключения"
};

struct  Book
{
	char Title[100]{};
	char Autor[100]{};
	char PublishingHouse[100]{};
	Genre Genre;
};

const char* createTitle() {
	const int NUM_TITLES = 15;

	const char* bookTitles[NUM_TITLES] = {
		 "Убить пересмешника",
		 "1984",
		 "Великий Гэтсби",
		 "Гордость и предубеждение",
		 "Над пропастью во ржи",
		 "Хоббит, или Туда и обратно",
		 "О дивный новый мир",
		 "Гарри Поттер и философский камень",
		 "Властелин колец",
		 "Голодные игры",
		 "Код да Винчи",
		 "Алхимик",
		 "Хроники Нарнии",
		 "Бегущий по лезвию",
		 "Виноваты звезды"
	};


	return bookTitles[rand() % 15];
}


const char* createAutor() {

	const int NUM_AUTHORS = 15;
	const char* authors[NUM_AUTHORS] = {
	   "Агата Кристи",
	   "Джордж Оруэлл",
	   "Фрэнсис Скотт Фицджеральд",
	   "Джейн Остин",
	   "Джером Д. Сэлинджер",
	   "Дж.Р.Р. Толкиен",
	   "Олдос Хаксли",
	   "Джоан К. Роулинг",
	   "Дж. Р. Р. Толкиен",
	   "Сьюзен Коллинз",
	   "Дэн Браун",
	   "Пауло Коэльо",
	   "Клайв Стейплз Льюис",
	   "Филип К. Дик",
	   "Джон Грин"
	};

	return authors[rand() % 15];
}

const  char* createPublishingHouse() {

	const int NUM_PUBLISHINGHOUSE = 15;
	const char* publishingHouses[NUM_PUBLISHINGHOUSE] = {
	   "Эксмо",
	   "АСТ",
	   "ACT",
	   "Амфора",
	   "Азбука",
	   "Альпина Паблишер",
	   "АСТ Москва",
	   "Бомбора",
	   "Вече",
	   "ВИАС",
	   "Вильямс",
	   "Гелиос",
	   "Гиперион",
	   "Дауру",
	   "Детектив-пресс"
	};
	return publishingHouses[rand() % 15];
}


void createLibrary(Book* books, int bookCount) {
	if (books == nullptr) return;

	Book newBook;

	for (size_t i = 0; i < bookCount; i++) {
		strcpy_s(newBook.Title, sizeof(newBook.Title), createTitle());
		strcpy_s(newBook.Autor, sizeof(newBook.Autor), createAutor());
		strcpy_s(newBook.PublishingHouse, sizeof(newBook.PublishingHouse), createPublishingHouse());
		newBook.Genre = static_cast<Genre>(rand() % 5);

		books[i] = newBook;
	}
}

Book* findBookByAuthor(Book* books, int booksCount, const char* author) {
	if (books == nullptr) return nullptr;

	for (size_t i = 0; i < booksCount; i++) 
		if (strstr(books[i].Autor, author) != nullptr) 
			return &books[i];	

	return nullptr;
}

Book* findBookByTitle(Book* books, int booksCount, const char* title) {
	if (books == nullptr) return nullptr;

	for (size_t i = 0; i < booksCount; i++)
		if (strstr(books[i].Title, title) != nullptr)
			return &books[i];

	return nullptr;
}

void editBook(Book* book) {
	cout << "Отредактируйте необходимые данные: " << endl;

	cout << "Название: " << book->Title << endl;
	cin.ignore(); 
	cin.getline(book->Title, sizeof(book->Title));

	cout << "Автор: " << book->Autor << endl;
	cin.getline(book->Autor, sizeof(book->Autor));

	cout << "Издательство: " << book->PublishingHouse << endl;
	cin.getline(book->PublishingHouse, sizeof(book->PublishingHouse));

	cout << "Выберите жанр, указав цифрой: " << endl;
	for (int i = 0; i < TOTAL_GENRES; i++)
		cout << i + 1 << ". " << genreNames[i] << endl;

	int choice;
	cin >> choice;
	book->Genre = static_cast<Genre>(choice - 1);
}

void sortingLibraryByTitle(Book* books, int booksCount) {

	for (size_t i = 0; i < booksCount; i++)	{

	}
}

void sortByTitle(Book* books, int bookCount) {
	sort(books, books + bookCount, [](const Book& a, const Book& b) {
		return strcmp(a.Title, b.Title) < 0;
		});
}

// Сортировка массива по автору
void sortByAutor(Book* books, int bookCount) {
	sort(books, books + bookCount, [](const Book& a, const Book& b) {
		return strcmp(a.Autor, b.Autor) < 0;
		});
}

// Сортировка массива по издательству
void sortByPublishingHouse(Book* books, int bookCount) {
	sort(books, books + bookCount, [](const Book& a, const Book& b) {
		return strcmp(a.PublishingHouse, b.PublishingHouse) < 0;
		});
}

void displayLibrary(Book* books, int countBooks) {

	for (int i = 0; i < countBooks; i++)	{
		cout << "Книга № " << i + 1 << endl;
		cout << "Название: " << books[i].Title << endl;
		cout << "Автор: " << books[i].Autor << endl;
		cout << "Издательство: " << books[i].PublishingHouse << endl;
		cout << "Жанр: " << genreNames[books[i].Genre] << endl;

		cout << "\n";
		cout << "-----------------------------";
		cout << "\n";

	}
	
}