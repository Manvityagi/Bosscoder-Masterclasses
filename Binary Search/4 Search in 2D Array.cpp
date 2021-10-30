//Approach 1 - O(nlogm)
class Solution
{
    public:
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        for(int i = 0; i < n; i++){
            if(binary_search(matrix[i].begin(),matrix[i].end(),x)) return true;
        }
        return false;
    }
};

//Approach 2 - O(n + m)
class Solution
{
    public:
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
         int row = 0, col = m-1;
         
         while(row < n && col >= 0){
             int curr = matrix[row][col];
             
             if(x == curr) return 1;
             
             if(x > curr) //move down
                 row++;
              else  //move left
                col--;
        }
        return 0;
    }
};