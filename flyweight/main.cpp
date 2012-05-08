#include <iostream>
#include <string>
#include <map>
using namespace std;
class Flyweight
{

public:
    virtual void set(string sth) = 0;
    virtual void operation() = 0;
};
class ConcreteFlyweight : public Flyweight
{
private:
    string something;
public:
    void set(string sth) 
    {
       something = sth;
    }
    void operation() 
    {
        cout << something << endl;
    }
};
class FlyweightFactory 
{
private:
   map<string, Flyweight*> list;
public:
    Flyweight* getFlyweight(string key)
    {
        map<string, Flyweight*>::iterator itr; 
        itr = list.find(key);
        if(itr != list.end())
        {
            return itr->second;
        }
        else 
        {
            Flyweight* fly = new ConcreteFlyweight;
            list.insert(pair<string, Flyweight*>(key, fly));
            return fly;
        }
    }
};
int main(int argc, const char *argv[])
{
    FlyweightFactory* factory = new FlyweightFactory;
    Flyweight* fly = factory->getFlyweight("123");
    fly->set("123");
    Flyweight* fly2 = factory->getFlyweight("123");
    fly2->operation();
    return 0;
}
