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
			cout << "num of pages : " << list[i].getNumsOfPage() << "\n";
			cout << "\n";
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
		fileName.append(std::to_string(bookID));
		fileName.append(name);
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
		cout << "Enter your name of book you want to search\n";
		string name;
		cin >> name;
		int stt = 1;
		cout << "list book have " << name << " in name : \n";
		cout << "numerical order   " << "book id         " << "name  \n";
		for (int i = 0; i < list.size(); i++) {
			if (list[i].getNameOfBook().find(name) != string::npos) {
				cout << stt << "                  " << i << "            " << list[i].getNameOfBook() << "\n";
			}
		}
	}



	void change() {
		cout << "What is book id you want to change info?\n";
		int id;
		cin >> id;

		if (id >= list.size()) {
			cout << "No book have id = " << id << "\n";
			return;
		}

		string name;
		cout << "what is the new name of book ?\n";
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


		int publishingYear;
		cout << "when did the book publish?\n";
		cin >> publishingYear;




		string fn = "./file/";
		fn.append(std::to_string(id));
		fn.append(list[id].getNameOfBook());
		fn.append(".txt");
		remove(fn.c_str());

		fn = "./file/";
		fn.append(std::to_string(id));
		fn.append(name);
		fn.append(".txt");

		ofstream myfile;
		myfile.open(fn);
		myfile << id;
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


		list[id].setNameOfBook(name);
		list[id].setAuthor(author);
		list[id].setField(field);
		list[id].setNumsOfBook(numsOfBook);
		list[id].setNumsOfPage(page);
		list[id].setPosition(position);
		list[id].setPublishingYear(publishingYear);

		fstream listBookFile(this->fileListBookName);


		fstream listPathBookfile(this->filePathListBookName);


		for (int i = 0; i < list.size(); i++) {
			listBookFile << list[i].getNameOfBook();
			listBookFile << "\n";



			string filename = "./file/";
			filename.append(std::to_string(i));
			filename.append(list[i].getNameOfBook());
			filename.append(".txt");
			listPathBookfile << filename;
			listPathBookfile << "\n";
		}


		listPathBookfile.close();
		listBookFile.close();

	}
};