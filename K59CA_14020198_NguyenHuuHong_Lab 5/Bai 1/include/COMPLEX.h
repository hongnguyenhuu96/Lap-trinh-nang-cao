#ifndef COMPLEX_H
#define COMPLEX_H
#include "iostream"
#include "cmath"
using namespace std;
class COMPLEX
{
    public:
        COMPLEX();
        COMPLEX(float a1, float b1);
        COMPLEX(const COMPLEX& other);
        virtual ~COMPLEX();
        COMPLEX operator + (const COMPLEX &other);
        COMPLEX operator - (const COMPLEX &other);
        int operator > (COMPLEX &other);
        int operator < (COMPLEX &other);
        int operator == (COMPLEX &other);
        int operator >= (COMPLEX &other);
        int operator <= (COMPLEX &other);
        int operator != (COMPLEX &other);
        COMPLEX& operator =(const COMPLEX& other);
        friend ostream& operator<< (ostream& os,const COMPLEX &a);
        friend istream& operator>> (istream& is, COMPLEX &b);
    protected:
    private:
        float a; // phan thuc re
        float b; // phan ao im
        float modun();
};

#endif // COMPLEX_H
