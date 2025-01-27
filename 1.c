#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *writeToFile(char *final, const char *filename) {
    // Open the file in write mode. This will overwrite the current content.
    FILE *file = fopen(filename, "w");

    // Check if the file was successfully opened.
    if (file == NULL) {
        printf("Could not open the file for writing.\n");
        return NULL;  // Exit the program if file can't be opened.
    }
    // New content to write to the file
    char *newContent = final;

    // Write the new content to the file
    fprintf(file, "%s", newContent);  // Or you can use fputs(file, newContent);

    // Close the file after writing
    fclose(file);

    printf("Success\n");

    return newContent;
}

char *readfile(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file for reading

    if (file == NULL) {  // Check if the file was successfully opened
        printf("Could not open the file.\n");
        return NULL;  // Exit if the file can't be opened
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char *content = (char *)malloc((filesize + 1) * sizeof(char));
    if (content == NULL){
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    fread(content, sizeof(char), filesize, file);
    content[filesize] = '\0';


    fclose(file);  // Close the file
    return content;
}


int main(){

    const char *filename = "text.txt";
    char *content = readfile(filename);
    int contentLength = strlen(content);
    char key[250] = "key";
    int direction = 5;

    char customAlphabet[250] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int customAlphabetLength = strlen(customAlphabet);

    char final[250] = "";
    int length = strlen(final);


    for (int i = 0; i < contentLength; i++){
        int found = 0;
        int charPosition = -1;

        for (int j = 0; j < customAlphabetLength; j++){
            if (content[i] == customAlphabet[j]){
                found = 1;
                charPosition = j;
                break;
            }   

        }
        if (found == 1){
            int iOffset = (charPosition + direction) % customAlphabetLength;
            if (iOffset < 0){
                // This checks if the offset is negative to make it a positive
                iOffset += customAlphabetLength;
            }
            final[length] = customAlphabet[iOffset];
        }
        else{
            final[length] = content[i];
        }
        length++;
    }
    if (content != NULL){
        printf("Final Message:\n%s", final);
        writeToFile(final, filename);
        free(content);
    }



    return 0;

}



