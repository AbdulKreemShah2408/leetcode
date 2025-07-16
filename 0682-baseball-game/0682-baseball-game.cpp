class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int score=0;
        for(auto& op:operations){
            if(op=="C"){
                score -=s.top();
                s.pop();
            }
            else if(op=="D"){
                int val=2*s.top();
                score +=val;
                s.push(val);

            }
            else if(op=="+"){
                int top1=s.top();
                s.pop();
                int top2=s.top();
                int sum=top1+top2;
                score +=sum;
                s.push(top1);
                s.push(sum);

            }
            else{
                int val=stoi(op);
                score +=val;
                s.push(val);
            }
        }
        return score;
    }
};