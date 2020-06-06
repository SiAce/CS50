#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
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
            BYTE tmp_blue = image[i][j].rgbtBlue;
            BYTE tmp_green = image[i][j].rgbtGreen;
            BYTE tmp_red = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtBlue = tmp_blue;
            image[i][width - j - 1].rgbtGreen = tmp_green;
            image[i][width - j - 1].rgbtRed = tmp_red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int tmp_blue = 0;
            int tmp_green = 0;
            int tmp_red = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    tmp_blue += image[i + k][j + l].rgbtBlue;
                    tmp_green += image[i + k][j + l].rgbtGreen;
                    tmp_red += image[i + k][j + l].rgbtRed;
                }
            }

            new_image[i][j].rgbtBlue = tmp_blue / 9;
            new_image[i][j].rgbtGreen = tmp_green / 9;
            new_image[i][j].rgbtRed = tmp_red / 9;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
            // image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            // image[i][j].rgbtRed = new_image[i][j].rgbtRed;
            image[i][j] = new_image[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
