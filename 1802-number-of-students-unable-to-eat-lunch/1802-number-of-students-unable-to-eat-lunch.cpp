class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0=0, count1=0;
        for(int s:students){
            if(s==0){
              count0++;
            }
            else{
                count1++;
            }
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0){
                if(count0==0) return sandwiches.size()-i;
                count0--;
            }
            else{
                if(count1==0) return sandwiches.size()-i;
                count1--;
            }
        }
        return 0;
    }
};