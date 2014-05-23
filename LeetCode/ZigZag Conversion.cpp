#include "utils.h"

#ifdef ZigZagConversion

#include <iostream>
#include <vector>
#include <string>
std::string convert(std::string s, int nRows)
{
	if (s.size() <= 1 || nRows == 1)
	{
		return s;
	}
	std::string ans;

	int totalCol = (s.size() + 2 * nRows - 1)/(2 * nRows - 2) * (nRows - 1);
	char **rct = new char* [nRows];
	for (int i = 0; i < nRows; i++)
	{
		rct[i] = new char[totalCol];
		for (int j = 0; j < totalCol; j++)
		{
			rct[i][j] = ' ';
		}
	}	
	int col = 0;
	for (int i = 0; i < s.size(); i++)
	{
		/*int col = i / (2 * nRows - 2);*/
		if (i % (2 * nRows - 2) == 0 )
		{
			int R = 0;
			while(i < s.size() && R < nRows)
			{
				//第col列先赋值
				rct[R][col] = s[i];
				R++;
				i = i++;
				//对第col++列赋值
				if (R == nRows - 1)
				{
					while(R > 0 && i < s.size())
					{	
						rct[R][col] = s[i];
						i = i++;
						R--;
						col++;
					}
				}
				//R又回到0,跳出
				if (R == 0)
				{
					i--;
					break;
				}
			}
		}
	}
	std::string ans;
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < totalCol; j++)
		{
			if (rct[i][j] != ' ')
			{
				ans += rct[i][j];
			}
		}
	}
	for (int i = 0; i < nRows; i++)
	{
		delete[] rct[i];
		rct[i] = NULL;
	}
	delete[] rct;
	rct = NULL;
	return ans;
}

int main()
{
	int nRows;
	std::cin>>nRows;
	std::string s("PAYPALISHIRING");
	/*std::cin>>s;*/
	std::string ans = convert(s,nRows);
	std::cout<<ans;
	system("pause");
	return 0;





}



#endif