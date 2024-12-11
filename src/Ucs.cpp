#include "Ucs.hpp"

void Ucs::findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal)
{
    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<std::pair<double, std::pair<int, int>>>> pq;
    
    std::vector<std::vector<bool>> visited (map.size(), std::vector<bool>(map[0].size(), false));
    std::vector<std::vector<double>> cost (map.size(), std::vector<double>(map[0].size(), std::numeric_limits<double>::infinity()));
    std::vector<std::vector<std::pair<int, int>>> parent (map.size(), std::vector<std::pair<int, int>>(map[0].size(), {-1, -1}));

    pq.push({0, start});
    cost[start.second][start.first] = 0;

    std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int total_explored = 0;
    while (!pq.empty()) {
        std::pair<int, int> current = pq.top().second;
        double currentCost = pq.top().first;
        
        pq.pop();

        if (visited[current.second][current.first]) continue;
        total_explored++;

        if (current == goal) {
            std::vector<std::pair<int, int>> path;
            double totalCost = 0;

            while (current != start) {
                path.push_back(current);
                totalCost += map[current.second][current.first];
                current = parent[current.second][current.first];
            }

            path.push_back(start);
            std::cout << "Explored nodes: " << total_explored << std::endl;
            printPath(path, cost[goal.second][goal.first]);
            return;
        }

        visited[current.second][current.first] = true;

        for (const std::pair<int, int>& direction : directions) {
            int x = current.first + direction.first;
            int y = current.second + direction.second;

            if (isValid(x, y, map)) {
                double newCost = cost[current.second][current.first] + map[y][x];
                if (newCost < cost[y][x]) {
                    cost[y][x] = newCost;
                    pq.push({newCost, {x, y}});
                    parent[y][x] = current;
                }
            }
        }
    }

    std::cerr << "No path found" << std::endl;
}

