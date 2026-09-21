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
