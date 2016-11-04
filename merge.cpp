#include<iostream>
using namespace std;


int n,a[50];

void mergesort(int B[], int L, int R)
 {
   int temp[50];
        if (L == R) return; // If the array has only one element
   int mid = (L + R)/2; // Finding the midpoint
        mergesort(B, L, mid); // Mergesort left half of the list
        mergesort(B, (mid+1), R); // Mergesort right half
     for (int i = L; i <= R; i++)
            temp[i] = B[i]; // Copy sub-array to temp

   // Do the merge operation back to B
  int i1 = L;
  int i2 = mid + 1;
        for (int now = L; now <= R; now++)   // loop for merging the sorted arrays to main array
            {
                if (i1 == mid+1)   // Left sub-array is empty
                        B[now] = temp[i2++];
                else if (i2 > R)   // Right sub-array is empty
                        B[now] = temp[i1++];
                else if (temp[i1] <= temp[i2])    //Comparing the values And get smaller value
                        B[now] = temp[i1++];
                else
                        B[now] = temp[i2++];
            }
}

int main()
{int f;
    cout<<"\n Enter the size of the array: ";
    cin>>n;                         //size of the array
    cout<<"\n Enter the values :\n";
    for( f=0;f<n;++f)
     cin>>a[f];

     mergesort(a,0,n-1);  // Calling the funtion mergesort
     cout<<"\n The Sorted array :";
     for(f=0;f<n;++f)           //printing the sorted list
        cout<<a[f]<<" ";
return 0;
}
