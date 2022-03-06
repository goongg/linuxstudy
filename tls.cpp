#include <vector>
#include <iostream>
#include <string>
#include "tls.h"
#include <gmp.h>

using namespace std;


int main()
{
    cout<< powm(3, 100, 23)<< '\n';
    cout<< powm(12, 25, 23)<< '\n';
    
    cout<< is_primitive(2,5)<< '\n';
    cout<< is_primitive(3,5)<< '\n';
    cout<< is_primitive(4,5)<< '\n';

    return 0;
}


int powm(int base, int exp, int mod)
{
    int r = 1;
    for(int i = 0; i <exp; i++)
    {
        r *= base;
        r %= mod;
    }

    return r;
}

bool is_primitive(int base, int mod)
{
    int exp = 2;
    int r = base * base;

    for(; r!= base; exp++)
    {
        r *= base;
        r %= mod;
    }
    return exp == mod;
}
