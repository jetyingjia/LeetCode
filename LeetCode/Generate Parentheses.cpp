#include "utils.h"

#ifdef GenerateParentheses
#include <iostream>
#include <vector>
#include <string>

std::string tmp;
std::vector<std::string> ans;

void DFS(int left, int right, int n)
{
	if(left == right && left == n)
	{
		ans.push_back(tmp);
		return;
	}
	if(left < n)
	{
		tmp[left + right] = '(';
		DFS(left + 1, right, n);
	}
	if(right < left)
	{
		tmp[left + right] = ')';
		DFS(left, right + 1, n);
	}	
}
std::vector<std::string> generateParenthesis(int n)
{
	tmp.resize(n << 1);
	DFS(0, 0, n);
	return ans;
}

int main()
{
	int n;
	std::cin>>n;
	std::vector<std::string> ans = generateParenthesis(n);
	system("pause");
	return 0;

}



#endif