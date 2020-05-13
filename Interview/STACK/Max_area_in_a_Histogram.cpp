long getMaxArea(long long arr[], int n){
    
    ll tp,max_area=-1,cmax_area=0;
    ll i=0;
    stack< ll  > s;
    while(i<n){
        
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }
        else{
            tp=s.top();
            s.pop();
            if(s.empty()){
                cmax_area= arr[tp]*i;
            }
            // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index'
            else{
                cmax_area= arr[tp]*(i-s.top()-1);
               // cout<<i<<" -----  " <<s.top()<<endl;
            }
            
            if(max_area<cmax_area){
                max_area=cmax_area;
            }
            //cout<<i<< "       "<<cmax_area<<endl;
        }
    }
    /*while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }*/
    
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar
    while(!s.empty()){
        tp=s.top(),s.pop();
        if(s.empty()){
            cmax_area= arr[tp]*i;
            }
            else{
                cmax_area= arr[tp]*(i-s.top()-1);
               // cout<<i<<" -----  " <<s.top()<<endl;
            }
            if(max_area<cmax_area){
                max_area=cmax_area;
            }
    }
    return max_area;
}
