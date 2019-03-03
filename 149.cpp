#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define LL long long

using namespace std;

struct Point {
 int x;
 int y;
 Point() : x(0), y(0) {}
 Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    struct cmp{
        bool operator()(const Point &a, const Point &b)
        {
            return a.x<b.x||(a.x==b.x&&a.y<b.y);
        }
    };
    int maxPoints(vector<Point>& points) {
        if(points.empty())return 0;
        map<Point,int,cmp> Map;
        int Size=points.size();
        int ans=1;
        int coinside;
        for(int i=0;i<Size;i++)
        {
            if(Size-i<=ans)break;
            Map.clear();
            coinside=1;
            for(int j=i+1;j<Size;j++)
            {
                int dx=points[i].x-points[j].x,dy=points[i].y-points[j].y;
                if(!(dx|dy))
                {
                    coinside++;
                    continue;
                }
                if(!dx)Map[Point(0,1)]++;
                else if(!dy)Map[Point(1,0)]++;
                else
                {
                    int k=gcd(dx,dy);
                    Map[Point(dx/k,dy/k)]++;
                }
            }
            ans=max(ans,coinside);
            for(map<Point,int,cmp>::iterator it=Map.begin();it!=Map.end();it++)
            {
                ans=max(ans,it->second+coinside);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
