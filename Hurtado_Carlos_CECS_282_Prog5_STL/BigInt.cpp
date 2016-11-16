//
//  BigInt.cpp
//  Standard Template Library
//
//  Created by Carlos Hurtado on 11/11/16.
//  Copyright © 2016 Carlos Hurtado. All rights reserved.
//

#include "BigInt.hpp"
using namespace std;
BigInt::BigInt()
{
    storage.push_back(1);
}

BigInt::BigInt(int n)
{
    int digit;
    while(n>0)
    {
        digit = n %10;
        n/=10;
        storage.push_back(digit);
    }
}

BigInt::BigInt(string n)
{
    string temp;
    vector<int> tempStorage;
    if(n.front()=='-')
    {
        temp = n.substr(1);
    }
    else
    {
        temp = n;
    }
    for(char c: temp)
    {
        tempStorage.push_back(parseInt(c," "));
    }
    for(rit = tempStorage.rbegin(); rit!=tempStorage.rend(); rit++)
    {
        storage.push_back(*rit);
        
    }
    
}

BigInt::BigInt(const BigInt& b)
{
    storage = b.storage;
}

BigInt::~BigInt()
{
    vector<int> tempVector;
    tempVector.swap(storage);
    tempVector.clear();
}

BigInt BigInt::operator+(BigInt b)
{
    int carried = 0;
    string sum = "";
    for(int i = 0; i < b.storage.size(); i++)
    {
        int x = storage[i];
        int y = b.storage[i];
        sum += parseStr((x+y+carried)%10);
        carried = carry(x, y , carried);
        
    }
    for(long i = b.storage.size(); i < storage.size(); i++)
    {
        
        sum+=parseStr(storage[i]+carried);
        carried = carry(storage[i], carried, 0);
    }
    if(carried==1)
    {
        sum+="1";
    }
    string result;
    result.assign(sum.rbegin(),sum.rend());
    BigInt endGame(result);
    return endGame;
}

/**
 * Substracting from storage size
 */
BigInt BigInt::operator-(BigInt b)
{
    string difference = "";
    if(storage.size() == b.storage.size())
    {
        for(int i = 0; i < b.storage.size(); i++)
        {
            int x = storage[i];
            int y = b.storage[i];
            if(x<y)
            {
                int nextInt = findNextInt(i+1);
                
                for(int j = i+1; j < nextInt; j++)
                {
                    if(storage[j] == 0)
                    {
                        storage[j] = 9;
                    }
                }
                if(storage[i] == 0)
                {
                    storage[i] = 10;
                }
                int temp = storage[nextInt]-1;
                storage[nextInt] = temp;
                string concatenate = "1" + parseStr(storage[i]);
                int largerNum = parseInt(' ', concatenate);
                storage[i] = largerNum;
                difference += parseStr(storage[i]-y);
            }
            else
            {
                difference += parseStr(x-y);
            }
        }
    }
    else if(storage.size()== 0)
    {
        difference+="0";
    }
    else
    {
        for(int i = 0; i < b.storage.size(); i++)
        {
            int x = storage[i];
            int y = b.storage[i];
            if(x<y)
            {
                int nextInt = findNextInt(i+1);
                
                for(int j = i+1; j < nextInt; j++)
                {
                    if(storage[j] == 0)
                    {
                        storage[j] = 9;
                    }
                }
                if(storage[i] == 0)
                {
                    storage[i] = 10;
                }
                int temp = storage[nextInt]-1;
                storage[nextInt] = temp;
                string concatenate = "1" + parseStr(storage[i]);
                int largerNum = parseInt(' ', concatenate);
                storage[i] = largerNum;
                difference += parseStr(storage[i]-y);
            }
            else
            {
                difference += parseStr(x-y);
            }
        }
        for(long i = b.storage.size(); i < storage.size();i++)
        {
            difference+=parseStr(storage[i]);
        }
    }
    string result;
    result.assign(difference.rbegin(),difference.rend());
    int pos = 1;
    for(char c: result)
    {
        string temp = result;
        if(c == '0')
        {
            temp = result.substr(pos);
            result = temp;
        }
        else
        {
            break;
        }
        pos++;
    }
    BigInt endGame(result);
    return endGame;
}

bool BigInt::operator==(const BigInt &b)
{
    bool isEqual = false;
    if(storage.size() == 1)
    {
        if(storage[0] == b.storage[0])
        {
            isEqual = true;
        }
    }
    return isEqual;
}

ostream & operator<<(ostream & os, const BigInt& b)
{
    vector<int> temp = b.storage;
    vector<int>::reverse_iterator rit;
    for(rit = temp.rbegin(); rit!=temp.rend(); rit++)
    {
        os<<*rit;
    }
    return os;
}

int BigInt::parseInt(char s, string c)
{
    int num = 0;
    if(s=='1')
    {
        num = 1;
    }
    else if(s=='2')
    {
        num = 2;
    }
    else if(s=='3')
    {
        num = 3;
    }
    else if(s=='4')
    {
        num = 4;
    }
    else if(s=='5')
    {
        num = 5;
    }
    else if(s=='6')
    {
        num = 6;
    }
    else if(s=='7')
    {
        num = 7;
    }
    else if(s=='8')
    {
        num = 8;
    }
    else if(s=='9')
    {
        num = 9;
    }
    if(c!= " ")
    {
        if(c=="10")
        {
            num = 10;
        }
        else if(c=="11")
        {
            num = 11;
        }
        else if(c=="12")
        {
            num = 12;
        }
        else if(c=="13")
        {
            num = 13;
        }
        else if(c=="14")
        {
            num = 14;
        }
        else if(c=="15")
        {
            num = 15;
        }
        else if(c=="16")
        {
            num = 16;
        }
        else if(c=="17")
        {
            num = 17;
        }
        else if(c=="18")
        {
            num = 18;
        }
        else if(c=="19")
        {
            num = 19;
        }
    }
    return num;
}

string BigInt::parseStr(int n)
{
    string str = "0";
    if(n==1)
    {
        str = "1";
    }
    else if(n==2)
    {
        str = "2";
    }
    else if(n==3)
    {
        str = "3";
    }
    else if(n==4)
    {
        str = "4";
    }
    else if(n==5)
    {
        str = "5";
    }
    else if(n==6)
    {
        str = "6";
    }
    else if(n==7)
    {
        str = "7";
    }
    else if(n==8)
    {
        str = "8";
    }
    else if(n==9)
    {
        str = "9";
    }
    
    return str;
}

int BigInt::carry(int x, int y, int c)
{
    if((x+y+c)>9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int BigInt::findNextInt(int start)
{
    int pos = -1;
    for(int i = start; i < storage.size(); i++)
    {
        if(storage[i]!=0)
        {
            pos = i;
            break;
        }
    }
    
    return pos;
}
