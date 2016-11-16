//
//  BigInt.hpp
//  Standard Template Library
//
//  Carlos Hurtado
//  CECS 282-07
//  Project 5: STL (GoldRabbits)
//  11/14/2016
//

#ifndef BigInt_hpp
#define BigInt_hpp
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class BigInt
{
    private:
    vector<int> storage;
    vector<int>::reverse_iterator rit;
    public:
    BigInt();
    BigInt(int);
    BigInt(string);
    BigInt(const BigInt&);
    ~BigInt();
    BigInt operator+(BigInt b);
    BigInt operator-(BigInt b);
    bool operator==(const BigInt& b);
    friend ostream& operator<< (ostream& os, const BigInt& b);
    int parseInt(char c, string s);
    string parseStr(int n);
    int carry(int x, int y, int c);
    int findNextInt(int start);
};


#endif /* BigInt_hpp */
