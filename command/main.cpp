#include <iostream>
using namespace std;
class Receiver 
{
public:
    void Action() {
        cout << "An action invoked!" << endl;
    }
};
class Command 
{
protected:
    Command(){}
public:
    virtual void Execute() = 0;
};
class ConcreteCommand : public Command 
{
private:
    Receiver* _receiver;
public:
    ConcreteCommand(Receiver* receiver) : _receiver(receiver){}
    void Execute() {
        _receiver->Action();
    }
};
class Invoker 
{
public:
    void invoke(Command* command) {
        command->Execute();
    }
};
int main(int argc, const char *argv[])
{
    Invoker* invoker = new Invoker();
    Command* command = new ConcreteCommand(new Receiver());
    invoker->invoke(command);
    return 0;
}
