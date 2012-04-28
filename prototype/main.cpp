#include <iostream>
using namespace std;
class File
{
public:
    virtual int getWidth() = 0;
    virtual File* clone() = 0;
};
class A5File : public File 
{
private:
    int width;
public:
    A5File(int n):width(n){}
    int getWidth()
    {
        return width;
    }
    File* clone()
    {
        return new A5File(this->width);
    }
};
class A4File : public File 
{
private:
    int width;
public:
    A4File(int n):width(n){}
    int getWidth()
    {
        return width;
    }
    File* clone()
    {
        return new A5File(this->width);
    }
};
class Tools 
{
public:
    virtual void go(){}
};
class Stapler : public Tools 
{
private:
    File* file;
public:
    Stapler(File* file)
    {
        this->file = file->clone();
    }
    void go() 
    {
        cout << "This is the stapler, this is " << this->file->getWidth() << " width!" << endl;
    }

};
class Cutter : public Tools 
{
private:
    File* file;
public:
    Cutter(File* file)
    {
        this->file = file->clone();
    }
    void go() 
    {
        cout << "This is the cutter, this is " << this->file->getWidth() << "width" << endl;
    }

};
int main(int argc, const char *argv[])
{
    Tools* tool = new Stapler(new A5File(123));
    tool->go();
    return 0;
}
