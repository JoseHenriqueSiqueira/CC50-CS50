#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average of the red, green, and blue values
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Set each color component to the average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row in the image
    for (int i = 0; i < height; i++)
    {
        // Loop through each pixel in the row, swapping pixels across the horizontal axis
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average color of the surrounding pixels
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            int count = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        sumRed += temp[row][col].rgbtRed;
                        sumGreen += temp[row][col].rgbtGreen;
                        sumBlue += temp[row][col].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(sumRed / count);
            image[i][j].rgbtGreen = round(sumGreen / count);
            image[i][j].rgbtBlue = round(sumBlue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Define the Sobel operator kernels
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the magnitude of the gradient at the current pixel
            int Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            int Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        Gx_red += temp[row][col].rgbtRed * Gx[k + 1][l + 1];
                        Gx_green += temp[row][col].rgbtGreen * Gx[k + 1][l + 1];
                        Gx_blue += temp[row][col].rgbtBlue * Gx[k + 1][l + 1];
                        Gy_red += temp[row][col].rgbtRed * Gy[k + 1][l + 1];
                        Gy_green += temp[row][col].rgbtGreen * Gy[k + 1][l + 1];
                        Gy_blue += temp[row][col].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }

            int sobel_red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int sobel_green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int sobel_blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap the values at 255 to prevent overflow
            image[i][j].rgbtRed = sobel_red > 255 ? 255 : sobel_red;
            image[i][j].rgbtGreen = sobel_green > 255 ? 255 : sobel_green;
            image[i][j].rgbtBlue = sobel_blue > 255 ? 255 : sobel_blue;
        }
    }
    return;
}
