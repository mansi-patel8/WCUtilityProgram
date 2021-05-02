/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to display the number of lines, words, and bytes contained in each input file using WC Utility found in most Unix systems for single file only.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    int noLines = 0;
    int noWords = 0;
    int noBytes = 0;
    char characters, previousCharacter = 0;

    string inputFileArg; //vars for cmd input

    if (argc == 2)
    {
        //taking cmd line arguments and setting the varibles
        for (int counter = 0; counter < argc; counter++)
        {
            inputFileArg = argv[1];
        }

        //Bytes calculations
        ifstream inputFileBytes(inputFileArg, ios::binary);
        inputFileBytes.seekg(0, ios::end);
        noBytes = inputFileBytes.tellg();
        inputFileBytes.close();

        //words and lines calculation
        ifstream inputFile(inputFileArg);
        while ((characters = inputFile.get()) != EOF)
        {
            if (ispunct(characters))        //check for punctuation
            {
                if (isalpha(previousCharacter))
                {
                    noWords++;
                }
            }
            if (iswspace(characters))       //check for whitespace and double whitespace 
            {
                if (isalpha(previousCharacter) && !iswspace(previousCharacter))
                {
                    noWords++;
                }
            }
            if (characters == '\n' || characters == '\r')         //check for new line 
            {
                noLines++;
            }
            previousCharacter = characters;         //set previousCharacter = characters to check for whitespace
        }
        inputFile.close();

        cout << "Number of lines: " << noLines << endl
            << "Number of words: " << noWords << endl
            << setw(8) << "Number of Bytes: " << noBytes << endl;
    }
    else
    {
        cout << "Invalid command. \n Please try again.\n";
    }

    return 0;
}