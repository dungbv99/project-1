#define _CRT_SECURE_NO_WARNINGS
#include "OneBookManagement.h"
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <fstream> 
#include <stdlib.h>     // EXIT_FAILURE
#include <stdio.h>
#include <string>
using namespace std;
class ListBook {
	vector<OneBookManagement> list;
	string filePathListBookName = "listpath.txt";
	string fileListBookName = "listbook.txt";
public:
	ListBook() {
		ifstream myfile(filePathListBookName);
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{

				string line;
				getline(myfile, line);
				ifstream fileBook(line);

				if (fileBook.is_open()) {
					int i = 0;
					int bookId;
					int numsOfBook;
					string position;
					string nameOfBook;
					string field;
					string author;
					int numsOfPage;
					int publishingYear;
					while (!fileBook.eof()) {
						string l;
						getline(fileBook, l);
						if (i == 0) {
							bookId = stoi(l);

						}
						else if (i == 1) {
							nameOfBook = l;
						}
						else if (i == 2) {
							position = l;
						}
						else if (i == 3) {
							author = l;
						}
						else if (i == 4) {
							field = l;
						}
						else if (i == 5) {
							numsOfPage = stoi(l);

						}
						else if (i == 6) {
							publishingYear = stoi(l);

						}
						else if (i == 7) {
							numsOfBook = stoi(l);

						}
						i++;
					}
					OneBookManagement oneBookManagement(bookId, numsOfBook, position, nameOfBook, field, author, numsOfPage, publishingYear);
					list.push_back(oneBookManagement);
				}
				fileBook.close();

				
			}
			myfile.close();
		}
		

	}

	void showListBook() {
		cout << "List book in library : \n";
		for (int i = 0; i < list.size(); i++) {
			cout <<i <<"   " <<list[i].getNameOfBook() << "\n";
		}
	}

	void showBookDetail() {
		cout << "id of book you want to show detail: \n";
		int i;
		cin >> i;
		if (i >= list.size()) {
			cout << "there is no book with id = " << i << "\n";
		}
		else {
			cout << "name : " << list[i].getNameOfBook() << "\n";
			cout << "author : " << list[i].getAuthor() << "\n";
			cout << "position : " << list[i].getPosition() << "\n";
			cout << "field : " << list[i].getField() << "\n";
			cout << "num of pages : " << list[i].getNumsOfPage() << "\n";
			cout << "publishing year : " << list[i].getPublishingYear() << "\n";
			cout << "num of books : " << list[i].getNumsOfBook() << "\n";
		}
	}
	

	void addBook() {
		string name;
		cout << "what is the name of book that you want to add?\n";
		cin >> name;
		
		string position;
		cout << "where is book's position?\n";
		cin >> position;
		
		string author;
		cout << "what is author of book?\n";
		cin >> author;
		
		string field;
		cout << "what is the field of book?\n";
		cin >> field;

		int numsOfBook;
		cout << "what is the number of book you want to add?\n";
		cin >> numsOfBook;

		int page;
		cout << "how many page in book?\n";
		cin >> page;

		int bookID = list.size();

		int publishingYear;
		cout << "when did the book publish?\n";
		cin >> publishingYear;

		string fileName = "./file/";
		fileName.append(name);
		fileName.append(author);
		fileName.append(".txt");

		OneBookManagement oneBookManagement(bookID, numsOfBook, position, name, field, author, page, publishingYear);
		list.push_back(oneBookManagement);

		

		ofstream listBookFile;
		
		listBookFile.open(this->fileListBookName, std::ios::app);
		listBookFile << name;
		listBookFile << "\n";
		listBookFile.close();

		ofstream listPathBookfile;
		listPathBookfile.open(this->filePathListBookName, std::ios::app);
		listPathBookfile << fileName;
		listPathBookfile << "\n";
		listPathBookfile.close();

		ofstream myfile;
		myfile.open(fileName);
		myfile << bookID;
		myfile << "\n";
		myfile << name;
		myfile << "\n";
		myfile << position;
		myfile << "\n";
		myfile << author;
		myfile << "\n";
		myfile << field;
		myfile << "\n";
		myfile << page;
		myfile << "\n";
		myfile << publishingYear;
		myfile << "\n";
		myfile << numsOfBook;
		myfile.close();

		

	}



	void search() {

	}



	void change() {
		

	}
};