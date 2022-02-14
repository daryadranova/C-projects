// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file.Your program should first read the 
    //header from the input file and write the header to the output file. 
    //Recall that this header is always exactly 44 bytes long.
    
    int8_t buff[HEADER_SIZE]; //куда мы будем копировать заголовок из инпута

    fread(buff, sizeof(buff), 1, input); //мы прочитали, сохранили в буфер ровно 44 элемента
    fwrite(buff, sizeof(buff), 1, output); //ровно эти 44 элемента мы записали в новый файл из буфера 

    int16_t sample;
    
    while(fread(sample, sizeof(sample), 1, input))
    {
        sample *= factor;
        fread(sample, sizeof(sample), 1, output);
    }
    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
