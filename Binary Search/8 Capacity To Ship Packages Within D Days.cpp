class Solution {
public:
    
    bool isPossible(vector<int> &weights, int ship_capacity, int days){
        int n = weights.size();
        
        //we will try to put as much weight as possible every day
        //and if for any day, weight exceeds the ship capacity, then move to next day
        
        int used_days = 1, curr_day_wt = 0;
        
        for(int i = 0; i < n; i++){
            curr_day_wt += weights[i];
            
            //edge case 
            if(weights[i] > ship_capacity) return 0;
            
            if(curr_day_wt > ship_capacity){
                used_days++;
                curr_day_wt = weights[i];
            }
            
            if(used_days > days) return 0;
        }
        
        return 1;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = 0;
        int hi = accumulate(weights.begin(),weights.end(),0);
        
        int ans = INT_MAX;
        
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(isPossible(weights,mid,days)){
                ans = min(ans,mid);
                //go left
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};