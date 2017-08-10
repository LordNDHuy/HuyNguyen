#pragma once
#ifndef BOOK_MODULE
#define BOOK_MODULE

#include <string>
#include <vector>
using namespace std;
typedef struct {
	string Bookname;
	string Type;
	string Publisher;
	int Number_of_book_at_first, Number_of_book_now;
}Booklist;

namespace Book {
	void AddBook(vector<Booklist> book, int &n);
	void DeleteBook(vector<Booklist> book, int &n);
	void EditBook(vector<Booklist> book, int &n);
}

#endif