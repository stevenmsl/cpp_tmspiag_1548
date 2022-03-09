#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1548;
using namespace std;

/*takeaways
  - let say if the target path is ["ATL","DXB","HND","LAX"], we can
    think of this as how we can come up with a path that has min
    edit distance by walking 4 steps in the graph (cities connected by roads).
  - we must exhaust all the possible 4-step paths and pick one with the
    min edit distance

  - DP design
   - in each step record the min edit distance for each city when it is
     at the endpoint of the path.
   - use example 1, and we are at step 2 (finding paths with length 2)
   - target as rows, and each city as columns
               ATL   PEK   LAX   DXB   HND
      ATL        0     1     1     1     1
      DBX        2     2     1     0     2

      Path
      - end with ATL : LAX->ATL, edit distance 2, path length 2,
                       so dp[1][0] = 2.
      - end with LAX: ATL->LAX, edit distance 1, path length 2,
                      PEK->LAX (x), we don't pick this one as
                                    its edit distance is 2

*/
vector<int> Solution::find(int n, vector<vector<int>> &roads,
                           vector<string> &names, vector<string> &targetPath)
{
  vector<vector<int>> g(n);
  for (auto &r : roads)
    g[r[0]].push_back(r[1]),
        g[r[1]].push_back(r[0]);

  const int m = targetPath.size();
  /* dp[i][j]
     - record the min edit distance after walking i steps
       in the graph and the path ends up in city j
  */
  vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
  /*
    - path1[i] means the path will end up in city i
      after taking "path[i].size()" steps in the graph
    - only path with min edit distance will be recorded
      - ATL-LAX (v), edit distance 1
        - this one will be picked
      - PEK-LAX (x), edit distance 2
    - when the path is LAX->ATL, the path1[0]=[2,0]. The
      very last element has to be 0 per the definition.
    - if dp[2][0] = 2, that means LAX->ATL has two edit
      distances from the target path: ATL->DXB
  */
  vector<vector<int>> path1(n);
  /*
    - path2 is a step ahead of path1
    - if path1[i].size()=2, then path2[i].size=3
    - we calculate the 3-step paths in path2
      based on the work done in path1 as path1
      has been optimized for the 2-step paths
      for example.
  */
  vector<vector<int>> path2(n);
  for (int i = 0; i < n; ++i)
    dp[0][i] = (names[i] != targetPath[0]),
    path1[i].push_back(i);

  int minDist = INT_MAX, minIndx = -1;
  for (int k = 1; k < m; ++k)
  {
    for (int i = 0; i < n; ++i)
    {
      if (dp[k - 1][i] == INT_MAX)
        continue;
      for (int j : g[i])
      {
        /*record the path only if the edit distance is smaller */
        if (dp[k][j] > dp[k - 1][i] + (names[j] != targetPath[k]))
        {
          dp[k][j] = dp[k - 1][i] + (names[j] != targetPath[k]);
          /* the path with one-less step that stops at city i */
          path2[j] = path1[i];
          /* extend the path to city j */
          path2[j].push_back(j);
        }
      }
    }
    swap(path1, path2);
  }

  /* find a path of length m that has the smallest edit distance  */
  for (int i = 0; i < n; i++)
    if (minDist > dp[m - 1][i])
      minDist = dp[m - 1][i],
      minIndx = i;

  return path1[minIndx];
}