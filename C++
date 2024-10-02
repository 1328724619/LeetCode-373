class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> result;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for(int i = 0; i < nums1.size(); i++)
        {  
            heap.push({nums1[i] + nums2[0], 0});               //find the sum of the nums1 adding all the first numbers of nums2
        }

        while(k-- && !heap.empty())                            
        {
            int first = heap.top().first;                      //find the first number of the first set from the heap;
            int second = heap.top().second;                    // .....   second number .....

            result.push_back({first - nums2[second], nums2[second]});           //Ex: first = 3, second = 0; nums2[second] = nums2[0] = 2; 3 - 2 = (1, 2), then push into the result;
            heap.pop();

            if(second + 1< nums2.size())              //Ex: nums2.size() = 3; if 0 + 1 < 3, then go in the loop
            {
                heap.push({first - nums2[second] + nums2[second + 1], second + 1});     //Ex: nums2[second + 1] = nums2[0 + 1] = nums[1] = 4; second + 1 = 0 + 1; 3 - 2 + 4 = (5, 1), push this to the heap
            }
        }
        return result;
    }
};
