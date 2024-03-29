#pragma once

///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives

#include <vector>
#include "Book.hpp"

/////////////////////// END-TO-DO (1) ////////////////////////////


// Singleton Design Pattern
class BookDatabase
{
  public:
    // Get a reference to the one and only instance of the database
    static BookDatabase & instance();

    // Locate and return a reference to a particular record
    Book * find( const std::string & isbn );                                    // Returns a pointer to the item in the database if
                                                                                // found, nullptr otherwise
    // Queries
    std::size_t size() const;                                                   // Returns the number of items in the database

  private:
    BookDatabase            ( const std::string & filename );

    BookDatabase            ( const BookDatabase & ) = delete;                  // intentionally prohibit making copies
    BookDatabase & operator=( const BookDatabase & ) = delete;                  // intentionally prohibit copy assignments

    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Private implementation details
      /// Add any necessary private helper functions, member attributes, etc.

    Book* find_rec(const std::string& isbn, auto iter);
    std::vector<Book> books = {};

    /////////////////////// END-TO-DO (2) ////////////////////////////
};
