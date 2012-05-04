#include <vector>
#include <iostream>
using namespace std;
class Component 
{
public:
    virtual void draw() = 0;
    virtual void add(Component* comp) { }
    virtual Component* getComponent(int n){ return 0; }
};
class Leaf1 : public Component
{
public:
    void draw()
    {
       cout << "Draw a leaf1" << endl;
    }
};
class Leaf2 : public Component
{
public:
    void draw()
    {
       cout << "Draw a leaf2" << endl;
    }
};
class Composite : public Component 
{
private:
    vector<Component*>* _compList;
public:
    Composite()
    {
        _compList = new vector<Component*>();
    }
    void draw()
    {
        for(vector<Component*>::iterator it = _compList->begin(); it != _compList->end(); it++) 
        {
            (*it)->draw();
        }
    }
    void add(Component* comp)
    {
        _compList->push_back(comp);
    }
    Component* getComponent(int n)
    {
        return _compList->at(n);
    }
};

int main(int argc, const char *argv[])
{
    Component* cpn = new Composite();
    cpn->add(new Leaf1);
    cpn->add(new Leaf2);

    Component* c = new Composite();
    c->add(new Leaf2);
    c->add(new Leaf2);

    cpn->add(c);
    cpn->draw();
    return 0;
}
