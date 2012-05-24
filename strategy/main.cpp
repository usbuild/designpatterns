#include <iostream>
using namespace std;
class Strategy 
{
public:
    virtual void DoAlgorithm() = 0;
};
class Context
{
private:
    Strategy* _strategy;
public:
    Context(Strategy* strategy) {
        this->_strategy =  strategy;
    }
    void DoSomething() {
        _strategy->DoAlgorithm();
    }
};
class ConcreteStrategyA : public Strategy
{
public:
    void DoAlgorithm() {
        cout << "This is strategy A" << endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void DoAlgorithm() {
        cout << "This is strategy B" << endl;
    }
};

int main(int argc, const char *argv[])
{
    Context contexta(new ConcreteStrategyA);
    contexta.DoSomething();
    Context contextb(new ConcreteStrategyB);
    contextb.DoSomething();
    return 0;
}
