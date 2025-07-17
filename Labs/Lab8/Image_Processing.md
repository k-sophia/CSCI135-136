## Supplied Materials
Image provided: inImage.pgm

Program provided: `lab-images.cpp`
#
`lab-images.cpp`, provides two helper functions. Don't modify these functions:
-	`void readImage(int image[MAX_H][MAX_W], int  height, int &width)`
-	`void writeImage(int image[MAX_H][MAX_W], int height, int width)`

Lab goal is to change the main function and possibly define your own new functions to implement the tasks.

## File Format
For this lab, we are using PGM (Portable Gray Map) graphical format.

To view an image file:
- `eog inImage.pgm`
    - use the program eog (Eye of Gnome)

To use an alternative image, use the command convert:
- `convert -compress none input-cat.png inImage.pgm`
	- convert image file into PGM format
- `convert outImage.pgm output-cat.png`
	- For the reverse transformation