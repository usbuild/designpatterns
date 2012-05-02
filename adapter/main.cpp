#include <iostream>
using namespace std;
class Car 
{
public:
    virtual void start()
    {
        cout << "Engine start!" << endl;
    }
};
class Bike 
{
public:
    virtual void ride()
    {
        cout << "Ride a bike!" << endl;
    }
};
class Adapter : public Bike, private Car 
{
public:
    void ride()
    {
        Car::start();
    }
};
class Adapter2 : public Bike 
{
private:
    Car* _car;
public:
    Adapter2(Car *car) : _car(car){}
    void ride()
    {
        _car->start();
    }
};
class DualAdapter : public Bike, public Car
{
public:
    void ride()
    {
        Car::start();
    }
    void start()
    {
        Bike::ride();
    }
};
class DualAdapter2 : public Bike 
{
private:
    Car* _car;
    Bike* _bike;
public:
    DualAdapter2(Car* car, Bike* bike) : _car(car), _bike(bike){}
    void ride()
    {
        _car->start();
    }
    void start()
    {
        _bike->ride();
    }
};
int main(int argc, const char *argv[])
{
    Bike* bike = new DualAdapter2(new Car, new Bike);
    bike->ride();
    return 0;
}
