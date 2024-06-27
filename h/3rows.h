#include"../header.h"

time_t strta = clock();
int wina = 0, losea = 0, alla = 0;
double avga = 0, dua;         // add an "a" for dodgeing "error: redefinition of 'int [variable name]" error

bool threerows(int num, string book[32320][3], bool continu)
{
    SetConsoleOutputCP( 65001 ); //https://stackoverflow.com/questions/1371012/how-do-i-print-utf-8-from-c-console-application-on-windows
    if(true)
    {
        srand(clock());
        string a, q; // a = answer, q = question
        short r = (rand() % num) - 2;

        printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", wina, losea, alla);
        cout << "平均作答時間: " << avga << "\n\n";
        if (r >= 2)
        {
            cout << book[r][0] << "\n >> ";
            cin >> a;
            if (a == book[r][1] || a == book[r][2])
            {
                printf("\a正確!\n");
                wina++;
            }
            else
            {
                printf("錯誤。\n正確答案是: ");
                cout << book[r][1] << " �� " << book[r][2] << endl;
                losea++;
            }
        }
        dua = (clock() - strta) / (double) CLOCKS_PER_SEC;
        if(a == "exit" || a == "esc")
        {
            clearscr();
            losea--;
            printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", wina, losea, alla);
            cout << "平均作答時間: " << avga << "\n\n";
            wlcmd("pause", "pause");
            continu = false;
        }
        if (r >= 2)
        {
            alla++;
            avga = dua / alla;
        }
        clearscr();
    }
    return continu;
}