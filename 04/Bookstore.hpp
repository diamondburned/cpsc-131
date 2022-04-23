#pragma once

#include <map>
#include <set>
#include <string>

#include "Book.hpp"



class Bookstore
{
  public:
    // Type Definition Aliases
    //    |Alias Name |            | Key              |  | Value                 |
    //    +-----------+            +------------------+  +-----------------------+
    using BooksSold     = std::set<std::string /*ISBN*/  /* N/A */                >;  // A collection of unique ISBNs representing books that have been sold

    using Inventory_DB  = std::map<std::string /*ISBN*/, unsigned int /*quantity*/>;  // A collection of quantities indexed by ISBN:                 Maintains of the quantity of books in stock identified by ISBN
    using ShoppingCart  = std::map<std::string /*ISBN*/, Book                     >;  // A collection of books indexed by ISBN:                      An individual shopping cart filled with books
    using ShoppingCarts = std::map<std::string /*name*/, ShoppingCart             >;  // A collection of shopping carts indexed by customer's name:  A collection of shoppers, identified by name, each pushing a shopping
                                                                                      //                                                             cart.  Notice that this structure is a tree, and each element in the
                                                                                      //                                                             tree is also a tree. That is, this is a tree of trees.

    // Constructors, assignments, destructor
    Bookstore( const std::string & persistentInventoryDB = "BookstoreInventory.dat" );

    // Returns a reference to the store's one and only inventory database
    Inventory_DB & getInventory();


    // Each customer, in turn, places the books in their shopping cart on the checkout counter where they are scanned, paid for, and
    // issued a receipt. Returns a collection of unique ISBNs for books that have been sold
    BooksSold ringUpAllCustomers( const ShoppingCarts & shoppingCarts );


    // Re-orders books sold that have fallen below the re-order threshold, then clears the reorder list
    void reorderItems( BooksSold & todaysSales );


    // Initializes a bunch of customers pushing shopping carts filled with books
    ShoppingCarts  makeShoppingCarts();


  private:
    // Instance attributes
    Inventory_DB _inventoryDB;                                                        // This store's inventory of books indexed by ISBN.


    // Class attributes
    inline static constexpr unsigned int REORDER_THRESHOLD = 15;                      // When the quantity on hand dips below this threshold, it's time to order more inventory
    inline static constexpr unsigned int LOT_COUNT         = 20;                      // Number of items that can be ordered at one time


    // Helper functions
    BooksSold ringUpCustomer( const ShoppingCart & shoppingCart );
};
