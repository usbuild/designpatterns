#include <iostream>
using namespace std;
class State 
{
public:
    virtual void Handle() = 0;
};
class Context
{
private:
    State* _state;
public:
    void SetState(State* state) {
        this->_state =  state;
    }
    State* GetState() {
        return this->_state;
    }
    void Request() {
        _state->Handle();
    }
};
class ConcreteStateA : public State
{
public:
    void Handle() {
        cout << "This is state A" << endl;
    }
};

class ConcreteStateB : public State
{
public:
    void Handle() {
        cout << "This is state B" << endl;
    }
};

int main(int argc, const char *argv[])
{
    Context context;
    context.SetState(new ConcreteStateA());
    context.Request();
    context.SetState(new ConcreteStateB());
    context.Request();
    return 0;
}
