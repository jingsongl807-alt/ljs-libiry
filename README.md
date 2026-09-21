# ljs-libiry
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
	string name;        
	string isbn;        
	string publisher;   
	double price;       
	int pages;         
	bool inStock;       
	
public:
	Book();                                            
	Book(string n, string i, string p, double pr, int pg);  
	
	void setName(string n);
	void setISBN(string i);
	void setPublisher(string p);
	void setPrice(double pr);
	void setPages(int pg);
	
	string getName() const;
	string getISBN() const;
	string getPublisher() const;
	double getPrice() const;
	int getPages() const;
	bool getInStock() const;
	
	void display() const;
	

	bool checkISBN() const;
	
	void borrow();      
	void returnBook();  
};

#endif

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
