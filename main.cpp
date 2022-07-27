#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "LibraryBook.h"
#include "Borrower.h"
#include "Library.h"

using namespace std;

Library readAndProcessTransactions(Library &lb); //header definition

int main() {
    std::fstream in("errorlog.txt");
    cerr.rdbuf(in.rdbuf());
    
    Library lb;
    
    lb.readBookList(); //read the librarybooks.txt
    lb.readBorrowerList(); //read the users.txt
    
    cout << "============================ LIBRARY SIMULATION ============================" << endl;
    lb = readAndProcessTransactions(lb); // start reading and processing transaction
    cout << "\n\n============================ SORTED LIBRARY BOOKS ============================" << endl;
    lb.displaySortedBookList(); //display sorted list
    cout << "\n\n============================ BORROWER WITH LARGEST LOANS ============================" << endl;
    lb.borrowerWithLargestNumberOfLoans(); //display borrower with largest number of loans
    cout << "\n\n============================ BORROWER WITH LEAST PAGES READ ============================" << endl;
    lb.borrowerWithLeastPagesRead(); //borrower with least pages read
    
    std::cout.rdbuf(in.rdbuf()); //reset to standard output
    in.close(); //close the buffer
    return 0;
}

/**
* reads the transaction file,
* takes a library object, process books and borrowers 
* and update the library object accordingly.
* @para: Library &lb
* @return Library
*/
Library readAndProcessTransactions(Library &lb) {
    //get the vectors for books and borrowers
    vector<LibraryBook> books = lb.getBooks();
    vector<Borrower> borrowers = lb.getBorrowers();
    //if book list or borrower list are empty
    if (books.empty() || borrowers.empty()) {
        cout << "Library's records are not updated" << endl;
        exit(1);
    }
    
    //open file
    ifstream in("transactions.txt");

    vector<Borrower>::iterator borrowerIt; //iterator over the borrowers 
    vector<LibraryBook>::iterator bookIt; //iterator over the books

    //setting up data that will hold transaction information
    string line = "";
    string transaction = "";
    string author = "";
    string title = "";
    string borrowerName = "";

    if (in.fail()) { //if opening file is failed
        cerr << "cannot open file" << endl;
        exit(1);
    }

    while (!in.eof()) {
        //get transaction info bit by bit
        std::getline(in, line, ':');
        transaction = line;
        std::getline(in, line, ' ');
        std::getline(in, line, ':');
        borrowerName = line;
        std::getline(in, line, ' ');
        std::getline(in, line, ',');
        author = line;
        std::getline(in, line, '"');
        std::getline(in, line, '"');
        title = line;
        std::getline(in, line, '\n');
        
        //if stream reached end of file, it still reads, 
        //therefore check if variables are not empty
        if (!transaction.empty()) { //condition for display purposes
            //display transaction
            cout << transaction << ": " << borrowerName << " : " << author << ", " << "\"" << title << "\"" << "\n" << endl;
        }
        //determine the borrower by name
        for (borrowerIt = borrowers.begin(); borrowerIt != borrowers.end(); borrowerIt++) {
            if (borrowerIt->getName() == borrowerName) { //get borrower
                break; //stop looping
            }
        }
        //determine transaction type, check if book exists, 
        //check if borrower is able to borrow, finally execute transaction
        for (bookIt = books.begin(); bookIt != books.end(); bookIt++) {
            if (bookIt->getTitle() == title && transaction == "request") { //if title matches and transaction type is 'request' do 
                if (borrowerIt->getLoanedBooks().size() < 3) { //if borrower can borrow a book
                    if (bookIt->getStatusCodeString() == "AVAILABLE FOR LENDING") { //check book status
                        borrowerIt->takeLoan(*bookIt);
                        bookIt->setStatusCode("ON LOAN");
                        cout << bookIt->getTitle() << " IS LOANED TO " << borrowerIt->getName() << endl;
                    } else if (bookIt->getStatusCodeString() == "REFERENCE ONLY") { //borrower should cannot borrow this
                        cerr << bookIt->getTitle() << " IS REFERENCE ONLY" << endl;//cerr saved to file
                        cout << bookIt->getTitle() << " IS REFERENCE ONLY" << endl;//output the error
                    } else {
                        cerr << bookIt->getTitle() << " IS ON LOAN" << endl; //cerr saved to file
                        cout << bookIt->getTitle() << " IS ON LOAN" << endl; //output the error 
                    }
                } else {
                    cerr << borrowerIt->getName() << " CANNOT LOAN MORE BOOKS" << endl;//cerr saved to file
                    cout << borrowerIt->getName() << " CANNOT LOAN MORE BOOKS" << endl;//output the error
                }
                break; //stop, proceed to next transaction
            } else if (bookIt->getTitle() == title && transaction == "return") { //if request is return and title matches
                borrowerIt->returnLoan(*bookIt); //return the loan
                bookIt->setStatusCode("AVAILABLE FOR LENDING"); //reset the book's status
                cout << bookIt->getTitle() << " IS AVAILABLE FOR LENDING" << endl;
                break; //stop, proceed to next transaction
            }
        }
    }
    //house keeping, when done close buffer
    in.close();
    //set the updated vectors to library's object
    lb.setBookList(books);
    lb.setBorrowerList(borrowers);
    return lb; //return library
}

