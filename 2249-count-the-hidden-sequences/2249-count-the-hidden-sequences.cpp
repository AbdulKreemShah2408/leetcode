class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
      long long min_Value=0, max_Value=0;
      long long current=0;
      for(int diff:differences){
        current +=diff;
         min_Value=min(min_Value,current);
         max_Value=max(max_Value,current);
      }
      long long start=(long long) lower-min_Value;
      long long end=(long long) upper-max_Value;
      if(start>end){
        return 0;
         
      }
      return end-start+1;
    }
};