// default_allocator.h
#ifndef DEFAULTALLOCATOR_H
#define DEFAULTALLOCATOR_H

#include "iallocator.h"
#include <iostream>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class DefaultAllocator : public IAllocator<T>
{
  public:
    // FREE OPERATORS
    DefaultAllocator<T>& operator= ( const DefaultAllocator<T>& other );
      // Override of the assignment operator

    // CONSTRUCTORS
    DefaultAllocator();
      // Default constructor.
    DefaultAllocator( const DefaultAllocator& other );
      // Copy constructor
    virtual ~DefaultAllocator();
      // Default virtual initialization of destructor

    // MUTATORS
    T* get( int count);
      // Implements parent virtual function get( int count )
    void release( T* myAlloc, int count );
      // Implements parent virtual function release( T* myAlloc, int count )
};

// FREE OPERATORS
template <class T>
inline
DefaultAllocator<T>& DefaultAllocator<T>::operator= ( const DefaultAllocator<T>& other )
{
    return *this;
}

template<class T>
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator<T>& allocator )
{
    return stream << "This is an object of type DefaultAllocator ";
}

// CONSTRUCTORS
template <class T>
inline
DefaultAllocator<T>::DefaultAllocator()
{
}

template <class T>
inline
DefaultAllocator<T>::DefaultAllocator( const DefaultAllocator& other )
{
}

template <class T>
inline
DefaultAllocator<T>::~DefaultAllocator()
{
}

// MUTATORS
template <class T>
inline
T* DefaultAllocator<T>::get( int count )
{
    return new T[ count ];
}

template <class T>
inline
void DefaultAllocator<T>::release( T* myAlloc, int count )
{
    delete myAlloc;
}

} // End sgdm namespace

} // End StevensDev namespace

#endif // DEFAULTALLOCATOR_H
