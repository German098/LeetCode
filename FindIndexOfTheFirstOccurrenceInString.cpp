#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
	int i;

	if(haystack.size() < needle.size()) return -1;

	i = 0;
	while(i <= (int)haystack.size() - (int)needle.size()){
		if(haystack.substr(i, needle.size()) == needle)
			return i;
		i++;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	std::string s1, s2;

	s1 = "leetcode";
	s2 = "leeto";
	std::cout<<strStr(s1, s2)<<std::endl;

	return 0;
}