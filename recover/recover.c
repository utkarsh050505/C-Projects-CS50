#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BLOCK_SIZE 512

bool JPEG(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n"); //checking for valid number of inputs.
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Could not open the file\n"); //checking if the file opens correctly.
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    char file[8]; //getting a file with 8 char - 3 char for numbers + .jpg(4 char).
    FILE *img;
    int n = 0;

    while (fread(buffer, BLOCK_SIZE, 1, f) == 1)
    {
        if (JPEG(buffer) == true)
        {
            if (n != 0)
            {
                fclose(img); //closing the  previous image.
            }

            sprintf(file, "%03i.jpg", n++);
            img = fopen(file, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img); //writing on the new file.
        }

        else if (n > 0) // as in question all the image are back to back so if n > 0 this means we don't have to check for jpg again.
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }

    }

}

bool JPEG(uint8_t buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}