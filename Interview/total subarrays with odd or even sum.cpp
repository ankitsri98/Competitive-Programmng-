/*Firstly if a number is even then it would just increase even number of subarrays by 1 because the number itself becomes the new subarray which is added in even total. Even +Even=Even
The odd sum subarrays remain constant as the sum still remains constant. Odd+Even=Odd
But when the new number is odd then comes the catch.Actually it makes all the even summed subarrays odd summed and odd summed to even summed.At the end since the number is odd it increases one odd subarray also.
Odd+Odd=Even
Even +Odd=Odd
Due to the above rules we need to swap odd and even then increase odd by 1.

At the end we need to remember to take the modulus for large testcases.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {    
      int odd=0,even=0,answer=0,modulus=(int)1e9+7;
        for(auto number:arr){
            if(number%2==0)even++;
            else{
                swap(odd,even);//considering the cumulative sums
                odd++;
            }
            answer=(answer%modulus+odd%modulus)%modulus;
        }
        return answer;
    }
};
