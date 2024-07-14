#include "Book.hpp"
using namespace std;

    // write and document all methods in this file.

    // Default constructor
    Book::Book() { 
      title_ = "";
      author_ = "";
      ISBN_ = 0;
      icon_ = nullptr;
      price_ = 0.00;
      keywords_ = {};
      blurb_ = "";
    }

    //Destructor
    Book::~Book()
    {
      // Deallocate memory for icon_
      delete[] icon_;
      icon_ = nullptr;
    }

    // Copy constructor.
    Book::Book(const Book& rhs)
    {
      title_ = rhs.title_;
      author_ = rhs.author_;
      ISBN_ = rhs.ISBN_;
      price_ = rhs.price_;
      keywords_ = rhs.keywords_;
      blurb_ = rhs.blurb_;

      if (rhs.icon_ != nullptr){
         // allocate memory
        icon_ = new int[80];   
        for (int i = 0; i < 80; i++){
          icon_[i] = rhs.icon_[i];
        }
      }
      else{
        icon_ = nullptr;
      }
    }

// Copy assignment operator.
Book& Book::operator=(const Book& rhs)
{
    if (this != &rhs) {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        // Deallocate memory before assigning new memory
        delete[] icon_;
       icon_ = nullptr;

        if (rhs.icon_ != nullptr) {
            // Allocate new memory and copy values
            icon_ = new int[80];
            for (int i = 0; i < 80; i++) {
                icon_[i] = rhs.icon_[i];
            }
        }
        else {
            icon_ = nullptr;
        }
    }

    return *this;
  }

// Move constructor
    Book::Book(Book&& rhs)
    {      
      title_ = move(rhs.title_);
      author_ = move(rhs.author_);
      ISBN_ = move(rhs.ISBN_);
      icon_ = rhs.icon_;
      price_ = move(rhs.price_);
      blurb_ = move(rhs.blurb_);
      keywords_ = move(rhs.keywords_);

      // prevent memory leak
      rhs.icon_ = nullptr;
    }

  //Move assignment operator 
    Book& Book::operator=(Book&& rhs)
    {
      if (this != &rhs){
        title_ = move(rhs.title_);
        author_ = move(rhs.author_);
        ISBN_ = move(rhs.ISBN_);
        icon_ = rhs.icon_;
        price_ = move(rhs.price_);
        blurb_ = move(rhs.blurb_);
        keywords_ = move(rhs.keywords_);
        // prevent memory leak
        rhs.icon_ = nullptr;
      }
      return *this; 
    }

    /*
        @return : the title of the Book
    */
    const std::string& Book::getTitle() const
    {
      return title_;
    }

    /** 
    @param  : a string reference title
    @post   : sets the Book's title to the value of the parameter
    */
    void Book::setTitle(const std::string& title)
    {
      title_ = title;
    }

    /*
        @return : the name of the Author
    */
    const std::string& Book::getAuthor() const
    {
      return author_;
    }

    /** 
    @param  : a reference string author
    @post   : sets the Book's author to the value of the parameter
    */
    void Book::setAuthor(const std::string& author)
    {
      author_ = author;
    }
    /*
        @return : the ISBN
    */
    long long int Book::getISBN() const
    {
      return ISBN_;
    }

    /** 
    @param  : a long long int which is the ISBN
    @post   : sets the Book's ISBN to the value of the parameter
    */
    void Book::setISBN(long long int ISBN)
    {
      ISBN_= ISBN;
    }
    
    /*
        @return : the icon
    */
    const int* Book::getIcon() const
    {
      return icon_;
    }

    /** 
    @param  : a int pointer icon
    @post   : sets the Book's icon to the value of the parameter
    */
    void Book::setIcon(int* icon)
    {
      icon_ = icon;
    }

    /*
        @return : the price
    */
    float Book::getPrice() const
    {
      return price_;
    }
    /** 
    @param  : a float which is the price
    @post   : sets the Book's price to the value of the parameter
    */
    void Book::setPrice(float price)
    {
      price_ = price;
    }
    
    /*
        @return : keyword
    */
    const std::vector<std::string>& Book::getKeywords() const
    {
      return keywords_;
    }

    /** 
    @param  : a reference vector to keywords
    @post   : sets the Book's keywords to the value of the parameter
    */
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
     keywords_ = keywords;
    }


    /*
        @return : the blurb
    */
    const std::string& Book::getBlurb() const
    {
      return blurb_;
    }
    
    /** 
    @param  : a reference string blurb
    @post   : sets the Book's blurb to the value of the parameter
    */
    void Book::setBlurb(const std::string& blurb)
    {
      blurb_ = blurb;
    }

    /*
        Prints the book data to the console.
    */
    void Book::print() const
    {
      cout << "Title: " << getTitle() << endl;
      cout << "Author: " << getAuthor() << endl;
      cout << "ISBN: " << getISBN() << endl;
      
      cout << "Icon: ";
      for (int i = 0; i < 80; i++){
        cout << getIcon()[i] << " ";
      }
      cout << endl;
      
      cout << "Price: $" << fixed << setprecision(2) << getPrice() << endl;

      
      cout << "Keywords: ";
      for (int i = 0; i < getKeywords().size(); i++){
        if (i == getKeywords().size() - 1){
          cout << getKeywords()[i];
        }
        else {
          cout << getKeywords()[i] << ", ";
        }
      } 
      cout << endl;

      cout << "Blurb: " << getBlurb() << endl;
    }