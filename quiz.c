#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genQuestion(int difficulty);
int answerQuestion(int correctAnswer);
void response(int correct);

int main(void)
{
    int numberOfQuestions = 0;
    int questionDifficulty = 0;
    int questionNumber = 0;
    int correctAnswer = 0;
    int numberCorrect = 0;
    int correct = 0;

    /* Prompt user for how many questions for test and validate */
    do
    {
        printf("%s", "How many questions for this test (1-20)? ");
        scanf("%d", &numberOfQuestions);
    }while(numberOfQuestions < 1 || numberOfQuestions > 20);

    /* Prompt user for difficulty and validate */
    do
    {
        printf("%s", "Select difficulty (1-4): ");
        scanf("%d", &questionDifficulty);
    }while(questionDifficulty < 1 || questionDifficulty > 4);

    srand(time(NULL));

    /* Generate Question, get response, and say whether correct or not */
    for(questionNumber = 1; questionNumber <= numberOfQuestions; questionNumber++)
    {
        correctAnswer = genQuestion(questionDifficulty);
        correct = answerQuestion(correctAnswer);
        response(correct);
        if(correct)
        {
            numberCorrect++;
        }
        else
        {
            printf("The correct answer was %d\n", correctAnswer);
        }
    }

    /* Give final score */
    printf("Your score was %d/%d\n", numberCorrect, numberOfQuestions);
    return 0;
}

int genQuestion(int difficulty)
{
    static int questionNum = 1;
    int answer = 0;
    int operator = 0;
    int max = 0;
    int min = 0;
    int operand1 = 0;
    int operand2 = 0;

    /* Find range of values based on difficulty */
    switch (difficulty)
    {
        case 1:
            max = 10;
            min = 1;
            break;
        case 2:
            max = 50;
            min = 1;
            break;
        case 3:
            max = 100;
            min = 1;
            break;
        case 4:
            max = 100;
            min = -100;
            break;
        default:
            puts("ERROR");
            break;
    }

    /* Get random operands and operator */
    operand1 = rand() % (max - min + 1) + min;
    operand2 = rand() % (max - min + 1) + min;
    operator = rand() % 4;

    /* Print the question */
    printf("Question %d: ", questionNum++);
    switch (operator)
    {
        case 0:
            answer = operand1 + operand2;
            printf("%d + %d =\n", operand1, operand2);
            break;
        case 1:
            answer = operand1 - operand2;
            printf("%d - %d =\n", operand1, operand2);
            break;
        case 2:
            answer = operand1 * operand2;
            printf("%d * %d =\n", operand1, operand2);
            break;
        case 3:
            while(operand2 == 0)
            {
                operand2 = rand() % (max - min + 1) + min;
            }
            answer  = operand1 / operand2;
            printf("%d / %d =\n", operand1, operand2);
            break;
        default:
            puts("ERROR");
            break;
    }
    return answer;
}

int answerQuestion(int correctAnswer)
{
    int userAnswer = 0;
    printf("%s", "Enter Answer: ");
    scanf("%d", &userAnswer);
    return !(correctAnswer - userAnswer);
}

void response(int correct)
{
    int responseNumber = rand() % 3;
    if(correct)
    {
        switch (responseNumber)
        {
            case 0:
                puts("Nice!");
                break;
            case 1:
                puts("Good job!");
                break;
            case 2:
                puts("You're right!");
                break;
            default:
                puts("ERROR");
                break;
        }
    }
    else
    {
        switch (responseNumber)
        {
            case 0:
                puts("Sorry!");
                break;
            case 1:
                puts("Incorrect!");
                break;
            case 2:
                puts("Wrong!");
                break;
            default:
                puts("ERROR");
                break;
        }
    }
}