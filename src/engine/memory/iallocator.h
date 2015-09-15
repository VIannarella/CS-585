// iallocator.h
#ifndef IALLOCATOR_H
#define IALLOCATOR_H

namespace StevensDev
{

namespace sgdm
{

template <class T>
class IAllocator
{
  public:
    // CONSTRUCTOR
    IAllocator();

    // DESTRUCTOR
    virtual ~IAllocator()
      // Default virtual destructor
    {
    }

    // MUTATORS
    virtual T* get( int count ) = 0;
      // Virtual function for memory allocation
    virtual void release( T* myAlloc, int count ) = 0;
      // Virtual function for memory release
};

template <class T>
inline
IAllocator<T>::IAllocator()
{
}

} // End sgdm namespace

} // End StevensDev namespace
#endif // IALLOCATOR_H
