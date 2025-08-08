#include <iostream>
#include <string>
#include <stack>

bool validParentheses(std::string s){
	int i;
	std::stack<unsigned char> s_chars;

	s_chars.push(s[0]);
	i = 1;
	while(i < (int)s.size()){
		if(s_chars.empty()) 
			s_chars.push(s[i]);
		else
			switch(s_chars.top()){
				case '(':
					if(s[i] == ')') s_chars.pop();
					else if(s[i] == ']' || s[i] == '}')
						return false;
					else
						s_chars.push(s[i]);
				break;
				case '[':
					if(s[i] == ']') s_chars.pop();
					else if(s[i] == ')' || s[i] == '}')
						return false;
					else
						s_chars.push(s[i]);
				break;
				default:
					if(s[i] == '}') s_chars.pop();
					else if(s[i] == ']' || s[i] == ')')
						return false;
					else
						s_chars.push(s[i]);
				break;
			}

		i++;
	}

	return s_chars.empty();
}

int main(int argc, char const *argv[])
{
	std::cout<<validParentheses("(([]){})")<<std::endl;

	return 0;
}