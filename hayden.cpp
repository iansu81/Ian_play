#include <iostream>
using namespace std;
/*
Aㆍctro
Bㆍctro
Cㆍctro
Cㆍdtro
B-dtro
A·dtro
/*
A·ctro
Bㆍctro
Cㆍctro
Cㆍdtro
Bㆍdtro
*/
#include <iostream>

using namespace std;

class A {
public:
    A() { 
        cout << "A ctor\n"; 
    }
    ~A() { 
        cout << "A dtor\n"; 
    }
};

class B : public A {
public:
    B() { 
        cout << "B ctor\n"; 
    }
    virtual ~B() { 
        cout << "B dtor\n"; 
    }
};

class C : public B {
public:
    C() { 
        cout << "C ctor\n"; 
    }
    ~C() { 
        cout << "C dtor\n"; 
    }
};

int main() {
    C c;  // Stack allocation of C object
    B *b = new C;  // Pointer to base class B pointing to derived class C object
    delete b;  // Correctly calls destructors due to virtual destructors
    return 0;
}
