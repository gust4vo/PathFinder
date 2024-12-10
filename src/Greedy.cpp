#include "Greedy.hpp"

struct Compare {
    bool operator()(const std::pair<std::pair<int, double>, std::pair<int, int>>& a, 
                    const std::pair<std::pair<int, double>, std::pair<int, int>>& b) const {
        // Prioriza menor distância Manhattan
        if (a.first.first != b.first.first) {
            return a.first.first > b.first.first; // Maior Manhattan tem menor prioridade
        }
        // Empate: prioriza menor custo acumulado
        return a.first.second > b.first.second; // Maior custo tem menor prioridade
    }
};

// Função findPath ajustada
void Greedy::findPath(
    const std::vector<std::vector<double>>& map, 
    const std::pair<int, int>& start, 
    const std::pair<int, int>& goal)
{
    std::priority_queue<
        std::pair<std::pair<int, double>, std::pair<int, int>>, 
        std::vector<std::pair<std::pair<int, double>, std::pair<int, int>>>, 
        Compare> pq;

    std::vector<std::vector<double>> cost(map.size(), std::vector<double>(map[0].size(), std::numeric_limits<double>::infinity()));
    std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
    std::vector<std::vector<std::pair<int, int>>> parent(map.size(), std::vector<std::pair<int, int>>(map[0].size(), {-1, -1}));

    pq.push({{0, 0}, start}); // Distância Manhattan, custo acumulado
    cost[start.second][start.first] = 0;

    std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int total_explored = 0;
    while (!pq.empty()) {
        std::pair<int, int> current = pq.top().second;
        pq.pop();

        if (visited[current.second][current.first]) {
            continue;
        }

        visited[current.second][current.first] = true;
        total_explored++;
        if (current == goal) {
            std::vector<std::pair<int, int>> path;
            double totalCost = cost[goal.second][goal.first];

            while (current != start) {
                path.push_back(current);
                current = parent[current.second][current.first];
            }
            path.push_back(start);
            std::cout << "Explored nodes: " << total_explored << std::endl;
            printPath(path, totalCost);
            return;
        }

        for (const std::pair<int, int>& direction : directions) {
            int x = current.first + direction.first;
            int y = current.second + direction.second;

            if (isValid(x, y, map)) {
                int manhattan = std::abs(goal.first - x) + std::abs(goal.second - y);
                double newCost = cost[current.second][current.first] + map[y][x];

                if (newCost < cost[y][x]) {
                    cost[y][x] = newCost;
                    parent[y][x] = current;
                    pq.push({{manhattan, newCost}, {x, y}});
                }
            }
        }
    }

    std::cerr << "No path found" << std::endl;
}

