# Battle

A turn-based RPG game for terminals.

## Overview

Battle is a simple turn-based RPG game developed in C, designed to run in terminal environments. This project is a micro-experience whose core is based solely and exclusively on battles that become progressively more challenging. You have a basic set of actions (attack, defend and inventory) and must win battles with what you have.

At the end of each battle you will be rewarded with items and improvements, allowing you to build personalized builds and add an extra layer of depth to the game.

The game is infinitely playable, with a simple but engaging combat system, and is a great way to practice C programming and terminal-based game development.

## Features

- Turn-based combat system
- Player and enemy entities with stats
- Inventory management with items
- Randomized enemy generation
- Simple text-based user interface
- Progressive difficulty scaling
- Infinite replayability

## Compilation and Execution

To compile and run the Battle game, follow these steps:

1. Ensure you have a C compiler (e.g., `gcc`) and make installed.
2. In this directory, run the following command to compile the game:

    ```bash
    make
    ```

3. When building the application, two directories will appear: `obj` and `bin`. The program executable is located in the `bin` directory.
4. To run the game, execute the following command:

    ```bash
    ./bin/battle
    ```
