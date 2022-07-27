#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <cstring>

using namespace std;
class Book
{
    public:
        Book(); //default constructor
        Book(string author, string title, int pages); //book constructor

        void setAuthor(string newAuthor); //author setter
        string getAuthor() const; //suthor getter

        void setTitle(string newTitle); //title setter
        string getTitle() const; //title getter

        void setPages(int newPages); //pages setter
        int getPages() const; //pages getter

        string to_uppercase(string &s); //header method for converting string to upper-case
        void strToInt(string &s); //converts string to integer

        friend ostream& operator<<(ostream &out, const Book &b); //overloading output stream
        friend istream& operator>>(istream &in, Book &b); //overloading extraction stream

        friend bool operator>(const Book &b1, const Book &b2); //overloading comparsion operator
        friend bool operator<(const Book &b1, const Book &b2);
        
        operator int () const;
    protected:
        string author; //protected variable so that sub-classes may inherit.
        string title;
        int pages;
    private:



};

#endif // BOOK_H
