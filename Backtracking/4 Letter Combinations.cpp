/*
    TC - N * 4^n
*/
class Solution {
public:
    string dic[10] = {{""},{""},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    vector<string> ans;
   
    void helper(string &digits, int index, string curr){
           if(index >= digits.size()){
               ans.push_back(curr);
               return;
           } 

            string current = dic[digits[index]-'0'];
            for(int j = 0; j < current.size(); j++){ 
                curr.push_back(current[j]);
                helper(digits,index+1,curr);
                curr.pop_back();
            
        }
    }
   
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){                
                 return ans;
         }
           string curr = {};
           helper(digits,0,curr);
           return ans;
    }
};