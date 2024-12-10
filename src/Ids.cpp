#include "Ids.hpp"

void Ids::findPath(const std::vector<std::vector<double>>& map, const std::pair<int, int>& start, const std::pair<int, int>& goal)
{
    for (int maxDepth = 0; maxDepth < 100000; maxDepth++) {
        std::vector<std::vector<double>> cost(map.size(), std::vector<double>(map[0].size(), std::numeric_limits<double>::infinity()));
        std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
        std::vector<std::vector<std::pair<int, int>>> parent(map.size(), std::vector<std::pair<int, int>>(map[0].size(), {-1, -1}));

        cost[start.second][start.first] = 0;

        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        std::stack<std::pair<std::pair<int, int>, int>> stack;
        stack.push({start, 0}); // Add current depth to the stack

        while (!stack.empty()) {
            std::pair<int, int> current = stack.top().first;
            int currentDepth = stack.top().second;
            stack.pop();

            if (visited[current.second][current.first]) {
                continue;
            }

            visited[current.second][current.first] = true;

            if (current == goal) {
                std::vector<std::pair<int, int>> path;
                double totalCost = cost[goal.second][goal.first];

                while (current != start) {
                    path.push_back(current);
                    current = parent[current.second][current.first];
                }
                path.push_back(start);
                printPath(path, totalCost);
                return;
            }

            if (currentDepth >= maxDepth) {
                continue;
            }

            for (const std::pair<int, int>& direction : directions) {
                int x = current.first + direction.first;
                int y = current.second + direction.second;

                if (isValid(x, y, map) && !visited[y][x]) {
                    double newCost = cost[current.second][current.first] + map[y][x];
                    if (newCost < cost[y][x]) {
                        cost[y][x] = newCost;
                        parent[y][x] = current;
                        stack.push({{x, y}, currentDepth + 1}); // Increment depth
                    }
                }
            }
        }
    }
}
