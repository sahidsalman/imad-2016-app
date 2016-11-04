#include <iostream>
#include <stdlib>

using namespace  std;

void insert_sort(int ar[],int length)

{
int i,j,temp;

	for(i=1;i<length;i++)

	{

		j=i;

	
	while(j>0&&ar[j]<ar[j-1])

		{
			temp=ar[j];

			ar[j]=ar[j-1];

			ar[j-1]=temp;

			j--;
		}

	}

}

int main()

{

	int ar[1000],length;

	cout<<"enter the length";

	cin>>length;

	cout<<"enter the numbers";

	for(int i=0;i<length;i++)

		ar[i]=rand(10000)%100;

	insert_sort(ar,length);

	for(int i=0;i<length;i++)

		cout<<ar[i]<<"\n";



	return 0;

}