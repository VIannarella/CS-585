// subtract.h
#ifndef SUBTRACT_H
#define SUBTRACT_H

namespace StevensDev
{

class Subtract
{
  public:
    // CONSTRUCTOR
    Subtract();
      // Default constructor.

    // OPERATOR
    int subtractElements( int, int);
      //Subtracts one int from another.
};

// CONSTRUCTOR
inline
Subtract::Subtract()
{
}

// OPERATOR
inline
int Subtract::subtractElements( int x, int y )
{
    return x - y;
}

} // End StevensDev namespace

#endif // SUBTRACT_H
