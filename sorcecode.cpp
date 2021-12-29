#include<conio.h>
#include<stdio.h>
#include<graphics.h> //This is the graphics header file which is used to show graphics in windows bgi
#include<math.h>
#include<time.h>  //very important in collecting local time from windows
#include<windows.h> // allows us to use sleep and other commands which change the cmd flow and look
int Alarm_clock(){

    system("color 01"); // changes cmd colour

    int a,b,c;

    system("cls");

    printf("\n");
    printf("                                Enter the time you want the alarm to ring :\n                                Enter the hour : ");

    scanf("%d",&a);
    printf("                                Enter the minute : ");
    scanf("%d",&b);
    printf("                                Enter the seconds : ");
    scanf("%d",&c);


    time_t rawtime; // taking local time from windows
    struct tm * timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    int h=timeinfo->tm_hour,m=timeinfo->tm_min,s=timeinfo->tm_sec; // giving hour to h and minute m and seconds to s

    int i=1;

    while(i)
    {
        s++;
        if(s>59)
            {
            m++;
            s=0;
        }
        if(m>59)
            {
            h++;
            m=0;
        }
        if(h>24)
            {
            h=1;
        }
        printf("\n Clock :");

        printf("\n %02d:%02d:%02d",h,m,s); // presentation of the clock

        Sleep(995); // sleeps the cmd for 995 milisecs
        system ("cls");

        if(a==h && b==m && c==s){

            int n=5;
            while(n--){
            printf("WAKE UP ");
		    Beep(10000000, 450); // this fuction gives sound when called and here 10000000 is the frequency and 450 is the time in ms
            i=0;
            }
        }
    }
    printf("\n");
    system("Pause"); // waits for the user to press a key...
    system("cls");
}

int isLeapYear( int year );
int leapYears( int year );
int todayOf( int y, int m, int d);
long days( int y, int m, int d);
void calendar(int y, int m);

int m_calend(void){
    system("cls");
    system("color 05");
    int year,month;
    int monthi;
    char yn;
    printf("Enter the month and year: ");
    scanf("%d %d", &month, &year);

    calendar(year, month);
    printf("CALENDER FOR %d YEAR IS AS FOLLOW : ",year);
    printf("Do You Want To Get Full Year Calendar\n");
    printf(" Y for yes and N for NO : ");
    scanf("%s",&yn);
    if(yn=='Y'||yn=='y'){
    for(monthi=1;monthi<13;monthi++){
        calendar(year,monthi);

    }
    }
    else {
        printf("YOUR REPLY WAS NO\n");

    }
    system("Pause");
    system("cls");
    return 0;
}

int isLeapYear( int y )
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
    }

int leapYears( int y )
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d)
{
    static int DayOfMonth[] =
        { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}

long days( int y, int m, int d)
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void calendar(int y, int m)
{

    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su Mo Tu We Th Fr Sa";
    int DayOfMonth[] =
        { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        printf("%2d ",day);
        if(i % 7 == 6)
            printf("\n");
    }
    printf("\n");
}

int hr,sec,min;

void drawClock(int xc,int yc)
{
int i,inr=140,outr=150;
int hdeg,mindeg,secdeg,x,y;
circle(xc,yc,outr);
circle(xc,yc,130);
setfillstyle(SOLID_FILL,LIGHTBLUE);
fillellipse(xc,yc,20,20);
for(i=180;i>-360;i-=6)
{
if(i%5==0)
fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),3,3);

else
fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),1,1);

hdeg=hr*360/12+30*min/60;
mindeg=min*6;
secdeg=sec*6;
x=xc+75*sin(hdeg*3.14f/180);
y=yc-75*cos(hdeg*3.14f/180);
line(xc,yc,x,y);
x=xc+90*sin(mindeg*3.14f/180);
y=yc-90*cos(mindeg*3.14f/180);
line(xc,yc,x,y);
x=xc+120*sin(secdeg*3.14f/180);
y=yc-120*cos(secdeg*3.14f/180);
line(xc,yc,x,y);

}

}

int A_clock()
{

time_t now;
struct tm *timeinfo;
int gd=DETECT,gm,midx,midy;
int tsec,tmin,thr;
initgraph(&gd,&gm,"..\\BGI\\");
midx=getmaxx()/2;
midy=getmaxy()/2;

time(&now);
timeinfo=localtime(&now);
hr=timeinfo->tm_hour;
min=timeinfo->tm_min;
sec=timeinfo->tm_sec;

while(1)
{
drawClock(midx,midy);
delay(995);
cleardevice();
tsec=(sec+1)%60;
tmin=(min+(tsec==0?1:0))%60;
thr=(hr+(tmin==0?1:0))%12;
hr=thr;
sec=tsec;
min=tmin;

}
return 0;
}

