#include<vector>
#include<iostream>
using namespace std;

void twosum(vector<int>& nums, int target)
{
	int i(0), j(0);
	for (i = 0; i < nums.size() - 1; i++)
	{
		for (j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				cout << "(" << i << "," << j << ")" << endl;
			}
		}

	}
	cout << "(" << i << "," << j << ")" << endl;

}

int main()
{
	const int k = 4;
	int target;
	cout << "ÊäÈëtargetµÄÖµ£º";
	cin >> target;

	vector<int> nums{2,7,11,15};
	twosum(nums, target);
	return 0;
}