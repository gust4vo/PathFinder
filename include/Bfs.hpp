#ifndef BFS_HPP
#define BFS_HPP

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

class Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);

protected:
    static bool isValid(int x, int y, const std::vector<std::vector<double>>& map);
    static void printPath(const std::vector<std::pair<int, int>>& path, double totalCost);
};

#endif // BFS_HPP       