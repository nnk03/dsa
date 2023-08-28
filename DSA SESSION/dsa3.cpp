#include<iostream>
using namespace std;

void swap(int &a, int &b){//pass by reference, it will take the actual values of a and b and swap it
							//
	int temp=a;
	a=b;
	b=temp;
}
int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int inp;
		cin>>inp;
		arr.push_back(inp);
	}//the problem is its not very fast ie push_back is not very fast
	//the another efficient way to do it is as follows
	vector<int> arr1(n,0);
	for(int i=0;i<n;i++){
		cin>>arr1[i];  //much more efficient way
	}//initialising all elements to zero and then assigning to the vector directly



	for(auto x: arr){
		cout<<x<<" ";

	}
	// x is not the index but it is the content of the arr
	vector<int> arr2(n,0);

	for(auto &x: arr2){//if we don't put '&', it will not work as expected
		cin>>x; 
	}



	//lambda functions
	// lets say the local function we want is sum(a,b) -> a + b

	auto sum = [n, &arr, arr1](int a, int b) -> int {
	//if we don't put n in the square bracket then there will be an error even if there is a global variable n
	//and at the same time we don't want n to given as a parameter
	//if we just put '&' in the square bracket everything outside the function will be copied by reference
	/*ie like 
	auto sum = [&](int a, int b) -> int {
		return a+b+n;
	}
	*/
		for(auto &y:arr){
			y=0;//arr will not be modified if we don't put '&' in the square bracket

		}
		return a+b+n;
	};    //semicolon is important
	/* base cases is important in recursion*/

	//towers of hanoi
	/*
	good examples of recursion
	graph traversals
	divide and conquer(merge sort??, quick sort??)


	*/









}







