class Solution {
public:

    vector<int> nextSmallerElement (vector<int> arr){
        vector<int> v (arr.size());
        stack<int>st;
        st.push(-1);
        
        for(int i = arr.size()-1 ; i>=0 ; i--){
            int ele = arr[i];
            while(st.top()!= -1 && arr[st.top()]>=ele){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> prevSmallerElement(vector<int> arr){
        vector<int> v(arr.size());
        stack<int>st;
        st.push(-1);
        for(int i = 0 ; i<arr.size() ; i++){
            int ele = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=ele){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev = prevSmallerElement(heights);
        vector<int>next = nextSmallerElement(heights);

        for(int i=0 ; i<next.size() ; i++){
          if(next[i]== -1){
            next[i] = next.size();
          }
        }

        vector<int> area(next.size());
        for(int i=0 ; i<next.size() ; i++){
            int width = next[i] - prev[i] -1 ;
            int length = heights[i];
            int currArea = width * length;
            area[i]=currArea;
        }

        int maxArea = INT_MIN;
        for (int i=0 ; i<area.size() ; i++){
            maxArea = max(maxArea , area[i]);
        }

        return maxArea;
    }
};