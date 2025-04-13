import sys

# create class for planets dict
class Planet:
    def __init__(self, number, type, mass, diameter, atmosphere, gravity, moons):
        self.number = number
        self.type = type
        self.mass = mass
        self.diameter = diameter
        self.atmosphere = atmosphere
        self.gravity = gravity
        self.moons = moons

# create dict for planets
planets = {
    "Sun": {"number": 0, "type": "star", "mass": 1.989e30, "diameter": 1392700, "atmosphere": "74% - hydrogen | 24% - helium | 2% - traces", "gravity": 274, "moons": "none"},
    "Mercury": {"number": 1, "type": "terrestrial", "mass": 3.285e23, "diameter": 4879.4, "atmosphere": "42% - oxygen | 29% - sodium | 22% - hydrogen | 6% - helium | 1% - potassium", "gravity": 3.7, "moons": "none"},
    "Venus": {"number": 2, "type": "terrestrial", "mass": 4.867e24, "diameter": 12103.6, "atmosphere": "96% - carbon dioxide | 3% - nitrogen | 1% - traces", "gravity": 8.87, "moons": "none"},
    "Earth": {"number": 3, "type": "terrestrial", "mass": 5.972e24, "diameter": 12742, "atmosphere": "78% - nitrogen | 21% - oxygen | 1% - traces", "gravity": 9.81, "moons": "luna"},
    "Mars": {"number": 4, "type": "terrestrial", "mass": 6.417e23, "diameter": 6779, "atmosphere": "95% - carbon dioxide | 3% - nitrogen | 1% - argon | 0.03% - oxygen", "gravity": 3.721, "moons": "phobos | deimos"},
    "Jupiter": {"number": 5, "type": "gas giant", "mass": 1.898e27, "diameter": 139820, "atmosphere": "90% - hydrogen | 10% - helium | 0.01% - traces", "gravity": 24.79, "moons": "io | europa | ganymede | callisto"},
    "Saturn": {"number": 6, "type": "gas giant", "mass": 5.683e26, "diameter": 116460, "atmosphere": "96% - hydrogen | 3% - helium | 0.4% - methane | 0.01% - traces", "gravity": 10.44, "moons": "titan | rhea | enceladus"},
    "Uranus": {"number": 7, "type": "ice giant", "mass": 8.681e25, "diameter": 50724, "atmosphere": "83% - hydrogen | 15% - helium | 2% - methane", "gravity": 8.69, "moons": "titania | oberon | miranda | ariel"},
    "Neptune": {"number": 8, "type": "ice giant", "mass": 1.024e26, "diameter": 49244, "atmosphere": "80% - hydrogen | 19% - helium | 1% - methane", "gravity": 11.15, "moons": "triton | proteus | nereid"},
    "Pluto": {"number": 9, "type": "dwarf planet", "mass": 1.303e22, "diameter": 2376.6, "atmosphere": "98% - nitrogen | 2% - methane | 0.01% - traces", "gravity": 0.62, "moons": "charon | hydra | nix"},
    }


def main():
    print()
    print()
    print("------------SOLARIS------------")
    print()
    print()

    while True:
        try:
            display_menu()
            choice = int(input("Enter: "))
            if choice == 1:
                search_planet()
            elif choice == 2:
                display_help()
            elif choice == 3:
                print("farewell space nomad...")
                sys.exit()
            else:
                print("Invalid input, try again.")
        except ValueError:
            print("Invalid input, try again.")


def search_planet():
    planet = input("Choose planet: ").lstrip().capitalize()
    
    if planet in planets:
        planet_info = planets[planet]
        planet_header()
        print(f"name: {planet}")
        print(f"location: {planet_info['number']}")
        print(f"type: {planet_info['type']}")
        print(f"mass: {planet_info['mass']} kg")
        print(f"diameter: {planet_info['diameter']} km")
        print(f"atmosphere: {planet_info['atmosphere']}")
        print(f"gravity: {planet_info['gravity']} m/s2")
        print(f"moons: {planet_info['moons']}")
        print()
        return
    elif planet.isdigit() and int(planet) in range(10):
        planet_number = int(planet)
        for name, info in planets.items():
            if info['number'] == planet_number:
                planet_header()
                print(f"name: {name}")
                print(f"location: {info['number']}")
                print(f"type: {info['type']}")
                print(f"mass: {info['mass']} kg")
                print(f"diameter: {info['diameter']} km")
                print(f"atmosphere: {info['atmosphere']}")
                print(f"gravity: {info['gravity']} m/s2")
                print(f"moons: {info['moons']}")
                print()
                return
    else:
        print("Planet not found. Try again.")
        print()
        return search_planet()
    

def display_menu():
    print()
    print("-----------MAIN MENU----------")
    print("1. Search for Planet")
    print("2. Help")
    print("3. Exit")
    print()
    print("Select an option: ")


def display_help():
    print()
    print("--------------HELP------------")
    print("1. Search by number 0-9 or by name")
    print("2. Show help menu")
    print("3. Exits application")
    print()


def planet_header():
    print("------------------------------")
    print("      PLANET INFORMATION      ")
    print("------------------------------")


if __name__ == "__main__":
    main()