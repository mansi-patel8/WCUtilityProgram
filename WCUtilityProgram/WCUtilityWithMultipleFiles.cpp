/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to display the number of lines, words, and bytes contained in each input file using WC Utility found in most Unix systems for multiple files (two files here).
*/


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    struct fileInfo
    {
        int noLines = 0;
        int noWords = 0;
        int noBytes = 0;
        int characters, previousCharacter;
        string inputFileArg;
    } inputFile1Struct, inputFile2Struct;

    if (argc == 3)
    {
        //taking cmd line arguments and setting the varibles
        for (int counter = 0; counter < argc; counter++)
        {
            inputFile1Struct.inputFileArg = argv[1];
            inputFile2Struct.inputFileArg = argv[2];
        }

        ifstream inputFileBytes1(inputFile1Struct.inputFileArg, ios::binary);
        ifstream inputFile1(inputFile1Struct.inputFileArg);

        if (inputFileBytes1.is_open() && !(inputFileBytes1.peek() == ifstream::traits_type::eof()) &&
            inputFile1.is_open() && !(inputFile1.peek() == ifstream::traits_type::eof()))
        {
            //Bytes calculation for file 1
            inputFileBytes1.seekg(0, ios::end);
            inputFile1Struct.noBytes = inputFileBytes1.tellg();
            inputFileBytes1.close();

            //line and word calculation for file 1
            while ((inputFile1Struct.characters = inputFile1.get()) != EOF)
            {
                if (ispunct(inputFile1Struct.characters)) //check for punctuation
                {
                    if (isalpha(inputFile1Struct.previousCharacter))
                    {
                        inputFile1Struct.noWords++;
                    }
                }
                if (iswspace(inputFile1Struct.characters)) //check for whitespace and double whitespace
                {
                    if (isalpha(inputFile1Struct.previousCharacter) && !iswspace(inputFile1Struct.previousCharacter))
                    {
                        inputFile1Struct.noWords++;
                    }
                }
                if (inputFile1Struct.characters == '\n' || inputFile1Struct.characters == '\r') //check for new line
                {
                    inputFile1Struct.noLines++;
                }
                inputFile1Struct.previousCharacter = inputFile1Struct.characters; //set previousCharacter = characters to check for whitespace
            }
            inputFile1.close();
            cout << "Number of lines: " << inputFile1Struct.noLines << "\t"
                << "Number of words: " << inputFile1Struct.noWords << "\t"
                << setw(8) << "Number of Bytes: " << inputFile1Struct.noBytes << "\t"
                << inputFile1Struct.inputFileArg << endl;
        }
        else
        {
            cerr << "Error opening the first inputfile. \nPlease check if you file exists and it has data." << endl;
            return -1;
        }

        //For File 2
        ifstream inputFileBytes2(inputFile2Struct.inputFileArg, ios::binary);
        ifstream inputFile2(inputFile2Struct.inputFileArg);
        if (inputFileBytes2.is_open() && !(inputFileBytes2.peek() == ifstream::traits_type::eof()) &&
            inputFile2.is_open() && !(inputFile2.peek() == ifstream::traits_type::eof()))
        {
            //Bytes calculation for file 2

            inputFileBytes2.seekg(0, ios::end);
            inputFile2Struct.noBytes = inputFileBytes2.tellg();
            inputFileBytes2.close();
            //line and words calculations for file 2

            while ((inputFile2Struct.characters = inputFile2.get()) != EOF)
            {
                if (ispunct(inputFile2Struct.characters)) //check for punctuation
                {
                    if (isalpha(inputFile2Struct.previousCharacter))
                    {
                        inputFile2Struct.noWords++;
                    }
                }
                if (iswspace(inputFile2Struct.characters)) //check for whitespace and double whitespace
                {
                    if (isalpha(inputFile2Struct.previousCharacter) && !iswspace(inputFile2Struct.previousCharacter))
                    {
                        inputFile2Struct.noWords++;
                    }
                }
                if (inputFile2Struct.characters == '\n' || inputFile2Struct.characters == '\r') //check for new line
                {
                    inputFile2Struct.noLines++;
                }
                inputFile2Struct.previousCharacter = inputFile2Struct.characters; //set previousCharacter = characters to check for whitespace
            }
            inputFile2.close();

            cout << "Number of lines: " << inputFile2Struct.noLines << "\t"
                << "Number of words: " << inputFile2Struct.noWords << "\t"
                << setw(8) << "Number of Bytes: " << inputFile2Struct.noBytes << "\t"
                << inputFile2Struct.inputFileArg << endl;

            cout << "Number of lines: " << inputFile1Struct.noLines + inputFile2Struct.noLines << "\t"
                << "Number of words: " << inputFile1Struct.noWords + inputFile2Struct.noWords << "\t"
                << setw(8) << "Number of Bytes: " << inputFile1Struct.noBytes + inputFile2Struct.noBytes << "\t"
                << "Total" << endl;
        }
        else
        {
            cerr << "Error opening the second inputfile. \nPlease check if you file exists and it has data." << endl;
            return -2;
        }
    }
    else
    {
        cerr << "Invalid number of cmd arguments. \nPlease try again.\n";
    }

    return 0;
}