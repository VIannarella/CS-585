// counting_allocator.h
#ifndef COUNTINGALLOCATOR_H
#define COUNTINGALLOCATOR_H

#include <assert.h>
#include "default_allocator.h"

namespace StevensDev
{

namespace sgdm
{

template <class T>
class CountingAllocator: public DefaultAllocator<T>
{
  private:
    int d_allocationCount;
      // Current number of allocations
    int d_releaseCount;
      // Current number of releases
    static int d_totalAllocationCount;
      // Current number of allocations across instances
    static int d_totalReleaseCount;
      // Current number of releases across instances

  public:
    // FREE OPERATORS
    CountingAllocator<T>& operator= ( const CountingAllocator<T>& other );
      // Override of the assignment operator

    // CONSTRUCTORS
    CountingAllocator();
      // Default constructor
    CountingAllocator( const CountingAllocator& other );
      // Copy constructor

    // DESTRUCTOR
    ~CountingAllocator();
      // Default destructor

    // ACCESSORS
    const int getAllocationCount() const;
      // Returns the number of allocations that occurred.
    const int getReleaseCount() const;
      // Returns the number of releases that occurred.
    const int getOutstandingCount() const;
      // Returns the number of allocations minus
      // the number of releases that occurred.
    static const int getTotalAllocationCount();
      // Returns the number of allocations that occurred across instances.
    static const int getTotalReleaseCount();
      // Returns the number of releases that occurred across instances.
    static const int getTotalOutstandingCount();
      // Returns the number of allocations minus
      // the number of releases across instances.

    // MUTATORS
    T* get( int count );
      // Override of parent function get( int count )
    void release( T* myAlloc, int count );
      // Override of parent function release( T* myAlloc, int count )
};

// STATIC VARIABLE INITIALIZATION
template <class T>
int CountingAllocator<T>::d_totalAllocationCount = 0;
template <class T>
int CountingAllocator<T>::d_totalReleaseCount = 0;

// FREE OPERATORS
template <class T>
inline
CountingAllocator<T>& CountingAllocator<T>::operator= ( const CountingAllocator<T>& other )
{

    if( this != &other )
    {
        d_allocationCount = other.getAllocationCount();
        d_releaseCount = other.getReleaseCount();
    }

    return *this;
}

template<class T>
inline
std::ostream& operator<<( std::ostream& stream, const CountingAllocator<T>& allocator )
{
    return stream << "{ allocation count: " << allocator.getAllocationCount()
                  << "\n release count: " << allocator.getReleaseCount()
                  << "\n outstanding count: " << allocator.getOutstandingCount()
                  << "\n total allocation count: "
                  << allocator.getTotalAllocationCount()
                  << "\n total release count: "
                  << allocator.getTotalReleaseCount()
                  << "\n total outstanding count: "
                  << allocator.getTotalOutstandingCount();
}

// CONSTRUCTORS
template <class T>
inline
CountingAllocator<T>::CountingAllocator()
{
    d_allocationCount = 0;
    d_releaseCount = 0;
}

template <class T>
inline
CountingAllocator<T>::CountingAllocator( const CountingAllocator &other )
{
    d_allocationCount = other.getAllocationCount();
    d_releaseCount = other.getReleaseCount();
}

// DESTRUCTORS
template <class T>
inline
CountingAllocator<T>::~CountingAllocator()
{
}

// ACCESSORS
template <class T>
inline
const int CountingAllocator<T>::getAllocationCount() const
{
    return d_allocationCount;
}

template <class T>
inline
const int CountingAllocator<T>::getReleaseCount() const
{
    return d_releaseCount;
}

template <class T>
inline
const int CountingAllocator<T>::getOutstandingCount() const
{
    return ( d_allocationCount - d_releaseCount );
}

template <class T>
inline
const int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_totalAllocationCount;
}

template <class T>
inline
const int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_totalReleaseCount;
}

template <class T>
inline
const int CountingAllocator<T>::getTotalOutstandingCount()
{
    return ( d_totalAllocationCount - d_totalReleaseCount );
}

// MUTATORS
template <class T>
inline
T* CountingAllocator<T>::get( int count )
  // Override of parent function DefaultAllocator::get( int count)
{
    d_allocationCount += count;
    d_totalAllocationCount += count;
    return new T[ count ];
}

template <class T>
inline
void CountingAllocator<T>::release( T* myAlloc, int count )
  // Override of parent function DefaultAllocator::release( T*, int count )
{
    assert( myAlloc != 0 );
    d_releaseCount += count;
    d_totalReleaseCount += count;
    delete myAlloc;
}

} // End namespace sgdm

} // End namespace StevensDev
#endif // COUNTINGALLOCATOR_H
