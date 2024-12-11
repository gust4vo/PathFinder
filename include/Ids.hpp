#ifndef IDS_HPP 
#define IDS_HPP 

#include "Bfs.hpp"

class Ids : public Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);
private:
    static bool DLS(const std::vector<std::vector<double>>& map, const std::pair<int, int>& current, const std::pair<int, int>& goal,
              int depth, int maxDepth, std::vector<std::vector<std::pair<int, int>>>& parent, int& totalExplored,
              std::vector<std::pair<int, int>>& directions, std::vector<std::vector<int>>& depth_map);
};

#endif // IDS_HPP