#include<bits/stdc++.h>
using namespace std;
int t=0;
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void merge1(int arr[],int l,int r,int m)
{
    int i,j,k,n1,n2;
    n1 =m-l+1;
     n2 =r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)L[i]=arr[l+i];
       for(j=0;j<n2;j++)R[j]=arr[m+1+j];

       i=0;
       j=0;
       k=l;
       while(i<n1&&j<n2)
       {
           if(L[i]<=R[j])
           {
               arr[k]=L[i];
               i++;
               k++;
            }
            else
            {
                arr[k]=R[j];
                k++;
                 j++;
            }
       }
       while(i<n1)
       {
           arr[k]=L[i];
           k++;
           i++;
       }
         while(j<n2)
       {
           arr[k]=R[j];
           k++;
           j++;
       }



}
void mergeSort(int arr[],int l,int r)
{
    t++;

    if(l<r)
    {

            int m=(l+r)/2;

        mergeSort(arr,l,m);
         mergeSort(arr,m+1,r);
         merge1(arr,l,r,m);

    }


}

int main()
{
    int arr[]={3,5,8,9,6,1};

    int s=sizeof(arr)/sizeof(arr[0]);
    //cout<<s;
         print(arr,s);
    mergeSort(arr,0,s-1);
    print(arr,s);
    cout<<t;
}

