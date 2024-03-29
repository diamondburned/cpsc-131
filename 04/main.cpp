#include <exception>
#include <iomanip>      // setprecision()
#include <iostream>     // cout, fixed(), showpoint()

#include "Bookstore.hpp"







int main()
{
  try
  {
    std::cout << std::fixed << std::setprecision( 2 ) << std::showpoint;


    ///////////////////////// TO-DO (1) //////////////////////////////
      /// Create your bookstore
      ///
    auto bookstore = Bookstore();

    /////////////////////// END-TO-DO (1) ////////////////////////////


    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Now, let's pretend your bookstore is busy with several shoppers, each pushing a shopping cart filled with a bunch of books
      /// by using your store's makeShoppingCarts function to create a collection of shopping carts.
      ///
    auto shoppingCarts = bookstore.makeShoppingCarts();

    /////////////////////// END-TO-DO (2) ////////////////////////////


    ///////////////////////// TO-DO (3) //////////////////////////////
      /// There are several shoppers standing in line waiting to purchase the books in their shopping cart.  Process them all by
      /// passing the collection of shopping carts to your store's ringUpAllCustomers function.  This function will, for
      /// each shopper, scan all the books in their shopping cart, print a receipt with an amount due, deduct the items bought from
      /// the store's inventory, and returns a collection of books sold.
      ///
    auto booksSold = bookstore.ringUpAllCustomers(shoppingCarts);

    /////////////////////// END-TO-DO (3) ////////////////////////////


    ///////////////////////// TO-DO (4) //////////////////////////////
      /// Get a reference to your store's inventory by using your store's inventory function.  The store doesn't carry everything,
      /// especially all at once.  The inventory tells you how many of each item are currently on hand (i.e., in stock).
      ///
      /// The store's managers have decided to stop selling Wild Mammals (ISBN: 9802161748), so remove this from the store's
      /// inventory.
      ///
    auto& inventory = bookstore.getInventory();
    inventory.erase("9802161748"); // Wild Mammals

    /////////////////////// END-TO-DO (4) ////////////////////////////


    ///////////////////////// TO-DO (5) //////////////////////////////
      /// All the shoppers have now checkout out and it's late in the day.  Close your store, take inventory, and if you sold enough
      /// books to fall below your re-order threshold, order more by using your store's reorderItems function passing the
      /// collection of books sold.
    std::cout << "\n\n\n\n\n";
    bookstore.reorderItems(booksSold);

    /////////////////////// END-TO-DO (5) ////////////////////////////
  }

  catch( const std::exception & ex )
  {
    std::cout << "FAILED - Unhandled exception:\n"  << ex.what() << '\n';
  }

  catch( ... )
  { std::cout << "FAILED - Unhandled exception:\n"; }

  return 0;
}
