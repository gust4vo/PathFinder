#include "Bfs.hpp"

int main(int argc, char *argv[]) {
    if (argc < 7) {
        std::cerr << "Usage: " << argv[0] << " <path/to/file.map> <method> <start_x> <start_y> <goal_x> <goal_y>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string method = argv[2];

    int start_x = std::stoi(argv[3]);
    int start_y = std::stoi(argv[4]);

    int goal_x = std::stoi(argv[5]);
    int goal_y = std::stoi(argv[6]);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    int cols, rows;
    file >> cols >> rows;

    std::vector<std::vector<double>> map(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            {
                char symbol;
                file >> symbol;
                switch (symbol) {
                    case '.':
                        map[i][j] = 1.0;
                        break;
                    case ';':
                        map[i][j] = 1.5;
                        break;
                    case '+':
                        map[i][j] = 2.5;
                        break;
                    case 'x':
                        map[i][j] = 6.0;
                        break;
                    case '@':
                        map[i][j] = std::numeric_limits<double>::max();
                        break;
                    default:
                        std::cerr << "Unknown symbol: " << symbol << std::endl;
                        file.close();
                        return 1;
                }
            }
        }
    }

    Bfs::findPath(map, {start_x, start_y}, {goal_x, goal_y});
}