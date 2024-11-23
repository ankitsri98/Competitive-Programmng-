class Solution {
    int floor(int[] arr, int x) {
        int r = arr.length-1;
        int l = 0;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (arr[mid]<=x) {
                l = mid+1;
                ans = mid;
            } else {
                r = mid-1;
            }
        }
        return ans == -1 ? -1 : arr[ans];
    }
    int ceil(int[] arr, int x) {
        int r = arr.length-1;
        int l = 0;
        int ans = arr.length;
        while(l<=r) {
            int mid = (l+r)/2;
            if (arr[mid]>=x) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans == arr.length ? -1 : arr[ans];
    }
    public int[] getFloorAndCeil(int x, int[] arr) {
        Arrays.sort(arr);
        int[] ans = new int[2];
        ans[0] = floor(arr,x);
        ans[1] = ceil(arr,x);
        return ans;
    }
}
