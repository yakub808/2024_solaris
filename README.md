# **SOLARIS**
#### Video Demo:  [SOLARIS VIDEO](https://youtu.be/oUkYc4HgVYo)
#### Description:
Solaris is an application written in C language, which provides detailed information about, known, celestial bodies nested in our solar system.
Designed for educational and informational purposes. It helps user to explore
our solar system and gain knowledge about it. The entire program is contained
within a single source file, making it compact and easy to manage.

**DATA STORAGE**

The application is designed to create a structure called 'planet', in which there is information about the selected celestial body. This includes detailed data
such as:
- name of a planet: stored as a string - char[].
- location in solar system: represented by an integer - int.
- type of a planet: stored as a string - char[].
- mass of a planet: stored as double-precision floating-point for accuracy - double.
- diameter of a planet: represented as double.
- composition of an atmosphere: stored as a string - char[].
- strength of gravity force: stored as a string - char[].
- presence and number of moons: stored as a string - char[].

The information about planets is stored in 'planets' database, embedded within 
the source code. Each planet is assigned a name and ID number. The ID number corresponds to the planet's location within the solar system. Users can search for a planet using either its name or ID number. This solution offers flexibility in how users can interact with the Solaris application.

**THE MAIN FUNCTION**

The main function serves as central hub for the Solaris application.
It starts with a warm welcome message, which sets tone for user experience.

Solaris application uses simple user menu, with three basic options, placed in an infinite loop. 

It allows user to:
1. search for planet,
2. access help menu, 
3. exit the application.

**Case 1**: user calls search_planet() function.

**Case 2**: user calls display_help() function.

**Case 3**: user terminates the program with exit message.

The program uses scanf to read and check user's input.
Thanks to infinite loop, user doesn't need to restart the application for another search. Application remains active until user chooses to exit. This solution creates seamless and intuitive experience for user.

**THE search_planet() FUNCTION**

The search_planet() function enables users to search for a planet from the Solaris database by it's name or ID number. Function processed user input, checks for validation of the data and displays detailed information about the selected planet in organized format. If the planet is not found, function informs the user with an error message.

**THE display_menu() FUNCTION**

The display_menu() function prints out the main menu of the Solaris application.

**THE display_help() FUNCTION**

The display_help() function provides a clear guide for using the Solaris application. It outlines the available menu options, making the program easy to navigate even for first-time users.

**VISUAL AND FORMATTING**

Application has been enriched with visual upgrades, to improve clarity and readability.

The print_header function is a simple tool that formats and displays a consistent header for all presenting planet information within the Solaris application.
Ensuring that output is visually appealing and easy to follow.

Each planet in the solar system is associated with specific color.
The color coding is achieved using the planet_colors array, where each planet is linked with a specific color using ANSI sequences. 
This solution enhances the visual presentation of the Solaris application. 
ANSI sequences modify text color in terminal, and are defined as:
- RESET: resets text color to it's default state
- RED, GREEN, BLUE, YELLOW, CYAN, WHITE, MAGENTA: defines text color

The use of color not only makes the output visually distinct but also helps users easily identify and differentiate between the planets.

**HOW TO COMPILE**
1. Open terminal window.
2. Go to Solaris directory.
3. Run: gcc -o solaris solaris.c
4. Run: ./solaris

**FUTURE ENHANCEMENTS**
1. Add more visual upgrades.
2. Add 3D models of planets.

**CONCLUSION**

Solaris is a versatile and visually appealing application designed to educate
users about our solar system. Application combines structured data storage, simple user interface with visual formatting.
