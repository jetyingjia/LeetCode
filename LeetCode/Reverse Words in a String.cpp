#include "utils.h"

#ifdef Reverse
/*
Given an input string, reverse the string word by word.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the".

	*/

#include <iostream>
#include <sstream>
#include <vector>

void reverseWords(std::string &s) {

	std::stringstream ss(s);
	std::string word;
	std::vector< std::string> temp;
	while (ss>>word)
	{
		temp.push_back(word);
		temp.push_back(" ");
	}
	s = "";
	for (int i = temp.size() - 2; i >= 0; i--)
	{
		s += temp[i];
	}
	
}


int main()
{
	std::string s("the   sky is blue  a");
	reverseWords(s);
	std::cout<<s;
	system("pause");
	return 0;
}



#endif