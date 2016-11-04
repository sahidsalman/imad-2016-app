#include<iostream>
using namespace std;

int a[50],n;
void swapp(int B[], int i, int j)   // function for swapping
{
  int temp;
        temp=B[i];
        B[i]=B[j];
        B[j]=temp;
}


int part(int B[],int left, int right,int piv)  // function for partitioning the list
{
    while(left<=right)
    {
        while(B[left]<piv)left++;  //moving left to right if it is less than pivot
        while((right>=left)&&(B[right]>=piv))right--;  //moving right to left if it is greater than pivot
        if(left<right)swapp(B,left,right);  //when both the while loop exits swap the current values of left and right
    }
    return left;   // returning left to m
}

void quick(int B[],int L,int R)
{   int pivot;
    pivot=(L+R)/2;   // calculating pivot
    swapp(B,pivot,R);  // swapping pivot value to the end of the list
    int m= part(B,L,R-1,B[R]);  //partitioning and m is the actual index of the current pivot value
    swapp(B,m,R);

    if((m-L)>1) quick(B,L,m-1); //if more than value, quick-sorting
    if((R-m)>1) quick(B,m+1,R);
}
int main()
{
    int f;
    cout<<"\n Enter the size of the array: ";
    cin>>n;                         //size of the array
    cout<<"\n Enter the values :\n";
    for( f=0;f<n;++f)
     cin>>a[f];

     quick(a,0,n-1);  // Calling the funtion quick
     cout<<"\n The Sorted array :";
     for(f=0;f<n;++f)           //printing the sorted list
        cout<<a[f]<<" ";

return 0;
}
