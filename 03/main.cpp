#include <cmath>       // abs()
#include <cstddef>     // size_t
#include <iomanip>     // setprecision(), setw()
#include <iostream>    // cerr, ,clog, fixed(), showpoint(), left(), right()
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>   // invalid_argument, out_of_range
#include <string>      // stod()

#include "Book.hpp"
#include "BookDatabase.hpp"



namespace
{
  // Output some observed behavior.
  // Call this function from within the carefully_move_books functions, just before kicking off the recursion and then just after each move.

  // trace()
  void trace( std::stack<Book> const & sourceCart, std::stack<Book> const & destinationCart, std::stack<Book> const & spareCart, std::ostream & s = std::clog )
  {
    // Count and label the number of moves
    static std::size_t move_number = 0;

    // First time called will bind parameters to copies
    static std::map<std::stack<Book> const *, std::stack<Book>> bookCarts = { { &sourceCart, {}            }, { &destinationCart, {}             }, { &spareCart, {}           } };
    static std::map<std::stack<Book> const *, std::string>      colLabels = { { &sourceCart, "Broken Cart" }, { &destinationCart, "Working Cart" }, { &spareCart, "Spare Cart" } };

    // Interrogating the stacks is a destructive process, so local copies of the parameters are made to work with.  The
    // carefully_move_books algorithm will swap the order of the arguments passed to this functions, but they will always be the
    // same objects - just in different orders. When outputting the stack contents, keep the original order so we humans can trace
    // the movements easier.  A container (std::map) indexed by the object's identity (address) is created so the canonical order
    // remains the same from one invocation to the next.
    bookCarts[&sourceCart]      = sourceCart;
    bookCarts[&destinationCart] = destinationCart;
    bookCarts[&spareCart]       = spareCart;


    // Determine the height of the tallest stack
    std::size_t tallestStackSize = 0;
    for( auto & [index, cart] : bookCarts )   if( cart.size() > tallestStackSize )   tallestStackSize = cart.size();


    // Print the header
    s << "After " << std::setw( 3 ) << move_number++ << " moves:     " << std::left;      // print the move number
    for( auto & [index, label] : colLabels )    s << std::setw( 23 ) << label;            // print the column labels
    s << std::right << "\n                     " << std::string( 23*3, '-' ) << '\n';     // underline the labels


    // Print the stack's contents
    for( ; tallestStackSize > 0;  --tallestStackSize )                                    // for each book on a cart
    {
      s << std::string( 21, ' ' );

      for( auto & [key, cart] : bookCarts )                                               // for each book cart
      {
        if( cart.size() == tallestStackSize )
        {
          auto title = cart.top().title();
          if( title.size() > 20 ) title[17] = title[18] = title[19] = '.';                // replace last few characters of long titles with "..."
          s << std::left << std::setw( 23 ) << title.substr( 0, 20 ) << std::right;
          cart.pop();
        }
        else
        {
          s << std::string( 23, ' ' );
        }
      }
      s << '\n';
    }
    s << "                     " << std::string( 69, '=' ) << "\n\n\n\n";
  }



  // carefully_move_books() - recursive
  /*********************************************************************************************************************************
  ** A recursive algorithm to carefully move books from a broken cart to a working cart is given as follows:
  ** START
  ** Procedure carefully_move_books (number_of_books_to_be_moved, broken_cart, working_cart, spare_cart)
  **
  **    IF number_of_books_to_be_moved == 1, THEN
  **       move top book from broken_cart to working_cart
  **       trace the move
  **
  **    ELSE
  **       carefully_move_books (number_of_books_to_be_moved-1, broken_cart, spare_cart, working_cart)
  **       move top book from broken_cart to working_cart
  **       trace the move
  **       carefully_move_books (number_of_books_to_be_moved-1, spare_cart, working_cart, broken_cart)
  **
  **    END IF
  **
  ** END Procedure
  ** STOP
  **
  ** As a side note, the efficiency class of this algorithm is exponential.  That is, the Big-O is O(2^n).
  *********************************************************************************************************************************/
  void carefully_move_books( std::size_t quantity, std::stack<Book> & broken_cart, std::stack<Book> & working_cart, std::stack<Book> & spare_cart )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      /// Implement the algorithm above.

    auto move_top = [](std::stack<Book>& from, std::stack<Book>& to) {
      to.push(from.top());
      from.pop();
    };

    if (quantity == 1) {
      move_top(broken_cart, working_cart);
      trace(broken_cart, working_cart, spare_cart);
    } else {
      carefully_move_books(quantity-1, broken_cart, spare_cart, working_cart);
      move_top(broken_cart, working_cart);
      trace(broken_cart, working_cart, spare_cart);
      carefully_move_books(quantity-1, spare_cart, working_cart, broken_cart);
    }

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }



  // carefully_move_books() - starter
  void carefully_move_books( std::stack<Book> & from, std::stack<Book> & to )
  {
    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Implement the starter function for the above algorithm.  If the "from" cart contains books, move those books to the "to"
      /// cart while ensuring the breakable books are always on top of the nonbreakable books, just like they already are in the
      /// "from" cart.  That is, call the above carefully_move_books function to start moving books recursively.  Call the above
      /// trace function just before calling carefully_move_books to get a starting point reference in the movement report.

    std::stack<Book> spare;
    trace(from, to, spare);

    if (!from.empty()) carefully_move_books(from.size(), from, to, spare);

    /////////////////////// END-TO-DO (2) ////////////////////////////
  }
}    // namespace




