#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(){
    int score = 0;
    char password[50] = "";

    int pass_min_length = 5;
    size_t pass_max_length = sizeof(password);

    // flags to see what we found
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    int has_symbol = 0;

    printf("Enter the Your Password:  ");
    if (fgets(password, pass_max_length, stdin) == NULL){
        return 1;
    }
    // drop the trailing newline from fgets
    password[strcspn(password, "\n")] = '\0';

    size_t pass_length = strlen(password);
    
    if ( pass_length >= pass_min_length){

        char ch ;
        for(size_t i = 0; i < pass_length ; i++){
            ch = password[i];

            if(ch >= 'A' && ch <= 'Z'){
                has_upper = true;
            }else if(ch >= 'a' && ch <= 'z'){
                has_lower = true;
            }else if(ch >= '0' && ch <= '9'){
                has_digit = true;
            }else if(ch >= 32 && ch <= 126){
                // printable ascii range for symbols
                has_symbol = 1;
            }

            // stop early if all 4 categories already exist
            if(has_upper  && has_lower && has_digit && has_symbol){
                break;
            }

        }

        // bonus points for longer passwords
        if (pass_length > 15) {
            score += 4;
        } else if (pass_length >= 9) {
            score += 2;
        }

        if (has_upper)  score += 1;
        if (has_lower)  score += 1;
        if (has_digit)  score += 1;
        if (has_symbol) score += 1;

        printf("\nPassword Score: %d / 8\n", score);

        // evaluate final strength
        if (score <= 3) {
            printf("Strength: Weak\n");
        } else if (score <= 6) {
            printf("Strength: Moderate\n");
        } else {
            printf("Strength: Strong\n");
        }

        if (!(has_upper && has_lower && has_digit && has_symbol)) {
            printf("Include uppercase, lowercase, numbers, and symbols to maximize strength.\n \n");
        }
    }
    else {
        printf("\nThe password is too short -(must be more than %d characters)-\n", pass_min_length);
    }

    return 0;
}