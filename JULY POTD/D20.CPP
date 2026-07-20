// LC 1260 = shift 2D grid;
#include<bits/stdc++.h>
using namespace std;
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
    int n = grid.size();
    int m = grid[0].size();
    vector<int>flat;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            flat.push_back(grid[i][j]);
        }
    }

    k = k % flat.size();
    reverse(flat.begin(),flat.end());
    reverse(flat.begin(), flat.begin() + k);
    reverse(flat.begin() + k , flat.end());

       vector<vector<int>> ans(n , vector<int>(m));
        int index = 0;
       for(int i = 0; i < n ; i++){
        for(int j = 0 ; j<m;j++){
            ans[i][j] = flat[index++];
        }
       }
       return ans;
                            
  }
  // time complexity = O(n* m);
  // space complexity = O( n* m );
  // approach name = Simulation + Array Flattening;
 int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    vector<vector<int>> ans = shiftGrid(grid, k);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}