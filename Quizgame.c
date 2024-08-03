#include <stdio.h>
#include <string.h>

// Structure to represent a quiz question
struct Question {
    char questionText[100];
    char options[4][50];
    int correctOption;
};

// Function to display a question and its options
void displayQuestion(struct Question question) {
    printf("%s\n", question.questionText);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
    printf("Enter your answer (1-4): ");
}

int main() {
    // Define an array of quiz questions
    struct Question questions[] = {
        { "What is the capital of France?", { "Paris", "London", "Berlin", "Madrid" }, 1 },
        { "Which planet is known as the Red Planet?", { "Mars", "Venus", "Jupiter", "Saturn" }, 1 },
        { "Who wrote the play 'Romeo and Juliet'?", { "William Shakespeare", "Jane Austen", "Charles Dickens", "Leo Tolstoy" }, 1 }
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;

    printf("Welcome to the Quiz Game!\n");

    // Loop through the questions
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer >= 1 && userAnswer <= 4) {
            if (userAnswer == questions[i].correctOption) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer was: %s\n", questions[i].options[questions[i].correctOption - 1]);
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
        }
    }

    printf("Your final score: %d out of %d\n", score, numQuestions);
    return 0;
}
