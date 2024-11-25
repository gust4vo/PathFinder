#include "Bfs.hpp"

void Bfs::findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal)
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
    std::vector<std::vector<std::pair<int, int>>> parent(map.size(), std::vector<std::pair<int, int>>(map[0].size(), {-1, -1}));

    q.push(start);
    visited[start.second][start.first] = true;

    std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();

        if (current == goal) {
            std::vector<std::pair<int, int>> path;
            double totalCost = 0;

            while (current != start) {
                path.push_back(current);
                totalCost += map[current.second][current.first];
                current = parent[current.second][current.first];
            }

            path.push_back(start);
            printPath(path, totalCost);
            return;
        }

        for (const std::pair<int, int>& direction : directions) {
            int x = current.first + direction.first;
            int y = current.second + direction.second;

            if (isValid(x, y, map) && !visited[y][x]) {
                q.push({x, y});
                visited[y][x] = true;
                parent[y][x] = current;
            }
        }
    }

    std::cerr << "No path found" << std::endl;
}

bool Bfs::isValid(int x, int y, const std::vector<std::vector<double>>& map) {
    return x >= 0 && x < (int)map[0].size() && y >= 0 && y < (int)map.size() && map[y][x] != std::numeric_limits<double>::max();
}

void Bfs::printPath(const std::vector<std::pair<int, int>>& path, double totalCost) {
    std::cout << totalCost << " ";
    for (int i = (int) path.size() -1; i >= 0; i--) {
        std::cout << "(" << path[i].first << "," << path[i].second << ") ";
    }
    std::cout << std::endl;
}

