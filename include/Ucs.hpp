#ifndef UCS_HPP
#define UCS_HPP

#include "Bfs.hpp"

class Ucs : public Bfs {
public:
    static void findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal);
};


#endif // UCS_HPP
