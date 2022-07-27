

#include "Borrower.h"
using namespace std;

/**
* Default Constructor
* @para: none
* @return void
*/
Borrower::Borrower() {

}

/**
* Borrower Constructor
* @para: string userID, string name, string address
* @return void
*/
Borrower::Borrower(string userID, string name, string address) {
    this->userID = userID;
    this->name = name;
    this->address = address;
}
/**
* set the user ID of this Borrower
* @para: string newID
* @return void
*/
void Borrower::setUserID(string newID) {
    this->userID = newID;
}
/**
* get the user ID of this Borrower
* @para: none
* @return string
*/
string Borrower::getUserID() const {
    return this->userID;
}

/**
* set the user name of this Borrower
* @para: string newName
* @return void
*/
void Borrower::setName(string newName) {
    this->name = newName;
}

/**
* get the user name of this Borrower
* @para: none
* @return string
*/
string Borrower::getName() const {
    return this->name;
}

/**
* set the user address of this Borrower
* @para: string newAddress
* @return void
*/
void Borrower::setAddress(string newAddress) {
    this->address = newAddress;
}

/**
* get the user address of this Borrower
* @para: none
* @return string
*/
string Borrower::getAddress() const {
    return this->address;
}

/**
* take a book for this Borrower
* @para: LibraryBook &book
* @return void
*/
void Borrower::takeLoan(LibraryBook &book){
    //all loans borrower will ever take stored here
    allLoans.push_back(book);

    //loans borrower currently has
    loanedBooks.push_back(book);
    
}

/**
* this Borrower will return a loaned book,
* which is determined by a boolean value of true if successful, false otherwise.
* @para: LibraryBook &book
* @return bool 
*/
bool Borrower::returnLoan(LibraryBook &book) {
    std::vector<LibraryBook>::iterator it;
    for (it = loanedBooks.begin(); it != loanedBooks.end(); it++){
        if (it->getTitle() == book.getTitle()) {
            loanedBooks.erase(it);
            return true;
        }
    }
    return false;
}

/**
* return the number of pages read by this borrower
* @para: none
* @return int
*/
int Borrower::pagesRead() {
    int pagesRead = 0; //pagesRead
    for (int i = 0; i < allLoans.size(); i++) {
        pagesRead += allLoans[i].getPages(); //get the pages of every book
    }
    return pagesRead; 
}

/**
* return the books taken by this Borrower
* @para: LibraryBook &book
* @return void
*/
vector<LibraryBook> Borrower::getLoanedBooks() {
    return this->loanedBooks;
}

/**
* return all the books ever taken by this Borrower
* @para: LibraryBook &book
* @return void
*/
vector<LibraryBook> Borrower::getAllLoans() {
    return this->allLoans;
}

/**
* overload the output operator for this Borrower
* @para: ostream &out, const Borrower &b
* @return ostream
*/
std::ostream& operator<<(std::ostream &out, const Borrower &b) {
    out << b.getUserID() << " " << b.getName() << ": " << b.getAddress();
    return out;
}

/**
* overload the extraction operator for this Borrower
* @para: istream &in, Borrower &b
* @return istream&
*/
std::istream& operator>>(std::istream &in, Borrower &b) {
    string data;

    getline(in, data, ' '); 
    b.setUserID(data);

    getline(in, data, ':');
    b.setName(data);

    getline(in, data, ' ');

    getline(in, data, '\n');
    b.setAddress(data);
    
    return in;
}
