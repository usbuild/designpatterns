#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Context 
{
private:
    string _message;
public:
    Context(string s) : _message(s){}
    string& getMsg() {
        return _message;
    }
};
class AbstractExpression 
{
public:
    virtual void interpret(Context){};
};
class UpExpression : public AbstractExpression 
{
public:
    void interpret(Context& context) {
        string* s = &context.getMsg();
        for(int i = 0; i < s->size(); i++)
        {
            s->at(i) = toupper(s->at(i));
        }
    }
};
class AddExpression : public AbstractExpression 
{
public:
    void interpret(Context& context) {
        string* s = &context.getMsg();
        s->insert(0, "{");
        s->append("}");
    }
};

int main(int argc, const char *argv[])
{
    Context context("abcDeFGhi");
    (new UpExpression())->interpret(context);
    (new AddExpression())->interpret(context);
    cout << context.getMsg() << endl;
    return 0;
}
