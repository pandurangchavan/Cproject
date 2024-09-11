#include <stdio.h>
#include <string.h>

int main() {
    // Open the file in read and write mode
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Define a buffer to read each line
    char buffer[100];
    int lineNumber = 3; // Line number where you want to insert data

    // Move to the end of the file
    fseek(file, 0, SEEK_END);

    // Determine the file size
    long fileSize = ftell(file);

    // Start from the end and shift lines down to make room for new data
    for (long i = fileSize; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        if (fgets(buffer, sizeof(buffer), file)) {
            fseek(file, i + strlen(buffer), SEEK_SET);
            fprintf(file, "%s", buffer);
        }
    }

    // Move to the specific location and insert new data
    fseek(file, (lineNumber - 1) * sizeof(buffer), SEEK_SET);

    int newValue = 42;
    float newFloat = 3.14;

    // Format the new data using sprintf
    char newData[100];
    sprintf(newData, "Inserted data: %d %.2f\n", newValue, newFloat);

    // Write the new data to the file
    fprintf(file, "%s", newData);

    // Close the file
    fclose(file);

    return 0;
}

