#include <stdio.h>
#include <unistd.h>

int main() {

    char word1[100], word2[100], result[200];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    snprintf(result, sizeof(result), "%s %s", word1, word2);

    printf("Your string says: \n%s\n", result);

    sleep(3);

    int number1, number2, sum;

    printf("Enter First Number: ");
    scanf("%d", &number1);

    printf("Enter Second Number: ");
    scanf("%d", &number2);

    sum = number1 + number2;

    printf("The sum of your numbers, which are %d + %d, is: %d\n", number1, number2, sum);

    return 0;

}
