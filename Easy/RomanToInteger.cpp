#include <iostream>
#include <map>
#include <string>

int romanToInt(std::string s) {
	int res;
	unsigned char lastNumber;
	std::string::reverse_iterator it;

	it = s.rbegin();
	res = 0;
	lastNumber = 'A';
	while(it != s.rend()){
		switch(*it){
	    	case 'I':
		    	if(!(lastNumber ^ 'V') || !(lastNumber ^ 'X'))
				    res -= 1;
		    	else
				    res += 1;
	    	break;
	    	case 'X':
		    	if(!(lastNumber ^ 'L') || !(lastNumber ^ 'C'))
				    res -= 10;
		    	else
				    res += 10;
	    	break;
	    	case 'C':
		    	if(!(lastNumber ^ 'D') || !(lastNumber ^ 'M'))
				    res -= 100;
		    	else
				    res += 100;
	    	break;
	    	case 'V':
		    	res += 5;
            break;
            case 'L':
		    	res += 50;
            break;
            case 'D':
		    	res += 500;
            break;
            default:
               	res += 1000;
		}

		lastNumber = *it;
		it++;
	}

    return res;
}

int main(int argc, char const *argv[])
{
	// MCDLXXVI
	std::cout<<romanToInt("MCDLXXVI")<<std::endl;

	return 0;
}