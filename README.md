*This project has been created as part of the 42 curriculum by kraksana.*

# fract-ol

A graphical fractal explorer written in C using MLX42, developed as part of the 42 Bangkok curriculum.

## Overview

The goal of this project is to render and explore mathematical fractals while learning graphics programming, complex numbers, event handling, and pixel-based rendering in C.

The implementation supports:

- Mandelbrot set
- Julia sets with custom parameters
- Mouse-wheel zoom in and out
- Multiple colors based on iteration depth
- ESC and window-close handling
- Image rendering with MLX42

This repository contains the mandatory part of the project.

## Concepts Practiced

- Complex numbers
- Mandelbrot and Julia sets
- Pixel-to-coordinate mapping
- Iterative fractal calculations
- Color generation
- Graphics with MLX42
- Mouse and keyboard events
- Image buffers
- Argument parsing
- Makefiles
- 42 Norm coding standard

## Build

Install the required dependencies on macOS:

```bash
brew install cmake glfw
```

Clone MLX42 into the project root:

```bash
git clone https://github.com/codam-coding-college/MLX42.git MLX42
```

Compile the project:

```bash
make
```

## Usage

Mandelbrot:

```bash
./fractol Mandelbrot
```

Julia:

```bash
./fractol Julia -0.7 0.27015
```

Another Julia example:

```bash
./fractol Julia 0.285 0.01
```

## Controls

- Mouse wheel up — zoom in
- Mouse wheel down — zoom out
- `ESC` — close the program
- Window close button — close the program

## Makefile Commands

```bash
make
make clean
make fclean
make re
```

## Project Status

- Supports Mandelbrot and Julia sets
- Supports custom Julia parameters
- Uses MLX42 image rendering
- Builds with `-Wall -Wextra -Werror`
- Passes Norminette
- Mandatory part completed

## Author

Kullatida Raksanaves
42 Bangkok
