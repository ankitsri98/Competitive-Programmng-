class Solution {
public:
    int trap(vector<int>& height) {
        int prevMaxHeight, result = 0, curResult = 0, peakIndex;
        
        prevMaxHeight = 0;
        
        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] < height[prevMaxHeight])
            {
                curResult += (height[prevMaxHeight] - height[i]);
            }
            
            else
            {
                result += curResult;
                curResult = 0;
                prevMaxHeight = i;
            }
        }
        
        peakIndex = prevMaxHeight;
        prevMaxHeight = height.size() - 1;
        curResult = 0;
        
        for(int i = height.size() - 2; i >= peakIndex; i--)
        {
           if(height[i] < height[prevMaxHeight])
            {
                curResult += (height[prevMaxHeight] - height[i]);
            }
            
            else
            {
                result += curResult;
                curResult = 0;
                prevMaxHeight = i;
            }
        }
        
        return result;
    }
};