int coundown(){
	int k;
	system("cls");
	printf("Enter the countdown time in seconds :");
	scanf("%d",&k);
	while(k--){
        system("color 06"); // changes cmd colour
		printf("You have %d seconds left\n",k);
		Sleep(995); // sleeps the system for 995 ms
		system ("cls");
	}
	int j=5;
	while(j--){
		printf("BEEP ");
		Beep(10000000, 450);
	}
	system ("cls");

}
int wlcm(){
    system("color 0A");
    char c;
    int i=0;
    while(i<60){
    printf("%c-",c=4);
    i++;}
    i=0;
    while(i<60){
    printf("%c-",c=4);
    i++;}
    printf("\n\n");
    printf("\t\t\t\t\t    1.Press 1 for countdown timer\n\n\t\t\t\t\t    2.Press 2 for Alarm Clock\n\n\t\t\t\t\t    3.Press 3 for Calender\n\n\t\t\t\t\t    4.Press 4 for analog clock\n\n\t\t\t\t\t    5.Press 5 to exit");
    int choice;
    printf("\n\n\t\t\t\t\t    Your Choice : ");
    scanf("%d",&choice);
    if(choice==1){
        coundown();

        wlcm();}
    else if(choice==2){
        Alarm_clock();
        printf("\n");
        wlcm();
        }
    else if(choice==3){
        m_calend();
        printf("\n");
        wlcm();
    }
    else if(choice==4){
        A_clock();
        printf("\n");
        wlcm();
    }
    else if(choice==5){
        system("cls");
        int n=5;
        printf("Thank you for using our program Made BY BALAJI(RA2111026010310) , DHRUV(RA2111026010302) and ISHAN(RA2111026010325) ");
        while(n--){
        system("color 05");
        delay(100);
        system("color 02");
        delay(100);
        system("color 01 ");
        delay(100);
        system("color 04");
        delay(100);
        }
        printf("\n");
        exit(0);
    }
    else{
        printf("\t\t\t\t\t      Please enter a valid number ");
        printf("\n");
        wlcm();}

}

void wlcScreen(){
    system("color f0");
    char c;
    system("cls");
    printf("\n\n\n\n      ");

    c = 215 ;
    printf("\n\t\t\t\t\t         /-+-+-+-+-+-+-+-+-+-\\ ");
    printf("\n\t\t\t\t\t        /                     \\ ");
    printf("\n\t\t\t\t\t       /                       \\ ");
    printf("\n\t\t\t\t\t      /                         \\ ");
    printf("\n\n");


    // first line
    printf("\t\t\t\t\t%c%c%c%c%c%c",c=176,c=176,c=177,c=177,c=178,c=178);
    printf("\t\t\t\t %c%c%c%c%c%c",c=178,c=178,c=177,c=177,c=176,c=176);
    printf("\n\n\t       ");


    // second line
    // diamonds
    c=4;
    for(int i=0; i<10; i++){
        printf("-%c",c);
    }
    // heart
    c=3;
    for(int i=0; i<5; i++){
        printf("--%c",c);
    }

    printf("    PPS Project   ");




    // heart
    c=3;
    for(int i=0; i<4; i++){
        printf("%c--",c);
    }

    printf("%c-",c);
   // diamonds
    c=4;
    for(int i=0; i<10; i++){
        printf("-%c",c);
    }
    printf("-\n");

    // third line
    c=157;
    printf("\n\t\t\t   ------ %c ------\t\t\t\t    ------ %c ------",c,c);


    // fourth line
    c=153;
    printf("\n\t\t\t\t\t\t\t   %c",c);


    // fifth line
    c=240;
    printf("\n\t\t\t\t\t\t\t ");
    for(int i=0; i<5; i++){
        printf("%c",c);
    }

    // sixth line
    c=194;
    printf("\n\t\t\t\t\t\t\t   %c",c);

    // seventh line
    printf("\n\t\t\t\t\t\t\t   |");

    // eighth line
    printf("\n\t\t\t\t\t\t\t   |");

    // ninth line
    printf("\n\t\t\t\t\t\t\t   |");

    // tenth line
    printf("\n\t\t\t\t\t\t\t   |");


    while(1){
        int i=0;
        system("color f5");
        delay(500);
        system("color f2");
        delay(500);
        system("color f1 ");
        delay(500);
        system("color f4");
        delay(500);
        i++;
        if(i == 1){
            system("color 07");
            break;
        }

    }

    printf("\n\n\n\t\t\t\t\t      ");
    system("pause");
    printf("\n\n");
}

int main()
{
    wlcScreen();
    wlcm();
    return 0;
    }
