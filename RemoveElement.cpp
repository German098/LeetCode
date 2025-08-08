#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
	int i, j;

	if((int)nums.size() == 0)
		return 0;

	i = 0;
	j = (int)nums.size() - 1;
	while(i < j){
		if(nums[i] == val){
			while(nums[j] == val){
				if(j <= i) return 0;
				j--;
			}
			nums[i] = nums[j];
			nums[j--] = val;
		}

		i++;
	}
	
	return i + 1;	
}

int main(int argc, char const *argv[])
{
	int i;
	std::vector<int> vec = {1,1};	

	std::cout<<removeElement(vec, 1)<<std::endl;

	for(i = 0; i < (int)vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<std::endl;

	return 0;
}