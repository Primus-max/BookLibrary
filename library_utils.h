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
