#include <iostream>
using namespace std;

class Point {
private:
    int xCoordinate;
    int yCoordinate;

public:
    Point() : xCoordinate(0), yCoordinate(0) {}
    Point(int x, int y) : xCoordinate(x), yCoordinate(y) {}

    friend istream& operator>>(istream& in, Point& point);
    friend ostream& operator<<(ostream& out, const Point& point);
};

istream& operator>>(istream& in, Point& point) {
    int x, y;

    if (!(in >> x >> y)) {
        in.setstate(ios::failbit);
        return in;
    }

    point.xCoordinate = x;
    point.yCoordinate = y;

    return in;
}

ostream& operator<<(ostream& out, const Point& point) {
    out << "(" << point.xCoordinate << "," << point.yCoordinate << ")";
    return out;
}

int main() {
    Point point;

    cout << "Enter the coordinates of the point (x y): ";
    cin >> point;

    if (cin.fail()) {
        cerr << "Invalid input." << endl;
        return 1;
    }

    cout << "The point is: " << point << endl;

    return 0;
}