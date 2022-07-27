/*
 * File:   Borrower.h
 * Author: fnj12dxa
 *
 * Created on 05 March 2015, 15:19
 */

#ifndef BORROWER_H
#define	BORROWER_H
#include <string>
#include <string.h>
#include "LibraryBook.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>


using namespace std;

class Borrower {
    public:
        Borrower(); //default constructor
        Borrower(string userID, string name, string address); //Borrower Constructor
        void setUserID(string newID); //set the user ID
        string getUserID() const; //get the user ID
        
        void setName(string newName); //set the user name
        string getName() const; //get the user name
        
        void setAddress(string newAddress); //set the user address
        string getAddress() const; //get the user address
        
        void takeLoan(LibraryBook &book); //take a loan 
        bool returnLoan(LibraryBook &book); //return a loan
        
        int pagesRead(); //return number of pages
        vector<LibraryBook> getLoanedBooks(); //return loaned books by this Borrower
        vector<LibraryBook> getAllLoans(); //return all loans by this Borrower
        
        friend ostream& operator<<(ostream &out, const Borrower &b); //overlaoding the output stream
        friend istream& operator>>(istream &in, Borrower &b); //overloading the extraction stream
    private:
        string userID;
        string name;
        string address;
        vector <LibraryBook> loanedBooks;
        vector <LibraryBook> allLoans;
};

#endif	/* BORROWER_H */

