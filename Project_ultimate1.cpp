#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<windows.h>

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
int i,inr=80,outr=100;
int hdeg,mindeg,secdeg,x,y;
circle(xc,yc,outr);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(xc,yc,5,5);
for(i=180;i>-360;i-=6)
{
if(i%5==0)
fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),1,1);

else
fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),1,1);

hdeg=hr*360/12+30*min/60;
mindeg=min*6;
secdeg=sec*6;
x=xc+40*sin(hdeg*3.14f/180);
y=yc-40*cos(hdeg*3.14f/180);
line(xc,yc,x,y);
x=xc+55*sin(mindeg*3.14f/180);
y=yc-55*cos(mindeg*3.14f/180);
line(xc,yc,x,y);
x=xc+65*sin(secdeg*3.14f/180);
y=yc-65*cos(secdeg*3.14f/180);
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

while(!kbhit())
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
        system("color 06");
		printf("You have %d seconds left\n",k);
		Sleep(995);
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
    printf("\t\t\t\t\t    1.Press 1 for countdown timer\n\n\t\t\t\t\t    2.Press 2 for Reserved\n\n\t\t\t\t\t    3.Press 3 for Calender\n\n\t\t\t\t\t    4.Press 4 for analog clock\n\n\t\t\t\t\t    5.Press 5 to exit");
    int choice;
    printf("\n\n\t\t\t\t\t    Your Choice :");
    scanf("%d",&choice);
    if(choice==1){
        coundown();

        wlcm();}
    else if(choice==2){
        printf("Reserved for something idk");
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
        printf("Thank you for using our program Made BY BALAJI,DHRUV,ISHAN,LOHIT(Temp)");
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

    printf("    Apna Project   ");




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