// main()
int main( int argc, char * argv[] )
{
  // Snag an empty cart as I enter the grocery store
  ///////////////////////// TO-DO (3) //////////////////////////////
    /// Create an empty book cart as a stack of books and call it myCart.

  std::stack<Book> myCart;
  /////////////////////// END-TO-DO (3) ////////////////////////////




  // Shop for awhile placing books into my book cart
  ///////////////////////// TO-DO (4) //////////////////////////////
    /// Put the following books into your cart with the heaviest book on the bottom and the lightest book on the top
    /// according to the ordering given in the table below
    ///
    ///      ISBN             Title               Author
    ///      --------------   -------------       ---------------
    ///      9780895656926    Like the Animals    any                     <=== lightest book, put this on the top so heavy books wont break them
    ///      54782169785      131 Answer Key      any
    ///      0140444300       Les Mis             any
    ///      9780399576775    Eat pray love       Asher
    ///      9780545310581    Hunger Games        any                     <===  heaviest book, put this on the bottom

  myCart.push(Book("Hunger Games", "any", "9780545310581"));
  myCart.push(Book("Eat pray love", "Asher", "9780399576775"));
  myCart.push(Book("Les Mis", "any", "0140444300"));
  myCart.push(Book("131 Answer Key", "any", "54782169785"));
  myCart.push(Book("Like the Animals", "any", "9780895656926"));
  /////////////////////// END-TO-DO (4) ////////////////////////////




  // A wheel on my cart has just broken and I need to move books to a new cart that works
  ///////////////////////// TO-DO (5) //////////////////////////////
    /// Create an empty book cart as a stack of books and call it workingCart.  Then carefully move the books in your now broken
    /// cart to this working cart by calling the above carefully_move_books function with two arguments.

  std::stack<Book> workingCart;
  carefully_move_books(myCart, workingCart);
  /////////////////////// END-TO-DO (5) ////////////////////////////




  // Time to checkout and pay for all this stuff.  Find a checkout line and start placing books on the counter's conveyor belt
  ///////////////////////// TO-DO (6) //////////////////////////////
    /// Create an empty checkout counter as a queue of books and call it checkoutCounter.  Then remove the books
    /// from your working cart and place them on the checkout counter, i.e., put them in this checkoutCounter queue.

  std::queue<Book> checkoutCounter;
  while (!workingCart.empty()) {
    checkoutCounter.push(workingCart.top());
    workingCart.pop();
  }
  /////////////////////// END-TO-DO (6) ////////////////////////////




  // Now add it all up and print a receipt
  double amountDue = 0.0;
  BookDatabase & storeDataBase = BookDatabase::instance();                // Get a reference to the store's database of books. The database
                                                                          // contains the full description and price of the book.

  ///////////////////////// TO-DO (7) //////////////////////////////
    /// For each book in the checkout counter queue, find the book by ISBN in the store's database.  If the book on the counter is
    /// found in the database then accumulate the amount due and print the book's full description and price on the receipt (i.e.
    /// write the book's full description and price to standard output).  Otherwise, print a message on the receipt that a
    /// description and price for the book wasn't found and there will be no charge.

  while (!checkoutCounter.empty()) {
    auto book = checkoutCounter.front();
    checkoutCounter.pop();

    auto *bookEntry = storeDataBase.find(book.isbn());
    if (bookEntry != nullptr) {
      amountDue += bookEntry->price();
      std::cout << *bookEntry << "\n";
    } else {
      std::cout
        << '"' << book.isbn() << '"' << " "
        << "(" << book.title() << ") not found, book is free!\n";
    }
  }

  /////////////////////// END-TO-DO (7) ////////////////////////////



  // Now check the receipt - are you getting charged the correct amount?
  // You can either pass the expected total when you run the program by supplying a parameter, like this:
  //    program 35.89
  // or if no expected results is provided at the command line, then prompt for and obtain expected result from standard input
    double expectedAmmountDue = 0.0;
  if( argc >= 2 )
    try
    {
      expectedAmmountDue = std::stod( argv[1] );
    }
    catch( std::invalid_argument & ) {}  // ignore anticipated bad command line argument
    catch( std::range_error &      ) {}  // ignore anticipated bad command line argument
  else
  {
    std::cout << "What is your expected amount due?  ";
    std::cin  >> expectedAmmountDue;
  }


  std::cout << std::fixed << std::setprecision( 2 ) << std::showpoint
            << std::string( 25, '-' )  << '\n'
            << "Total  $" << amountDue << "\n\n\n";


  if( std::abs(amountDue - expectedAmmountDue) < 1E-4 ) std::clog << "PASS - Amount due matches expected\n";
  else                                                  std::clog << "FAIL - You're not paying the amount you should be paying\n";

  return 0;
}
