/*
E:魔兽世界之一：备战
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
using namespace std;

int ini_life_r = 0, ini_life_b = 0, Ctime = 0;
int l_dragon = 0, l_ninja = 0, l_iceman = 0, l_lion = 0, l_wolf = 0;
int l_monster_r[10], l_monster_b[10]; 
int tmp_r = 0, tmp_b = 0, flag_r = 0, flag_b = 0;        
int flag_dragon_r = 0, flag_ninja_r = 0, flag_iceman_r = 0, flag_lion_r = 0, flag_wolf_r = 0;
int flag_dragon_b = 0, flag_ninja_b = 0, flag_iceman_b = 0, flag_lion_b = 0, flag_wolf_b = 0;
char monster_r[5][10] = {"iceman", "lion", "wolf", "ninja", "dragon"};
char monster_b[5][10] = {"lion", "dragon", "ninja", "iceman", "wolf"};
int num_r_made[5], num_b_made[5];
int num_r_total, num_b_total;
int i = 0, j = 0;

class CSodier
{
    int clife, cnum, cpower, ckind;
    static int cnum_total;
    public:
        CSodier() : clife(0), cnum(0), cpower(0), ckind(0) 
        {
            cnum_total++;
        }
        CSodier(int a) {}

};

void C_initializing()
{
    ini_life_r = 0, ini_life_b = 0, Ctime = 0;
    l_dragon = 0, l_ninja = 0, l_iceman = 0, l_lion = 0, l_wolf = 0; 
    tmp_b = tmp_r = 0;
    flag_dragon_r = 0, flag_ninja_r = 0, flag_iceman_r = 0, flag_lion_r = 0, flag_wolf_r = 0;
    flag_dragon_b = 0, flag_ninja_b = 0, flag_iceman_b = 0, flag_lion_b = 0, flag_wolf_b = 0;
    for (j = 0;j < 5;j++)
    {
        memset(l_monster_b, 0, sizeof(l_monster_b));
        memset(l_monster_r, 0, sizeof(l_monster_r));
    }
    memset(num_r_made, 0, sizeof(num_r_made));
    memset(num_b_made, 0, sizeof(num_b_made));
    num_r_total = num_b_total = 0;
    cin >> ini_life_r;
    cin >> l_dragon >> l_ninja >> l_iceman >> l_lion >> l_wolf;
    ini_life_b = ini_life_r;
    flag_r = flag_b = 0;
    l_monster_r[0] = l_monster_b[3] = l_iceman;
    l_monster_r[1] = l_monster_b[0] = l_lion;
    l_monster_r[2] = l_monster_b[4] = l_wolf;
    l_monster_r[3] = l_monster_b[2] = l_ninja;
    l_monster_r[4] = l_monster_b[1] = l_dragon;
}
//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

int main()
{
    cin >> i;
    while(i--)
    {
        C_initializing();
        while(flag_b == 0 || flag_r == 0)
        {
            //iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
            if(ini_life_r && flag_r == 0)
            {
                for (j = 0; j < 5; j++)
                {
                    if(ini_life_r >= l_monster_r[(tmp_r+j)%5])
                    {
                        num_r_made[(tmp_r+j)%5]++;
                        num_r_total++;
                        printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n", Ctime, monster_r[(tmp_r+j)%5], 
                                num_r_total, l_monster_r[(tmp_r+j)%5], num_r_made[(tmp_r+j)%5], monster_r[(tmp_r+j)%5]);
                        ini_life_r -= l_monster_r[(tmp_r+j)%5];
                        tmp_r++;
                        break;
                    }
                    if(j == 4)
                    {
                        printf("%03d red headquarter stops making warriors\n", Ctime);
                        flag_r = 1;
                    }
                }
            }
            if(ini_life_b && flag_b == 0)
            {
                for (j = 0; j < 5; j++)
                {
                    if(ini_life_b >= l_monster_b[(tmp_b+j)%5])
                    {
                        num_b_made[(tmp_b+j)%5]++;
                        num_b_total++;
                        printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n", Ctime, monster_b[(tmp_b+j)%5], 
                                num_b_total, l_monster_b[(tmp_b+j)%5], num_b_made[(tmp_b+j)%5], monster_b[(tmp_b+j)%5]);
                        ini_life_b -= l_monster_b[(tmp_b+j)%5];
                        tmp_b++;
                        break;
                    }
                    if(j == 4)
                    {
                        printf("%03d blue headquarter stops making warriors\n", Ctime);
                        flag_b = 1;
                    }
                }
            }
            Ctime++;
        }
    }
    system("pause");
    return 0;
}
