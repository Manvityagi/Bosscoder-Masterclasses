class Solution
{
public:
    
bool check(vector<int> &pos, int numOfBalls, int currGap){
    int prevPos = 0;
    int balls_placed = 1;  
    for(int i = 1; i < pos.size(); i++){
        if(pos[i] - pos[prevPos] >= currGap){
            prevPos = i; 
            balls_placed++; 
        }
    }
    if(balls_placed < numOfBalls) return false;
    return true;
}

    int maxDistance(vector<int> &pos, int balls)
    {
        int n = pos.size();
        sort(pos.begin(), pos.end());

        int lo = 0, hi = pos[n - 1] - pos[0]; //10^9

        int ans = 0;

        while (lo <= hi)
        {
            int mid_force = (lo + hi) >> 1;
            if (check(pos, balls, mid_force))
            {
                ans = max(ans, mid_force);
                lo = mid_force + 1; //F = 3, we will try to find for F = 4
            }
            else
            {
                hi = mid_force - 1;
            }
        }
        return ans;
    }
};