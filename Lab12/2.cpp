#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding random number generator
#include <random>

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
    string getName() const {
        return name;
    }
    string getSound() const {
        return sound;
    }
    string getType() const {
        return type;
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
    vector<Pokemon> caughtPokemons;
    bool pokeballsAdded;

public:
    Player() : pokeballsAdded(false) {}

    void addPokeball(const Pokeball& pokeball) {
        pokeballs.push_back(pokeball);
        pokeballsAdded = true;
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
            caughtPokemons.push_back(Pokemon(wildPokemon.getName(), wildPokemon.getSound(), wildPokemon.getType(), wildPokemon.getPower(), wildPokemon.getSpeed()));
        } else {
            cout << "Oh no! The wild Pokemon escaped. Better luck next time!" << endl;
        }

        // Assuming the Pokeball is consumed after attempting to catch a Pokemon
        pokeballs.pop_back();
    }

    void stockpilePokeballs() {
        const int numPokeballsToAdd = 5; // Number of Pokeballs to add
        const string pokeballTypes[] = {"Basic Pokeball", "Great Pokeball", "Ultra Pokeball", "Master Pokeball", "Premier Pokeball"};
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, sizeof(pokeballTypes) / sizeof(pokeballTypes[0]) - 1);

        for (int i = 0; i < numPokeballsToAdd; ++i) {
            int randomIndex = dis(gen);
            Pokeball newPokeball(pokeballTypes[randomIndex], 100 + (rand() % 21)); // Random efficiency between 100 and 120
            addPokeball(newPokeball);
        }

        cout << "Added " << numPokeballsToAdd << " new Pokeballs to the stockpile." << endl;
    }

    bool hasPokeballs() const {
        return !pokeballs.empty();
    }
    void listPokeballs() const {
        cout << "Pokeballs in Stock:" << endl;
        for (const Pokeball& pokeball : pokeballs) {
            cout << "- " << pokeball.getName() << " (" << pokeball.getEfficiency() << " efficiency)" << endl;
        }
    }
    void displayPokemonCollection() const {
        if (caughtPokemons.empty()) {
            cout << "No Pokémon caught yet." << endl;
        } else {
            cout << "Caught Pokémon:" << endl;
            for (const Pokemon& pokemon : caughtPokemons) {
                cout << "- " << pokemon.getName() << " (" << pokemon.getType() << ")" << endl;
            }
        }
    }
    bool hasAddedPokeballs() const {
        return pokeballsAdded;
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

        // Use random_device to seed the random number generator
        std::random_device rd;
        // Use mt19937 as the random number generator engine
        std::mt19937 gen(rd());
        // Create a uniform distribution for selecting a random index in the wildPokemons vector
        std::uniform_int_distribution<> dis(0, wildPokemons.size() + 1); // +1 for the possibility of encountering nothing

        // Simulate exploration and encounters with wild Pokemon or nothing
        int randomIndex = dis(gen);

        if (randomIndex < wildPokemons.size()) {
            WildPokemon& wildPokemon = wildPokemons[randomIndex];
            cout << "Encountered a wild " << wildPokemon.getName() << "!" << endl;
            
            // You can add more logic here, like giving the player options to catch or run away.
            player.catchPokemon(wildPokemon);
        } else {
            cout << "You didn't encounter any wild Pokemon this time." << endl;
        }

        // Assuming exploration is successful if at least one Pokemon was caught or nothing was encountered
        return true;
    }
    bool isEmpty() const {
        return wildPokemons.empty();
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
class Game {
private:
    World world;
    Player player;

public:
    Game() {
        // Initialize random seed
        srand(time(0));

        // Add five diverse wild Pokémon to the world
        world.addWildPokemon(WildPokemon("Pikachu", "Pika pika!", "Electric", 10, 60, 30));
        world.addWildPokemon(WildPokemon("Charmander", "Char char!", "Fire", 15, 50, 25));
        world.addWildPokemon(WildPokemon("Squirtle", "Squirt squirt!", "Water", 12, 55, 28));
        world.addWildPokemon(WildPokemon("Bulbasaur", "Bulba bulba!", "Grass", 14, 52, 27));
        world.addWildPokemon(WildPokemon("Jigglypuff", "Jigglypuff!", "Fairy", 8, 70, 20));
    }

    void play() {
        cout << "Welcome to the Pokémon Go-Inspired Game!" << endl;

        // Player starts with zero Pokeballs

        while (!world.isEmpty()) {
            cout << "Options:\n1. Add Pokeballs to Stock\n2. Walk (Encounter Pokémon)\n3. List Pokeballs\n4. List Caught Pokémon\n5. Exit\n";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    if (!player.hasAddedPokeballs()) {
                        // Player can only add Pokeballs once
                        player.stockpilePokeballs();
                    } else {
                        cout << "You have already added Pokeballs. Cannot add more." << endl;
                    }
                    break;
                case 2:
                    world.explore(player);
                    if (!player.hasPokeballs()) {
                        cout << "Game Over! You ran out of Pokéballs. Better luck next time!" << endl;
                        return;
                    }
                case 3:
                    player.listPokeballs();
                    break;
                case 4:
                    player.displayPokemonCollection();
                    break;
                case 5:
                    cout << "Thanks for playing! Goodbye." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please choose again." << endl;
            }
        }

        cout << "Game Over! ";
        if (player.hasPokeballs()) {
            cout << "You captured all wild Pokémon!";
        } else {
            cout << "You ran out of Pokéballs. Better luck next time!";
        }
        cout << endl;
    }
};

int main() {
    Game game;
    game.play();

    return 0;
}


