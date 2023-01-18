#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compress_backup(char* destination, char* directory){

    return 0;
}


int backup_job(char* destination, char* directory){
    char command[500]; 

    strcat(command, "cp ");
    strcat(command, directory); 
    strcat(command, " ");
    strcat(command, destination); 

    system(command);

    compress_backup(destination, directory);

    return 0;
}


int config_backup(void){
    char destination[100];
    char directory[100];
    char consent[100];
    
    printf("List a destination filepath for the backup to be stored: (ex. ~/Documents/):\n");
    scanf("%s", destination);

    printf("Enter the filepath to the upper-most directory you would like to include in the backup process (ex. ~/Documents/):\n");
    scanf("%s", directory);

    printf("The backup will be of '%s' and be saved at '%s', do you wish to proceed? (y/n):", directory, destination);
    scanf("%s", consent);

    if(strcmp(consent, "y") == 0){
        backup_job(destination, directory);
        return 0;
    }else{
        exit(EXIT_SUCCESS);
    }


    return 0;
}


int main(void){
    system("clear");

    char config_now[100];

    printf("Welcome to Serious Backup Agent\n");
    printf("Configure Backup Now(y/n): ");

    scanf("%s", config_now);
    printf("\n");

    if(strcmp("y", config_now) == 0){
        int config_backup_return = config_backup();

        if(config_backup_return != 0){
            printf("Error: Failed to configure backup job.\n");
            exit(EXIT_FAILURE);
        }
    }else if(strcmp("n", config_now) == 0){
        printf("Exiting now\n");
        exit(EXIT_SUCCESS);
    }else{
        printf("Error: incorrect input detected\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
