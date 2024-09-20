#include <iostream>
#include <vector>

char patternCheck(char ch, const std::vector<std::vector<char>>& charVector) {
    int totalCount = 0, rowCounts[4] = {0}, colCounts[4] = {0}, diagLR = 0, diagRL = 0;
    int patternType = 0; // 0 for 'n', 1 for '-', 2 for '|', 3 for '\\', 4 for '/'
    
    // Count occurrences
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bool match = charVector[i][j] == ch;
            totalCount += match;
            rowCounts[i] += match;
            colCounts[j] += match;
            if (i == j) diagLR += match;
            if (i + j == 3) diagRL += match;
        }
    }

    // Determine the pattern type based on counts
    for (int i = 0; i < 4; ++i) {
        switch (rowCounts[i]) {
            case 4:
                patternType = totalCount == 4 ? 1 : 0;
                break;
        }
        switch (colCounts[i]) {
            case 4:
                patternType = totalCount == 4 ? 2 : 0;
                break;
        }
    }
    switch (diagLR) {
        case 4:
            patternType = totalCount == 4 ? 3 : 0;
            break;
    }
    switch (diagRL) {
        case 4:
            patternType = totalCount == 4 ? 4 : 0;
            break;
    }

    // Use switch case to return the pattern
    switch (patternType) {
        case 1: return '-';
        case 2: return '|';
        case 3: return '\\';
        case 4: return '/';
        default: return 'n';
    }
}

int main() {
    std::vector<std::vector<char>> charVector = {
        {'x', 'o', 'o', 'o'},
        {'o', 'x', 'o', 'o'},
        {'o', 'o', 'x', 'o'},
        {'o', 'o', 'o', 'x'}
    };

    char ch = 'x';
    std::cout << "The pattern formed by '" << ch << "': " << patternCheck(ch, charVector) << std::endl;

    return 0;
}