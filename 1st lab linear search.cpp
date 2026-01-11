#include<iostream>
using namespace std;

int LinearSearch(int arr[],int size,int key)
{
	for(int i=0;i<=size;i++)
	{
		if(arr[i] == key)
		{
			return i;
		}
		
	}
	return -1;
}

int main()
{

int Numbers[20] = {10,2,7,6,4,5,61,47,8,9,12,47,59,101,51,99,72,98,39,78};

int Search;

cout<<"Enter Number For Searching: ";
cin>>Search;

int Result = LinearSearch(Numbers,20,Search);

if(Result > -1)
{
	cout<<"Value Found"<<endl;
}
else
{
	cout<<"Value Not Found!"<<endl;
}

return 0;
}
