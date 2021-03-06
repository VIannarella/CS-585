// dynamic_array.h
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "../memory/counting_allocator.h"
#include <stdexcept>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class DynamicArray
{
  private:
    T* d_pointer;
      // Pointer to allocated memory
    sgdm::IAllocator<T>* d_allocator;
      // Pointer to allocator
    int d_length;
      // Holds the current length of the array
    int d_capacity;
      // Holds the current array capacity

  public:
    // FREE OPERATORS
    T& operator[]( int index );
      // Assign the [] operator for DynamicArray objects.
      // Undefined behavior if index is out of bounds.
    const T operator[]( int index ) const;
      // Assign the [] operator for DynamicArray objects
      // Undefined behavior if index is out of bounds
    DynamicArray<T>& operator= ( const DynamicArray<T>& other );
      // Override of the assignment operator

    // CONSTRUCTORS
    DynamicArray();
      // Default constructor
    DynamicArray( sgdm::IAllocator<T>* alloc );
      // Constructs using a pointer to an allocator for use with memory
      // with an initial allocation of 5 elements.
    DynamicArray( DynamicArray &other );
      // Copy constructor
    ~DynamicArray();
      // Destructor

    // ACCESSORS
    unsigned int const getLength() const;
      // Returns the number of elements contained
    unsigned int const getCapacity() const;
    T const at( unsigned int index ) const;
      // Retrieves an element at a given locations, throws if out of bounds

    // MUTATORS
    void reallocate();
      // Allocate more memory for the array.
      // Allocates 5 array elements at a time. 
      // The array is copied, deleted, reallocated,
      // then repopulated with the original data.
      // The temporary array is then deleted.
    void push( const T& element );
      // Add element to end of collection, grow
    void pushFront( T element );
      // Pushes to the front of the collection, grow, shift
    T pop();
      // Removes and retrieves the last element, shifts
    T popFront();
      // Removes and retrieves the first element, shifts
    T setAt( T setData, unsigned int index );
      // Sets an element, undefined behavior if out of bounds
    T removeAt( unsigned int index );
      // Removes an element, throws if invalid, shifts
    T insertAt( T element, unsigned int index );
      // Adds an element, grows, shifts
};

// FREE OPERATORS
template <class T>
inline
T& DynamicArray<T>::operator []( int index )
{
    return at( index );
}

template <class T>
inline
const T DynamicArray<T>::operator []( int index ) const
{
    return at( index );
}

template <class T>
inline
DynamicArray<T>& DynamicArray<T>::operator= ( const DynamicArray<T>& other )
{

    if( this != &other )
    {
        this->d_allocator = other.d_allocator;
        this->d_length = other.d_length;
        this->d_capacity = other.d_capacity;
        this->d_pointer = this->d_allocator->get( d_capacity );

        for( int i = 0; i < d_length; i ++ )
        {
            this->d_pointer[ i ] = other.d_pointer[ i ];
        }
    }

    return *this;


}

template <class T>
inline
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& dynArray )
{
    return stream << " This is a DynamicArray of length "
                  << ( dynArray.getLength() ) << " and capacity "
                  << ( dynArray.getCapacity() );
}

// CONSTRUCTORS
template <class T>
inline
DynamicArray<T>::DynamicArray()
{
    d_allocator = new sgdm::CountingAllocator<T>();
    d_pointer = d_allocator->get( 5 );
    d_capacity = 5;
    d_length = 0;
}

template <class T>
inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
    d_allocator = alloc;
    d_pointer = d_allocator->get( 5 );
    d_capacity = 5;
    d_length = 0;
}

template <class T>
inline
DynamicArray<T>::DynamicArray( DynamicArray &other )
{

    if( d_pointer != 0 )
    {
        d_allocator->release( d_pointer, d_capacity );
        d_pointer = 0;
    }

    d_pointer = d_allocator->get( other.getLength() );

    for( int i = 0; i < other.getLength(); i ++ )
    {
        push( other[ i ] );
    }

}

