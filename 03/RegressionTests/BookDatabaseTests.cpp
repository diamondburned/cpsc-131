#include <cmath>      // abs()
#include <cstdlib>    // exit()
#include <exception>
#include <filesystem> // exists()
#include <iomanip>    // setprecision()
#include <iostream>   // boolalpha(), showpoint(), fixed()
#include <sstream>
#include <string>     // to_string()

#include "CheckResults.hpp"
#include "BookDatabase.hpp"





namespace  // anonymous
{
  class BookDatabaseRegressionTest
  {
    public:
      BookDatabaseRegressionTest();

    private:
      void tests();

      Regression::CheckResults affirm;
  } run_bookDatabase_tests;




  void BookDatabaseRegressionTest::tests()
  {
    BookDatabase & db           = BookDatabase::instance();
    std::size_t    expectedSize = 0;
    if     ( std::filesystem::exists( "Open Library Database-Full.dat"   ) ) expectedSize = 10'837'828;
    else if( std::filesystem::exists( "Open Library Database-Large.dat"  ) ) expectedSize = 104'003;
    else if( std::filesystem::exists( "Open Library Database-Medium.dat" ) ) expectedSize = 10'003;
    else if( std::filesystem::exists( "Open Library Database-Small.dat"  ) ) expectedSize = 203;
    else if( std::filesystem::exists( "Sample_Book_Database.dat"         ) ) expectedSize = 211;

    affirm.is_equal( "Database construction - Expected size", expectedSize, db.size() );

    if( auto p = db.find( "0001034359" ); p == nullptr )
    {
      affirm.is_not_equal( "Database query - existing book should have been found, but it wasn't", nullptr, p );
    }
    else
    {
      Book control( "Tales of Hans Christian Andersen ; \n                     read by Michael Redgrave. (1st edition)",
                    "Hans Christian Andersen",
                    "0001034359",
                    99.92 );

      affirm.is_equal( "Database query - existing book located", control, *p );

      // Modify the contents and verify the DB sees those changes
      p->title( "Modified Title" );
      auto q = db.find( p->isbn() );

      affirm.is_equal( "Database query - returned pointer to book in database", *p, *q );

      // Now, put it back how you found it
      *p = control;
    }

    {
      auto book = db.find( "--------------" );
      affirm.is_equal( "Database query - non-existing book found when it shouldn't have been", nullptr, book );
    }
  }

 

  BookDatabaseRegressionTest::BookDatabaseRegressionTest()
  {
    std::clog << std::boolalpha << std::showpoint << std::fixed << std::setprecision( 2 );


    try
    {
      std::clog << "\nBook Database Regression Test:\n";
      tests();

      std::clog << affirm << '\n';
    }
    catch( const std::exception & ex )
    {
      std::clog << "FAILURE:  Regression test for \"class Book\" failed with an unhandled exception. \n\n\n"
                << ex.what() << std::endl;
    }
  }
} // namespace
