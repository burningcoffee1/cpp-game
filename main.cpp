/**
 * 
 * -------------------------更新日志-------------------------
 * 20210706
 * V0.0.0 游戏诞生，制作了所有的界面及游戏大概
 * 
 * 
 * 未完待续……
**/
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cctype>
#include <time.h>
#include"conio.h"
#define ForEver while(true)
#define Bst break;
#define Normal cout << "\033[0m"
#define Back cout << "\n-Enter键继续-";char c = played()
namespace LColorSTD {
    #define LRed            'r'
    #define LGreen          'g'
    #define LYellow         'y'
    #define LBlue           'b'
    #define LPurple         'p'
    #define LCyan           'c'
    #define LWhite          'w'
    #define LDark           'd'
    
    #define LBright_Red     'u'
    #define LBright_Green   'q'
    #define LBrown          'f'
    #define LBright_Blue    't'
    #define LBright_Purple  'e'
    #define LBright_Cyan    'o'
    #define LBright_Gray    'h'
    #define LDark_Gray      'a'
};

using namespace std;
using namespace LColorSTD;

#define ENGINNUM 30
#define MONNUM1 1
#define MONNUM2 0
#define MONNUM3 0
#define MONNUM4 0


bool crit[101];
string class_Player_handEngin_name = "";
string class_Player_engins_name[31] = {};
int class_Player_enginIndex = 0;

char played() {
	char c;
	//system("stty -echo");
	//system("stty -icanon");
	//c = getchar();
    c = getch();
	//system("stty icanon");
	//system("stty echo");
	return c;
}

int Random(const int a,const int b) {
    if(a == b) {
        return a;
    }
    int num = rand() % (b - a + 1) + a;
    return num;
}

void ucolor(const char c) {              //背景颜色控制函数
    switch(c) {
        case 'r':cout << "\033[41m";Bst; //    red —— 红色
        case 'g':cout << "\033[42m";Bst; //  green —— 绿色
        case 'y':cout << "\033[43m";Bst; // yellow —— 黄色
        case 'b':cout << "\033[44m";Bst; //   blue —— 蓝色
        case 'p':cout << "\033[45m";Bst; // purple —— 紫色
        case 'c':cout << "\033[46m";Bst; //   cyan —— 青色
        case 'w':cout << "\033[47m";Bst; //  white —— 白色
        case 'd':cout << "\033[40m";Bst; //   dark —— 黑色
        case 't':cout << "\n";           // return —— 换行
        default :Normal;                 //           退出
    }
}

void mcolor(const char c) {
    switch(c) {
        case 'r':cout << "\033[0;31m";Bst; // 红色
        case 'u':cout << "\033[1;31m";Bst; // 亮红
        case 'g':cout << "\033[0;32m";Bst; // 绿色
        case 'q':cout << "\033[1;32m";Bst; // 亮绿 
        case 'f':cout << "\033[0;33m";Bst; // 棕色
        case 'y':cout << "\033[1;33m";Bst; // 黄色
        case 'b':cout << "\033[0;34m";Bst; // 蓝色
        case 't':cout << "\033[1;34m";Bst; // 浅蓝
        case 'p':cout << "\033[0;35m";Bst; // 紫色
        case 'e':cout << "\033[1;35m";Bst; // 浅紫
        case 'c':cout << "\033[0;36m";Bst; // 青色
        case 'o':cout << "\033[1;36m";Bst; // 浅青
        case 'h':cout << "\033[0;37m";Bst; // 浅灰
        case 'w':cout << "\033[1;37m";Bst; // 白色
        case 'd':cout << "\033[0;30m";Bst; // 黑色
        case 'a':cout << "\033[1;30m";Bst; // 深灰
        default :Normal;                   // 退出
    }
}          //字的颜色控制函数

bool findWord(const string s1,const string s2) {
    long l1 = s1.length();
    long l2 = s2.length();
    bool flag = false;
    
    for(int i = 0;i <= l1 - l2;i++) {
        int j = 0;
        int k = i;
        while(j <= l2 - 1) {
            if(s1[k] == s2[j]) {
                k++;
                j++;
            } else { 
                break;
            }
        }
        if(j == l2) {   
            flag = true;
            break ; 
        } 
    } 
    return flag;
}

void wordWay(string word,int maxNum,string way = ".left") {
    long len = word.length();
    if(len > maxNum) return;
    int spaceNum = maxNum - len;
    
    if(way == ".right") {
        for(int i = 1;i <= spaceNum;i++) cout << ' ';
        cout << word;
    } else if(way == ".left") {
        cout << word;
        for(int i = 1;i <= spaceNum;i++) cout << ' ';
    }
}

void print(const string s,bool getch = true,const char color = '0') {
    long len = s.length();
    mcolor(color);
    for(int i = 0;i < len;i++) {
        cout << s[i];
        usleep(15000);
    }
    if(getch) {
        char c = played();
        system("CLS");
    }
}

