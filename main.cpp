#include <memory>
#include <iostream>


class A
{
public:
    ~A()
    {
        std::cout << "A" << std::endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        std::cout << "B" << std::endl;
    }
};

int main()
{
    std::shared_ptr<A> lol(new B());
    lol.reset(new A());
    return 0;
}