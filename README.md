# 42_fdf
This project is a part of *42 Ecole* cursus.

## Intro

The representation in 3D of a landscape is a critical aspect of modern mapping.
For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest.

Decription of the project in subject:
![subject1](/pic_examples/subject1.png)

## Initial steps:
 
1. Clone the repo and go there
2. Compile the programm using Makefile

```bash
  make 
```
3. Chose the map and run the programm to open a window with the picture
```bash
  ./fdf  [path to the map]
```

## Usage Instructions:

 To translate the model within the viewer, use the arrow keys on your keyboard:
 
 - **Left Arrow Key**: Moves the model to the left.
 - **Right Arrow Key**: Moves the model to the right.
 - **Up Arrow Key**: Moves the model upwards.
 - **Down Arrow Key**: Moves the model downwards.

 To zoom in/zoom out use +/-

 - **D** To rotate the model along z axis 
 - **S** To rotate the model along x axis

 - **R** Reset to initial view
 

### Examples:

Map - 42.fdf
```bash
  ./fdf  test_maps/42.fdf
```
![42 Map](/pic_examples/example1.png)

Map - pylone.fdf
```bash
  ./fdf  test_maps/pylone.fdf
```
![Pylone Map](/pic_examples/example2.png)

Map - mars.fdf
```bash
  ./fdf  test_maps/mars.fdf
```
![Mars Map](/pic_examples/example3.png)

#### Additional steps to improve project
 - Fix rotation (now the model gradually decreases as it rotates)
 - Make colors more diverse and beautiful
 - Computation optimization
 - Make the project cross-platform (Now it works only on MacOS)


Feel free to provide any other suggestions on how to improve the project
