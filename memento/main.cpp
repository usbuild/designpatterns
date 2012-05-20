#include <iostream>
using namespace std;
class Position 
{
public:
    int x;
    int y;
};
class Memento
{
private:
    Position _postion;
public:
    Memento(Position& pos) {
        _postion.x = pos.x;
        _postion.y = pos.y;
    }
    Position& GetPosition() {
        return _postion;
    }
    void SetPosition(Position& pos) {
        _postion.x = pos.x;
        _postion.y = pos.y;
    }
};
class Rect 
{
private:
    Position _postion;
public:
    Memento* createMemento() {
        return new Memento(_postion);
    }
    void SetMemento(Memento& memento){
        _postion = memento.GetPosition();
    }
    Rect(int x, int y) {
        _postion.x = x;
        _postion.y = y;
    }

    void Say() {
        cout << "Rect At:" << _postion.x << "," << _postion.y << endl;
    }
    void MoveX(int x) {
        _postion.x += x;
    }
    void MoveY(int y) {
        _postion.y += y;
    }
};
int main(int argc, const char *argv[])
{
    Rect rect(1, 2);
    rect.Say();
    Memento* mem = rect.createMemento();
    rect.MoveX(-10);
    rect.MoveY(12);
    rect.Say();
    rect.SetMemento(*mem);
    rect.Say();
    return 0;
}
