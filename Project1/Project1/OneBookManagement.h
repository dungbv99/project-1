#define _CRT_SECURE_NO_WARNINGS
#include "BookCard.h"
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class OneBookManagement {
private:
	int bookId;
	int numsOfBook;
	std::string position;
	std::string nameOfBook;
	std::string field;
	std::string author;
	int numsOfPage;
	int publishingYear;
	
	vector<BookCard> listBookCard;

	std::string createBookCode(int orderOfBook) {
		
		std::string numAddString = std::to_string(orderOfBook);
		
		std::string bookIdString = std::to_string(this->bookId);

		string bCode = "";

		bCode.append(bookIdString);
		bCode.append("_");
		bCode.append(numAddString);
		return bCode;
	}
public:



	OneBookManagement(int _bookId,int _numsOfBook, string _position, string _nameOfBook, string _field, string _author, int _numsOfpage, int _publishingYear) {
		this->bookId = _bookId;
		this->numsOfBook = _numsOfBook;
		this->publishingYear = _publishingYear;
		this->numsOfPage = _numsOfpage;
		this->author = _author;
		this->field = _field;
		this->nameOfBook = _nameOfBook;
		this->position = _position;
		

		for (int i = 0; i < _numsOfBook; i++) {
			this->listBookCard.push_back(addBookCard(i));
		}
		
	}


	BookCard addBookCard(int orderOfBook) {
		string bookCode = this->createBookCode(orderOfBook);
		return BookCard(nameOfBook, bookCode, field, author, numsOfPage, publishingYear);
		
	}



	void addExtraBook(int numsOfExtraBook) {
		for (int i = 0; i < numsOfExtraBook; i++) {
			this->listBookCard.push_back(addBookCard(i + this->numsOfBook));
		}
		this->numsOfBook += numsOfExtraBook;
		this->changeNumsOfBook(this->numsOfBook);
	}
	
	void changePosition() {
		cout << "new position\n";
		string newPosition;
		cin >> newPosition;
		

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = this->position;
		string str_replace = newPosition;
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;

		this->position = newPosition;
	}

	void changeNameOfBook() {
		cout << "new name of book\n";
		string news;
		cin >> news;

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = this->nameOfBook;
		string str_replace = news;
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;


		this->nameOfBook = news;
	}

	void changeField() {
		cout << "new field of book\n";
		string news;
		cin >> news;

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = this->field;
		string str_replace = news;
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;




		this->field = news;
	}

	void changeAuthor() {
		cout << "new author of book\n";
		string news;
		cin >> news;

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = this->author;
		string str_replace = news;
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;


		this->author = news;
	}

	void changeNumsOfPage() {
		int news;
		cout << "change number of pages in book\n";
		cin >> news;

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = std::to_string(this->numsOfPage);
		string str_replace = std::to_string(news);
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;



		this->numsOfPage = news;
	}


	void changePublishingYear() {
		int news;
		cout << "change publish year\n";
		cin >> news;

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = std::to_string(this->publishingYear);
		string str_replace = std::to_string(news);
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;



		this->publishingYear = news;
	}



	void changeNumsOfBook(int news) {
		

		string fileName = "./file/";
		fileName.append(nameOfBook);
		fileName.append(".txt");

		ostringstream text;
		ifstream in_file(fileName);

		text << in_file.rdbuf();
		string str = text.str();
		string str_found = std::to_string(this->numsOfBook);
		string str_replace = std::to_string(news);
		size_t pos = str.find(str_found);
		str.replace(pos, string(str_found).length(), str_replace);
		in_file.close();

		ofstream out_file(fileName);
		out_file << str;

	}


	int getNumsOfBook() {
		return this->numsOfBook;
	}
	int getNumsOfPage() {
		return this->numsOfBook;
	}
	int getPublishingYear() {
		return this->publishingYear;
	}
	std::string getPosition() {
		return this->position;
	}
	std::string getField() {
		return this->field;
	}
	std::string getAuthor() {
		return this->author;
	}
	
	std::string getNameOfBook() {
		return this->nameOfBook;
	}

	int getBookId() {
		return this->bookId;
	}
	void setBookId(int _bookId) {
		this->bookId = _bookId;
	}
	void setNumsOfBook(int _numsOfBook) {
		this->numsOfBook = _numsOfBook;
	}
	void setPosition(string _position) {
		this->position = _position;
	}
	void setNameOfBook(string _nameOfBook) {
		this->nameOfBook = _nameOfBook;
	}
	void setField(string _field) {
		this->field = _field;
	}
	void setAuthor(string _author) {
		this->author = _author;
	}
	void setNumsOfPage(int _numsOfPage) {
		this->numsOfPage = _numsOfPage;
	}
	void setPublishingYear(int _publishingYear) {
		this->publishingYear = _publishingYear;
	}
};
