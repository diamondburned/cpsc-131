///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives

/////////////////////// END-TO-DO (1) ////////////////////////////



// Return a reference to the one and only instance of the database
BookDatabase & BookDatabase::instance()
{
  std::string filename;

  // Look for a prioritized list of database files in the current working directory to use
  // Don't forget to #include <filesystem> to get visibility to the exists() function
  if     ( filename = "Open Library Database-Full.dat"  ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Large.dat" ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Medium.dat";   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Open Library Database-Small.dat" ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else if( filename = "Sample_Book_Database.dat"        ;   std::filesystem::exists( filename ) ) /* intentionally empty*/ ;
  else     filename.clear();

  static BookDatabase theInstance( filename );
  return theInstance;
}




// Construction
BookDatabase::BookDatabase( const std::string & filename )
{
  std::ifstream fin( filename, std::ios::binary );

  // The file contains Books separated by whitespace.  A Book has 4 pieces of data delimited with a comma.  (This exactly matches
  // the previous assignment as to how Books are read)
  //
  //       Field            Type            Notes
  //  1.   Book's ISBN      String          Unique identifier (primary key), always enclosed in double quotes
  //  2.   Book's Title     String          May contain spaces, always enclosed in double quotes
  //  3.   Book's Author    String          May contain spaces, always enclosed in double quotes
  //  4.   Book's Price     Floating Point  In dollars
  //
  //  Example:
  //    "0001062417",  "Early aircraft",                 "Maurice F. Allward", 65.65
  //    "0000255406",  "Shadow maker \"1st edition)\"",  "Rosemary Sullivan",   8.08
  //    "0000385264",  "Der Karawanenkardinal",          "Heinz Gstrein",      35.18
  //
  //  Note: double quotes within the string are escaped with the backslash character
  //

  ///////////////////////// TO-DO (2) //////////////////////////////
    /// Hint:  Use your Book's extraction operator to read Books, don't reinvent that here.
    ///        Read books until end of file pushing each book into the data store as they're read.

  /////////////////////// END-TO-DO (2) ////////////////////////////

  // Note:  The file is intentionally not explicitly closed.  The file is closed when fin goes out of scope - for whatever
  //        reason.  More precisely, the object named "fin" is destroyed when it goes out of scope and the file is closed in the
  //        destructor. See RAII
}









///////////////////////// TO-DO (3) //////////////////////////////
  /// Implement the rest of the interface, including functions find (recursively) and size
  ///
  /// See the SinglyLinkedList's extended interface in our Sequence Container Implementation Examples (SinglyLinkedList.hpp) for a
  /// recursive find function example. Instead of starting at the head of the list, you want to start at the beginning of your data
  /// store.
  ///
  /// Programming note:  An O(n) operation, like searching an unsorted vector, would not generally be implemented recursively.  The
  ///                    depth of recursion may be greater than the program's function call stack size.  But for this programming
  ///                    exercise, getting familiar with recursion is a goal.

/////////////////////// END-TO-DO (3) ////////////////////////////
