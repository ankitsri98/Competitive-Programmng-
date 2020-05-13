void max_of_subarrays(int *arr, int n, int k){
    
    deque< int  > d(k);
    int i;
    //in dequeue elemnents are maintained in descending order
    //from front to rear
    for(i=0;i<k;i++){
        while(!d.empty() && arr[i]>=arr[d.back()]){
            d.pop_back();//removing useless elements of a particular window
        }
        d.push_back(i);
    }
    for(;i<=n;i++){
        cout<<arr[d.front()]<<" ";
        
        while(!d.empty() && d.front()<=i-k){//removing front front coz it has the most old elements
            d.pop_front();//removing the elements which r not in this new window
        }
        while(!d.empty() && arr[i]>=arr[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
        
    }
}
