#include "LibraryBook.h"
#include "Book.h"

/**
* Default Constructor
* @para: none
* @return void
*/
LibraryBook::LibraryBook()
{
    
}

/**
* LibraryBook constructor
* @para: string author, string title, int pages, string classificationCode, StatusCode statusCode
* @return void
*/
LibraryBook::LibraryBook(string author, string title, int pages, string classificationCode, int statusCode) {
    //assign values
    this->author = author;
    this->title = title;
    this->pages = pages;
    this->classificationCode = classificationCode;
    this->statusCode = (StatusCode) statusCode;
}


/**
* sets the statusCode of this LibraryBook object depending on its code
* @para: String newStat
* @return void
*/
void LibraryBook::setStatusCode(string newStat) {
    if (newStat == "AVAILABLE FOR LENDING") {
        this->statusCode = (StatusCode)0;
    }
    else if (newStat == "ON LOAN") {
        this->statusCode = (StatusCode)1;
    }
    else {
        this->statusCode = (StatusCode)2;
    }
}

/**
* returns the statusCode of this LibraryBook
* @para: none
* @return StatusCode
*/
int LibraryBook::getStatusCode() const{
    //return statusCode
    return this->statusCode;
}

/**
* sets the classificationCode of libraryBook object
* @para: string newCode
* @return void
*/
void LibraryBook::setClassificationCode(string newCode){
    this->classificationCode = newCode;
}

/**
*
* returns the classificationCode of this LibraryBook object
* @para: none
* @return String
*/
string LibraryBook::getClassificationCode() const{
    //return classificationCode
    return classificationCode;
}

/**
* sets the statusCode of this LibraryBook object depending on its code
* @para: String newStat
* @return void
*/
string LibraryBook::getStatusCodeString() const {
    //get current status code
    int code = this->getStatusCode();

    //decide on string representation
    if (code == 0) {
        return "AVAILABLE FOR LENDING";
    }
    else if (code == 1) {
        return "ON LOAN";
    }
    else {
        return "REFERENCE ONLY";
    }
}

/**
* Overloading the output operator
* @para: ostream &out, const LibraryBook &lb
* @return void
*/
std::ostream& operator<<(ostream &out, const LibraryBook &lb) {
    out << lb.getAuthor() << ", " << "\"" << lb.getTitle() << "\" ("
    << lb.getPages() << " pp.)  [" << lb.getClassificationCode() << " " << lb.getStatusCodeString() << "]" << endl;
    //overloading inherited overloaded output stream

    return out;
}

/**
* Overloading the extraction operator to be used on files
* @para: fstream &fileIn, const LibraryBook &lb
* @return void
*/
std::istream& operator>>(istream &in, LibraryBook &lb) {
    string data;
    //P.G. Wodehouse, "Heavy Weather" (336 pp.) [PH.409 AVAILABLE FOR LENDING]

    getline(in, data, ',');
    lb.setAuthor(data);

    getline(in, data, '"');
    getline(in, data, '"');
    lb.setTitle(data);

    getline(in, data, '(');
    getline(in, data, ')');
    lb.strToInt(data);

    getline(in, data, '[');
    getline(in, data, ' ');
    lb.setClassificationCode(data);

    getline(in, data, ']');
    lb.setStatusCode(data);

    getline(in, data, '\n');

    return in;
}

