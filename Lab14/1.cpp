#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Mapper class to process the file content
class Mapper {
public:
    std::vector<std::pair<std::string, int> > map(const std::string& line) {
        std::vector<std::pair<std::string, int> > result;
        std::string word;
        for (char c : line) {
            if (std::isalpha(c)) {
                word.push_back(std::tolower(c));
            } else if (!word.empty()) {
                result.push_back({word, 1});
                word.clear();
            }
        }
        if (!word.empty()) {
            result.push_back({word, 1});
        }
        return result;
    }
};

// Reducer class to aggregate word counts
class Reducer {
public:
    std::vector<std::pair<std::string, int> > reduce(const std::vector<std::pair<std::string, int> >& pairs) {
        std::vector<std::pair<std::string, int> > result;
        for (const auto& pair : pairs) {
            auto it = std::find_if(result.begin(), result.end(), [&](const auto& p) {
                return p.first == pair.first;
            });
            if (it != result.end()) {
                it->second += pair.second;
            } else {
                result.push_back(pair);
            }
        }
        return result;
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: File not found." << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, int> > mappedPairs;
    Mapper mapper;
    std::string line;
    while (std::getline(file, line)) {
        auto pairs = mapper.map(line);
        mappedPairs.insert(mappedPairs.end(), pairs.begin(), pairs.end());
    }

    std::sort(mappedPairs.begin(), mappedPairs.end());

    Reducer reducer;
    auto reducedPairs = reducer.reduce(mappedPairs);

    std::ofstream outputFile(filename.substr(0, filename.find_last_of('.')) + "_mr.txt");
    for (const auto& pair : reducedPairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}