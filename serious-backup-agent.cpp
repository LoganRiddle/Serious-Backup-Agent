#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;


int compress_backup(string destination, string directory){
    string pre_command;
    string name = "Vince";

    pre_command = "tar --create --file " + name + "-Backup.tar.gz " + directory;
    
    const char* command = pre_command.c_str();

    system(command);

    return 0;
}


int backup_job(string destination, string directory){
    string pre_command; 

    pre_command = "cp -r " + directory + " " + destination; 

    const char* command = pre_command.c_str();

    //cout << command;

    system(command);

    // compress_backup(destination, directory);

    return 0;
}


int config_backup(void){
    string destination;
    string directory;
    string consent;
    
    cout << "List a destination filepath for the backup to be stored: (ex. ~/Documents/):\n";
    cin >> destination;

    cout << "Enter the filepath to the upper-most directory you would like to include in the backup process (ex. ~/Documents/):\n";
    cin >> directory;

    cout << "The backup will be of '" << directory << "' and be saved at '" << destination << "', do you wish to proceed? (y/n):";
    cin >> consent;

    if(consent == "y"){
        backup_job(destination, directory);
        return 0;
    }else{
        exit(EXIT_SUCCESS);
    }


    return 0;
}


int main(void){
    system("clear");

    string config_now;

    cout << "Welcome to Serious Backup Agent\n";
    cout << "Configure Backup Now(y/n): ";

    cin >> config_now;
    cout << "\n";

    if("y" == config_now){
        int config_backup_return = config_backup();

        if(config_backup_return != 0){
            cout << "Error: Failed to configure backup job.\n";
            exit(EXIT_FAILURE);
        }
    }else if("n" == config_now){
        cout << "Exiting now\n";
        exit(EXIT_SUCCESS);
    }else{
        cout << "Error: incorrect input detected\n";
        exit(EXIT_FAILURE);
    }

    return 0;
}
