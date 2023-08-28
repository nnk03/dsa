#include<iostream>
#include<vector>
using namespace std;
vector<int> global_arr[10];//all values will be zero by default since ITS DECLARED GLOBALLY
//standard template library
int main(){
	vector<int> arr(10,2);
	vector<int> arr_10(10);//will create an vector of 10 elements
	vector<int> arr_10_11(10,11);//will create a vector of 10 elements each element being 11

	arr.push_back(70);
	vector<int> local_arr[10];
	for(int i=0;i<10;i++){
		cout<<local_arr[i]<<" ";
		//will print junk values since its declared locally rather than zero as in the case of global_arr

	}
	cout<<"\n";
	for(int i=0;i<10;i++){
		cout<<global_arr[i]<<" ";
		//will print zero for all i since its declared globally
	}
	//arr.pop_back()


	//SORTING
	sort(arr.begin(),arr.end());//will sort in ascending order


	//REVERSE FOR DESCENDING
	reverse(arr.begin(),arr.end());
	/*
	OR we can use the below statement instead of first sorting in ascending and then reversing the order
	sort(arr.begin(),arr.end(),greater<int>());

	but its better to use basic functions like sort and reverse

	OR another way is to use rbegin() and rend()
	sort(arr.rbegin(),arr.rend());

	*/

	//vector can be of any type
	vector<vector<string>>//vector of vector of string
	vector<vector<int>>//like a matrix
	/*
	if we want to change the 3rd index we can just write
	arr[3]=10;

	*/
	auto t=5;
	/*auto keyword is that it automatically identifies which datatype is assigned 
	to the variable but we have to assign at the time of declaration*/
	/*
	auto t; this will be an error
	auto t={1,2,3,4,5};// t will be considered as list

	*/

	/*

	vector<int> a={1,2,3};
	a={4,5}; // this is allowed, we can redefine the vector a
	*/

	arr.clear()//will clear the array



	vector<int> a={1,2,3,4,5};//this is a valid statement






	return 0;

}