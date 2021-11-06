    int can_jump2_levels(const vector<int>& nums,int pos){
        const int last_pos = nums.size()-1;
        if(pos==last_pos)
            return 0;
        int last_reachable = pos+nums[pos];
        if(last_reachable >= last_pos)
            return 1;
        int next = last_reachable;
        for(int i = pos+1 ; i <= pos+nums[pos] ; i++)
        {
            if(i+nums[i]>last_reachable){
                last_reachable = i+nums[i];
                next = i;
            }
            if(last_reachable >= last_pos){
                break;
            }
        }
        return 1+jumps(nums, next);
    }
    int jump(vector<int>& nums) 
    {
        return jumps(nums, 0);        
        
    }