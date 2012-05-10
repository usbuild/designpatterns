#include <iostream>
using namespace std;
class IObject 
{
public:
    virtual void operation() = 0;
};
class IObjectImpl : public IObject
{
public:
    void operation()
    {
        cout << "operation by iobjectimpl" << endl; 
    }
};
class IObjectProxy : public IObject
{
private:
    IObject* object;
public:
    IObjectProxy()
    {
        object = new IObjectImpl;
    }
    void operation()
    {
        cout << "before operation" << endl;
        object->operation();
        cout << "after operation" << endl;
    }
};

int main(int argc, const char *argv[])
{
    IObject* object = new IObjectProxy;
    object->operation();
    return 0;
}
