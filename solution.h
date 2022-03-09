#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol1548
{

  class Solution
  {
  private:
  public:
    static vector<int> find(int n, vector<vector<int>> &roads,
                            vector<string> &names, vector<string> &targetPath);
  };
}
#endif