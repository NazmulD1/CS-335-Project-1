#include "MoveAll.hpp"
#include "Book.hpp"
using namespace std;

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this
// function. Use iterators whenever appropriate. Hint: you need a const iterator
// for a const vector, but this will be automatically handled using "auto".

void moveAll(const std::string keyword, std::vector<Book> &source,
             std::vector<Book> &dest) {
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved = 0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // Iterates through the elements of the source vector
  for (auto it = source.begin(); it != source.end();) {

    // Initializes a boolean variable found to false
    bool found = 0;

    // Gets a reference to the Book object that the iterator it is pointing to
    const auto &book = *it;

    // Iterates through each keyword of the current Book object's keywords
    for (const auto &bookKeyword : book.getKeywords()) {

      // Checks if the current keyword matches the specified keyword
      if (bookKeyword == keyword) {
        found = 1;
        break;
      }
    }

    // If a match is found, moves the book to the dest vector, removes it from
    // source, and increments books_moved by 1
    if (found == 1) {
      dest.push_back(move(*it));
      it = source.erase(it);
      books_moved++;
    }
    // If no match is found, moves the iterator to the following element in the
    // source vector
    else {
      it++;
    }
  }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds."
            << std::endl;
}
