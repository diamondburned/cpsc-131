#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>

#include "Book.hpp"

int main()
{
  std::cout << "Welcome to Forgotten Books, a bookstore filled with books from all nations.  Place books into your shopping cart by entering each book's information."
               "   enclose string entries in quotes, separate fields with comas"
               "   Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";

  // Initialize cout to pretty-print numbers.
  std::cout << std::showpoint << std::fixed << std::setprecision( 2 );

  std::vector<Book> cart;

  // Temporary variable only for reading.
  Book tmpBook;

  while( std::cout << "Enter ISBN, Title, Author, and Price" << std::endl, std::cin >> tmpBook )
  {
    cart.push_back( tmpBook );
    std::cout << "Item added to shopping cart: " << tmpBook << "\n"
              << std::endl;
  }

  std::cout << "Here is an itemized list of the items in your shopping cart:\n\n";

  std::reverse( cart.begin(), cart.end() );
  for( auto & book : cart )
  {
    std::cout << book << "\n";
  }

  return 0;
}
