class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        //first array should me of smaller length
        if(m<n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int low=0,high=n;
        while(low<=high){
            //cout<<low<<"   ///   "<<high<<endl;
            //finding the pos. of partition in both the arrays
            int par_x=low+ (high-low)/2;
            int par_y=((n+m+1)/2)-par_x;
            
            //cout<<par_x<<" "<<par_y<<endl;
            
            //now handling base cases
            //the boundaries of these to partion will have max and min values 
            //calc. both for the both the arrays
            int max_left_x= (par_x==0) ? INT_MIN: nums1[par_x-1];
            int min_right_x= (par_x==n) ? INT_MAX: nums1[par_x];
            
            int max_left_y= (par_y==0) ? INT_MIN: nums2[par_y-1];
            int min_right_y= (par_y==m) ? INT_MAX: nums2[par_y];
            
            //now checking if left partition is smaller than right partion coz thats what median does
            if(max_left_x <= min_right_y  && max_left_y<=min_right_x){
                //cond. satisfies
                //return median acc. to size
                
                if((n+m)%2==0){
                    return (double)((max(max_left_x,max_left_y)+min(min_right_x,min_right_y))/2.0);
                }
                else{
                    return (double)(max(max_left_x,max_left_y));
                }
            }
            else if(max_left_x > min_right_y){
                high=par_x-1;
            }
            else if(max_left_y > min_right_x){
                low=par_x+1;
            }
        }
        return 0;
    }
};
