#ifndef GREEDY_HPP 
#define GREEDY_HPP 

#include "Bfs.hpp"

class Greedy : public Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);
};

#endif // GREEDY_HPP