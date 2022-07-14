#include<iostream>
using namespace std;
void Print(int B[],int n)
{
for(int i=0;i<n;i++) 
cout<<B[i]<<endl;
}
void InsertionSort(int B[],int n)
{
int tmp, j;
for(int i=1;i<n;i++)
{
tmp=B[i];
j=i;
while(j>0 && B[j-1]>tmp)
{
B[j]= B[j-1];
j--;
}
B[j]=tmp;
}

}

int main()
{
int n;
cin>>n;
int B[n];
for(int i=0;i<n;i++)
{
cin>>B[i];
}

InsertionSort(B,n);
Print(B,n);
}
