#include <stdio.h>
#include <string.h>

// Function to count total number
// of words in the string
int countWords(char* s)
{
    if (s == NULL || strlen(s) == 0)
        return 0;

    int count = 0;

    char* token = strtok(s, "/");

    while (token != NULL) {
        ++count;
        token = strtok(NULL, "/");
    }

    return count;
}

int main()
{
    char str[] = "One/ two /      three/n four/tfive ";

    // Print the result
    printf("No of words: %d\n", countWords(str));

    return 0;
}
