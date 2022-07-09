# brainscrap
Brainfuck in the form of a 2d game

# Usage
## Build

Depends on ncurses
```
git clone https://github.com/longwatermelon/brainscrap
cd brainscrap
make
```

## Create empty board
```
./a.out make [board size] [file]

# Example
./a.out make 10 out
```

## Run program
```
./a.out run [file]
```

## Debug program
```
./a.out debug [file]
```

# How to play
The `x` is you. On game start, x will be facing right by default. Control characters (`wasd`, `?`, `e`) are solid and must be in front of the player to be executed, while
brainfuck commands (`.,+-<>`) are not solid and are executed by stepping on them.

The tile below the x will be evaluated first before the tile in front.

The x will first check the tile in front of it, then move.

# Control characters
* wasd: Gamer controls to turn the x (w: up, a: left, s: down, d: right)
* ?: Conditional operator, turn right if true else left
* e: Exit program

All original brainfuck characters are implemented except for `[` and `]`, because it's impossible to have closing and opening brackets on a 2d board.

