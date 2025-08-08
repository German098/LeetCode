#include <iostream>
#include <vector>

// https://cplusplus.com/reference/vector/vector/assign/
int searchInsert(std::vector<int>& nums, int target) {
	int i, j, i2, j2, newSize, acc;

	i = acc = 0;
	j = (int)nums.size() - 1;
	while(true){
		if(nums[j] < target)
			return j + 1;
		else if(nums[i] >= target)
			return i;

		newSize = (j - i + 1) / 2;
		i2 = newSize - 1 + i;
		j2 = i2 + 1;

		if(nums[i2] < target){
			i = j2;
			acc += i2;
		}
		else if(nums[j2] > target || nums[i2] > target){
			j = i2 - 1;
		}
		else if(nums[i2] == target){
			return i2 + acc;
		}
		else if(nums[j2] == target){
			return j2 + acc;
		}
		else{
			i = j2 + 1;
			acc += i2;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	std::vector<int> vec = {1,2,3,4,5,10};

	int res = searchInsert(vec, 2);
	std::cout<<"Res: "<<res<<std::endl;

	/*for(int i = 0; i < (int)vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<std::endl;*/

	std::vector<int> first;
  	std::vector<int> second;
  	std::vector<int> third;

  	first.push_back(0);
  	first.push_back(1);
  	first.push_back(2);
  	first.push_back(3);
  	first.push_back(4);
  	first.push_back(5);
  	first.push_back(6);

  	for(int i = 0; i < (int)first.size(); i++){
		std::cout<<first[i]<<" ";
  	}
	std::cout<<std::endl;

  	std::vector<int>::iterator it;
  	it = first.begin()+3;

  	second.assign(it, first.end());

  	for(int i = 0; i < (int)second.size(); i++)
		std::cout<<second[i]<<" ";
	std::cout<<std::endl;

  	third.assign(first.begin()+4, first.end());

  	for(int i = 0; i < (int)third.size(); i++)
		std::cout<<third[i]<<" ";
	std::cout<<std::endl;

	return 0;
}