#include <bits/stdc++.h>
using namespace std;
void Swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int Partition(int a[],int l,int h)
{
    int p=a[h];
    int i=(l-1);
    for(int j=l;j<h;j++)
    {
        if(a[j]<=p)
       {

       i++;
        Swap(&a[i],&a[j]);}
    }
    Swap(&a[i+1],&a[h]);
    return (i+1);
}
void quicksort(int a[],int l,int h)
{ if(l<h)
   {

   int p=Partition(a,l,h);
    quicksort(a,l,p-1);
     quicksort(a,p+1,h);}
}
int main()
{
    int arr[]={4,87,1,0,3,6};
    int s=sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting"<<endl;
    print(arr,s);
    quicksort(arr,0,s-1);
      cout<<"After sorting"<<endl;
    print(arr,s);


}
