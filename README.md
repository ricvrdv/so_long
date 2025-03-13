# 42 - SO_LONG

### [MILESTONE 2]

<p align="center">
  <img src="https://github.com/ricvrdv/so_long/blob/main/so_long.gif" alt="So Long">
</p>


### SUMMARY
In this repository you can find the code implementation for the SO_LONG project for 42. The goal of the project is to create a simple yet engaging game using the MinilibX graphics library. The player navigates a character through a map, collecting items and reaching the exit to win the game.

This project demonstrates skills in C programming, graphics programming, memory management, and algorithm design (e.g., pathfinding).

### REPOSITORY STRUCTURE
Version for Linux and macOS inside `linux_version` and `macos_version` directories, respectively.
- `src`: Contains the source code for the program.
- `includes`: Contains the header file `so_long.h`, `libft`, which is a custom library for utility functions, and the graphics library `minilibx`.
- `Makefile`: Compiles the project.
- `maps`: Contains `valid` and `invalid` maps that can be used to run and test the program.
- `textures`: Contains .xpm image files that are loaded into the game.
- `README.md`: Project overview and usage instructions.

### KEY FEATURES
**Dynamic map parsing:** Reads and validates maps from `.ber` files.

**Player movement:** Allows the player to move up, down, left, and right.

**Collectibles:** The player must collect all items before reaching the exit.

**Win condition:** The game ends when the player reaches the exit after collecting all items.

**Graphics:** Renders the game using the MinilibX library.

**Error handling:** Robust error handling for invalid maps, missing files, and memory allocation issues.

**Path validation:** Ensures the map has a valid path for the player to collect all items and reach the exit.

### USAGE
1. **Compile the program:**
```
make
```

2. **Run the program with a map file:**
```
./so_long maps/valid/map4_valid.ber
```

To win the game open all chests to unlock the computer and exit the game. To close the game press ESC or click the cross on the window with the mouse. 



