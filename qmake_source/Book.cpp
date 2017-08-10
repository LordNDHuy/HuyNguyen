#include <iostream>
#include "Book.h"
#include <string>
#include "Search.h"
using namespace std;

void Book::AddBook(vector<Booklist> book, int &n) {
	cout << "Ready to add new book : " << endl;
	cout << "Name of book : ";
	cin.ignore();
	getline(cin, book[n].Bookname);
	cout << "Book's type : ";
	getline(cin, book[n].Type);
	cout << "Publisher : ";
	getline(cin, book[n].Publisher);
	cout << "The number of book at first : ";
	cin >> book[n].Number_of_book_at_first;
	book[n].Number_of_book_now = book[n].Number_of_book_at_first;
	cout << endl;
	cout << "Done!!! ";
}
void Book::DeleteBook(vector<Booklist> book, int &n) {
	search::searchBook(string keyword); // them search
	if (book[n].Bookname == search::searchBook(string keyword)) // search duoc dung quyen sach
		if (book[n].Number_of_book_now < book[n].Number_of_book_at_first)
			cout << "\n Borrowed!! \n";
		else
		{
			book.erase(book.begin() + n - 1);
			book.shrink_to_fit();
			cout << "Erased !!  ";
		}
}
void Book::EditBook(vector<Booklist> book, int &n) {
	int Borrowed_book;
	// them search sach 
	// them cin sach chon
	if (book[n].Bookname == search::searchBook(string keyword)){
	Borrowed_book = book[n].Number_of_book_at_first - book[n].Number_of_book_now;
	cout << "\n Change book data : \n";
	cin.ignore();
	getline(cin, book[n].Bookname);
	cout << "Book's type : ";
	getline(cin, book[n].Type);
	cout << "Publisher : ";
	getline(cin, book[n].Publisher);
	cout << "The number of book at first : ";
	cin >> book[n].Number_of_book_at_first;
	book[n].Number_of_book_now = book[n].Number_of_book_at_first;
	book[n].Number_of_book_now = book[n].Number_of_book_at_first - Borrowed_book;
	cout << endl;
	cout << "Done!!! ";
}
}
