#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <fstream> 
#include <stdlib.h>     // EXIT_FAILURE
#include <stdio.h>
#include <string>
#include "OneBookManagement.h"
#include "BookManagent.h"


using namespace std;

using namespace std;
int main() {
	/*
	FILE* f = fopen("a.txt", "w+");
	char str[] = "sadasdasdasdadasaa\n";
	int i = 0;
	while (i < 10) {
		fwrite(str, 1, sizeof(str), f);
		i++;
	}

	fclose(f);

	string a;
	cin >> a;
	a.append(".txt");
	cout << a;

	std::ifstream file(a);
	std::string str1;
	while (std::getline(file, str1))
	{
		cout << str;
	}
	
	*/


	
	/*

	int bookId;
	int numsOfBook;
	string position;
	string nameOfBook;
	string field;
	string author;
	int numsOfPage;
	int publishingYear;


	cout << "position\n";
	cin >> position;
	cout << "nameOfBook\n";
	cin >> nameOfBook;
	cout << "field\n";
	cin >> field;
	cout << "author\n";
	cin >> author;



	OneBookManagement a(1, 2, position, nameOfBook, field, author, 200, 2010);
	cout << a.getNumsOfBook();
	a.addExtraBook(3);
	cout << a.getNumsOfBook();
	a.changePosition();
	cout << a.getPosition();
	


	*/
	
	ListBook listBook;
	listBook.addBook();
	listBook.addBook();
	listBook.showListBook();
	listBook.change();
	listBook.addBook();
	listBook.addBook();
	listBook.addBook();
	listBook.addBook();
	listBook.change();
	
}

