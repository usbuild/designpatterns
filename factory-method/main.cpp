#include <iostream>
using namespace std;
class Bread 
{
public :
    virtual void color() = 0;
};
class WhiteBread : public Bread 
{
public:
    void color()
    {
        cout << "this bread is white!" << endl;
    }
};
class BlackBread : public Bread 
{
    void color()
    {
        cout << "this bread is black!" << endl;
    }
};
class BreadFactory 
{
public:
    virtual Bread* createBread() = 0;
    virtual void wrapBread(Bread* bread) 
    {
        cout << "I'm wrapping the bread; ";
        bread->color();
    }
    virtual void go()
    {
        this->wrapBread(this->createBread());
    }
};
class WhiteBreadFactory : public BreadFactory
{
public:
    Bread* createBread() 
    {
        return new WhiteBread;
    }
};
class BlackBreadFactory : public BreadFactory 
{
public:
    Bread* createBread()
    {
        return new BlackBread;
    }
};
template<typename T>
class NewBreadFactory : public BreadFactory
{
public:
    T* createBread()
    {
        return new T;
    }
};
int main(int argc, const char *argv[])
{
    //BreadFactory* factory = new WhiteBreadFactory();
    BreadFactory* factory = new NewBreadFactory<WhiteBread>();
    factory->go();
    return 0;
}
