#include"./header.h"
#include"./h/2rows.h"
#include"./h/3rows.h"

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
    printf("���J�ɮפ�...\n");  bool fileFail = false;
    
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
        printf("�@�@�@�@�@�@���@�~�@�I\n�@�@�ɮ׿򥢾ɭP���i�Ұʳn��C\n\n�ѨM��k:\n");
        printf("  1. �ˬd Preference.csv �O�_���b�M���n��@�˪���Ƨ��A�άO Preference.csv �O�_��L�ɦW�C\nPreference.csv ���i���ʡB�ק�Χ���ɦW�A�_�h�N�|�X�{�����~�C\n");
        printf("  2. �ˬd�A�Q�n�C�����D�� (.csv) �ɬO�_���ƥ���W�� this.csv�A�άO�ˬd�O�_����� this.csv\n");
        wlcmd("pause", "pause");
        exit(0);
    }

    clearscr();

    if (setting[2][1] == "0")
    {
        printf("�o�O csv �ɮ��H���X�D���A�A�i�H�ۤv�� Excel �άO Calc ���n��s�@�D�ةM���רæs�� csv �ɫ�C���C\n�n����ɮ׫�²��A�u�n���ɮש���o�ӳn��P�@�Ӹ�Ƨ��éR�W�� this �Y�i�C\n");
        printf("�Ĥ@���}�ҳo�ӳn�骺�ܤ]���n��i�A�ثe�w�g���@�ӽd���ɮ׶פJ�n�i�H���դF�C�b�s�@�ΤU�� csv �ɫe�i�H���δ��Ѫ��ɮק@���ճ�!\n���Ѫ��ɮצ� 1.csv, 2.csv, 3.csv, 3langOpposite.csv, sincostan.csv�A�o���ɮ׳��i�H�ΨӴ��աA�u�n�R�W�� this �N�n�C\n");
        printf("�n�`�N Preference.csv ���n���ʡB�ק�Χ��ɦW�A�_�h�n��|�L�k�ҰʡC\n");
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