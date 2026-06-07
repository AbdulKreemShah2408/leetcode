/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid,int rStart,int rEnd,int cStart,int cEnd){
        int firstVal=grid[rStart][cStart];
        for(int i=rStart;i<=rEnd;i++){
            for(int j=cStart;j<=cEnd;j++){
                if(grid[i][j] != firstVal){
                    return false;
                }
            }
        }
        return true;
    }
    Node* constructTree(vector<vector<int>>& grid,int rStart,int rEnd,int cStart,int cEnd){
        if(isAllSame(grid,rStart,rEnd,cStart,cEnd)){
            return new Node(grid[rStart][cStart],true);
        }
        int rMid=rStart+(rEnd-rStart)/2;
        int cMid=cStart+(cEnd-cStart)/2;
        Node* root=new Node(true,false);
        root->topLeft=constructTree(grid,rStart,rMid,cStart,cMid);
        root->topRight=constructTree(grid,rStart,rMid,cMid+1,cEnd);
        root->bottomLeft=constructTree(grid,rMid+1,rEnd,cStart,cMid);
        root->bottomRight=constructTree(grid,rMid+1,rEnd,cMid+1,cEnd);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return NULL;
        return constructTree(grid,0,n-1,0,n-1);
    }
};