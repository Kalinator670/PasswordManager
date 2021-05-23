#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <cstring>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string pass1, login1,lp,log2;
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    string logpass;
    int vhod, vhod1, vhod2, vhod3, vhod4;
    int a;
    int b;
    cout<< "#########################################################################################"<<'\n'
        << "###############||+++++++++++++++++++++++++++++++++++++++++++++++++++||###################" << '\n'
        << "###############||+---------------МЕНЕДЖЕР ПАРОЛЕЙ------------------+||###################" << '\n'
        << "###############||+++++++++++++++++++++++++++++++++++++++++++++++++++||###################"<<'\n'
        << "#########################################################################################"<<'\n'
        << "=============================Arkadiy Savelev==============================="<<endl;
        
    cout<<'\n'<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<'\n'
              <<"$********Нажми 1, если хочешь увидеть список функций****************$" <<'\n'
              <<"$-------------------------------------------------------------------$"<<'\n'
              <<"$~~~~~~~~~~~~~~~Нажми 2, если выйти (в окно)~~~~~~~~~~~~~~~~~~~~~~~~$"<<'\n'
              <<"$-------------------------------------------------------------------$"<<'\n' 
              <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cin >>a;
    if (a == 1)
        {
            cout << "1. Войти в свой акк"<<'\n'
                 <<"------------------------------------------------------"<<endl;
            cout << "2. Создать новый акк"<<'\n'
                 <<"******************************************************"<< endl;
            cout << "3. Сгенерировать пароль" << '\n' <<
                    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin >> b;
            if (b == 2)
            {
                ofstream bd("bd.txt");
                char login[80] = { 0 };
                char pass[80] = { 0 };
                cout << "Название нового логина (не должен включать русских букв)" << endl;
                cin >> login;
                cout << "Новый пароль (не должен включать русских букв)" << endl;
                cin >> pass;
                login1 = login;
                for (int i = 0; i < strlen(login); i++)
                {
                    login[i] += 5;
                }
                for (int j = 0; j < strlen(pass); j++)
                {
                    pass[j] += 5;
                }
                string str = string() + login + pass;
                bd << str;
                bd.close();
                ofstream my;
                login1 += ".txt";
                my.open(login1);
                my.close();
                cout << "Нажми 1, чтобы войти в акк" << endl;
                cin >> vhod;
            }
            //генератор паролей
            else if (b == 3)
            {
                string co, sa;
                for (int i = 'a'; i < 'i'; i++)
                {
                    co = char('a' + rand() % ('z' - 'a'));
                    sa = rand() % 10 + 55;
                    cout << co;
                    cout << sa;
                }
                cout << "    <<<Новый пароль для тебя!"<<endl;
                cout <<"Веди 0, чтобы выйти "<<"\n";
                cin >> vhod3;
            }
            //вход в акк
            if (b == 1 || vhod==1)
            {
                ifstream bd1("bd.txt");
                char pass1[50];
                char log1[50];
                string f, log3,line1,log4;
                int ku;
                cout << "Введите свой логин" << endl;
                cin >> log1;
                cout << "Введите пароль" << endl;
                cin >> pass1;
                log3 += log1;
                log3 += ".txt";
                for (int e = 0; e < strlen(log1);e++)
                   {
                        log1[e] += 5;
                   }
                for (int p = 0; p < strlen(pass1); p++)
                   {
                        pass1[p] += 5;
                   }
                log4 = strcat(log1, pass1);
                while (getline(bd1, lp))
                {
                  if (log4 == lp)
                  {

                      bd1.close();
                      char c;
                      char mass[255];
                      char lol[50];
                      char massa[255];
                      string lol1,l,line1;
                      cout << "1. Увидеть все значения (логин-пароль)" << endl;
                      cout << "2. Добавить новое значение" << endl;
                      cin >> ku;
                      if (ku == 1)
                      {
                          ifstream my1(log3);
                          if (my1.is_open())
                          {
                              while (getline(my1, line1))
                              {
                                  strcpy(massa,line1.c_str());
                                  for (int i = 0; i < strlen(massa); i++)
                                  {
                                      massa[i] -= 7;
                                  }
                                  cout << massa << endl;
                                  cout << "Всё, гуляй! Я слишком много уделил тебе внимания! " << endl;
                              }
                          }
                          my1.close(); 
                          cout << "Если хочешь добавить новый пароль введи 1" << endl;
                          cin >> vhod2;
                      }
                      else if (ku == 2 || vhod2==1)
                      {
                          ofstream my(log3);
                          cout << "Ведите новое значение логин-пароль(например, если логин: abcdabcd@gmail.com , а пароль:123, то новое значение: abcdabcd@gmail.com-123)" << endl;
                          cin >> lol;
                          string str1 = string() + lol;
                          str1 += "~~~~";
                          lol1 = asctime(timeinfo);
                          str1 += lol1;
                          strcpy(mass, str1.c_str());
                          //самый сок
                          for (int i = 0; i < strlen(mass); i++)
                          {
                              mass[i] += 7;
                          }
                          my << mass;
                          my.close();
                          cout << "Готово, твои пароли теперь у меня :)" << endl;
                          cout << "Нажми 0, чтобы выйти";
                          cin >> vhod3;
                      }
                  }
                }
               /* //считывание до определенного символа, хз, мб нужно будет (и никто не заметил сначала идет коммент для всего текста, а потом для строки :) )
                char text[50];
                cin.getline(text, 50, '!');
                cout << text << endl;
                */
            }

       }
    return 0;
    }