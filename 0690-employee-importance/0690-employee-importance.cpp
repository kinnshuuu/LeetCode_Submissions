/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    map<int,Employee*> mp;
    int solve(Employee* a)
    {
        int ans = a->importance;
        
        for(auto i:a->subordinates)
        {
            ans += solve(mp[i]);
        }
        
        return ans;
    }
public:
    
    int getImportance(vector<Employee*> arr, int id) {
        int n = arr.size();
        
        for(auto i:arr)
        {
            mp[i->id] = i;
        }
        
        for(auto i: arr)
        {
            if(i->id == id)
            {
                return solve(i);
            }
        }
        
        return 0;
    }
};