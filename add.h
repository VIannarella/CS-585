// add.h
#ifndef ADD_H
#define ADD_H

namespace StevensDev
{

class Add
{
  public:
    // CONSTRUCTOR
    Add();
      // Default constructor.

    // MUTATOR
    int addElements( int, int);
      // Adds two ints.
};

// CONSTRUCTOR
inline
Add::Add()
{
}

// MUTATOR
inline
int Add::addElements( int x, int y )
{
    return x + y;
}

} // End StevensDev namespace

#endif // ADD_H
