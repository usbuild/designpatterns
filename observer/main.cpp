#include <iostream>
#include <vector>
using namespace std;
class Observer 
{
public:
    virtual void Update() = 0;
};
class Subject
{
private:
    vector<Observer*> v;
public:
    void Add(Observer* o) {
        v.push_back(o);
    }
    void Notify() {
        for(int i = 0; i < v.size(); i++)
            v.at(i)->Update();
    }
};   

class ConcreteObserver : public Observer 
{
public:
    void Update() {
        cout << "UPdated!" << endl;
    }
};

int main(int argc, const char *argv[])
{
    Subject sub;
    ConcreteObserver co;
    sub.Add(&co);
    sub.Notify();
    return 0;
}
