#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(int x) {
	bool res;
	long long l;
	int r, div;

	if(x < 0) return false;

	res = true;
	r = 10;
	div = 1;
	l = 1;
	while(x/(l*10) != 0)
		l *= 10; 

	while(r <= l){
		if((x/l)%10 != (x%r)/div){
			res = false;
			break;
		}
		r *= 10;
		div *= 10;
		l /= 10;
	}

	return res;
}

int main(int argc, char const *argv[]) {
	int x = -121;
	int p = 1000000000;
	std::cout<<(x%1000)/100<<std::endl;

	std::cout<<isPalindrome(x)<<std::endl;

	return 0;
}