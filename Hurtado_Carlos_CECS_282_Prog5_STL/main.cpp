//
//  main.cpp
//  Standard Template Library
//
//  Created by Carlos Hurtado on 10/31/16.
//  Copyright © 2016 Carlos Hurtado. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <map>
#include "BigInt.hpp"
using namespace std;

BigInt goldRabbits(int n);
static map<int, BigInt> values;

int main()
{
    bool isRunning = true;
    while(isRunning)
    {
        cout<<"1) Find amount of goldRabbits in 12 years"<<endl;
        cout<<"2) Find goldRabbits(1000)"<<endl;
        cout<<"3) Find goldRabbits of your choice"<<endl;
        cout<<"4) Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1)
        {
            int const TenYears = 12 * 10; //this is 10 years
            long start = time(0); //number of seconds since Jan 1, 1970
            for(int i= 0; i <= TenYears; i++)
            {
                BigInt answer = goldRabbits(i);
                long current = time(0);
                long deltaSeconds = current-start; //number of seconds since program started
                cout<<"\n Seconds:"<<setw(5)<<deltaSeconds<<",";
                cout<<" goldRabbits("<<setw(2)<<i<<") = ";
                cout<<setw(11)<<answer<<endl;
                cout<<endl;
            }
        }
        else if(choice == 2)
        {
            long start = time(0);
            for(int i= 0; i <= 1000; i++)
            {
                BigInt answer = goldRabbits(i);
                long current = time(0);
                long deltaSeconds = current-start; //number of seconds since program started
                cout<<"\n Seconds:"<<setw(5)<<deltaSeconds<<",";
                cout<<" goldRabbits("<<setw(2)<<i<<") = ";
                cout<<setw(11)<<answer<<endl;
            }
            cout<<endl;
        }
        else if(choice == 3)
        {
            cout<<"How many years: ";
            int years;
            cin>>years;
            years*=12;
            if(years>=0)
            {
                long start = time(0);
                for(int i= 0; i <= years; i++)
                {
                    BigInt answer = goldRabbits(i);
                    long current = time(0);
                    long deltaSeconds = current-start; //number of seconds since program started
                    cout<<"\n Seconds:"<<setw(5)<<deltaSeconds<<",";
                    cout<<" goldRabbits("<<setw(2)<<i<<") = ";
                    cout<<setw(11)<<answer<<endl;
                }
                cout<<endl;
            }
            else
            {
                cout<<"\n-Invalid Input-\n"<<endl;
            }
        }
        else if(choice == 4)
        {
            cout<<"\n-Exiting...Done-\n"<<endl;
            isRunning = false;
        }
        else
        {
            cout<<"\n-Invalid Input-\n"<<endl;
        }
    }
    
    return 0;
}

BigInt goldRabbits(int n)
{
    map<int, BigInt>::iterator it;
    for(it = values.begin(); it!= values.end(); it++)
    {
        if(values.size()==3)
        {
            values.erase(it);
            break;
        }
    }
    
    if(n==0 || n==1)
    {
        values[n] = 1;
        return 1;
    }
    else
    {
        values[n] = values[n-1] + values[n-2];
        BigInt b(values[n]);
        return b;
    }
    
}
