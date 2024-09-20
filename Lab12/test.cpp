#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pokemon {
protected:
    string name;
    string sound;
    string type;
    int power;
    int speed;

public:
    Pokemon(const string& name, const string& sound, const string& type, int power, int speed) 
    : name(name), sound(sound), type(type), power(power), speed(speed) {}

    string getName() const {
        return name;
    }
    string getSound() const {
        return sound;
    }
    string getType() const {
        return type;
    }
    int getPower() const {
        return power;
    }
    int getSpeed() const {
        return speed;
    }
};

class WildPokemon : public Pokemon {
private:
    int catchRate;

public:
    WildPokemon(const string& name, const string& sound, const string& type, int power, int speed, int catchRate) 
    : Pokemon(name, sound, type, power, speed), catchRate(catchRate) {}

    int getCatchRate() const {
        return catchRate;
    }
    bool attemptCatch(int pokeball) {
        return (speed * catchRate) % 100 > 50;
    }
};

class PalPokemon : public Pokemon {
public:
    PalPokemon(const string& name, const string& sound, const string& type, int power, int speed) 
    : Pokemon(name, sound, type, power, speed) {}
};

class Pokeball {
private:
    string name;
    int efficiency;

public:
    Pokeball(const string& name, int efficiency) : name(name), efficiency(efficiency) {}

    string getName() const {
        return name;
    }
    int getEfficiency() const {
        return efficiency;
    }
    bool catchPokemon(const WildPokemon& wildPokemon) {
        return (efficiency * 100) / (100 + wildPokemon.getCatchRate()) > 50;
    }
};

class Berry {
private:
    string name;
    int effectiveness;

public:
    Berry(const string& name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    string getName() const {
        return name;
    }
    int getEffectiveness() const {
        return effectiveness;
    }
    void applyEffect(Pokeball& pokeball) const {
        pokeball = Pokeball(pokeball.getName(), pokeball.getEfficiency() + effectiveness);
    }
};

class Player {
private:
    vector<Pokeball> pokeballs;
    Berry* optionalBerry = nullptr;

public:
    Player() {}

    void addPokeball(const Pokeball& pokeball) {
        pokeballs.push_back(pokeball);
    }

    void addBerry(const Berry& berry) {
        optionalBerry = new Berry(berry); // Assuming Berry has a copy constructor
    }

    bool hasBerry() const {
        return optionalBerry != nullptr;
    }

    void catchPokemon(WildPokemon& wildPokemon) {
        if (pokeballs.empty()) {
            cout << "No Pokeballs available. Cannot attempt to catch Pokemon." << endl;
            return;
        }

        Pokeball& selectedPokeball = pokeballs.back();
        
        if (hasBerry()) {
            optionalBerry->applyEffect(selectedPokeball);
            cout << "Applied Berry effect to the Pokeball." << endl;
        }

        if (selectedPokeball.catchPokemon(wildPokemon)) {
            cout << "You caught a wild Pokemon! Congratulations!" << endl;
        } else {
            cout << "Oh no! The wild Pokemon escaped. Better luck next time!" << endl;
        }

        // Assuming the Pokeball is consumed after attempting to catch a Pokemon
        pokeballs.pop_back();
    }

    ~Player() {
        delete optionalBerry;
    }
};

class World {
private:
    vector<WildPokemon> wildPokemons;

public:
    World() {}

    void addWildPokemon(const WildPokemon& wildPokemon) {
        wildPokemons.push_back(wildPokemon);
    }

    bool explore(Player& player) {
        if (wildPokemons.empty()) {
            cout << "No wild Pokemon in the world. Nothing to explore." << endl;
            return false;
        }

        // Simulate exploration and encounters with wild Pokemon
        for (WildPokemon& wildPokemon : wildPokemons) {
            cout << "Encountered a wild " << wildPokemon.getName() << "!" << endl;

            // You can add more logic here, like giving the player options to catch or run away.
            player.catchPokemon(wildPokemon);
        }

        // Assuming exploration is successful if at least one Pokemon was caught
        return true;
    }
};

class GameTester {
public:
    static void testCatchMechanics() {
        Player player;
        Pokeball basicPokeball("Basic Pokeball", 100);
        player.addPokeball(basicPokeball);

        World world;
        WildPokemon pikachu("Pikachu", "Pika pika!", "Electric", 10, 60, 30);
        world.addWildPokemon(pikachu);

        cout << "Testing Catch Mechanics..." << endl;
        bool result = world.explore(player);
        if (result) {
            cout << "The player succesfully caught a Pokemon." << endl;
        } else {
            cout << "The player failed ti catch a Pokemon." << endl;
        }
    }

    static void testEscapeMechanics() {
        Player player;
        Pokeball weakPokeball("Weak Pokeball", 20);
        player.addPokeball(weakPokeball);
        
        World world;
        WildPokemon abra("Abra", "Teleport", "Psychic", 20, 90, 70);
        world.addWildPokemon(abra);

        cout << "Testing Escape Mechanics..." << endl;
        bool result = world.explore(player);
        if (result) {
            cout << "The player succesfully caught a Pokemon." << endl;
        } else {
            cout << "The Pokemon escaped." << endl;
        }
    }
};

int main() {
    GameTester::testCatchMechanics();
    cout << "----------------------------------------" << endl;
    GameTester::testEscapeMechanics();
    return 0;
}

