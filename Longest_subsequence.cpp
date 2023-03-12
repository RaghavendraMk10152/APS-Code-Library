#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter the string s1 : ";
    cin>>s1;
    cout<<"Enter the string s2 : ";
    cin>>s2;
    cout<<endl;

    cout<<"Length of s1 : "<<s1.length()<<endl;
    cout<<"Length of s2 : "<<s2.length()<<endl;

    int m = s1.length() , n = s2.length();

    int a[m+1][n+1];

    //Initializing the matrix

    for (int i = 0; i <= m; i++)
    {
        a[i][0] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        a[0][i] = 0;
    }

    cout<<endl;

    //Displaying the initialing matrix

    cout<<"initialized matrix : "<<endl;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<<a[i][j]<<" ";
        }   
        cout<<endl;
    }
    
    cout<<endl;

    //algorithm starts
    //Dynamic programming
    //Bellman Ford

    for (int i = 1; i <= m ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s1.at(i-1)==s2.at(j-1))
            {
                a[i][j] = a[i-1][j-1] + 1;
            }
            else
            {
                int p = a[i-1][j] , q = a[i][j-1] ;
                int max = (p > q) ? p : q;
                a[i][j] = max; 
            }
        }
    }

    cout<<endl;

    //Display the matrix after populating the matrix

    cout<<"Display the final matrix : "<<endl;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<<a[i][j]<<" ";
        }   
        cout<<endl;
    }

    cout<<endl;

    cout<<"The Final output = "<<a[m][n]<<endl;

    return 0;
}