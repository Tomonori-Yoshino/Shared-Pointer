# Shared-Pointer
This demonstrates how to implement shared pointer in standard template library of c++, which is one of the smart pointer introduced into c++ since c++11. 

A shared pointer is an object wrapping two pointers as its private attribute, an stored pointer and an own pointer respectively. In this project, a shard pointer shares a resource and a control block. The stored pointer points the resource and the own pointer points the control block. 
