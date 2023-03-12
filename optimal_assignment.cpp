#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define INF 99999

using namespace std;


int main()
{
    int n,i,j,x,temp,mask;
    cout<<"enter the size of the matrix : "<<endl;
    cin>>n;
    int size = pow(2,n);
    int cost[n][n];
    int DPtable[size];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    DPtable[0]=0;
    for(i=1;i<size;i++)
    {
        DPtable[i]=INF;
    }
    for(mask=0;mask<size;mask++)
    {
        temp=mask;
        x=0;
        while(temp)
        {
            if((temp%2)!=0)
            {
                x++;
            }
            temp = temp>>1;
        }
        for(j=0;j<n;j++)
        {
            if(!(mask&(1<<j)))
            {
                DPtable[mask|(1<<j)] = DPtable[mask|(1<<j)]>(DPtable[mask]+cost[x][j]) ? (DPtable[mask]+cost[x][j]) : DPtable[mask|(1<<j)];
            }
        }
    }
    for(i=0;i<size;i++)
    {
        cout<<DPtable[i]<<" ";
    }
    return 0;
}