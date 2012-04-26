#include <cstdio>
using namespace std;
class Dish
{
public:
    int oil,ingredient,salt;
    void eat()
    {
        printf("a dish with %dg oil, %dg ingredient and %dg salt!", this->oil, this->ingredient, this->salt);
    }
};
class Pot
{
public:
    virtual void putOil(int n){}
    virtual void putIngredient(int n){}
    virtual void putSalt(int n){}
    virtual Dish* getDish(){return NULL;}
};
class Cook
{
public:
    virtual Dish* createDish(Pot* pot) = 0;
};
class WangCook : public Cook
{
public:
    Dish* createDish(Pot* pot)
    {
        pot->putOil(4);
        pot->putIngredient(200);
        pot->putSalt(2);
        return pot->getDish();
    }
    
};
class LiCook : public Cook
{
public:
    Dish* createDish(Pot* pot)
    {
        pot->putOil(8);
        pot->putIngredient(200);
        pot->putSalt(6);
        return pot->getDish();
    }
    
};
class Saucepan : public Pot
{
private:
    Dish* dish;
public:
    Saucepan() 
    {
        dish = new Dish();
    }
    void putOil(int n)
    {
        dish->oil = n;
    }
    void putIngredient(int n)
    {
        dish->ingredient = n;
    }
    void putSalt(int n)
    {
        dish->salt = n;
    }
    Dish* getDish()
    {
        return dish;
    }
};
class PressurePot : public Pot
{
private:
    Dish* dish;
public:
    PressurePot() 
    {
        dish = new Dish();
    }
    void putOil(int n)
    {
        dish->oil = n;
    }
    void putIngredient(int n)
    {
        dish->ingredient = n;
    }
    void putSalt(int n)
    {
        dish->salt = n + 1;
    }
    Dish* getDish()
    {
        return dish;
    }
};
class Eater
{
public:
    Eater()
    {
        Cook* cook = new WangCook();
        Dish* dish = cook->createDish(new Saucepan);
        dish->eat();
    }
};
int main(int argc, const char *argv[])
{
    Eater eater;    
    return 0;
}
