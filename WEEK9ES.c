#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAMELENGTH 50

// prototypes
void printBelowAverage(const char **names, const int *scores, int count, float average);
int findTopScore(const int *scores, int count);
void sortScores(int *scores, char **names, int count);

int main()
{
    int studentsnum;
    printf("enter number of students: ");
    scanf("%d", &studentsnum);

    // dynamically allocate memory for student names and scores
    char **names = (char **)malloc(studentsnum * sizeof(char *));
    int *scores = (int *)malloc(studentsnum * sizeof(int));

    if (names == NULL || scores == NULL)
    {
        printf("memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < studentsnum; i++)
    {
        printf("name of student %d: ", i + 1);
        names[i] = (char *)malloc(MAXNAMELENGTH * sizeof(char));
        scanf("%s", names[i]);

        printf("score of student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    float average = 0;
    for (int i = 0; i < studentsnum; i++)
    {
        average += scores[i];
    }
    average /= studentsnum;

    printf("\naverage score: %.2f\n", average);

    printBelowAverage((const char **)names, scores, studentsnum, average);

    sortScores(scores, names, studentsnum);

    printf("\nhighest test score : %d\n", scores[0]);
    printf("top one: %s\n", names[0]);

    for (int i = 0; i < studentsnum; i++)
    {
        free(names[i]);
    }
    free(names);
    free(scores);

    return 0;
}

void printBelowAverage(const char **names, const int *scores, int count, float average)
{
    printf("\nbelow avarege score:\n");
    for (int i = 0; i < count; i++)
    {
        if (scores[i] < average)
        {
            printf("%s is below avarege, try to work hard the next time\n", names[i]);
        }
    }
}

int findTopScore(const int *scores, int count)
{
    int maxIndex = 0;
    for (int i = 1; i < count; i++)
    {
        if (scores[i] > scores[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void sortScores(int *scores, char **names, int count)
{
    // Bubble sort for simplicity
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (scores[j] < scores[j + 1])
            {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                char tempName[MAXNAMELENGTH];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
}
