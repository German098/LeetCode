#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
	bool leftWord;
	std::string::iterator i, i1, i2, j, j1;

	leftWord = false;
	i = s.begin();
	j = s.end() - 1;
	i1 = i2 = j1 = s.end();
	while(i < j){
		if(*i != ' '){
			if(i1 == s.end() || leftWord){
				i1 = i;
				i2 = s.end();
				leftWord = false;
			}
		}
		else{
			if(i1 != s.end() && !leftWord){
				i2 = i - 1;
				leftWord = true;
			}
		}

		if(*j != ' '){
			if(j1 == s.end())
				j1 = j;
		}
		else{
			if(j1 != s.end())
				return std::distance(j, j1);
		}

		i++;
		j--;
	}

	if(*i != ' ' && *j != ' '){
		if(i1 != s.end() && j1 != s.end() && i2 == s.end()){
			return std::distance(i1, j1) + 1;
		}
		else if(j1 == s.end() && i1 != s.end() && i2 == s.end()){
			return std::distance(i1, j) + 1;
		}
		else if(j1 == s.end() && i1 == s.end()){
			return std::distance(i, j) + 1;
		}
		else if(j1 != s.end()){
			return std::distance(j, j1) + 1;
		}
		else{
			return std::distance(i, j) + 1;
		}
	}
	else if(*i != ' ' && *j == ' '){
		if(j1 != s.end()){
			return std::distance(i, j1) + 1;
		}
	}
	else if(*i == ' ' && *j != ' '){
		if(j1 == s.end() && i1 != s.end()){
			return std::distance(i1, j) + 1;
		}
	}
	else{
		if(j1 != s.end()){
			return std::distance(j + 1, j1) + 1;
		}
		else if(i2 != s.end()){
			return std::distance(i1, i2) + 1;
		}
		else{
			return std::distance(i1, i);
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	std::string s = " abc   lmnop ";

	std::cout<<lengthOfLastWord(s)<<std::endl;

	return 0;
}
