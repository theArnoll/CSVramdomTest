#include"../header.h"

time_t strt = clock();
int win = 0, lose = 0, all = 0;
double avg = 0, du;

bool tworows(int num, string book[32320][3], bool continu)
{
    SetConsoleOutputCP( 65001 ); //https://stackoverflow.com/questions/1371012/how-do-i-print-utf-8-from-c-console-application-on-windows
    if(book[0][1] == "both" || book[0][1] == "2")
    {
        srand(clock());
        string a, q; // a = answer, q = question
        short r[2] = {(rand() % 2), ((rand() % num) - 2)};

        printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", win, lose, all);
        cout << "平均作答時間: " << avg << "\n\n";
        switch (r[0])
        {
        case 0:
            if (r[1] >= 2)
            {
                cout << book[r[1]][0] << "\n >> ";
                cin >> a;
                if (a == book[r[1]][1])
                {
                    printf("\a正確!\n");
                    win++;
                }
                else
                {
                    printf("錯誤。\n正確答案是: ");
                    cout << book[r[1]][1] << endl;
                    lose++;
                }
                break;
            }
        case 1: // value to sin/cos/tan
            if (r[1] >= 2)
            {
                cout << book[r[1]][1] << "\n >> ";
                cin >> a;
                if (a == book[r[1]][0] && r[1] >= 2)
                {
                    printf("\a正確!\n");
                    win++;
                }
                else
                {
                    printf("錯誤。\n正確答案是: ");
                    cout << book[r[1]][0] << endl;
                    lose++;
                }
                break;
            }
        default:
            break;
        }
        du = (clock() - strt) / (double) CLOCKS_PER_SEC;
        if(a == "exit" || a == "esc")
        {
            clearscr();
            lose--;
            printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", win, lose, all);
            cout << "平均作答時間: " << avg << "\n\n";
            continu = false;
        }
        if (r[1] >= 2)
        {
            all++;
            avg = du / all;
            wlcmd("pause", "pause");
        }
        clearscr();
    }           //if both direction
    else if(book[0][1] == "single" || book[0][1] == "1")
    {
        srand(clock());
        string a, q; // a = answer, q = question
        short r = (rand() % num) - 2;

        printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", win, lose, all);
        cout << "平均作答時間: " << avg << "\n\n";
        if (r >= 2)
        {
            cout << book[r][0] << "\n >> ";
            cin >> a;
            if (a == book[r][1])
            {
                printf("\a正確!\n");
                win++;
            }
            else
            {
                printf("錯誤。\n正確答案是: ");
                cout << book[r][1] << endl;
                lose++;
            }
        }
        du = (clock() - strt) / (double) CLOCKS_PER_SEC;
        if(a == "exit" || a == "esc")
        {
            clearscr();
            lose--;
            printf("正確數: %d\t錯誤數: %d\t總題數: %d\t", win, lose, all);
            cout << "平均作答時間: " << avg << "\n\n";
            continu = false;
        }
        if (r >= 2)
        {
            all++;
            avg = du / all;
            wlcmd("pause", "pause");
        }
        clearscr();
    }       //else single direction
    return continu;
}