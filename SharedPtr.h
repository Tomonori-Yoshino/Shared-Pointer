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
    SharedPtr() = default;
    SharedPtr( const ValueType& v ){
        _ptr = new ValueType{v};
        count = new int{1};
        cout << "DBUG: SharedPtr is constructed. \n";
        cout << "Value: " << *_ptr << endl;
        cout << "Count: " << *count << endl;
    };
    SharedPtr( const SharedPtr& rhs ){
        cout << "DBUG: SharedPtr is constructed by a copy constructor. \n";
        *this = rhs;
        cout << "Value: " << *_ptr << endl;
        cout << "Count: " << *count << endl;
    };
    template <typename... Args>
    SharedPtr( const Args&... args ) : SharedPtr{ ValueType{args...} } {}

    //destructor
    ~SharedPtr(){
        cout << "DBUG: SharedPtr is destructed. \n";
        --*count;
        cout << "Count: " << *count << endl;
        if ( *count == 0 ){
            delete _ptr;
            delete count;
            cout << "The memory was freed.\n";
        }
    };

    //member method
    int        get_count()   const { return *count; }

    //overloaded operator
    ValueType& operator* ()  const  { return *_ptr; }
    ValueType* operator-> () const  { return _ptr; }
    const      SharedPtr& operator= ( const SharedPtr& rhs ){
        if ( _ptr != rhs._ptr ){
            if ( _ptr ){
                --*count;
                cout << "Old count: " << *count << endl;
                if ( *count == 0 ){
                    delete _ptr;
                    delete count;
                    cout << "The old memory was freed.\n";
                }
            }
            _ptr = rhs._ptr;
            count = rhs.count;
            ++*count;
        }
        return rhs;
    };
private:
    //attributes
    ValueType* _ptr   = nullptr;
    int*        count = nullptr;
};





template <typename ValueType>
class SharedPtr<ValueType[]> {
public:
    SharedPtr() = default;
    SharedPtr( int size ){
        _ptr = new ValueType[size];
        count = new int{1};
        cout << "DBUG: SharedPtr is constructed. \n";
        cout << "Count: " << *count << endl;
    }
    SharedPtr( const SharedPtr& rhs ) { *this = rhs; }
    ~SharedPtr(){
        cout << "DBUG: SharedPtr is destructed. \n";
        --*count;
        cout << "Count: " << *count << endl;
        if ( *count == 0 ){
            delete [] _ptr;
            delete count;
            cout << "The memory was freed.\n";
        }
    }


    int        get_count()   const { return *count; }
    ValueType& operator* ()  const { return *_ptr; }
    ValueType& operator[](int i) const { return _ptr[i]; };
    const SharedPtr& operator= ( const SharedPtr& rhs ){
        if ( _ptr != rhs._ptr ){
            if ( _ptr ){
                --*count;
                cout << "Old count: " << *count << endl;
                if ( *count == 0 ){
                    delete [] _ptr;
                    delete count;
                    cout << "The old memory was freed.\n";
                }
            }
            _ptr = rhs._ptr;
            count = rhs.count;
            ++*count;
        }
        return rhs;
    };
private:
    ValueType* _ptr   = nullptr;
    int*        count = nullptr;
};

#endif
