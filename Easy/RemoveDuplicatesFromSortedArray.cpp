#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
	int i, k;

	if((int)nums.size() == 1)
        return 1;

    i = 1;
    k = 0;
    while(nums[i - 1] != nums.back() && i < (int)nums.size()){
        if(nums[i - 1] != nums[i])
            nums[k++] = nums[i - 1];
        i++;
    }
    nums[k++] = nums.back();

    return k;
}

int main(int argc, char const *argv[])
{
	int i;
	std::vector<int> vec = {0,0,1,1,1,2,2,3,3,4};	

	std::cout<<removeDuplicates(vec)<<std::endl;

	for(i = 0; i < (int)vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<std::endl;

	return 0;
}