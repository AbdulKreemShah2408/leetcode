#include <cmath>
#include <map>
#include <vector>

using namespace std;

class DetectSquares {
  
    map<pair<int, int>, int> pointsCount;
    vector<pair<int, int>> pointsList;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointsCount[{x, y}]++;
        
        pointsList.push_back({x, y});
    }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int totalWays = 0;

        for (auto& p : pointsList) {
            int x3 = p.first;
            int y3 = p.second;

        
            if (abs(x1 - x3) == 0 || abs(x1 - x3) != abs(y1 - y3)) {
                continue;
            }

            if (pointsCount.count({x1, y3}) && pointsCount.count({x3, y1})) {
                totalWays += pointsCount[{x1, y3}] * pointsCount[{x3, y1}];
            }
        }
        return totalWays;
    }
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */