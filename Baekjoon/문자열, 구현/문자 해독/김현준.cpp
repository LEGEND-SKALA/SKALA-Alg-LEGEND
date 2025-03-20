#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
int main(){
	std::string a,b;
	int a_length=0;
	int b_length=0;
	std::cin>>a_length>>b_length>>a>>b;
	int count=0;
	std::unordered_map<char,int> W_count,S_count;
	for(char c:a)
	{
		W_count[c]++;
	}
	for(int i=0;i<a_length;i++)
	{
		S_count[b[i]]++;
	}
	if(W_count==S_count)
		count++;
	for(int i=a_length;i<b_length;i++)
	{
		if(--S_count[b[i-a_length]]==0)
			S_count.erase(b[i-a_length]);
		S_count[b[i]]++;
		if(W_count==S_count)
			count++;
	}
	std::cout<<count;
	return 0;
}
