//author: seema kumari patel
//Implementation of palindrome in c++

#include<bitset>/stdc++.h>

using namespace std;

void main ()
{
  String str = "racecar" 

    int n=str.length();
    bool flag=true;
    for(int i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-i-1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"The string is a palindrome."<<endl;
    else
        cout<<"The string is not a palindrome."<<endl;
}