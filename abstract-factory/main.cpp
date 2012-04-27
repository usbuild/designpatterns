#include <iostream>
using namespace std;

class Tree 
{
public:
    virtual void color() = 0;
};
class Sky
{
public:
    virtual void drop() = 0;
};
class WinterTree : public Tree
{
public:
    void color()
    {
        cout << "The tree is black!" << endl;
    }
};

class SummerTree : public Tree
{
public:
    void color()
    {
        cout << "The tree is green!" << endl;
    }
};
class WinterSky : public Sky
{
public:
    void drop()
    {
        cout << "It snows" << endl;
    }
};

class SummerSky : public Sky
{
public:
    void drop()
    {
        cout << "It rains" << endl;
    }
};

class Factory 
{
public:
    virtual Tree* createTree() = 0;
    virtual Sky* createSky() = 0;
};
class WinterFactory : public Factory 
{
public:
    Tree* createTree()
    {
        return new WinterTree();
    }
    Sky* createSky()
    {
        return new WinterSky();
    }
};
class SummerFactory : public Factory 
{
public:
    Tree* createTree()
    {
        return new SummerTree();
    }
    Sky* createSky()
    {
        return new SummerSky();
    }
};



int main(int argc, const char *argv[])
{
    Factory* factory = new SummerFactory();
    Tree* tree = factory->createTree();
    Sky* sky = factory->createSky();
    tree->color();
    sky->drop();
    return 0;
}
