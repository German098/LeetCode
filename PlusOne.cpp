#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
	
}

int main(int argc, char const *argv[])
{
	std::vector<int> res, vec = {4,3,2,1};
	
	res = plusOne(vec);

	for(int i = 0; i < (int)res.size(); i++)
		std::cout<<res[i]<<" ";
	std::cout<<std::endl;

	return 0;
}