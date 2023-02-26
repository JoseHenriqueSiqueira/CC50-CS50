#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // Open input file (forensic image)
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // Create a buffer to store 512 bytes from the memory card
    BYTE buffer[512];

    // Count amount of JPEG files found
    int jpeg_count = 0;

    // File pointer for output JPEG file
    FILE *outptr = NULL;

    // Read memory card until the end of file
    while (fread(buffer, sizeof(BYTE) * 512, 1, inptr))
    {
        // Check if the start of a JPEG file is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the output file pointer if it's open
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // Create a new filename for the output JPEG file
            char filename[8];
            sprintf(filename, "%03d.jpg", jpeg_count++);

            // Open the new output JPEG file for writing
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
        }

        // Write to the output JPEG file if it's open
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outptr);
        }
    }

    // Close the last output file pointer
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    // Close input file (forensic image)
    fclose(inptr);

    return 0;
}