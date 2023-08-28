#include<iostream>
#include<string>
// string and time complexity
using namespace std;
int main(){
	string s;//its like a vector of characters
	cin>>s;
	cout<<s[1]<<'\n';
	cout<<"The string is "<<s;
	s+=" World";
	/* if we use s+='a'; the time complexity is O(n);
	so always use s.push_back('a') because s.push_back() has time complexity O(1)
we cannot type s.push_back("a") because "a" is a string and 'a' is a char 
so we have to always use character if we use the function call s.push_back()

	*/
	cout<<s.length()<<'\n';
	cout<<s.substr(3,2)<<'\n';//string slicing of 3 characters from 2nd index onwards from the string s


	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());




	return 0;

}