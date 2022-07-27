#ifndef LIBRARY_H
#define LIBRARY_H
#include "Borrower.h"
#include "LibraryBook.h"
#include <algorithm>
#include <sstream>

class Library
{
    public:
        Library(); //default constructor
        
        vector<LibraryBook> getBooks(); //book list getter
        vector<Borrower> getBorrowers(); //borrower list getter
        
        void setBookList(vector<LibraryBook> newBookList); //book list setter
        void setBorrowerList(vector<Borrower> newBorrowerList); // borrower list setter
        
        vector<Borrower> readBorrowerList(); //read users file
        vector<LibraryBook> readBookList(); //read librarybooks file
        
        void displayBorrowerList(); //display borrowers
        void displaySortedBookList(); //display sorted book list 
        void borrowerWithLargestNumberOfLoans(); //display borrower with with largest number of loans
        void borrowerWithLeastPagesRead(); //display borrower with least number of pages read
    protected:
    private:
        vector<LibraryBook> books; //book vector
        vector<Borrower> borrowers; //borrower vector
        
};

#endif // LIBRARY_H
