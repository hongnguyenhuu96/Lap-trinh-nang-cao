/**
 * \file Bai5.cpp
 * \brief su dung tinh chat da hinh va ke thua lop vi du ve bai toan tinh dien tich
 * \author Nguyen Huu Hong 14020198
 */
#include<iostream>

using namespace std;
class Shape
{
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape
{
private:
    float length, width;
public:
    Rectangle() // ham tao khong doi
    {
        length = 0;
        width = 0;
    }
    Rectangle(float a1, float b1) // ham tao co doi
    {
        length = a1;
        width = b1;
    }
    float getArea() // ham tinh dien tich // chu y khai bao getArea cua lop Shape
    {
        return length*width;
    }
};

class Square : public Rectangle
{
public:
    Square() : Rectangle() {}
    Square(int a) : Rectangle(a, a){} // ham tao co doi cho hinh vuong, do la hinh vuong nen 2 canh bang nhau = a
};



int main(){
    Rectangle a(3, 4); // hinh chu nhat co 2 canh la 3 va 4
    cout << "Dien tich hinh chu nhat la: " << a.getArea() << endl;
    Square b(5); // hinh vuong co canh la 5
    cout << "Dien tich hinh vuong la: " << b.getArea() << endl;
}
