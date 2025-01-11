#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creating color pallette
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// define color for each planet using an array
const char *planet_colors[] = 
{
    YELLOW,                     // sun
    MAGENTA,                    // mercury
    GREEN,                      // venus
    CYAN,                       // earth
    RED,                        // mars
    YELLOW,                     // jupiter
    MAGENTA,                    // saturn
    BLUE,                       // uranus
    CYAN,                       // neptune
    WHITE                       // pluto
};

// creating struct for planet
typedef struct planet
{
    char name[20];              // planet's name
    int number;                 // location in solar system
    char type[20];              // type of planet
    double mass;                // mass of planet
    double diameter;            // diameter of planet
    char atmosphere[100];       // atmosphere of planet
    char gravity[50];           // gravity force
    char moons[200];            // moons of planet
} planet;

// creating database for each planet
planet planets[] = {
    {"Sun", 0, "star", 1.9891e30, 1391000, "74%% - hydrogen | 24%% - helium | 2%% - traces", "274 m/s2 [28xEARTH]"},                  
    {"Mercury", 1, "terrestial", 3.285e23, 4879.4, "thin exosphere", "3.7 m/s2 [0.38xEARTH]", "none"},
    {"Venus", 2, "terrestial", 4.867e24, 12104, "97%% - carbon dioxide | 3%% - nitrogen", "8.87 m/s2 [0.9xEARTH]"},
    {"Earth", 3, "terrestial", 5.972e24, 12742, "78%% - nitrogen | 21%% - oxygen | 1%% - traces", "9.8 m/s2", "luna"},
    {"Mars", 4, "terrestial", 6.39e23, 6779, "95%% - carbon dioxide | 2.5%% - nitrogen | 1.5%% - argon", "3.71 m/s2 [0.38xEARTH]", "phobos | deimos"},
    {"Jupiter", 5, "gas giant", 1.898e27, 139820, "90%% - hydrogen | 10%% - helium", "24.79 m/s2 [2.5xEARTH]", "Io | europa | ganymede | callisto | himalia | thebe"},
    {"Saturn", 6, "gas giant", 5.683e26, 116460, "96%% - hydrogen | 3%% - helium | 1%% - traces", "10.44 m/s2 [1.07xEARTH]", "titan | enceladus | mimas | tethys | dione"},
    {"Uranus", 7, "ice giant", 8.681e25, 50724, "83%% - hydrogen | 15%% - helium | 2%% - methane", "8.69 m/s2 [0.89xEARTH]", " miranda | ariel | umbriel | titania | oberon"},
    {"Neptune", 8, "ice giant", 1.024e26, 49244, "80%% - hydrogen | 19%% - helium | 1%% - methane", "11.15 m/s2 [1.14xEARTH]", "triton | nereid | proteus | larissa"},
    {"Pluto", 9, "dwarf planet", 1.303e22, 2377, "thin", "0.62 m/s2 [0.06xEARTH]", "charon | nix | hydra | kerberos | styx"}
};

// attached functions
void display_menu();
void search_planet();
void display_help();
void print_header();

// main menu function
int main(void) 
{
    printf("\n");
    printf("\n");
    printf("-----------SOLARIS------------\n");
    printf("\n");

    int choice;
    while (1) {
        display_menu();  // Show the menu
        scanf("%d", &choice);  // Get user choice
        
        switch(choice) 
        {
            case 1:
                search_planet();
                break;
            case 2:
                display_help();
                break;
            case 3:
                printf("exiting...\n");
                printf("\n");
                return 0;
        }
    }
}

// main search function
void search_planet()
{
    char input_name[20];                                                                    // input of user in chars
    int input_num;                                                                          // input of user in int
    int found = 0;                                                                          // flag to check if planet is found
    
    printf("Enter planet name or number: \n");                                              // asking for input

    if (scanf("%d", &input_num) == 1)
    {
        while (getchar() != '\n');                                                          // clear the input buffer

        if (input_num >= 0 && input_num <= 9)                                               // compare input number to planet number
        {
            planet selected = planets[input_num];                                           // assign input number to proper array number
            print_header();
            printf("%sname: %s%s\n", planet_colors[input_num], selected.name, RESET);
            printf("solar system location: %d\n", selected.number);
            printf("type: %s\n", selected.type);
            printf("\n");
            printf("mass: %.2e kg\n", selected.mass);
            printf("diameter: %.2f km\n", selected.diameter);
            printf("atmosphere: %s\n", selected.atmosphere);
            printf("gravity: %s\n", selected.gravity);
            printf("\n");
            printf("moons: %s\n", selected.moons);
            printf("\n");
            found = 1;
        }
    }

    if(!found)
    {
        
        if (scanf("%s", input_name) == 1)
        {
            // adjust input to match planet name
            input_name[0] = toupper(input_name[0]);                                         // capitalize first letter
            for (int i = 1; input_name[i] != '\0'; i++)                                     // lowercase the rest
            {
                input_name[i] = tolower(input_name[i]);
            }

            for (int i = 0; i < 10; i++)
            {
                if (strcmp(input_name, planets[i].name) == 0)                               // checks if the name matches
                {
                    print_header();
                    printf("%sname: %s%s\n", planet_colors[i], planets[i].name, RESET);
                    printf("solar system location: %d\n", planets[i].number);
                    printf("type: %s\n", planets[i].type);
                    printf("\n");
                    printf("mass: %.2e kg\n", planets[i].mass);
                    printf("diameter: %.2f km\n", planets[i].diameter);
                    printf("atmosphere: %s\n", planets[i].atmosphere);
                    printf("gravity: %s\n", planets[i].gravity);
                    printf("\n");
                    printf("moons: %s\n", planets[i].moons);
                    printf("\n");
                    found = 1;
                    break;
                }
            }
        }
    }
        
    if (!found)
    {
        printf("Planet do not exist.\n");
        return;
    }
}

// display menu content
void display_menu()
{
    printf("\n");
    printf("-----------MAIN MENU----------\n");
    printf("1. Search for Planet\n");
    printf("2. Help\n");
    printf("3. Exit\n");
    printf("\n");
    printf("select an option: ");
}

// display help content
void display_help()
{
    printf("\n");
    printf("--------------HELP------------\n");
    printf("1. Search by number 0-9 or by name\n");
    printf("2. Show help menu\n");
    printf("3. Exits application\n");
    printf("\n");
}

// creating a header function for better visual effect
void print_header()
{
    printf("------------------------------\n");
    printf("      PLANET INFORMATION      \n");
    printf("------------------------------\n");
}
