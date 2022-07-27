#include "Library.h"

/**
* default constructor
*/
Library::Library() {
    
}

/**
* return the book vector
* @para: none
* @return vector<LibraryBook>
*/
vector<LibraryBook> Library::getBooks() {
    return this->books;
}

/**
* return the borrower vector
* @para: none
* @return vector<Borrower>
*/
vector<Borrower> Library::getBorrowers() {
    return this->borrowers;
}

/**
* set book vector to newBookList
* @para: vector<LibraryBook> bookList
* @return void
*/
void Library::setBookList(vector<LibraryBook> newBookList) {
    this->books = newBookList;
}

/**
* set borrower vector to newBorrowerVector
* @para: vector<Borrower> borrowerList
* @return void
*/
void Library::setBorrowerList(vector<Borrower> newBorrowerList) {
    this->borrowers = newBorrowerList;
}

/**
* reads the users.txt file and adds the data to borrower vector
* @para: none
* @return vector<Borrower>
*/
vector<Borrower> Library::readBorrowerList() {
    Borrower b; //prepare a borrower object
    fstream in; //file stream
    vector<Borrower> borrowerList; //borrower vector
    in.open("users.txt"); // open file
    if (in.fail()) { //if it fails
        cerr << "error opening file" << endl;
    }
    while (in >> b) { // while there is data in stream
        borrowerList.push_back(b); //get data
    }
    setBorrowerList(borrowerList); //set this Library's borrower vector
    in.close(); //close file stream
    return borrowerList;
}

/**
* reads the librarybooks.txt file and adds the data to book vector
* @para: none
* @return vector<LibraryBook>
*/
vector<LibraryBook> Library::readBookList() {
    LibraryBook lb; //prepare a LibraryBook object
    vector<LibraryBook> libraryBookList; //LibraryBook vector
    std::ifstream in("librarybooks.txt"); //file stream 
    while (in >> lb) { // while there is data in stream
        libraryBookList.push_back(lb); 
    }
    setBookList(libraryBookList); //set this Library's book vector
    in.close(); // close file stream
    return libraryBookList;
}

/**
* displays the borrower list of the library
* @para: none
* @return void
*/
void Library::displayBorrowerList() {
    vector<Borrower>::iterator it;
    for (it = borrowers.begin(); it != borrowers.end(); it++) {
        cout << *it << "\n" << endl; // display
    }
}

/**
* displays the sorted book list of this library
* @para: none
* @return void
*/
void Library::displaySortedBookList() {
    sort(books.begin(), books.end()); //sort
    for (vector<LibraryBook>::iterator it = books.begin(); it != books.end(); it++) {
        cout << *it << "\n" << endl; //display 
    }
}

/**
* displays the borrower from this library with largest number of loans
* @para: none
* @return void
*/
void Library::borrowerWithLargestNumberOfLoans() {
    int loanSize = 0; 
    Borrower borrower; // prepare borrower object
    for (vector<Borrower>::iterator it = borrowers.begin(); it != borrowers.end(); it++) {
        if (it->getAllLoans().size() > loanSize) { //get largest size of loans
            loanSize = it->getAllLoans().size(); 
            borrower = *it; //get the borrower with largest loans
        }
    }
    cout << borrower << " --- Total Loans: " << borrower.getAllLoans().size(); //display 
}

/**
* display the borrower of this library with least number of pages read
* @para: none
* @return void
*/
void Library::borrowerWithLeastPagesRead() {
    Borrower borrower; //prepare borrower object
    int pagesRead = 0; //pages read of every borrower
    int leastPages = 0; //least pages 
    for (vector<Borrower>::iterator it = borrowers.begin(); it != borrowers.end(); it++) {
        pagesRead = it->pagesRead();
        if (leastPages == 0 || pagesRead < leastPages) {
            leastPages = pagesRead;
            borrower = *it; //get the borrower with least pages
        }
    }
    cout << borrower << " --- Total Pages Read: " << leastPages << endl; //display
}
    







