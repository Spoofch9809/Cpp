#include <iostream>
#include <vector>
#include <string>

char patternCheck(char ch, const std::vector<std::vector<char> >& charVector) {
    int diagonalLRCount = 0, diagonalRLCount = 0;
    bool foundPattern = false;
    char patternType = 'n'; // Default to 'n' if no pattern is found

    // Loop to check diagonal counts
    for (int i = 0; i < 4; ++i) {
        if (charVector[i][i] == ch) ++diagonalLRCount;
        if (charVector[i][3 - i] == ch) ++diagonalRLCount;
    }

    // Checking diagonals first
    if (diagonalLRCount == 4) return '\\';
    if (diagonalRLCount == 4) return '/';

    // Checks for horizontal and vertical lines
    for (int i = 0; i < 4 && !foundPattern; ++i) {
        bool horizontal = true, vertical = true;
        for (int j = 0; j < 4 && (horizontal || vertical); ++j) {
            if (charVector[i][j] != ch) horizontal = false;
            if (charVector[j][i] != ch) vertical = false;
        }
        if (horizontal || vertical) {
            foundPattern = true;
            patternType = horizontal ? '-' : '|';
        }
    }

    return patternType;
}

int main() {
    // Example usage
    std::vector<std::vector<char> > charVector = {
        {'x', 'x', 'x', 'o'},
        {'o', 'x', 'x', 'o'},
        {'o', 'o', 'x', 'o'},
        {'o', 'o', 'x', 'x'}
    };

    char ch = 'x';
    std::cout << "The pattern formed by '" << ch << "': " << patternCheck(ch, charVector) << std::endl;

    return 0;
}