#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class A {
    public:
        virtual void foo(){
            cout << "A is called" << endl;
        }
};

class B : public A {
    public:
        void foo() {
            cout << "B is called" << endl;
        }
};

class C : public B {
    public:
        void foo() {
            cout << "C is called" << endl;
        }
};

int main() {

    vector<unique_ptr<int>> record;
    record.reserve(10);

    A* a = new A();
    B* b = new B();
    B* c = new C();
    A* d = new C();

    a->foo();
    b->foo();
    c->foo(); 
    d->foo();
    delete a;
    delete b;
    delete c;
    delete d;
}