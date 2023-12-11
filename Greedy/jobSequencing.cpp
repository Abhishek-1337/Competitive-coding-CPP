struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool myCom(Job a, Job b){
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxi = -1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i].dead);
        }
        vector<int> slot(maxi+1, -1);
        sort(arr, arr+n, myCom);
        
        int countJobs = 0, profit = 0;
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(slot[j] == -1){
                    countJobs++;
                    profit += arr[i].profit;
                    slot[j] = i;
                    break;
                }
            }
        }
        vector<int> ans;
    ans.push_back(countJobs);
    ans.push_back(profit);
    return ans;
    } 
    
};