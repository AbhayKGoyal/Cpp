/*
--------------------Question Statement--------------------- 
Given N Cartesian Points in a 2D Plane, find the number of Right
 triangles such that the base or perpendicular is parallel to
the X or Y-axis.

Sample Input
N = 3
(0,0) (2,0) (0,1)
Sample Output
1

Another Example
Input
N = 5
(1 2)
(2 0)
(2 2)
(2 3)
(4 2)
Output
4

 */
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count_triangles(vector<pair<int,int> > &points){

    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for(auto p : points)
    {
        int x = p.first;
        int y = p.second;

        freq_x[x]++;
        freq_y[y]++;
    }

    int ans = 0;

    for(auto p : points)
    {
        int x = p.first;
        int y = p.second;
        int fx = freq_x[x];
        int fy = freq_y[y];
        ans += (fx - 1) * (fy - 1);
    }

    return ans;
}


int main() {
    
    int N;
    cin>>N;

    vector<pair<int,int> > points;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    cout<<count_triangles(points) <<endl;

    return 0;
}
