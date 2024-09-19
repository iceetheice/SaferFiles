#include "encryption.h"
#include <stdio.h>
#include <stdlib.h>


void encrypt(const char *inputPath, const char *outputPath, int key) {
    FILE *file = fopen(inputPath, "rb");
    if (file) {
        FILE *outputFile = fopen(outputPath, "wb");
        if (outputFile) {
            char buffer[1024];
            size_t bytesRead;

            while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                for (size_t i = 0; i < bytesRead; i++) {
                    buffer[i] = buffer[i] + key;
                }
                
                size_t bytesWritten = fwrite(buffer, 1, bytesRead, outputFile);
                if (bytesWritten != bytesRead) {
                    perror("Error: Writing to output file");
                    fclose(file);
                    fclose(outputFile);
                    return;
                }
            }

            fclose(file);
            fclose(outputFile);
        } else {
            perror("Error: Unable to create output file");
        }
    } else {
        perror("Error: Unable to open input file");
    }
}

void decrypt(const char *inputPath, const char *outputPath, int key) {
    FILE *file = fopen(inputPath, "rb");
    if (file) {
        FILE *outputFile = fopen(outputPath, "wb");
        if (outputFile) {
            char buffer[1024];
            size_t bytesRead;

            while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                for (size_t i = 0; i < bytesRead; i++) {
                    buffer[i] = buffer[i] - key;
                }
                
                size_t bytesWritten = fwrite(buffer, 1, bytesRead, outputFile);
                if (bytesWritten != bytesRead) {
                    perror("Error: Writing to output file");
                    fclose(file);
                    fclose(outputFile);
                    return;
                }
            }

            fclose(file);
            fclose(outputFile);
        } else {
            perror("Error: Unable to create output file");
        }
    } else {
        perror("Error: Unable to open input file");
    }
}
