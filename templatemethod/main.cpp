#include <iostream>
using namespace std;
class AbstractClass 
{
public:
    void TemplateMethod(){
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
    virtual void PrimitiveOperation1(){
        cout << "PrimitiveOperation1 from AbstractClass" << endl;
    }
    virtual void PrimitiveOperation2(){
        cout << "PrimitiveOperation2 from AbstractClass" << endl;
    }
};

class ConcreateClass : public AbstractClass
{
public:
    virtual void PrimitiveOperation1(){
        cout << "PrimitiveOperation1 from ConcreateClass" << endl;
    }
    virtual void PrimitiveOperation2(){
        cout << "PrimitiveOperation2 from ConcreateClass" << endl;
    }
};
int main(int argc, const char *argv[])
{
    AbstractClass* ac = new ConcreateClass;
    ac->TemplateMethod();
    return 0;
}
