# Some Interesting Stuff Here...

https://github.com/eliben/code-for-blog/blob/master/2014/variadic-tuple.cpp

**UNFINISHED**
```C++
#include <iostream>

//Elemental type: fire
class Fire
{
    public:
    void operator()()
    {
        std::cout << "Calling fire\n";
    }
};


//Elemental type: ice
class Ice
{
    public:
    void operator()(int i)
    {
        std::cout << "Calling ice\n";
    }
};


//Derived class that can take any amount of base classes of any type...
template <typename... Bases>
class Staff: public Bases...
{
    using Bases::operator()...;

};

int main()
{
    //Declare a staff of type 'Fire' and 'Ice'
    Staff<Fire, Ice> wizard_staff;

    //Call a derived spell
    wizard_staff();    //arbitrary int to differentiate 'Ice::spell()' and 'Fire::spell()'

    return 0;
}
```
