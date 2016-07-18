#include <iostream>
#include <string>
#include <cstring> // strlen
#include <cassert> // assert
using namespace std;

// Utility function to split a string by a delimitor
char** str_split(char* a_str, const char a_delim = '/')
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    // Count how many elements will be extracted.
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    // Add space for trailing token.
    count += last_comma < (a_str + strlen(a_str) - 1);

    // Add space for terminating null string so caller
    //   knows where the list of returned strings ends.
    count++;

    result = (char**) malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void splitName(char fileName[])
{
    cout << strlen(fileName) << endl;
    char *ch;
    ch = strtok(fileName, "/");

    while (ch != NULL)
    {
        cout << ch << endl;
        ch = strtok(NULL, "/");
    }
}

void parseInputName(char** tokens)
{
    char* tokenPart;
    if (tokens)
    {
        for (int i = 0; *(tokens + i); i++)
        {
            tokenPart = *(tokens + i);
            cout << tokenPart << " : " << strlen(tokenPart) << endl;
        }
    }
}

void getUserInput()
{
    string input_string;

    cout << "Enter a string: ";
    // Ignore the contents in current buffer before reading the next input.
    //cin.ignore();
    getline(cin, input_string);

    unsigned int len = input_string.length();
    char* user_name = new char[len];

    strcpy(user_name, input_string.c_str());


    cout << "Input Str: " << input_string << endl;
    cout << "User Name: " << user_name << endl;
    
    char** tokens;
    char* tokenPart;
    tokens = str_split(user_name);
    if (tokens)
    {
        for (int i = 0; *(tokens + i); i++)
        {
            tokenPart = *(tokens + i);
            cout << tokenPart << " : " << strlen(tokenPart) << endl;
        }
    }

    parseInputName(tokens);
}

void parseInputCommand(string inputCmd)
{
    unsigned int len         = inputCmd.length();
    char*       userCmd     = new char[len];

    strcpy(userCmd, inputCmd.c_str());
    cout << "Given User Cmd: " << userCmd << endl;

    char** userCmdTokens;
    char*  tokenPart;
    userCmdTokens = str_split(userCmd);

    cout << "0: " << userCmdTokens << endl;
    if (userCmdTokens)
    {
        cout << "1: " << *(userCmdTokens + 0) << endl;
        for (int i = 0; *(userCmdTokens + i); i++)
        {
            tokenPart = *(userCmdTokens + i);
            cout << tokenPart << " : " << strlen(tokenPart) << endl;
        }
    }
}

void getInputCommand()
{
    string inputCmd;
    cout << "Enter the command: " << endl;

    //cin.ignore();
    getline(cin, inputCmd);

    parseInputCommand(inputCmd);
}

int main()
{
    {
        //char months[] = "JAN/FEB/MAR/APR/MAY/JUN/JUL/AUG/SEP/OCT/NOV/DEC";
        char months[] = "JAN/FEBa/MARCH/MAY/JUNE/NOVEMBER/DECEMBER";
        char** tokens;

        cout << "months = [" << months << "]" << endl;

        tokens = str_split(months);

        if (tokens)
        {
            int i;
            for (i = 0; *(tokens + i); i++)
            {
                //printf("month=[%s]\n", *(tokens + i));
                cout << "month[" << i << "] = " << *(tokens + i) << endl;
                free(*(tokens + i));
            }
            cout << endl;
            free(tokens);
        }

        char months2[] = "JAN/FEBa/MARCH/MAY/JUNE/NOVEMBER/DECEMBER";
        //splitName(months2);
        getUserInput();
        //getInputCommand();
    }

    {
        string tok = "My name is Hi.How Are!You!";
        cout << tok << endl;

        for (int i = 0; i < tok.length(); ++i)
        {
            tok[i] = tolower(tok[i]);
            if (ispunct(tok[i])) {
                tok.erase(i--,1);
            }
        }

        cout << tok << endl;

    }
    cout << endl;
    return 0;
}

