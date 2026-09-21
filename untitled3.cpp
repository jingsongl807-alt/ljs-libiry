#include "Book.h"
#include <iostream>
#include <cctype>

Book::Book() {
	name = "未知书名";
	isbn = "0000000000000";
	publisher = "未知出版社";
	price = 0.0;
	pages = 0;
	inStock = true;
}

Book::Book(string n, string i, string p, double pr, int pg) {
	name = n;
	isbn = i;
	publisher = p;
	price = (pr > 0) ? pr : 0.0;   
	pages = (pg > 0) ? pg : 0;    
	inStock = true;
}

void Book::setName(string n)    { name = n; }
void Book::setISBN(string i)    { isbn = i; }
void Book::setPublisher(string p) { publisher = p; }

void Book::setPrice(double pr) {
	if (pr > 0) price = pr;
	else cout << "价格必须为正数！" << endl;
}

void Book::setPages(int pg) {
	if (pg > 0) pages = pg;
	else cout << "页数必须为正数！" << endl;
}

string Book::getName() const      { return name; }
string Book::getISBN() const      { return isbn; }
string Book::getPublisher() const { return publisher; }
double Book::getPrice() const     { return price; }
int Book::getPages() const        { return pages; }
bool Book::getInStock() const     { return inStock; }

bool Book::checkISBN() const {
	string clean;
	for (char c : isbn) {
		if (c != '-' && c != ' ') clean += c;
	}
	
	int len = clean.length();
	
	if (len == 10) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (!isdigit(clean[i])) return false;
			sum += (clean[i] - '0') * (10 - i); 
		}
		if (clean[9] != 'X' && clean[9] != 'x' && !isdigit(clean[9]))
			return false;
		
		int checkDigit = (clean[9] == 'X' || clean[9] == 'x') ? 10 : (clean[9] - '0');
		return (11 - (sum % 11)) % 11 == checkDigit;
	}
	
	if (len == 13) {
		if (clean.substr(0, 3) != "978" && clean.substr(0, 3) != "979")
			return false;
		
		int sum = 0;
		for (int i = 0; i < 12; i++) {
			if (!isdigit(clean[i])) return false;
			int digit = clean[i] - '0';
			sum += (i % 2 == 0) ? digit : digit * 3;  
		}
		int checkDigit = (10 - (sum % 10)) % 10;
		return checkDigit == (clean[12] - '0');
	}
	
	return false;  
}

void Book::borrow() {
	if (inStock) {
		inStock = false;
		cout << "《" << name << "》借出成功" << endl;
	} else {
		cout << "《" << name << "》已被借出，无法再次借阅" << endl;
	}
}

void Book::returnBook() {
	if (!inStock) {
		inStock = true;
		cout << "《" << name << "》归还成功" << endl;
	} else {
		cout << "《" << name << "》已在馆内，无需归还" << endl;
	}
}

void Book::display() const {
	cout << "书名：" << name << endl;
	cout << "ISBN：" << isbn << endl;
	cout << "出版社：" << publisher << endl;
	cout << "价格：" << price << " 元" << endl;
	cout << "页数：" << pages << " 页" << endl;
	cout << "状态：" << (inStock ? "可借" : "已借出") << endl;

