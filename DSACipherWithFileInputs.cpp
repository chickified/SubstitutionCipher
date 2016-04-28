//======================================//
//            DSA MINI PROJECT          //
//         *Substitution Cipher*        //
//         Done By: Nestor Lee          //
//                  Tay Wei Kian        //
//                  Xiao Huiyong        //
//         Class : DCPE/2B/04           //
//======================================//
#include <iostream> // Standard Input/Ouput Stream
#include <cstdlib> // Needed in this program for using system("CLS") function to clear screen
#include <vector>  // Needed in this program to allow for use with Vector functions
#include <fstream> // Needed in this program to allow for file inputs and outputs
using namespace std;

/* Main Program starts at Line 225
   Decipher Function starts at Line 118
   Cipher Function starts at Line 19 */

void cipher(void) // Function to Cipher Message
{
    int k,j,three=0,temp1=0,temp2=0,one=0,two=0;
    char choice3; // For choosing to type or file input
    char exit; // For exiting function
    vector<int> eMSG;
    string ogMSG;
    system("CLS");

    start: // Goes to here when goto start; executed inside this function
    cout << "Do you wish to input a file to cipher or manually type it?";
    cout << "\n\n1. Input a file";
    cout << "\n\n2. Manually type it";
    cout << "\n\nEnter your choice: ";
    cin >> choice3;

    if(choice3=='1' || choice3=='2') // If user chooses File Input or Manual
    {
        if(choice3=='1')
        {
            ifstream myRedFile; //Initalise myRedFile
            myRedFile.open("C:\\Users\\Nestor\\Desktop\\needcipher.txt"); // Directory needs to be changed from Computer to Computer
            if (myRedFile.is_open()) // If file is successfully opened
            {
                while (!myRedFile.eof()) //Continues looping until the end of file
                {
                    getline(myRedFile,ogMSG); // Getline used because of spacing
                }
            }
            else // Shows up when File Input Error
            {
                system("CLS");
                goto start;
                cout << "There is some error opening the file.";
                cout << "Please try again.";
            }
            myRedFile.close(); // Closes file when operation complete
            k=ogMSG.size();
            for(int count=0;count<k;count++) // Loop to convert character to Octal value  - Base 8 conversion
            {
                one=ogMSG[count]%8;
                temp1=ogMSG[count]/8;
                two=temp1%8;
                temp2=temp1/8;
                three=temp2%8;
                eMSG.push_back(three+1);
                eMSG.push_back(two+2);
                eMSG.push_back(one+2);
            }
            cout << "Enter this code the next time you want to decrypt this message: " << endl;
            ofstream fout("C:\\Users\\Nestor\\Desktop\\ciphered.txt"); //Directory needs to be changed from Computer to Computer
            for(int r=0;r<eMSG.size();r++)
            {
                cout << eMSG[r]; //Displays contents inside Vector eMSG
                fout << eMSG[r]; //Stores data into file name ciphered.txt
            }
            fout.close();
            cout << "\n\nA file called ciphered.txt is also saved in the same directory.";
            cout << "\nEnter anything to exit back to menu.";
            cin >> exit;
        }
        if(choice3=='2') // If user wants to manually type in the message he wanted to encrypt
        {
            cout << "Enter the message you want to encrypt and terminate with a ~ symbol.\n";
            getline(cin, ogMSG, '~'); // Terminate with ~
            cout << ogMSG << endl;
            k=ogMSG.size();
            for(int count=0;count<k;count++) // Loop to convert to Octal - Base 8
            {
                one=ogMSG[count]%8;
                temp1=ogMSG[count]/8;
                two=temp1%8;
                temp2=temp1/8;
                three=temp2%8;
                eMSG.push_back(three+1);
                eMSG.push_back(two+2);
                eMSG.push_back(one+2);
            }
            cout << "Enter this code the next time you want to decrypt this message: " << endl;
            ofstream fout("C:\\Users\\Nestor\\Desktop\\ciphered.txt"); //needs to be changed from comp to comp
            for(int r=0;r<eMSG.size();r++)
            {
                cout << eMSG[r]; // Outputs contents of array
                fout << eMSG[r]; // Writes to file
            }
            fout.close(); // Closes file
            cout << "\n\nA file called ciphered.txt is also saved in the same directory.";
            cout << "\nEnter anything to exit back to menu.";
            cin >> exit;
            }
        }
    else // Goes to here if only user does not enter choice 1 or 2
    {
        system("CLS");
        cout << "You have entered an invalid choice. Please try again.";
        goto start;
    }
}

