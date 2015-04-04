#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

    //Initialize "command" to store user's shell command
    string command = "Empty";

    //Initialize "cwd" to store user's current working directory
    string cwd = "Empty"

    //Create queue to track user commands
    //I chose to use a deque because it has built in iterators
    queue<string> command_history;

    //Loop until user types "exit"
    while(true){
        //Print current directory
        cout << "Current Directory>";

        //Ask user for command
        cin >> command;

        //Add command to command_history
        command_history.push(command);

        //if command_history has 11 elements, remove the oldest
        if (command_history.size() == 11){
            command_history.pop();
        }

        //If user command is exit, exit the loop
        if (command=="exit"){
            break;
        }

        //If user command is history, print the ten previous commands
        if (command == "history"){
            string previous_command;

            for(int it=0; it < command_history.size();it++){
                previous_command = command_history.front();
                cout << it << " " << previous_command << "\n";
                command_history.pop();
                command_history.push(previous_command);
            }
        }

        //If user command is cd, change the current directory
        if (command=="cd"){
            cout << "CD\n";
        }


        //If user command is ls, list all elements in the current directory
        if (command=="ls"){
            cout << "LS\n";
        }

        //If user command is pwd, print the current directory
        if (command=="pwd"){
            cout << cwd << "\n";
        }
    }


    return 0;
}