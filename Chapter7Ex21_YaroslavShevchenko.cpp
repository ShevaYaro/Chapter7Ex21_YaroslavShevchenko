/*

Tite Chapter 7 Exercise 21 - 2D Operations
File name:Chapter7Ex21_YaroslavShevchenko.cpp
Programmer: Yaroslav Shevchenko
Date: 12/13/2024
Requirements:

Write a program that creates a two-dimensional array initialized with test data. Use any data type you wish. The program should have the following functions:

• getTotal—This  function  should  accept  a  two-dimensional  array  as  its  argument  and return the total of all the values in the array.

• getAverage—This function should accept a two-dimensional array as its argument and return the average of all the values in the array.

• getRowTotal—This  function  should  accept  a  two-dimensional  array  as  its  first  argument  and  an  integer  as  its  second  argument. 
The  second  argument  should  be  the subscript of a row in the array. The function should return the total of the values in the specified row.

• getColumnTotal—This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a column in the array. The function should return the total of the values in the specified column.

• getHighestInRow—This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a row in the array. The function should return the highest value in the specified row of the array.

• getLowestInRow—This function should accept a two-dimensional array as its first argument  and  an  integer  as  its  second  argument.  
The  second  argument  should  be  the subscript of a row in the array. The function should return the lowest value in the
Display the options in a menu to call the various functions.

*/

#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 3;


int menu(int arr[ROW][COL]);

int getTotal(int arr[ROW][COL]);

double getAvarage(int arr[ROW][COL]);

int getRowTotal(int arr[ROW][COL], int rowN);

int getColumnTotal(int arr[ROW][COL], int colN);

int getHighestInRow(int arr[ROW][COL], int rowN);

int getLowestInRow(int arr[ROW][COL], int colN);

int main()
{
    int twoDArr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int userChoice = menu(twoDArr);

    if (userChoice == 1) {
        cout << "The combined total from 2d Array: " << getTotal(twoDArr);
    }
    else if (userChoice == 2) {
        cout << "The avrage number from 2d Array: " << getAvarage(twoDArr);
    }
    else if (userChoice == 3) {
        int rowNum;
        cout << "input the row number: (1-3)";
        cin >> rowNum;
        cout << "The combined total from row " << rowNum << ": " << getRowTotal(twoDArr, rowNum);
    }
    else if (userChoice == 4) {
        int colNum;
        cout << "input the column number: (1-3)";
        cin >> colNum;
        cout << "The combined total from column " << colNum << ": " << getColumnTotal(twoDArr, colNum);
    }
    else if (userChoice == 5) {
        int rowNum;
        cout << "input the row number: (1-3)";
        cin >> rowNum;
        cout << "The highest number from row " << rowNum << ": " << getHighestInRow(twoDArr, rowNum);
    }
    else {
        int colNum;
        cout << "input the column number: (1-3)";
        cin >> colNum;
        cout << "The lowest number from column " << colNum << ": " << getLowestInRow(twoDArr, colNum);
    }

}

int menu(int arr[ROW][COL]) {
    cout << "This program is based on this 2D array: " << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    int choice;
    cout << "What would you like to compute?: " << endl;
    cout << "1. total of all the values in the array\n";
    cout << "2. average of all the values in the array\n";
    cout << "3. the total of the values in the specified row\n";
    cout << "4. the total of the values in the specified column\n";
    cout << "5. the highest value in the specified row\n";
    cout << "6. the lowest value in the specified row\n";

    cin >> choice;
    while (choice < 1 || choice > 6) {
        cout << "input number from 1 to 6:";
        cin >> choice;
    }

    return choice;
}

int getTotal(int arr[ROW][COL]) {
    int sum = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

double getAvarage(int arr[ROW][COL]) {
    double count = 0;
    double sum = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            sum += arr[i][j];
            count++;
        }
    }
    return sum / count;
}

int getRowTotal(int arr[ROW][COL], int rowN) {
    int sum = 0;
    for (int i = 0; i < ROW; i++) {
        sum += arr[rowN-1][i];
    }
    return sum;
}

int getColumnTotal(int arr[ROW][COL], int colN) {
    int sum = 0;
    for (int i = 0; i < COL; i++) {
        sum += arr[i][colN - 1];
    }
    return sum;
}

int getHighestInRow(int arr[ROW][COL], int rowN) {
    int highest = 0;
    for (int i = 0; i < ROW; i++) {
        if (highest < arr[rowN - 1][i]) {
            highest = arr[rowN - 1][i];
        }
    }
    return highest;
}

int getLowestInRow(int arr[ROW][COL], int colN) {
    int lowest = 10000;
    for (int i = 0; i < ROW; i++) {
        if (lowest > arr[i][colN - 1]) {
            lowest = arr[i][colN - 1];
        }
    }
    return lowest;
}