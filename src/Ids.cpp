#include "Ids.hpp"

bool Ids::DLS(const std::vector<std::vector<double>>& map, const std::pair<int, int>& current, const std::pair<int, int>& goal,
              int depth, int maxDepth, std::vector<std::vector<std::pair<int, int>>>& parent, int& total_explored, 
              std::vector<std::pair<int, int>>& directions, std::vector<std::vector<int>>& depth_map) {
    
    total_explored++;

    if (current == goal)
        return true; 

    if (depth >= maxDepth)
        return false;
    
    for (const auto& direction : directions) {
        int x = current.first + direction.first;
        int y = current.second + direction.second;

        if (isValid(x, y, map)) {
            if(depth_map[y][x] == -1 || depth+1 <= depth_map[y][x]) {
                parent[y][x] = current;
                depth_map[y][x] = depth+1;
                if (DLS(map, {x, y}, goal, depth + 1, maxDepth, parent, total_explored, directions, depth_map)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Ids::findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal) {
    int total_explored = 0;

    std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    std::vector<std::vector<int>> depth_map (map.size(), std::vector<int>(map[0].size(), -1));
    std::vector<std::vector<std::pair<int, int>>> parent (map.size(), std::vector<std::pair<int, int>>(map[0].size(), {-1, -1}));

    for (int maxDepth = abs(goal.first-start.first)+abs(goal.second-start.second); maxDepth < 100000; maxDepth++) {
        if (DLS(map, start, goal, 0, maxDepth, parent, total_explored, directions, depth_map)) {
            double totalCost = 0;
            
            std::vector<std::pair<int, int>> path;
            std::pair<int, int> current = goal;

            while (current != start) {
                totalCost += map[current.second][current.first];
                path.push_back(current);
                current = parent[current.second][current.first];
            }
            path.push_back(start);

            std::cout << "Explored nodes: " << total_explored << std::endl;
            printPath(path, totalCost);
            return;
        }
    }

    std::cerr << "No path found" << std::endl;
}



