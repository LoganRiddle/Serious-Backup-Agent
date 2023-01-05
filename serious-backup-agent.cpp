#include <iostream>
#include <string>

using namespace std;


int cleanup(){
    //  Deletes temp
    const char* clean_command = "rm -rf .backup_job";
    system(clean_command);

    return 0;
}


int compress_backup(string destination, string directory, string name){
    string pre_comp_command;

    // Compresses temporary backup folder
    pre_comp_command = "tar --create --file " + name + ".tar.gz .backup_job";
    const char* comp_command = pre_comp_command.c_str();
    system(comp_command);

    return 0;
}


int backup_job(string destination, string directory, string name){
    string pre_copy_command; 
    string pre_move_command;
    
    // Makes temp hidden folder to house backup
    const char* make_command = "mkdir .backup_job";
    system(make_command);

    // Copies chosen directory to temp backup folder
    pre_copy_command = "cp -r " + directory + " .backup_job"; 
    const char* copy_command = pre_copy_command.c_str();
    system(copy_command);

    compress_backup(destination, directory, name);

    pre_move_command = "mv " + name + ".tar.gz " + destination;
    const char* move_command =  pre_move_command.c_str();
    system(move_command);

    cleanup();

    return 0;
}


int config_backup(void){
    string destination;
    string directory;
    string name;
    string consent;
    
    cout << "List a destination filepath for the backup to be stored: (ex. ~/Documents/):\n";
    cin >> destination;

    cout << "Enter the filepath to the upper-most directory you would like to include in the backup process (ex. ~/Documents/):\n";
    cin >> directory;

    cout << "Enter what you would like to name the backup:\n";
    cin >> name;

    cout << "The backup will be of '" << directory << "' named '" << name << "' and be saved at '" << destination << "', do you wish to proceed? (y/n):";
    cin >> consent;

    if(consent == "y"){
        backup_job(destination, directory, name);
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
