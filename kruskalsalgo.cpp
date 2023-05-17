#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v 5
int p[v];
int find(int x)
{
    while(p[x]!=x)
    {
        x=p[x];
    }
    return x;
}
//p[0]=0        p[1]=1      p[2]=2      p[3]=3      p[4]=4
//p[0]=1
void mixing(int i,int j)//0,1
{
    int a=find(i);
    int b=find(j);
    p[a]=b;
}
void kruskalmst(int mcost[][v])
{
    for(int i=0;i<v;i++)
    {
        p[i]=i;
    }
    int mc=0;
    int ec=0;//ec=edge cost
    while(ec<v-1)
    {
        int min=INT_MAX;
        int a=-1;
        int b=-1;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(find(i)!=find(j) && mcost[i][j]<min)
                {
                    min=mcost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        //min=2,a=0,b=1
        //
        mixing(a,b);
        cout<<"edge: "<<ec<<" "<<a<<","<<b<<"min edge cost: "<<min<<endl;
        ec++;//1
        mc=mc+min;//2
    }
    cout<<"minimum cost = "<<mc;
}
int main()
{
    int mcost[][v]={{INT_MAX,2,INT_MAX,6,INT_MAX},
                    {2,INT_MAX,3,8,5},
                    {INT_MAX,3,INT_MAX,INT_MAX,7},
                    {6,8,INT_MAX,INT_MAX,9},
                    {INT_MAX,5,7,9,INT_MAX}};
    kruskalmst(mcost);//kruskal's minimum spanning tree
}