#ifndef ASTAR_HPP 
#define ASTAR_HPP 

#include "Bfs.hpp"

class Astar : public Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);
};

#endif // ASTAR_HPP