# Shared-Pointer
This demonstrates how to implement shared pointer in standard template library of c++, which is one of the smart pointer introduced into c++ since c++11. 

A shared pointer is an object wrapping two pointers as its private attribute, an stored pointer and an own pointer respectively. In this project, a shard pointer shares a resource and a control block. The stored pointer points the resource and the own pointer points the control block. 

# Data type to which the pointer points 
Since this class is implemented as using template, a programmer can use this class with any data types as long as they are copyable and assignable. Variadic template, introduced in C++11, also enable the object to be constructed with multiple arguments. 


# Point to array
It is possible to construct an object pointing to an array of some types. In this case, a programmer must pass an intger for its constructor as a size of the array. One cannot pass any other arguments during the construction. Hence, the type used for an array must be default constructable. 
