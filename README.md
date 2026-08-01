*This project has been created as part of the 42 curriculum by kraksana.*

# fract-ol

## Description

`fractol` is a small graphical program that renders and explores the
Mandelbrot and Julia fractal sets. It maps every pixel in the window to a
complex number, repeatedly applies `z = z² + c`, and colors the pixel using
the number of iterations required for the sequence to escape.

This submission contains the mandatory part only. Zooming is centered on the
current view. Mouse-position zoom, movement with arrow keys, extra fractals,
and color shifting are not included.

## Features

- Mandelbrot set
- Julia sets selected with command-line parameters
- Mouse-wheel zoom in and out
- Multiple colors showing escape depth
- Clean exit with ESC or the window close button
- Rendering through an MLX42 image

## Instructions

### Dependencies on macOS

```sh
brew install cmake glfw
```

Place the MLX42 repository in the project root using the directory name
`MLX42`:

```sh
git clone https://github.com/codam-coding-college/MLX42.git MLX42
```

Compile the project:

```sh
make
```

Available Makefile rules:

```sh
make
make clean
make fclean
make re
```

### Execution

```sh
./fractol Mandelbrot
./fractol Julia -0.7 0.27015
./fractol Julia 0.285 0.01
```

Invalid or missing arguments print the available usage and exit cleanly.

## Controls

- Mouse wheel up: zoom in toward the center
- Mouse wheel down: zoom out from the center
- ESC: close the program
- Window close button: close the program

## Resources

- MLX42 repository and documentation:
  https://github.com/codam-coding-college/MLX42
- Mandelbrot set:
  https://en.wikipedia.org/wiki/Mandelbrot_set
- Julia set:
  https://en.wikipedia.org/wiki/Julia_set
- Complex numbers:
  https://en.wikipedia.org/wiki/Complex_number

AI was used to review project structure, identify possible Norm issues, suggest
test cases, and improve documentation. The fractal equations, pixel mapping,
argument parsing, event handling, memory cleanup, and final source code were
reviewed and tested by the project author, who is responsible for understanding
and explaining every submitted part.
