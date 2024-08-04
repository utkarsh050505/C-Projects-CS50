#include "helpers.h"
#include <math.h>

// Convert image to grayscale


void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initialising values
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            //For average

            int avg = round((R + G + B) / 3);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initialising values
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            // sepia formula

            float sepiaRed = .393 * R + .769 * G + .189 * B;
            float sepiaGreen = .349 * R + .686 * G + .168 * B;
            float sepiaBlue = .272 * R + .534 * G + .131 * B;

            //for values over 255

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //converting original to sepia

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // using the swaping technique mentioned from class

            RGBTRIPLE x = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = x;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j]; // copying the image.
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red, Green, Blue;
            Red = 0;
            Green = 0;
            Blue = 0;
            float count = 0.00;

            for (int x = -1; x < 2; x++) // for relative position around the image.
            {
                for (int y = -1; y < 2; y++)
                {

                    int X = x + i;
                    int Y = y + i;

                    if (X < 0 || X > (height - 1) || Y < 0 || Y > (width - 1))
                    {
                        continue; // skips only the current iteration of loop, while break; completely stops the loop.
                    }

                    //adding the values and counter for average.
                    Red += image[X][Y].rgbtRed;
                    Green += image[X][Y].rgbtGreen;
                    Blue += image[X][Y].rgbtBlue;

                    count++;
                }

                //averaging
                tmp[i][j].rgbtRed = round(Red / count);
                tmp[i][j].rgbtGreen = round(Green / count);
                tmp[i][j].rgbtBlue = round(Blue / count);

            }
        }
    }

    // copying new value of images.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }
    return;
}