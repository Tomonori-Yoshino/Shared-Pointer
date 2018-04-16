#ifndef SharedPtr_h
#define SharedPtr_h

#include <iostream>
using std::cout;
using std::cin;
using std::endl;



template <typename ValueType>
class SharedPtr {
public:
    //constructors
    template <typename... Args>
    SharedPtr( const Args&... args ) : _ptr{ new ValueType{args...} }, count{ new int{1} } {}
    SharedPtr( const SharedPtr& rhs ){ *this = rhs; };  //copy constructor

    //destructor
    ~SharedPtr();

    //member method
    int        get_count()   const { return *count; }
    ValueType* ptr()         const { return _ptr; }  //for debugging

    //overloaded operator
    ValueType&       operator* ()  const  { return *_ptr; }
    ValueType*       operator-> () const  { return _ptr; }
    const SharedPtr& operator= ( const SharedPtr& rhs );


private:
    //attributes
    ValueType* _ptr   = nullptr;  //stored pointer
    int*        count = nullptr;  //owned pointer
};



/**
 * Destructs the object of SharedPtr.
 */
template <typename ValueType>
SharedPtr<ValueType>::~SharedPtr(){
    --*count;  //decrement the count
    if ( *count == 0 ){
        //deallocate the memory...
        delete _ptr;
        delete count;
    }
}


/**
 * Overloaded assignment operator.
 *
 * @param[out]   rhs        an object of SharedPtr to be assigned
 *
 * @return  an object of SharedPtr on right hand side
 */
template <typename ValueType>
const SharedPtr<ValueType>& SharedPtr<ValueType>::operator= ( const SharedPtr& rhs ){
    //check if the both objects are different and if the left object is
    //not pointing null.
    if ( _ptr != rhs._ptr){
        if ( _ptr ){
            --*count;  //decrement the count
            if ( *count == 0 ){  //if the object is the last one...
                delete _ptr;
                delete count;
            }
        }
        _ptr = rhs._ptr;
        count = rhs.count;
        ++*count;
    }
    //otherwise do nothing...
    return rhs;
}




template <typename ValueType>
class SharedPtr<ValueType[]> {
public:
    //constructors
    SharedPtr( int size ) : _ptr{new ValueType[size]}, count{new int{1}} {}
    SharedPtr( const SharedPtr& rhs ) { *this = rhs; }

    //destructor
    ~SharedPtr();


    //member methods
    int        get_count()   const { return *count; }
    ValueType& operator* ()  const { return *_ptr; }
    ValueType& operator[](int i) const { return _ptr[i]; };
    const SharedPtr& operator= ( const SharedPtr& rhs );


private:
    ValueType* _ptr   = nullptr;
    int*        count = nullptr;
};



/**
 * Destructs the object of SharedPtr with array type.
 */
template <typename ValueType>
SharedPtr<ValueType[]>::~SharedPtr(){
    --*count;
    if ( *count == 0 ){
        delete [] _ptr;
        delete count;
    }
}



/**
 * Overloaded assignment operator.
 *
 * @param[out]   rhs        an object of SharedPtr to be assigned
 *
 * @return  an object of SharedPtr on right hand side
 */
template <typename ValueType>
const SharedPtr<ValueType[]>& SharedPtr<ValueType[]>::operator= ( const SharedPtr& rhs ){
    if ( _ptr != rhs._ptr ){
        if ( _ptr ){
            --*count;
            if ( *count == 0 ){
                delete [] _ptr;
                delete count;
            }
        }
        _ptr = rhs._ptr;
        count = rhs.count;
        ++*count;
    }
    return rhs;
}





#endif
