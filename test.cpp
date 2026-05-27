#include <iostream>


class Complex{
    public:
    Complex(float input1, float input2): a(input1), b(input2){}
    Complex operator+(Complex& other){
        this->a += other.a;
        this->b += other.b;
        return *this;

    }
    void print() {
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
    }


    private:
        float a;
        float b;    
};


int main(){
    Complex test1(5, 3);
    Complex test2(1,1);
    // test1.a = 5;
    // test1.b = 3;

    // test2.a = 1;
    // test2.b = 1;
    
    test1 = test1 + test2;
    test1.print();
    // st;d::cout << test1.a << std::endl;
    // std::cout << test1.b << std::endl

    return 0;

}

