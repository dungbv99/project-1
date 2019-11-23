#include <string>
#include <iostream>
using namespace std;
class BookCard {
private:
	string bookName;
	string bookCode;
	string field;
	string author;
	int numsOfPage;
	int publishingYear;
public:
	BookCard( string _bookName , string _bookCode, string _field , string _author , int _numsOfPage,int _publishingYear) {
		this->numsOfPage = _numsOfPage;
		this->publishingYear = _publishingYear;
		/*
		int size = sizeof(_bookName) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->bookName[i] = _bookName[i];
		}

		size = sizeof(_bookCode) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->bookCode[i] = _bookCode[i];
		}

		size = sizeof(_field) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->field[i] = _field[i];
		}
		size = sizeof(_author) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->author[i] = _author[i];
		}
		*/
		this->author = _author;
		this->bookCode = _bookCode;
		this->bookName = _bookName;
		this->field = _field;

	}
/*
	void setBookName(char* _bookName) {
		int size = sizeof(_bookName) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->bookName[i] = _bookName[i];
		}
	}

	void setBookCode(char* _bookCode) {
		int size = sizeof(_bookCode) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->bookCode[i] = _bookCode[i];
		}
	}


	void setField(char* _field) {
		int size = sizeof(_field) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->field[i] = _field[i];
		}
	}

	void setAuthor(char* _author) {
		int  size = sizeof(_author) / sizeof(char);
		for (int i = 0; i < size; i++) {
			this->author[i] = _author[i];
		}
	}
*/

	std::string getBookName() {
		return this->bookName;
	}
	std::string getBookCode() {
		return this->bookCode;
	}
	std::string getField() {
		return this->field;
	}
	std::string getAuthor() {
		return this->author;
	}
	int getNumsOfPage() {
		return this->numsOfPage;
	}
	int getPublishingYear() {
		return this->publishingYear;
	}

};