template <class T>
inline
DynamicArray<T>::~DynamicArray()
{
    d_length = 0;
    d_allocator->release( d_pointer, d_capacity );
    delete d_allocator;
    d_pointer = 0;
    d_allocator = 0;
}

// ACCESSORS
template <class T>
inline
unsigned int const DynamicArray<T>::getLength() const
{
    return d_length;
}

template <class T>
inline
unsigned int const DynamicArray<T>::getCapacity() const
{
    return d_capacity;
}

template <class T>
inline
T const DynamicArray<T>::at( unsigned int index ) const
{

    if( index > d_length+1 || index < 0 )
    {
        throw std::out_of_range( "index is out of bounds" );
    }

    return d_pointer[ index ];
}

// MUTATORS
template <class T>
inline
void DynamicArray<T>::reallocate()
{
    d_capacity += 5;
    T *tempPointer = d_allocator->get( d_capacity );

    for( int i = 0; i < d_length; i ++ )
    {
        tempPointer[ i ] = d_pointer[ i ];
    }

    d_allocator->release( d_pointer, d_capacity-5 );
    d_pointer = 0;
    d_pointer = d_allocator->get( d_capacity );

    for( int i = 0; i < d_length; i ++ )
    {
        d_pointer[ i ] = tempPointer[ i ];
    }

    d_allocator->release( tempPointer, d_capacity );
    tempPointer = 0;
}

template <class T>
inline
void DynamicArray<T>::push( const T& element )
{

    if( d_length == d_capacity )
    {
        reallocate();
    }

    d_pointer[ d_length ] = element;
    d_length ++;
}

template <class T>
inline
void DynamicArray<T>::pushFront( T element )
{

    if( d_length == d_capacity )
    {
        reallocate();
    }

    for( int i = d_length; i > 0; i-- )
    {
        d_pointer[ i ] = d_pointer[ i-1 ];
    }

    d_pointer[ 0 ] = element;
    d_length ++;
}

template <class T>
inline
T DynamicArray<T>::pop()
{
    T returnRemovedElement = d_pointer[ d_length-1 ];
    d_pointer[ d_length-1 ] = 0;
    d_length --;
    return returnRemovedElement;
}

template <class T>
inline
T DynamicArray<T>::popFront()
{
    T returnRemovedElement = d_pointer[ 0 ];

    for( int i = 0; i < ( d_length-1 ); i++ )
    {
        d_pointer[ i ] = d_pointer[ i + 1 ];
    }

    d_pointer[ d_length - 1] = 0;
    d_length --;
    return returnRemovedElement;
}

template <class T>
inline
T DynamicArray<T>::setAt( T setData, unsigned int index )
{
    d_pointer[ index ] = setData;
    return d_pointer[ index ];
}

template <class T>
inline
T DynamicArray<T>::removeAt( unsigned int index )
{

    if( index >= d_length || index < 0 )
    {
        throw std::out_of_range( "index is out of bounds" );
    }

    T returnRemovedElement = d_pointer[ index ];

    for( int i = index; i < ( d_length-1 ); i++ )
    {
        d_pointer[ i ] = d_pointer[ i + 1 ];
    }

    d_pointer[ d_length - 1] = 0;
    d_length --;
    return returnRemovedElement;
}

template <class T>
inline
T DynamicArray<T>::insertAt( T element, unsigned int index )
{

    if( index >= d_capacity || index < 0 )
    {
        throw std::out_of_range( "index is out of bounds" );
    }

    if( d_length == d_capacity )
    {
        reallocate();
    }

    for( int i = d_length; i > index; i-- )
    {
        d_pointer[ i ] = d_pointer[ i-1 ];
    }

    d_pointer[ index ] = element;
    d_length ++;
    return d_pointer[ index ];
}

}  // End sgdc namespace

}  // End StevensDev namespace

#endif // DYNAMICARRAY_H
