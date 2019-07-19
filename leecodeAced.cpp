
//2.1.1 Remove Duplicates from sorted array

#include <iostream>
#include <vector>
#include <algorithm>

int removeDuplicates(std::vector<int>& nums)
{
   return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

int main()
{
    std::vector<int> A = {1,1,2,2};
    int i  = removeDuplicates(A);
    std::cout<<i<<"\n";
    for(auto i : A)
    {std::cout<<i<<" ";}
}






