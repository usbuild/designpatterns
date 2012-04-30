class Singleton 
{
private:
    Singleton(){}
    static Singleton* instance;
public:
    static Singleton* getInstance();
};
Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance()
{
    if (Singleton::instance == 0)
    {
        Singleton::instance = new Singleton();
    }
    return instance;
}
int main(int argc, const char *argv[])
{
    Singleton* single = Singleton::getInstance();
    return 0;
}
