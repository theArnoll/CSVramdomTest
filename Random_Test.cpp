#include"./header.h"
#include"./h/2rows.h"
#include"./h/3rows.h"

#pragma execution_character_set( "utf-8" )
//https://stackoverflow.com/questions/1371012/how-do-i-print-utf-8-from-c-console-application-on-windows

using namespace std;

int num = 0;
string book[32320][3], setting[4][2];

int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
// create custom split() function
void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
          //  strings[currIndex] = subStr;
            book[num][currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}
void Psplit (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
          //  strings[currIndex] = subStr;
            setting[num][currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }  
        i++;
    }
}
//https://www.javatpoint.com/how-to-split-strings-in-cpp

int main()
{
    SetConsoleOutputCP( 65001 ); //https://stackoverflow.com/questions/1371012/how-do-i-print-utf-8-from-c-console-application-on-windows

    printf("載入檔案中...\n");  bool fileFail = false;
    
    string Pline; //load Preference
    ifstream Pfile (".\\Preference.csv");
    if (Pfile.is_open())  //process file
    {
        while (getline(Pfile, Pline)) //process file by line
        {
            Psplit(Pline, ',');
            num++;
        }
        Pfile.close();
        printf("Pok\n");
    } else fileFail = true;
    num = 0;
    string line; //load question
    ifstream file (".\\" + setting[3][1]);
    if (file.is_open())  //process file
    {
        while (getline(file, line)) //process file by line
        {
            split(line, ',');
            num++;
        }
        file.close();
        printf("Fok\n");
    } else fileFail = true;

    if(fileFail)
    {
        printf("　　　　　　錯　誤　！\n　　檔案遺失導致不可啟動軟體。\n\n解決方法:\n");
        printf("  1. 檢查 Preference.csv 是否有在和本軟體一樣的資料夾，或是 Preference.csv 是否改過檔名。\nPreference.csv 不可移動、修改或更改檔名，否則就會出現此錯誤。\n");
        printf("  2. 檢查你想要遊玩的題本 (.csv) 檔是否有事先改名為 ");
        std::cout << setting[3][1];
        printf("，或是檢查是否有兩個 ");
        std::cout << setting[3][1] << "。" << endl;
        wlcmd("pause", "pause");
        exit(0);
    }

    clearscr();

    if (setting[2][1] == "0")
    {
        printf("這是 csv 檔案隨機出題器，你可以自己用 Excel 或是 Calc 等軟體製作題目和答案並存成 csv 檔後遊玩。\n要選擇檔案很簡單，只要把檔案放到跟這個軟體同一個資料夾並命名為 this 即可。\n");
        printf("第一次開啟這個軟體的話也不要緊張，目前已經有一個範例檔案匯入好可以測試了。在製作或下載 csv 檔前可以先用提供的檔案作測試喔!\n提供的檔案有 1.csv, 2.csv, 3.csv, 3langOpposite.csv, sincostan.csv，這些檔案都可以用來測試，只要命名為 this 就好。\n");
        printf("要注意 Preference.csv 不要移動、修改或改檔名，否則軟體會無法啟動。\n");
        wlcmd("pause", "pause");
        clearscr();
    }
    
    continu = true;

    while(continu)
    {
        if(book[1][1] == "2")
        {  
            bool temp = tworows(num, book, continu);
            continu = temp;
        }   //if 2 row
        else if(book[1][1] == "3")
        {
            bool temp = threerows(num, book, continu);
            continu = temp;
        }
    }
    return 0;
}