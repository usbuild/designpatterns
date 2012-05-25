#include <iostream>
#include <string>
using namespace std;
class ElementA;
class ElementB;
class Visitor 
{
public:
    virtual void Visit(ElementA*) = 0;
    virtual void Visit(ElementB*) = 0;
};
class Element 
{
public:
    virtual void Accept(Visitor*) = 0;
};
class ElementA : public Element
{
public:
    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }
    string GetName() {
        return "ElementA";
    }
};
class ElementB : public Element
{
public:
    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }
    string GetName() {
        return "ElementB";
    }
};
class VisitorA : public Visitor 
{
public:
    void Visit(ElementA* element) {
        cout << element->GetName() << endl;
    }
    void Visit(ElementB* element) {
        cout << element->GetName() << endl;
    }
};
int main(int argc, const char *argv[])
{
    Visitor* visitor = new VisitorA();
    Element* element = new ElementA();
    Element* element2 = new ElementB();
    element->Accept(visitor);
    element2->Accept(visitor);
    return 0;
}
