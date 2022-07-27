#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H
#include "Book.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

class LibraryBook : public Book
{
    public:
        LibraryBook(); //default constructor
        LibraryBook(string author, string title, int pages, string classificationCode, int statusCode); //Library Book constructor
        
        void setStatusCode(string newStat); //status code setter
        int getStatusCode() const; //status code getter
        
        void setClassificationCode(string newCode); //classification code setter
        string getClassificationCode() const; //classification code getter
        
        string getStatusCodeString() const; //status code getter as string
        
        friend ostream& operator<<(ostream &out, const LibraryBook &lb); //overloading the output stream
        friend istream& operator>>(istream &in, LibraryBook &lb); //overloading the input stream
    protected:
    private:
        enum StatusCode //enumeration
        {
            ONLOAN,
            AVAILABLEFORLENDING,
            REFERENCEONLY
        };      
       string classificationCode;
       StatusCode statusCode;
};

#endif // LIBRARYBOOK_H
