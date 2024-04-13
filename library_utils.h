#pragma once
#include <cstdlib>
#include <random>

//Random random;

enum Genre {
	Novel,
	Detective,
	ScienceFiction,
	Fantasy,
	Adventure,
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
		 "����� ������������",
		 "1984",
		 "������� ������",
		 "�������� � �������������",
		 "��� ��������� �� ���",
		 "������, ��� ���� � �������",
		 "� ������ ����� ���",
		 "����� ������ � ����������� ������",
		 "��������� �����",
		 "�������� ����",
		 "��� �� �����",
		 "�������",
		 "������� ������",
		 "������� �� ������",
		 "�������� ������"
	};


	return bookTitles[rand() % 15];
}


const char* createAutor() {

	const int NUM_AUTHORS = 15;
	const char* authors[NUM_AUTHORS] = {
	   "����� ������",
	   "������ ������",
	   "������� ����� �����������",
	   "����� �����",
	   "������ �. ���������",
	   "��.�.�. �������",
	   "����� ������",
	   "����� �. �������",
	   "��. �. �. �������",
	   "������ �������",
	   "��� �����",
	   "����� ������",
	   "����� ������� �����",
	   "����� �. ���",
	   "���� ����"
	};

	return authors[rand() % 15];
}

const  char* createPublishingHouse() {

	const int NUM_PUBLISHINGHOUSE = 15;
	const char* publishingHouses[NUM_PUBLISHINGHOUSE] = {
	   "�����",
	   "���",
	   "ACT",
	   "������",
	   "������",
	   "������� ��������",
	   "��� ������",
	   "�������",
	   "����",
	   "����",
	   "�������",
	   "������",
	   "��������",
	   "�����",
	   "��������-�����"
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
