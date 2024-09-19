#include "gui.h"



void clearTextBoxes() {
    memset(inputPath, 0, sizeof(inputPath));
}

void updateGUI() {
    if (IsKeyPressed(KEY_ENTER)) {
        inputPathActive = false;
        inputKeyActive = false;
        // clearTextBoxes();
    }
}

void drawGUI() {
    GuiLabel((Rectangle){200, 50-30, 200, 30}, "Path");
    GuiLabel((Rectangle){260-10, 200-90, 100, 30}, "Key (numbers)");

    if (GuiTextBox((Rectangle){200, 70-20, 200, 30}, inputPath, sizeof(inputPath), inputPathActive)) {
        inputPathActive = true;
        inputKeyActive = false;
    }

    if (GuiTextBox((Rectangle){260-10, 220-80, 100, 30}, inputKey, sizeof(inputKey), inputKeyActive)) {
        inputKeyActive = true;
        inputPathActive = false;
    }

    if (GuiButton((Rectangle){200-55, 300-85, 120, 30}, "Encrypt")) {
        if (strcmp(inputPath, "") != 0 && strcmp(inputKey, "") != 0) {
            file = fopen(inputPath, "rb");
            clearTextBoxes();
            if (file) {
                FILE *outputFile = fopen("encrypted_file.txt", "wb");
                if (outputFile) {
                    char buffer[1024];
                    size_t bytesRead;
                    
                    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                        int key = atoi(inputKey);
                        for (size_t i = 0; i < bytesRead; i++) {
                            buffer[i] = buffer[i] + key;
                        }
                        fwrite(buffer, 1, bytesRead, outputFile);
                    }
                    
                    fclose(file);
                    fclose(outputFile);
                } else {
                    fprintf(stderr, "Error: Unable to create output file\n");
                }
            } else {
                fprintf(stderr, "Error: Unable to open input file\n");
            }
        }
    }

    if (GuiButton((Rectangle){400-55, 300-85, 120, 30}, "Decrypt")) {
        if (strcmp(inputPath, "") != 0 && strcmp(inputKey, "") != 0) {
            file = fopen(inputPath, "rb");
            clearTextBoxes();
            if (file) {
                FILE *outputFile = fopen("decrypted_file.txt", "wb");
                if (outputFile) {
                    char buffer[1024];
                    size_t bytesRead;
                    
                    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                        int key = atoi(inputKey);
                        for (size_t i = 0; i < bytesRead; i++) {
                            buffer[i] = buffer[i] - key;
                        }
                        fwrite(buffer, 1, bytesRead, outputFile);
                    }
                    
                    fclose(file);
                    fclose(outputFile);
                } else {
                    fprintf(stderr, "Error: Unable to create output file\n");
                }
            } else {
                fprintf(stderr, "Error: Unable to open input file\n");
            }
        }
    }
}
