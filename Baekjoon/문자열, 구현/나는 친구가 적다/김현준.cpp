#include <stdio.h>
#include<iostream>
#include<regex>
#include<string>
#include<cstring>
int main(){
	std::string a,b,c;
	std::cin>>a>>b;
	for(char ch :a)
	{
		if(!isdigit(ch))
			c+=ch;
	}
	if(c.find(b) !=std::string::npos)
		std::cout<<1;
	else
		std::cout<<0;
	return 0;
}
