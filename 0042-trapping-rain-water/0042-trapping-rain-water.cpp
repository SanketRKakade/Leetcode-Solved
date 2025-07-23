class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); 
        int water = 0;         
        vector<int> stack;     
        for (int right = 0; right < n; right++)
        {
            while (!stack.empty() && height[stack.back()] < height[right])
            {
                int mid = stack.back(); 
                stack.pop_back();       
                if (stack.empty())
                    break;
                int left = stack.back();                                                      
                int minHeight = min(height[right] - height[mid], height[left] - height[mid]);
                int width = right - left - 1;                                                 
                water += minHeight * width;                                                   
            }
            stack.push_back(right); 
        }
        return water;
    }
};