#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1548;

/* Example 1:
Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]],
names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"]
which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has
edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has
edit distance = 1 with targetPath.
*/
tuple<int, vector<vector<int>>, vector<string>,
      vector<string>, vector<int>>
testFixture1()
{
  auto roads = vector<vector<int>>{
      {0, 2}, {0, 3}, {1, 2}, {1, 3}, {1, 4}, {2, 4}};
  auto names = vector<string>{"ATL", "PEK", "LAX", "DXB", "HND"};
  auto target = vector<string>{"ATL", "DXB", "HND", "LAX"};
  auto output = vector<int>{0, 2, 4, 2};

  return make_tuple(5, roads, names, target, output);
}

/* Example 2:
Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]],
names = ["ATL","PEK","LAX","DXB"],
targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.
*/
tuple<int, vector<vector<int>>, vector<string>,
      vector<string>, vector<int>>
testFixture2()
{
  auto roads = vector<vector<int>>{
      {1, 0}, {2, 0}, {3, 0}, {2, 1}, {3, 1}, {3, 2}};
  auto names = vector<string>{"ATL", "PEK", "LAX", "DXB"};
  auto target = vector<string>{"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX"};
  auto output = vector<int>{0, 1, 0, 1, 0, 1, 0, 1};

  return make_tuple(4, roads, names, target, output);
}

/*Example 3
Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]],
names = ["ATL","PEK","LAX","ATL","DXB","HND"],
targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with
edit distance = 0 with targetPath.
It’s equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
*/
tuple<int, vector<vector<int>>, vector<string>,
      vector<string>, vector<int>>
testFixture3()
{
  auto roads = vector<vector<int>>{
      {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
  auto names = vector<string>{"ATL", "PEK", "LAX", "ATL", "DXB", "HND"};
  auto target = vector<string>{"ATL", "DXB", "HND", "DXB", "ATL", "LAX", "PEK"};
  auto output = vector<int>{3, 4, 5, 4, 3, 2, 1};

  return make_tuple(6, roads, names, target, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<4>(f)) << endl;
  auto result = Solution::find(get<0>(f), get<1>(f), get<2>(f), get<3>(f));
  cout << "result: " << Util::toString(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << Util::toString(get<4>(f)) << endl;
  auto result = Solution::find(get<0>(f), get<1>(f), get<2>(f), get<3>(f));
  cout << "result: " << Util::toString(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << Util::toString(get<4>(f)) << endl;
  auto result = Solution::find(get<0>(f), get<1>(f), get<2>(f), get<3>(f));
  cout << "result: " << Util::toString(result) << endl;
}

void testSwap()
{
  auto v1 = vector<int>{1, 2, 3, 4};
  auto v2 = vector<int>{5, 6, 7};
  swap(v1, v2);

  cout << "v1:" << Util::toString(v1) << endl;
  cout << "v2:" << Util::toString(v2) << endl;
}

main()
{
  test1();
  test2();
  test3();
  //  testSwap();
  return 0;
}