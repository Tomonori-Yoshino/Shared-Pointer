#include "SharedPtr.h"



int main() {


    SharedPtr<std::string> p1{"Hello"};
    SharedPtr<std::string> p2{p1};
    SharedPtr<std::string> p3 = p2;

    SharedPtr<std::string> p4{"HI"};
    p4 = p3;
    p4 = p1;

    p3 = p2;
    p2 = p3;


    cout << "P1Value: " << *p1 << endl;
    cout << "P1Count: " << p1.get_count() << endl;
    cout << "P2Value: " << *p2 << endl;
    cout << "P2Count: " << p2.get_count() << endl;
    cout << "P3Value: " << *p3 << endl;
    cout << "P3Count: " << p3.get_count() << endl;
    cout << "P4Value: " << *p4 << endl;
    cout << "P4Count: " << p4.get_count() << endl;
     

    /*

    SharedPtr<double[]> p{5};
    for (int i = 0; i < 5; i++){
        p[i] = i+1;
    }

    for (int i = 0; i < 5; i++){
        cout << p[i];
    }
    cout << endl;

    SharedPtr<double[]> pd = p;
*/
    

    return 0;
}
