#include "utils.h"

#ifdef IntegertoRoman

#include <iostream>
#include <vector>
#include <string>

char convert(char s, int i)
{
	std::string table = "IVXLCDM";
	if (s == 'I')  return table[i];
	if (s == 'V')  return table[i + 1];
	if (s == 'X')  return table[i + 2];
	
}


std::string intToRoman(int num)
{
	std::string str[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
 	std::vector<std::string> table;
	std::string ans;
	for (int i = 0; i < 10; i++)
	{
		table.push_back(str[i]);
	}
	for (int i = 0; num; i += 2, num /= 10)
	{
		int x = num % 10;
		std::string temp = table[x];
		for (int j = 0; j < temp.size(); j++)
		{
			temp[j] = convert(temp[j], i);
		}
		ans = temp + ans; //Ë³Ðò²»ÄÜµßµ¹
	}
	return ans;
}

int main()
{
	int value;
	std::cin>>value;
	std::string ans = intToRoman(value);
	std::cout<<ans;
	system("pause");
	return 0;
}


#endif