void decipher(void) // Function to DeCipher Message
{
    system("CLS");
    string dMSG; //String used to store the Number Code
    int four,five=0,six=0;
    char seven;
    char exit1; //Used to exit the program
    vector <char> aMSG; //Vector to store the DeCipher Message

    start:
    cout << "Do you wish to enter the code manually or by a file input?";
    cout << "\n\n1. Enter code by file input. ";
    cout << "\n\n(Please ensure that the name of the text file is named ciphered.txt and located in the same directory.)";
    cout << "\n\n2. Enter code manually.";
    char choice2;
    cout << "\n\nEnter your choice: ";
    cin >> choice2;

    if(choice2=='1' || choice2=='2') //If function to determine if wants to File Input or Manual type Number Code
    {
        if(choice2=='1')
        {
            ifstream myReadFile;
            myReadFile.open("C:\\Users\\Nestor\\Desktop\\ciphered.txt"); // Directory Needs to be Changed from Computer from Computer
            if (myReadFile.is_open()) //If file is successfuly opened or not
            {
                while (!myReadFile.eof()) //Loops until end of file
                {
                    myReadFile >> dMSG; // Inputs contents of file into string dMSG
                }
            }
            else //If file has error in opening
            {
                system("CLS");
                goto start;
                cout << "There is some error opening the file.";
                cout << "Please try again.";
            }
            myReadFile.close(); //Closes file
            for(int n=0;n<dMSG.size();n++) //Function to convert character string into int values
            {
                switch (dMSG[n])
                {
                    case '0' : dMSG[n] = 0 ; break;
                    case '1' : dMSG[n] = 1 ; break;
                    case '2' : dMSG[n] = 2 ; break;
                    case '3' : dMSG[n] = 3 ; break;
                    case '4' : dMSG[n] = 4 ; break;
                    case '5' : dMSG[n] = 5 ; break;
                    case '6' : dMSG[n] = 6 ; break;
                    case '7' : dMSG[n] = 7 ; break;
                    case '8' : dMSG[n] = 8 ; break;
                    case '9' : dMSG[n] = 9 ; break;
                }
            }
            for(int f=0;f<dMSG.size();f+=3) //Loop to convert back to ASCII decimal value. Increments by 3 because 1 Character needs 3 array slot
            {
                four=(8*8)*(dMSG[f]-1); // -1 because encypt +1
                five=8*(dMSG[f+1]-2); // -2 because encrypt +2
                six=1*(dMSG[f+2]-2); // -2 because encrypt +2
                seven = four+five+six; // Adds up to be the decimal value
                aMSG.push_back(seven); //Pushs the decimal value inside the array
            }
        }
        if(choice2=='2') // Goes to here if user want to manually type in the code to decrypt
        {
            cout << "\nPlease enter the code you want to decrypt:" << endl;
            cin >> dMSG;
            for(int n=0;n<dMSG.size();n++) //Function to convert char to int
            {
                switch (dMSG[n])
                {
                    case '0' : dMSG[n] = 0 ; break;
                    case '1' : dMSG[n] = 1 ; break;
                    case '2' : dMSG[n] = 2 ; break;
                    case '3' : dMSG[n] = 3 ; break;
                    case '4' : dMSG[n] = 4 ; break;
                    case '5' : dMSG[n] = 5 ; break;
                    case '6' : dMSG[n] = 6 ; break;
                    case '7' : dMSG[n] = 7 ; break;
                    case '8' : dMSG[n] = 8 ; break;
                    case '9' : dMSG[n] = 9 ; break;
                }
            }
            for(int f=0;f<dMSG.size();f+=3) //Loop to convert Octal to ASCII decimal value
            {
                four=(8*8)*(dMSG[f]-1); //-1 because encrypt +1
                five=8*(dMSG[f+1]-2); // -2 because encrypt +2
                six=1*(dMSG[f+2]-2); // -2 because encrypt +2
                seven = four+five+six; // Adds up to be the decimal value
                aMSG.push_back(seven);//Pushs the decimal value inside the array
            }

        }
    }
    else // If user does not enter 1 or 2
    {
        system("CLS");
        cout << "You have entered an invalid value. Please try again." << endl;
        goto start;
    }
    cout << "\nThe decrypted message is: " << endl; // Starts outputing the deciphered message here
    for(int b=0;b<aMSG.size();b++) //Character vector because wants to output its ASCII equal
        cout << aMSG[b];
    cout << "\nPress anything to exit back to main menu..";
    cin >> exit1;
}
int main()
{
    char choice;

    start:
    cout << "Welcome.";
    cout << "\nWhat do you wish to do?";
    cout << "\n1. Cipher";
    cout << "\n2. DeCipher";
    cout << "\n3. Exit";
    cout << "\n\nYour Choice: ";
    cin >> choice;

    switch(choice)
    {
        case '1':   cipher(); // Function to Cipher - Starts at Line 19
                    system("CLS");
                    goto start;
                    break;
        case '2':   decipher();
                    system("CLS"); // Function to Decipher - Starts at Line 118
                    goto start;
                    break;
        case '3':   return 0;
        default :   system("CLS");
                    cout << "Invalid choice. Please enter your choice again.";
                    cout << endl;
                    goto start;
                    break;
    }
}