int tenget(const int n) {
    int sum = 1;
    for(int i = 1;i <= n;i++) {
        sum *= 10;
    }
    return sum;
}

bool isNULL(const char c) {
    return c == '\0';
}

string intToString(int num) {
    int len = 1,sum = 10;
    string str;
    while(num != num % sum) {
        sum *= 10;
        len++;
    }
    
    if(len == 1) {
        str += num + '0';
    } else {
        int j = len - 1;
        for(int i = 1;i <= len;i++) {
            str += num / tenget(j) + '0';
            num = num % tenget(j--);
        }
        str += num;
    }
    return str;
}

double stringToDouble(const string s) {
    double val,power;
    int i;
    
    for(i = 0;isNULL(s[i]);i++)
        ;
    for(val = 0.0;isdigit(s[i]);i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0;isdigit(s[i]);i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return val / power;
}

int stringToInt(const string s) {
    int val = stringToDouble(s);
    if(s.length() == 1 && s[0] == '0') {
        return 0;
    }
    return val;
}

class Enginery {
public:
    string name;
    string introduce;
    string level;
    string key;
    int aggSml;
    int aggBig;
    int outG;
    int inG;
    
    int aggNum;
    int defNum;
    int critNum;
    int useLevel;
    bool canBuy;
    bool canSell;
    bool isHave;
    
    void printEnginLevel() {
        if(level == "普通") mcolor(LBright_Gray);
        else if(level == "稀有") mcolor(LBright_Green);
        else if(level == "精品") mcolor(LBlue);
        else if(level == "史诗") mcolor(LPurple);
        else if(level == "传奇") mcolor(LYellow);
        
        cout << "[" << level << "] ";
    }
    
    void synopsis() {
        cout << name << ' ';
        printEnginLevel();
        if(name == class_Player_handEngin_name) {
            mcolor(LBright_Purple);
            cout << "[已装备]\n";
                
            Normal;
            cout << "介绍：" << introduce << "\n";
            cout << "攻击：" << aggSml << "~" << aggBig << "\n";
            cout << "售出价格：" << outG << "G\n\n";
            return;
        }
        
        if(isHave) {
            mcolor(LBrown);
            for(int i = 1;i <= class_Player_enginIndex;i++) {
                if(name == class_Player_engins_name[i]) {
                    cout << "[已拥有]\n";
                    break;
                }
            }
            
            Normal;
            cout << "介绍：" << introduce << "\n";
            cout << "攻击：" << aggSml << "~" << aggBig << "\n";
            cout << "售出价格：" << outG << "G\n\n";
            return;
        } else {
            mcolor(LBlue);
            cout << "[未获得]\n ";
            
            Normal;
            cout << "介绍：" << introduce << "\n";
            cout << "攻击：" << aggSml << "~" << aggBig << "\n";
            cout << "售出价格：" << outG << "G\n\n";
            return;
        }
    }
};

Enginery engin[31] = {
    {
        "无",
        "",
        "",
        "",
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        false,
        true,
        false
    },{
        "生锈的剑",
        "锈迹斑斑，别人送的礼物",
        "普通",
        "PU",
        2,
        5,
        50,
        0,
        0,
        0,
        0,
        1,
        false,
        true,
        false
    },{
        "轻质钢剑",
        "用不锈钢制成，质量不咋地",
        "普通",
        "LI",
        4,
        8,
        60,
        0,
        0,
        0,
        0,
        1,
        false,
        true,
        false
    },{
        "木剑",
        "对一块木雕来说不错了",
        "普通",
        "MH",
        3,
        7,
        80,
        750,
        0,
        0,
        0,
        1,
        true,
        true,
        false
    },{
        "海盗的大刀",
        "这把刀曾经是海盗的武器",
        "普通",
        "OE",
        8,
        14,
        120,
        1600,
        0,
        1,
        0,
        2,
        true,
        true,
        false
    },{
        "镀银军刀",
        "镀银以防锈",
        "普通",
        "KA",
        8,
        15,
        150,
        1800,
        1,
        0,
        0,
        4,
        true,
        true,
        false
    },{
        "大木锤",
        "似乎这是木匠人的传家宝",
        "普通",
        "NQ",
        15,
        24,
        200,
        3000,
        0,
        0,
        0,
        5,
        true,
        true,
        false
    },{
        "短刀",
        "小而短的刀",
        "普通",
        "PZ",
        2,
        5,
        60,
        500,
        1,
        0,
        0,
        1,
        true,
        true,
        false
    },{
        "森林之刃",
        "拥有森林眷顾的魔法之剑",
        "稀有",
        "JW",
        8,
        18,
        250,
        3200,
        0,
        1,
        1,
        5,
        true,
        true,
        false
    },{
        "大宝剑",
        "很重的阔剑",
        "稀有",
        "IE",
        12,
        25,
        300,
        4500,
        1,
        1,
        0,
        5,
        true,
        true,
        false
    },{
        "夜之刃",
        "散发着神秘的黑暗力量，好像可以吞噬一切",
        "稀有",
        "UC",
        10,
        30,
        280,
        0,
        0,
        1,
        3,
        6,
        false,
        true,
        false
    },{
        "圣堂之刃",
        "它曾是骑士的胸前佩剑",
        "稀有",
        "HD",
        22,
        29,
        300,
        0,
        1,
        1,
        0,
        7,
        false,
        true,
        false
    },{
        "铅棒",
        "很重很重，需要用浑身力气才能挥得动的大棒",
        "稀有",
        "VF",
        18,
        27,
        180,
        0,
        1,
        0,
        5,
        8,
        false,
        true,
        false
    },{
        "水晶匕首",
        "刀片是纯石英制成",
        "稀有",
        "GP",
        10,
        15,
        450,
        10000,
        6,
        0,
        0,
        9,
        true,
        true,
        false
    },{
        "铁德克",
        "一把常见的铁匕首，防身武器",
        "稀有",
        "YR",
        8,
        20,
        120,
        1500,
        5,
        0,
        0,
        4,
        true,
        true,
        false
    },{
        "雪怪之牙",
        "寒气逼人，让你瑟瑟发抖",
        "精品",
        "TK",
        26,
        42,
        450,
        0,
        0,
        2,
        5,
        11,
        false,
        true,
        false
    },{
        "炎魔之牙",
        "传说中的炎魔的利齿，温度极高",
        "精品",
        "FL",
        26,
        42,
        450,
        0,
        0,
        2,
        6,
        11,
        false,
        true,
        false
    },{
        "大骨棒",
        "可以锤飞人的那种",
        "精品",
        "CP",
        29,
        36,
        250,
        0,
        0,
        0,
        11,
        11,
        false,
        true,
        false
    },{
        "圣剑",
        "握在手中充满力量，是神圣的武器",
        "精品",
        "BS",
        18,
        24,
        280,
        7000,
        0,
        2,
        0,
        7,
        true,
        true,
        false
    },{
        "海王星之剑",
        "拥有海之眷顾的魔法之剑",
        "精品",
        "XZ",
        18,
        35,
        350,
        20000,
        2,
        0,
        5,
        10,
        true,
        true,
        false
    },{
        "黑曜石大刀",
        "这东西锋利无比",
        "精品",
        "DK",
        30,
        45,
        500,
        0,
        3,
        3,
        0,
        12,
        false,
        true,
        false
    },{
        "双刃大金刀",
        "巨重无比的大剑",
        "精品",
        "RI",
        20,
        32,
        750,
        25000,
        3,
        0,
        0,
        12,
        true,
        true,
        false
    },{
        "熔岩武士刀",
        "用熔岩炼成，在火山口诞生",
        "精品",
        "EU",
        55,
        64,
        1200,
        27000,
        3,
        3,
        9,
        15,
        true,
        true,
        false
    },{
        "风塔",
        "一个迅速的小刀片",
        "史诗",
        "SY",
        20,
        22,
        600,
        12000,
        7,
        0,
        0,
        10,
        true,
        true,
        false
    },{
        "狼牙棒",
        "令人闻风丧胆",
        "史诗",
        "ZN",
        29,
        44,
        0,
        18000,
        0,
        0,
        5,
        11,
        true,
        false,
        false
    },{
        "kudgel",
        "野蛮的武器",
        "史诗",
        "AO",
        37,
        50,
        0,
        0,
        5,
        0,
        10,
        11,
        false,
        false,
        false
    },{
        "邪恶的克里斯",
        "刀片是铱合金",
        "史诗",
        "QL",
        34,
        40,
        0,
        0,
        6,
        0,
        14,
        11,
        false,
        false,
        false
    },{
        "暴躁的大刀",
        "它看起来可以承受任何事情",
        "史诗",
        "RJ",
        39,
        54,
        0,
        0,
        0,
        0,
        18,
        12,
        false,
        false,
        false
    },{
        "监狱",
        "一个极重的大木锤，击飞敌人",
        "传奇",
        "TO",
        40,
        55,
        0,
        28000,
        5,
        3,
        10,
        13,
        true,
        false,
        false
    },{
        "巨人之刀",
        "巨人留下的遗物",
        "传奇",
        "GH",
        45,
        57,
        0,
        0,
        0,
        0,
        15,
        13,
        false,
        false,
        false
    },{
        "银河之剑",
        "你闻所未闻",
        "传奇",
        "RY",
        60,
        80,
        0,
        28000,
        0,
        0,
        0,
        14,
        true,
        false,
        false
    },
};

class Player {
public:
    Enginery engins[31];
    int enginIndex; 
    Enginery handEngin;
    int G;
    int level;
    int agg;
    int def;
    int crit;
    int forHP;
    int nowHP;
    
    bool arenaOver;
    int arenaNum;
    int holeNum;
    int oceanNum;
    int bunkerNum;
    int desertNum;
    
    int forEXP;
    int nowEXP;
    
    void printG() {
        cout << "您现在拥有 ";
        mcolor(LYellow);
        cout << G << "G\n";
        Normal;
    }
    
    void haveEngin(Enginery &v_engin) {
        v_engin.isHave = true;
        engins[++enginIndex] = v_engin;
        class_Player_engins_name[++class_Player_enginIndex] = v_engin.name;
        cout << "(获得了" << v_engin.name << ")\n";
        char c = played();
    }
    
    void enginShow() {
        system("CLS");
        for(int i = 1;i <= enginIndex;i++) {
            cout << i << ". ";
            engins[i].synopsis();
        }
        cout << "\n输入use [武器编号] 可以使用武器\n"
             << "输入throwAway [武器编号] 可以出售武器\n";
        int n;
        string s;
        cin >> s;
        cin >> n;
        if(n >= 1 && n <= enginIndex) {
            if(s == "use") {
                handEngin = engins[n];
                class_Player_handEngin_name = engins[n].name;
            } else if(s == "throwAway" && enginIndex >= 1) {
                handEngin = engin[0];
                G += engins[n].outG;
                for(int i = n;i < enginIndex;i++) {
                    engins[i] = engins[i+1];
                }
                enginIndex--;
            }
        }
    }
};

Player player = {
    {},
    0,
    engin[0],
    500,
    1,
    10,
    10,
    5,
    40,
    40,
    false,
    100,
    0,
    0,
    0,
    0,
    100,
    0
};

class Foe {
public:
    Enginery handEngin;
    int nowHP;
    int agg;
    int def;
    int crit;
    int G;
};

Foe foe[6] = {
    {},{
        engin[1],
        20,
        10,
        10,
        5,
        800
    },{
        engin[1],
        50,
        10,
        10,
        5,
        1200
    },{
        engin[7],
        50,
        9,
        9,
        10,
        3000
    },{
        engin[7],
        60,
        10,
        10,
        10,
        4500
    },{
        engin[2],
        60,
        12,
        12,
        15,
        5000
    },
};

class Mon {
public:
    string name;
    int nowHP;
    int agg;
    int lowAgg;
    int highAgg;
    int def;
    int lowG;
    int highG;
    int live[101];
    int liveNum;
};

Mon mon[51] {
    {},{
        "骷髅",
        80,
        8,
        15,
        20,
        8,
        100,
        200,
        {1,2,3,4,5,6},
        6
    }
};

class Map {
public:
    string name;
    int gateNum;
    Mon monster[31];
    int monNum;
    bool canGo;
};

Map risk[5] {
    {},{
        "骷髅洞穴",
        6,
        {mon[0],mon[1]},
        1,
        false
    },{
        "深水沟",
        3,
        {},
        0,
        false
    },{
        "地堡",
        11,
        {},
        0,
        false
    },{
        "沙漠战场",
        999999,
        {},
        0,
        false
    }
};

void mainView() {
    cout << "1. 擂台赛";
    if(player.arenaOver)
        cout << "【通关成功】\n";
    else
        cout << "\n";
    cout << "2. 冒险之旅\n";
    cout << "3. 角斗士\n";
    cout << "4. 兵器库\n";
    cout << "5. 商店\n";
    cout << "6. 保存并退出\n\n";
}

// Story

void action() {
    char c;
    cout << "1.跳过开头 2.查看故事情节\n";
    c = played();
    if(c == '1') {
        player.haveEngin(engin[1]);
        return;
    }
    system("CLS");
    print("你好啊，年轻人");
    print("我是上个时代的决斗之王");
    print("唉，可惜我老了，不中用了，上不了战场了");
    print("我有一个宝贝想送给你");
    print("拿着吧，它会给你带来好运的");
    player.haveEngin(engin[1]);
}

void theClubStory() {
    system("CLS");
    char c;
    print("哇，你的技术还不错哦\n");
    print("要不要考虑一下加入我们冒险家工会\n");
    print("我们会在你危难时刻提供帮助的\n");
    do {
        print("1.加入 2.不加入\n");
        c = played();
    } while(c == 2);
    print("好的，那就这样定了\n");
    print("最后送你个礼物\n");
    player.haveEngin(engin[2]);
}

// Introduce

void introduceView() {
    system("CLS");
    string enginName;
    bool flag = false;
    cout << "输入武器名称：";
    cin >> enginName;
    system("CLS");
    for(int i = 1;i <= ENGINNUM;i++) {
        if(findWord(engin[i].name,enginName)) {
            engin[i].synopsis();
            flag = true;
        }
    }
    if(flag == false) {
        cout << "找不到武器" << enginName << "\n";
    }
    char cc = played();
    Back;
}

// War

void actionPlayer(Player &thisPlayer) {
    thisPlayer.agg += thisPlayer.handEngin.aggNum;
    thisPlayer.def += thisPlayer.handEngin.defNum;
    thisPlayer.crit += thisPlayer.handEngin.critNum;
}

void actionFoe(Foe &thisFoe) {
    thisFoe.agg += thisFoe.handEngin.aggNum;
    thisFoe.def += thisFoe.handEngin.defNum;
    thisFoe.crit += thisFoe.handEngin.critNum;
}

// Soldier

void myself() {
    system("CLS");
    cout << "角斗士" << "等级" << player.level << "\n";
    cout << player.nowEXP << "EXP\n";
    cout << player.G << "G\n";
    cout << "武器 " << player.handEngin.name << "\n";
    cout << "装备库 e\n";
    char c = played();
    switch (c) {
    case 'e':
        player.enginShow();
        break;
    }
    c = played();
}

// Wrestle

void critClear() {
    for(int i = 1;i <= 100;i++) {
        crit[i] = false;
    }
}

bool critModel(int critSet) {
    critClear();
    for(int i = 1;i <= 100;i++) {
        if(critSet > 0) {
            crit[i] = true;
            critSet--;
        }
    }
    int index = Random(1,100);
    return crit[index] ? true : false;
}

void fightViewW(Foe thisFoe,Player thisPlayer) {
    ucolor(LRed);
    cout << "敌方\n";
    Normal;
    cout << "HP " << thisFoe.nowHP << "\n";
    cout << "攻击" << thisFoe.agg << "\n";
    cout << "防御" << thisFoe.def << "\n";
    cout << "暴击" << thisFoe.crit << "\n";
    cout << "武器 " << thisFoe.handEngin.name << "\n\n";
    
    ucolor(LBlue);
    cout << "己方\n";
    Normal;
    cout << "HP " << thisPlayer.nowHP << "\n";
    cout << "攻击" << thisPlayer.agg << "\n";
    cout << "防御" << thisPlayer.def << "\n";
    cout << "暴击" << thisPlayer.crit << "\n";
    cout << "武器 " << thisPlayer.handEngin.name << "\n\n";
}

int EXPGotW(Player thisPlayer,Foe thisFoe) {
    int got
    = thisPlayer.nowHP
    -thisFoe.nowHP
    +thisFoe.agg
    +thisFoe.def
    +thisFoe.crit
    +Random(1,10);
    return got;
}

int goAgg(int def,int agg,int aggNumUp,int aggNumDown) {
    srand((unsigned)time(NULL));
    int aggNum = Random(aggNumDown,aggNumUp);
    return aggNum * agg / def;
}

int goDef(int &def) {
    int up = Random(1,4);
    def += up;
    return up;
}

void foeToAggW(Player &thisPlayer,Foe &thisFoe) {
    int up = thisFoe.handEngin.aggBig;
    int down = thisFoe.handEngin.aggSml;
    int agg = goAgg(thisPlayer.def,thisFoe.agg,up,down);
    bool flat = critModel(thisFoe.crit);
    if(flat) {
        agg *= 2;
    }
    thisPlayer.nowHP -= agg;
    if(flat) {
        print("对方打出了暴击，造成了"+intToString(agg)+"点伤害\n",false);
    } else {
        print("对方给你造成了"+intToString(agg)+"点伤害\n",false);
    }
}

void playerToAggW(Player &thisPlayer,Foe &thisFoe) {
    int up = thisPlayer.handEngin.aggBig;
    int down = thisPlayer.handEngin.aggSml;
    int agg = goAgg(thisFoe.def,thisPlayer.agg,up,down);
    bool flat = critModel(thisPlayer.crit);
    thisFoe.nowHP -= agg;
    if(flat) {
        print("你打出了暴击，造成了"+intToString(agg)+"点伤害\n",false);
    } else {
        print("你给对方造成了"+intToString(agg)+"点伤害\n",false);
    }
}

void wrestle(int arenaNum) {
    system("CLS");
    if(player.handEngin.name == "无") {
        print("先去角斗士中的装备库中选择武器吧\n");
        return;
    }
    Foe thisFoe;
    Player thisPlayer;
    bool win;
    switch (arenaNum) {
    case 100: thisFoe = foe[1];break;
    case 200: thisFoe = foe[2];break;
    case 300: thisFoe = foe[3];break;
    case 400: thisFoe = foe[4];break;
    case 500: thisFoe = foe[5];break;
    case 600: player.arenaOver = true;risk[1].canGo = true;return;
    default : return;
    }
    
    thisPlayer = player;
    
    actionPlayer(thisPlayer);
    actionFoe(thisFoe);
    
    fightViewW(thisFoe,thisPlayer);
    ForEver {
        system("CLS");
        if(thisPlayer.nowHP <= 0 && thisFoe.nowHP <= 0) {
            cout << "平局\n";
            srand((unsigned)time(NULL));
            int got = EXPGotW(thisPlayer,thisFoe);
            cout << "你得到了" << got << "点经验值\n";
            cout << "你得到了" << thisFoe.G/2 << "G\n";
            player.nowEXP += got/2;
            player.G += thisFoe.G/2;
            player.arenaNum += 100;
            char c = played();
            return;
        } else if(thisPlayer.nowHP <= 0) {
            cout << "真可惜\n";
            win = false;
            char c = played();
            return;
        } else if (thisFoe.nowHP <= 0) {
            cout << "你赢了！\n";
            win = true; 
            srand((unsigned)time(NULL));
            int got = EXPGotW(thisPlayer,thisFoe);
            cout << "你得到了" << got << "点经验值\n";
            cout << "你得到了" << thisFoe.G << "G\n";
            player.nowEXP += got;
            player.G += thisFoe.G;
            char c = played();
            if(player.arenaNum == 100) {
                theClubStory();
                player.arenaNum += 100;
                return;
            }
            player.arenaNum += 100;
            c = played();
            return;
        }
        fightViewW(thisFoe,thisPlayer);
        char c = played();
        switch (c) {
        case 'j':
            playerToAggW(thisPlayer,thisFoe);
            break;
        }
        sleep(1);
        
        int moveE = Random(1,1);
        switch (moveE) {
        case 1: 
            foeToAggW(thisPlayer,thisFoe);
            break;
        }
        
        sleep(1);
    }
}

// Store

void storeView(int i,Enginery thisEngin) {
    cout << i << ". "
         << thisEngin.name << ' ';
    thisEngin.printEnginLevel();
    Normal;
    cout << "\n";
    cout << "  购买花费: " << thisEngin.inG << "G\n";
}

void store() {
    system("CLS");
    Enginery tmp[31];
    int index = 0;
    int n;
    ucolor(LWhite);
    mcolor(LDark);
    ucolor(LWhite);
    cout << "\t\t\t商店\n\t\t";
    Normal;
    cout << "   ";
    player.printG();
    for(int i = 1;i <= ENGINNUM;i++) {
        if(engin[i].canBuy && engin[i].useLevel <= player.level) {
            tmp[index++] = engin[i];
        }
    }
    for(int i = 1;i < index;i++)
        storeView(i,tmp[i]);
    
    cout << "请输入购买武器的序号: ";
    cin >> n;
    if(n > 0 && n <= index && player.G >= tmp[n].inG) {
        player.haveEngin(tmp[n]);
        player.G -= tmp[n].inG;
        for(int i = 1;i <= ENGINNUM;i++) {
            if(engin[i].name == tmp[n].name) {
                engin[i].canBuy = false;
            }
        }
        cout << "\n购买成功\n";
    } else {
        cout << "\n购买失败\n";
    }
    char c = played();
}

// Adventure

void fightViewA(Player thisPlayer,Mon thisMonster,int round) {
    cout << "Round " << round << "\n";
    
    cout << thisMonster.name << "\n";
    cout << "HP " << thisMonster.nowHP << "\n";
    cout << "攻击" << thisMonster.agg << "\n";
    cout << "防御" << thisMonster.def << "\n\n";
    
    cout << "己方\n";
    cout << "HP " << thisPlayer.nowHP << "\n";
    cout << "攻击" << thisPlayer.agg << "\n";
    cout << "防御" << thisPlayer.def << "\n";
    cout << "暴击" << thisPlayer.crit << "\n";
    cout << "武器 " << thisPlayer.handEngin.name << "\n\n";
}

void monToAggA(Player &thisPlayer,Mon &thisMonster) {
    int agg = goAgg(thisPlayer.def,thisMonster.agg,thisMonster.highAgg,thisMonster.lowAgg);
    thisPlayer.nowHP -= agg;
    print("怪物给你造成了"+intToString(agg)+"点伤害\n");
}

void playerToAggA(Player &thisPlayer,Mon &thisMonster) {
    int up = thisPlayer.handEngin.aggBig;
    int down = thisPlayer.handEngin.aggSml;
    int agg = goAgg(thisMonster.def,thisPlayer.agg,up,down);
    bool flat = critModel(thisPlayer.crit);
    if(flat)
        agg *= 2;
    thisMonster.nowHP -= agg;
    if(flat) {
        print("你打出了暴击，造成了"+intToString(agg)+"点伤害\n");
    } else {
        print("你给对方造成了"+intToString(agg)+"点伤害\n");
    }
}

int EXPGotA(Player thisPlayer,Mon thisMonster) {
    int got
    = thisPlayer.nowHP
    -thisMonster.nowHP
    +thisMonster.agg
    +thisMonster.def
    +Random(1,10);
    return got;
}

int advView() {
    system("CLS");
    int index = 1;
    if(risk[1].canGo) {
        cout << index << ".骷髅洞穴\n";
        index++;
    }
    if(risk[2].canGo) {
        cout << index << ".深海沟\n";
        index++;
    }
    if(risk[3].canGo) {
        cout << index << ".地堡\n";
        index++;
    }
    if(risk[4].canGo) {
        cout << index << ".沙漠战场\n";
        index++;
    }
    if(index == 1) {
        cout << "你还不能冒险\n";
        return 0;
    }
    cout << "输入冒险名称：";
    string s;
    cin >> s;
    for(int i = 1;i <= 5;i++) {
        if(risk[i].name == s) {
            return i;
        }
    }
    return 0;
}

Mon createMonster(Map riskx,int index) {
    Mon allMon[99];
    int monIndex = 0;
    bool canBe = false;
    for(int i = 1;i <= riskx.monNum;i++) {
        canBe = false;
        for(int j = 1;j <= riskx.monster[i].liveNum;j++) {
            if(riskx.monster[i].live[j] == index) {
                canBe = true;
                break;
            }
        }
        if(canBe) {
            allMon[++monIndex] = riskx.monster[i];
        }
    }
    int decide = Random(1,monIndex);
    return allMon[decide];
}

void holeADV() {
    system("CLS");
    srand((unsigned)time(NULL));
    cout << "--------------第" << player.holeNum << "关--------------\n";
    sleep(5);
    Player thisPlayer = player;
    int gotMonNum = Random(2,5);
    actionPlayer(thisPlayer);
    char c = played();
    system("CLS");
    for(int round_ = 1;round_ <= gotMonNum;round_++) {
        Mon thisMonster = createMonster(risk[1],player.holeNum);
        ForEver {
            fightViewA(thisPlayer,thisMonster,round_);
        }
    }
    system("CLS");
    if(player.holeNum < risk[1].gateNum) {
        cout << "闯关成功\n";
        player.holeNum++;
    } else {
        cout << "恭喜你！完成了「骷髅洞穴」地图！\n";
        risk[2].canGo = true;
    }
}

void adventure() {
    int n = advView();
    if(n == 0)
        return;
    switch(n) {
    case 1: holeADV();break;
    }
}

string endGame();
bool theTrueCode(string code);
void actionGame(string code);

int main() {
    char move;
    system("CLS");
    cout << "输入存档代码，新手输入1\n";
    string s;
    cin >> s;
    char c = played();
    if(s == "1") {
        system("CLS");
        action();
    } else if(theTrueCode(s)) {
        actionGame(s);
    } else {
        return 0;
    }
    system("CLS");
    ForEver {
        if(player.forEXP <= player.nowEXP && player.level < 15) {
            player.nowEXP = 0;
            player.forEXP += 20;
            player.nowHP += 10;
            player.level++;
            
            player.agg += 1;
            player.def += 1;
            player.crit += 1;
        }
        mainView();
        move = played();
        switch (move) {
        case '1':
            wrestle(player.arenaNum);
            break;
        case '2':
            adventure();
            break;
        case '3':
            myself();
            break;
        case '4':
            introduceView();
            break;
        case '5':
            store();
            break;
        case '6':
            cout << endGame();
            return 0;
        default :
            system("CLS");
            continue;
        }
        system("CLS");
    }
    return 0;
}

string moneyGet() {
    string code = "";
    
    int money = player.G;
    int tmp = 100000;
    for(int i = 6;i >= 1;i--) {
        int have = money / tmp;
        money = money % tmp;
        tmp/=10;
        if(have == 0) continue;
        code += intToString(have);
        switch (i) {
        case 1: code += 'Q';break;
        case 2: code += 'U';break;
        case 3: code += 'C';break;
        case 4: code += 'S';break;
        case 5: code += 'K';break;
        case 6: code += 'D';break;
        }
    }
    
    return code;
}

string enginGetSet() {
    string code = "";
    
    for(int i = 1;i <= player.enginIndex;i++) {
        code += player.engins[i].key;
        if(i != player.enginIndex)
            code += '_';
    }
    
    return code;
}

void codeDigitAndAlpha(string &code) {
    long len = code.length();
    int digitSum = 0;
    int alphaSum = 0;
    for(int i = 0;i < len;i++) {
        if(isdigit(code[i])) {
            digitSum += code[i] - '0';
            digitSum = digitSum % 10;
        } else if(isalpha(code[i])) {
            alphaSum += (int)code[i];
            alphaSum = alphaSum % 10;
        }
    }
    code += intToString(digitSum) + '|';
    code += intToString(alphaSum);
}

string endGame() {
    string code = "";
    srand((unsigned)time(NULL));
    
    string agg = intToString(player.agg);
    string s1 = '['+intToString(player.arenaNum)+',';
    string s2 = intToString(player.holeNum)+',';
    string s3 = intToString(player.oceanNum)+',';
    string s4 = intToString(player.bunkerNum)+',';
    string s5 = intToString(player.desertNum)+']';
    int nowEXP = player.nowEXP;
    
    code += "U!";
    code += moneyGet();code += '|';
    code += intToString(player.level) + '|';
    code += intToString(player.agg) + '|';
    code += intToString(player.def) + '|';
    code += intToString(player.crit) + '|';
    code += intToString(player.nowEXP) + '|';
    code += enginGetSet();
    code += s1;code += s2;code += s3;code += s4;code += s5;
    codeDigitAndAlpha(code);
    
    return code;
}

bool theTrueCode(string code) {
    if(code[0] != 'U' || code[1] != '!') return false;
    int digitSum = 0,alphaSum = 0;
    long len = code.length();
    if(len < 20) return false;
    for(int i = 0;i < len-3;i++) {
        if(isdigit(code[i])) {
            digitSum += code[i] - '0';
            digitSum = digitSum % 10;
        } else if(isalpha(code[i])) {
            alphaSum += (int)code[i];
            alphaSum = alphaSum % 10;
        }
    }
    //if(digitSum != code[len-3]-'0' || alphaSum != code[len-1] - '0') return false;
    return true;
}

int AmoneyGot(string &code) {
    int i = 0;
    int tmp = 0;
    int G = 0;
    long len = code.length();
    for(i = 0;isNULL(code[i]);i++)
        ;
    while(code[i] != '|') {
        if(isdigit(code[i])) {
            tmp = code[i] - '0';
        } else if(isalpha(code[i])) {
            switch (code[i]) {
            case 'Q': G += 1*tmp;break;
            case 'U': G += 10*tmp;break;
            case 'C': G += 100*tmp;break;
            case 'S': G += 1000*tmp;break;
            case 'K': G += 10000*tmp;break;
            case 'D': G += 100000*tmp;break;
            }
        }
        code[i++] = '\0';
    }
    code[i] = '\0';
    return G;
}

int AlevelGot(string &code,char stop) {
    int i;
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    int sum = stringToInt(code);
    for(;code[i] != stop && i <= code.length();i++) {
        code[i] = '\0';
    }
    code[i] = '\0';
    return sum;
}

int AaggGot(string &code,char stop) {
    int i;
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    int sum = stringToInt(code);
    for(;code[i] != stop && i <= code.length();i++) {
        code[i] = '\0';
    }
    code[i] = '\0';
    return sum;
}

int AdefGot(string &code,char stop) {
    int i;
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    int sum = stringToInt(code);
    for(;code[i] != stop && i <= code.length();i++) {
        code[i] = '\0';
    }
    code[i] = '\0';
    return sum;
}

int AcritGot(string &code,char stop) {
    int i;
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    int sum = stringToInt(code);
    for(;code[i] != stop && i <= code.length();i++) {
        code[i] = '\0';
    }
    code[i] = '\0';
    return sum;
}

int AEXPGot(string &code,char stop) {
    int i;
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    int sum = stringToInt(code);
    for(;code[i] != stop && i <= code.length();i++) {
        code[i] = '\0';
    }
    code[i] = '\0';
    return sum;
}

void AEnginGot(string &code) {
    int i;
    bool last = false;
    string s = "";
    
    for(i = 0;isNULL(code[i]);i++)
        ;
    for(i = i;code[i] != '[' && i <= code.length();i++) {
        if(last == false) {
            last = true;
        } else  {
            last = false;
        }
        
        for(int j = 1;j <= ENGINNUM;j++) {
            if(code[i] == engin[j].key[0] && code[i+1] == engin[j].key[1]) {
                player.haveEngin(engin[j]);
                break;
            }
        }
        code[i] = '\0';
    }
}

void AFightGot(string &code) {
    int i;
    int flat = 0;
    for(i = 0;isNULL(code[i]);i++)
        ;
    if(code[i] == '[') {
        code[i++] = '\0';
        while(code[i] != ']') {
            if(isdigit(code[i])) {
                int sum = stringToInt(code);
                while(isdigit(code[i])) {
                    code[i++] = '\0';
                }
                i--;
                flat++;
                switch(flat) {
                case 1: player.arenaNum = sum;break;
                case 2: player.holeNum = sum;break;
                case 3: player.oceanNum = sum;break;
                case 4: player.bunkerNum = sum;break;
                case 5: player.desertNum = sum;break;
                }
            }
            code[i++] = '\0';
        }
        code[i] = '\0';
    }
}

void actionGame(string code) {
    long len = code.length();
    code[0] = '\0';code[1] = '\0';
    
    player.G = AmoneyGot(code);
    player.level = AlevelGot(code,'|');
    player.agg = AaggGot(code,'|');
    player.def = AdefGot(code,'|');
    player.crit = AcritGot(code,'|');
    player.nowEXP = AEXPGot(code,'|');
    AEnginGot(code);
    AFightGot(code);
}

//U!5C|1|10|10|5|10|GH[500,0,0,0,0]7|7
