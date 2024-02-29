
#include <bits/stdc++.h>
using namespace std;
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void countingsort(int a[],int n)
{
    int o[n];
    int m=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    int c[m+1];
    for(int i=0;i<=m;i++)
    {
        c[i]=0;
    }
    for( int i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    for( int i=1;i<=m;i++)
    {
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        o[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=o[i];
    }


}

int main()
{
    int arr[]={4,7,1,0,3,6};
    int s=sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting"<<endl;
    print(arr,s);
   countingsort(arr,s);
      cout<<"After sorting"<<endl;
    print(arr,s);


}
