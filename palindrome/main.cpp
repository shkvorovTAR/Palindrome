#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>

using namespace std;

//Zadajem peremennqe i ix tipq
char string1[20];
int i, length;
int flag = 0;

//Inicializiruem Funckiju
void checkPalindrome();

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);
    qDebug() << "Lets check if word is a Palindrome or not!";
    qDebug() << "Enter a string: ";
    cin >> string1;
    qDebug() << " ";
    length = strlen(string1);
    checkPalindrome(); //Vqzqvaem funckiju proverki na palindrom

    //Zapisj proverki faila na palindrom v otdeljnqi fail
    QFile wfile("FinalResults.txt");
    if (wfile.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writeStream(&wfile);
        if (flag)
        {
            writeStream <<  "Your word: " << string1 << " is not a Palindrome" << endl;
        }
        else
        {
            writeStream <<  "Your word: " << string1 << " is a Palindrome" << endl;
        }
        qDebug() << "Results also will be stored in File PalindromeOrNot.txt in Build Directory";
        qDebug() << " ";
    }
    wfile.close();
    return/*a.exec()*/0;
}

//Funcija proverki slova na palindrom
void checkPalindrome()
{
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
        }
    }
    if (flag) {
        qDebug() << string1 << " is not a Palindrome" << endl;
    }
    else {
        qDebug() << string1 << " is a Palindrome" << endl;
    }
}
