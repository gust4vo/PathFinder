#ifndef BFS_HPP
#define BFS_HPP

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

class Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);
    static bool isValid(int x, int y, const std::vector<std::vector<double>>& map);

private:
    static void printPath(const std::vector<std::pair<int, int>>& path, double totalCost);
};

#endif // BFS_HPP       