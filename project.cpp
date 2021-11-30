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
    int year,month;

    printf("Enter the month and year: ");
    scanf("%d %d", &month, &year);

    calendar(year, month);

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

int D_clock()
{
    int h=0,m=0,s=0;
    if(h>12 || m>60 || s>60)
    {
        printf("ERROR! \n");
        exit(0);
    }
    while(1)
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
        if(h>12)
        {
            h=1;
        }
        printf("\n Clock :");
        printf("\n %02d:%02d:%02d",h,m,s);
        Sleep(1000);
        system ("cls");
    }
}

int main()
{
    int choice;
    printf("Please Enter the number :");

    while(1){
        scanf("%d",&choice);
        switch(choice){
        case 1:
            D_clock();
            break;
        case 2:
            A_clock();
            break;
        case 3:
            m_calend();
            break;
        case 4:
            printf("will be updated shortly");
            break;
        case 5:
            system("cls");
            printf("will be updated shortly");
            exit(0);
    }
return 0;
}}
