#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	bool ok;
	int i, j, i1, j1, llimit, rlimit;

	ok = false; 
	llimit = 0;
	rlimit = (int)nums.size() - 1;
	i = llimit;
	j = rlimit;
	while(!ok && i < j){
		i1 = i + 1;
		j1 = j - 1;
		while(i1 <= rlimit && j1 >= llimit){
			std::cout<<"? "<<nums[i] + nums[i1]<<" == "<<target<<std::endl;
			if((nums[i] + nums[i1]) == target){
				j = i1;
				std::cout<<i<<" - "<<j<<std::endl;
				ok = true;
				break;
			}
			std::cout<<"? "<<nums[j] + nums[j1]<<" == "<<target<<std::endl;
			if((nums[j] + nums[j1]) == target){
				i = j1;
				std::cout<<i<<" -- "<<j<<std::endl;
				ok = true;
				break;
			}

			std::cout<<"-> "<<i1<<" "<<j1<<std::endl;
			i1++;
			j1--;
			std::cout<<"->> "<<i1<<" "<<j1<<std::endl;
		}
		if(!ok){
			i = ++llimit;
			j = --rlimit;
		}
	}

	return {i, j};
}

int main(int argc, char const *argv[])
{
	std::vector<int> vec = {2, 8, 1, 15};
	std::vector<int> res;

	res = twoSum(vec, 9);

	std::cout<<res[0]<<" "<<res[1]<<std::endl;

	return 0;
}