#include "Book.h"
#include <iostream>
#include <stdlib.h>

//using std
using namespace std;

/**
* Default Constructor for Book
* @para: none
* @return void
*/
Book::Book()
{
    //default constructor sets variable to 'empty' or '0'
    this->author = "";
    this->title = "";
    this->pages = 0;

}


/**
* Book Constructor
* @para: string author, string title, int pages
* @return void
*/
Book::Book(string author, string title, int pages) {
    //set class variable
    this->author = author;
    this->title = title;
    this->pages = pages;

}
/**
* sets the author of this Book
* @para: string newAuthor
* @return void
*/
void Book::setAuthor(string newAuthor) {
    //set author
    this->author = newAuthor;
}

/**
* returns the author of this Book
* @para: none
* @return String
*/
string Book::getAuthor() const{
    //return author
    return this->author;
}

/**
* sets the the title of this Book
* @para: string newTitle
* @return void
*/
void Book::setTitle(string newTitle) {
    //set title
    this->title = newTitle;
}

/**
* returns the title of this Book
* @para: none
* @return String
*/
string Book::getTitle() const{
    //return title
    return this->title;
}
/**
* sets the pages number of this Book
* @para: int pages
* @return void
*/
void Book::setPages(int newPages) {
    //set pages
    this->pages = newPages;
}

/**
* returns the pages number of this Book
* @para: none
* @return int
*/
int Book::getPages() const{
    //return pages
    return this->pages;
}

/**
* converts a string into upper case
* @para: string s
* @return String
*/
string to_uppercase(string& s){
    string::iterator it; //string iterator
    unsigned int ALPH_SIZE = 27; //size of alphabetical
    char alpha[27] = "abcdefghijklmnopqrstuvwxyz"; //small alphabetical
    char ALPHA[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //capital alphabetical
    for (unsigned int i = 0; i < s.size(); i++){//go through all string's characters
        for (unsigned int j= 0; j < ALPH_SIZE; j++){ //decide which alphabet should be capital
            if (s[i] == alpha[j]){
                s[i] = ALPHA[j];
            }
            else if (s[i] == ALPHA[j]) { //if letter is already capital, go to next letter
                break;
            }
        }
    }
    return s;
}
/**
* converts a string onto an integer and sets the integer as the new pages of this Book
* @para: string s
* @return void
*/
void Book::strToInt(string &s) {
    // convert to integer
    int newPages = atoi(s.c_str());
    //set new pages value
    setPages(newPages);
}
/**
* Overloading the output operator
* @para: ostream &out, const Book &b
* @return ostream
*/
std::ostream &operator<<(ostream &out, const Book &b){
    //output stream overloading
    out << b.getAuthor() << "\n" << b.getTitle()
    << "\n" << b.getPages() << "\n" << endl;

    return out;
}
/**
* Overloading the extraction operator
* @para: istream &out, const Book &b
* @return istream
*/

std::istream &operator >> (std::istream &in, Book &b){
    //using getline() to take a whole line of input
    string pages_str = "";
    getline(in, b.author);
    getline(in, b.title);
    getline(in, pages_str);
    b.strToInt(pages_str);
    return in;
}

/**
* Overloading the relational operator '>'
* @para: const Book &b1, const Book &b2
* @return bool
*/
bool operator> (const Book &b1, const Book &b2) {
    //take copies so that actual values are not edited
    string auth1 = b1.getAuthor(); string auth2 = b2.getAuthor();
    auth1 = to_uppercase(auth1); auth2 = to_uppercase(auth2);

    //if values are the same
    if (auth1.compare(auth2) == 0) {
        //take values so that they are not edited
        string t1 = b1.getTitle(); string t2 = b2.getTitle();
        t1 = to_uppercase(t1); t2 = to_uppercase(t2);
        return t1.compare(t2) > 0; //compare
    } else { //else if they are not
        return auth1.compare(auth2) > 0;
    }
}

/**
* Overloading the relations operator '<'
* @para: const Book &b1, const Book &b2
* @return bool
*/
bool operator< (const Book &b1, const Book &b2) {
    //take copies so that actual values are not edited
    string auth1 = b1.getAuthor(); string auth2 = b2.getAuthor();
    auth1 = to_uppercase(auth1); auth2 = to_uppercase(auth2);

    //if values are the same
    if (auth1.compare(auth2) == 0) {
        //take values so that they are not edited
        string t1 = b1.getTitle(); string t2 = b2.getTitle();
        t1 = to_uppercase(t1); t2 = to_uppercase(t2);
        return t1.compare(t2) < 0; //compare
    } else {  //else if they are not
        return auth1.compare(auth2) < 0;
    }
}



