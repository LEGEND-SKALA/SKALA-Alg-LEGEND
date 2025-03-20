#include <stdio.h>
#include<iostream>
#include<regex>
#include<string>
#include<cstring>
int main(){
	std::string a,b;
	std::cin>>a>>b;
	while(b.length()>a.length())
	{
		if(b.back()=='B')
		{
			b.pop_back();
			std::reverse(b.begin(),b.end());
		}
		else
		{
			b.pop_back();
		}
		if(a==b)
		{
			std::cout<<1;
			return 0;
		}

	}
	std::cout<<0;
	return 0;
}
