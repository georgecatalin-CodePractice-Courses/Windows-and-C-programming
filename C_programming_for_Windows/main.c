#include "utility_functions.h"
#include "macro_definition.h"

int main()
{

/*
   printf("\n|----- System Diagonists -----|\n");
   printf("\n Checking PC for problems...\n");
   system("systeminfo");
   */


    char *user_logged_in=NULL;
    user_logged_in=get_the_user_logged_at_the_computer_the_geek_way();
    printf("The user that is logged in currently in the long way ===> %s .\n", user_logged_in);

    char *user_logged_in_the_simple_way=NULL;
    user_logged_in_the_simple_way=get_the_user_logged_at_the_computer_the_simple_way();
    printf("The user that is logged in currently obtained in the simple way ===> %s .\n",user_logged_in_the_simple_way);

   //char *user = getenv("USERNAME");

  //printf("PATH : %s\n", getenv("PATH"));
   //printf("HOME : %s\n", getenv("HOME"));

   //printf("Hey, %s.\n",user);

    return 0;
}
