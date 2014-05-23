#include "utils.h"

#ifdef ValidParentheses

#include <iostream>
#include <vector>
#include <string>

bool isValid(std::string s) 
{
	std::vector<char> ans;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '(': ans.push_back(s[i]); break;
		case '[': ans.push_back(s[i]); break;
		case '{': ans.push_back(s[i]); break;
		case ')': if (ans.size() == 0 || ans[ans.size() - 1] != '(')
				  {
					  return false;
				  }
				  ans.pop_back();
				  break;
		case ']': if (ans.size() == 0 || ans[ans.size() - 1] != '[')
				  {
					  return false;
				  }
				  ans.pop_back();
				  break;
		case '}': if (ans.size() == 0 || ans[ans.size() - 1] != '{')
				  {
					  return false;
				  }
				  ans.pop_back();
				  break;
		}
		
	}
	return ans.empty();
}



int main()
{
	std::string str;
	std::cin>>str;
	bool ans = isValid(str);
	system("pause");
	return 0;
}





#endif