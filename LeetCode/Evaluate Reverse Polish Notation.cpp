#include "utils.h"

#ifdef EvaluateReversePolishNotation

#include <iostream>
#include <vector>
#include <string>

int stringToDigit(std::string s)
{
	bool state = true;
	int ans = 0;
	int multi = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='-')
		{
			state = false;
		}
		else 
		{
			multi = 10;
			ans = multi * ans + s[i] - '0';
		}
	}
	if (!state)
	{
		return -ans;
	}
	return ans;
}



int evalRPN(std::vector<std::string> &tokens) 
{
	std::vector<int> rct;
	for (int i = 0; i < tokens.size(); i++)
	{
		int temp;
		if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
		{
			temp = stringToDigit(tokens[i]);
			rct.push_back(temp);
			//temp2 = stringToDigit(tokens[i]);
		}
		else if (tokens[i] == "+")
		{
			int temp1 = rct[rct.size() - 1];
			rct.pop_back();
			int temp2 = rct[rct.size() - 1];
			rct.pop_back();
			rct.push_back(temp1 + temp2);
		}
		else if (tokens[i] == "-")
		{
			int temp1 = rct[rct.size() - 1];
			rct.pop_back();
			int temp2 = rct[rct.size() - 1];
			rct.pop_back();
			rct.push_back(temp1 - temp2);
		}
		else if (tokens[i] == "*")
		{
			int temp1 = rct[rct.size() - 1];
			rct.pop_back();
			int temp2 = rct[rct.size() - 1];
			rct.pop_back();
			rct.push_back(temp1 * temp2);
		}
		else if (tokens[i] == "/")
		{
			int temp1 = rct[rct.size() - 1];
			rct.pop_back();
			int temp2 = rct[rct.size() - 1];
			rct.pop_back();
			rct.push_back(temp2 / temp1);
		}
		else
		{
			;
		}
	}
	return rct[0];
}
int main()
{
	int N;
	std::cin>>N;
	std::vector<std::string> tokens;
	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin>>temp;
		tokens.push_back(temp);
	}

	int ans = evalRPN(tokens);
	std::cout<<ans;
	system("pause");
	


}






#endif