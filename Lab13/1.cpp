#include <iostream>
#include <vector>

// Base class
class SpaceObject {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic space object.\n";
    }

    virtual ~SpaceObject() {}
};

// Derived classes
class Martian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Martian with green skin.\n";
    }
};

class Venutian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Venutian with a yellow atmosphere.\n";
    }
};

class Plutonian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Plutonian with icy surface.\n";
    }
};

class SpaceShip : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a SpaceShip with futuristic design.\n";
    }
};

class LaserBeam : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a LaserBeam with intense energy.\n";
    }
};

// Screen manager class
class ScreenManager {
private:
    std::vector<SpaceObject*> objects;

public:
    void addObject(SpaceObject* obj) {
        objects.push_back(obj);
    }

    void refreshScreen() {
        for (const auto& obj : objects) {
            obj->draw();
        }
    }
};

// Demonstrate polymorphism
class Mercurian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Mercurian with rocky terrain.\n";
    }
};

int main() {
    ScreenManager screenManager;

    // Add various objects to the screen manager
    screenManager.addObject(new Martian());
    screenManager.addObject(new Venutian());
    screenManager.addObject(new Plutonian());
    screenManager.addObject(new SpaceShip());
    screenManager.addObject(new LaserBeam());

    // Demonstrate polymorphism by adding Mercurian without changing screen manager's code
    screenManager.addObject(new Mercurian());

    // Refresh the screen to see different visual representations
    screenManager.refreshScreen();
}
