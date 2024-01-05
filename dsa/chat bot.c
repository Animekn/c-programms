#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 4096

// Replace 'YOUR_API_KEY' with your GPT-3.5 API key
#define API_KEY "YOUR_API_KEY"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, char *output) {
    strcat(output, (char *)contents);
    return size * nmemb;
}

char *generate_response(const char *prompt) {
    char *output = (char *)malloc(MAX_OUTPUT_LENGTH);
    output[0] = '\0';

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/engines/text-davinci-002/completions");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, prompt);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer " API_KEY);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            free(output);
            output = NULL;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return output;
}

int main() {
    printf("Text Bot: Hello! I am your friendly Text Bot. How can I assist you today?\n");

    char user_input[MAX_INPUT_LENGTH];

    while (1) {
        printf("You: ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, "exit") == 0 || strcmp(user_input, "quit") == 0 || strcmp(user_input, "bye") == 0) {
            printf("Text Bot: Goodbye! Have a great day!\n");
            break;
        } else {
            char prompt[MAX_INPUT_LENGTH + 15]; // Length of "You: " + Max input length + 1 for null-terminator
            snprintf(prompt, sizeof(prompt), "You: %s\nText Bot:", user_input);

            char *response = generate_response(prompt);
            if (response) {
                printf("%s\n", response);
                free(response);
            } else {
                printf("Text Bot: Sorry, an error occurred while generating the response.\n");
            }
        }
    }

    return 0;
}
