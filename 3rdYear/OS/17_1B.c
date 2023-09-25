/**
 * ::------ TEAM DETAILS ------::
   Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 02-08-2023
 */

/**
 * ::------ ASSIGNMENT DETAILS ------::
 * Assignment 1B: Program to get and set environment variables
   using system calls
 *
 * Problem Definition:
   Program to GET and SET the Environment variable and to know
   use of getenv and setenv system calls
 *
 * (i) Display the following  environment variables using getenv call:
    - USER (your login name)
    - HOME (the path name of your home directory)
    - HOST (the name of the computer you are using)
    - ARCH (the architecture of the computer's processor)
    - DISPLAY (the name of the computer screen to display X windows)
    - PRINTER (the default printer to send print jobs)
    - PATH (the directories the shell should search to find a command)

 * (ii) Now, Set two new environment variables and display them.
 *
 * ::------ INPUT DESCRIPTION ------::
   This program takes optional command-line arguments that specify the
   name and value of the new environment variables. If nothing is specified
   for a given parameter, the hard-coded values within the program are used.
 *
   The input is of the form:
    ./17_1B [optional: first_ENV_VAR_NAME] [optional: first_ENV_VAR_VALUE] [optional: second_ENV_VAR_NAME] [optional: second_ENV_VAR_VALUE]
 * See the sample input section for more details.
 *
 * ::------ OUTPUT DESCRIPTION ------::
 * The program prints the values of the environment variables given
   in the question. Then the program prints the value of the two new environment
   variables.
 */

/**
 * ::------ COMPILATION COMMAND ------::
    gcc 17_1B.c -o 17_1B -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
    ./17_1B [optional: first_ENV_VAR_NAME] [optional: first_ENV_VAR_VALUE] [optional: second_ENV_VAR_NAME] [optional: second_ENV_VAR_VALUE]
 */
/**
 * Sample Input: ./17_1B
 * Sample Output:
    ============================ getenv =================================
    [.. the getenv output for the specified environment ..]

    ================ setenv ===================
    ENVIRON_KEY1=TEAM17
    ENVIRON_KEY2=IT_UG_3
 */

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Print the components of the PATH variable in a better way
 * @param PATH The value of the PATH environment variable
 * @param delim The delimiter
 */
void tokenize_path(char *PATH, const char *delim)
{
    char *path_component = strtok(PATH, delim);
    int char_count = 0, curr_char_count = 0, chars_per_line = 50;

    printf("\t");

    /* until there are tokens present in string: */
    while (path_component != NULL)
    {
        curr_char_count = strlen(path_component);
        if (curr_char_count > chars_per_line)
        {
            printf("\n%s", path_component); /* print the token */
            char_count = 0;
        }
        else if (char_count + curr_char_count > chars_per_line)
        {
            printf("\n%s | ", path_component);
            char_count = 0;
        }
        else
        {
            printf("%s | ", path_component);
            char_count += curr_char_count;
        }
        path_component = strtok(NULL, delim); /* get next token */
    }
}

/**
 * @brief Print a specified environment variable
 * @param KEY name of the environment variable
 */
void print_env_variable(const char *KEY)
{
    char *VALUE = getenv(KEY), msg[50];
    if (VALUE != NULL && strcmp(KEY, "PATH") != 0)
        printf("%s=%s\n", KEY, VALUE);
    else if (VALUE != NULL && strcmp(KEY, "PATH") == 0)
    {
        printf("%s=", KEY);
        tokenize_path(VALUE, ":");
    }
    else
    {
        sprintf(msg, "%s does not exist in the environment", KEY);
        errno = EINVAL; /* Invalid argument */
        perror(msg);    /* handle error */
    }
}

/**
 * @brief The main function
 * @param argc number of command-line arguments
 * @param argv the command-line arguments as an array of character arrays
 * @return int return value of main
 */
int main(int argc, char **argv)
{
    /* getenv - GET ENVIRONMENT VARIABLES */
    const char *env_vars[] = {"USER", "HOME", "HOST", "ARCH", "DISPLAY", "PRINTER", "PATH"};
    size_t i, no_of_env_vars = 7;

    printf("============================ getenv =================================\n");
    /* print all the specified environment variables */
    for (i = 0; i < no_of_env_vars; i++)
        print_env_variable(env_vars[i]);

    /* setenv - SET ENVIRONMENT VARIABLES */
    printf("\n\n================ setenv ===================\n");
    char ENV_KEY1[20] = "ENVIRON_KEY1", ENV_KEY2[20] = "ENVIRON_KEY2";
    char ENV_VALUE1[20] = "TEAM17", ENV_VALUE2[20] = "IT_UG_3";

    /* interpreting the command-line arguments */
    if (argc >= 2)
        strcpy(ENV_KEY1, argv[1]);
    if (argc >= 3)
        strcpy(ENV_VALUE1, argv[2]);
    if (argc >= 4)
        strcpy(ENV_KEY2, argv[3]);
    if (argc >= 5)
        strcpy(ENV_VALUE2, argv[4]);

    /* set the environment variables */
    if (setenv(ENV_KEY1, ENV_VALUE1, 0) < 0 || setenv(ENV_KEY2, ENV_VALUE2, 0) < 0)
        perror("Error in setenv"); /* error in setting the env var */
    else
    {
        print_env_variable(ENV_KEY1);
        print_env_variable(ENV_KEY2);
    }
    printf("\n");

    /* unset the environment variables */
    if (unsetenv(ENV_KEY1) < 0 || unsetenv(ENV_KEY2) < 0)
        perror("Error in unsetenv"); /* handle error */

    return 0;
}
