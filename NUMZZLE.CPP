#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

static int n=4,cnt=0;
int ans[6][6];
int st[6][6]={{3,2,6,13,18,27},{1,4,8,15,21,32},{5,7,9,11,24,28},{12,14,10,16,22,33},{23,19,20,17,25,35},{26,30,34,29,31,36}};
int row=n;
int col=n;

void sol()
{
    int c=1;
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
	    ans[i][j]=c;
	    c++;
	}
    }
}

int check()
{
    int d=0;
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(ans[i][j]!=st[i][j]) return d;
		else d++;
	}
    return d;
}

void cod()
{
    float xm=22.0,ym=9.85,w1=8.0,w2=5.4,g=1.55,x,y,row,col;
    for(row=0;row<n;row++)
    {
	y=(row/n)*ym*g;
	for(col=0;col<n;col++)
	{
	    x=(col/n)*xm*g;
	    gotoxy(x+w1,y+w2);
	    if(st[row][col]==n*n)
	    {
	      cout<<"  ";
	      continue;
	    }
	    cout<<st[row][col];
	}
    }
}


void scod()
{
    float xm=22.0,ym=9.85,w1=8.0,w2=5.4,g=1.55,x,y,row,col;
    for(row=0;row<n;row++)
    {
	y=(row/n)*ym*g;
	for(col=0;col<n;col++)
	{
	    x=(col/n)*xm*g;
	    gotoxy(x+w1,y+w2);
	    cout<<ans[row][col];
	}
    }
}


void grid()
{
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");
    setcolor(3);
    int w=42,g=2,l=1,t=1,r=310,b=300;
    float ratio=(float)1/(n+1);
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    rectangle((j*ratio*l)+w,(i*ratio*t)+w,(j*ratio*r)+w,(i*ratio*b)+w);
	    rectangle((j*ratio*l)+w+g,(i*ratio*t)+w+g,(j*ratio*r)+w-g,(i*ratio*b)+w-g);
	}
    }
    setcolor(5);
    rectangle(295,365,550,420);
    rectangle(294,364,551,421);
    settextstyle(0,0,1);
    outtextxy(300,370,"HINT");
    line(298,380,335,380);
    outtextxy(300,390,"PRESS ENTER TO START OR QUIT");
    outtextxy(300,410,"USE ARROW KEYS TO MOVE");
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    cnt++;
}

void game()
{
    int ch,r,c,d=0;
    while((d=check())!=n*n)
    {
	 r=row-1;
	 c=col-1;
	 cout<<"\n\n\n\n\t\t\t\t\tMATCH: "<<d<<"   "<<endl<<"   "<<"\t\t\t\t\tMOVE : "<<cnt<<"   ";
	 cod();
	 ch=getch();
	 if(ch==72&&r!=n-1)   //up key
	 {
	     swap(&st[r][c],&st[r+1][c]);
	     row++;
	 }
	 else if(ch==80&&r!=0)   //down key
	 {
	     row--;
	     swap(&st[r][c],&st[r-1][c]);
	 }
	 else if(ch==75&&c!=n-1)   //left key
	 {
	     swap(&st[r][c],&st[r][c+1]);
	     col++;
	 }
	 else if(ch==77&&c!=0)        //right key
	 {
	     col--;
	     swap(&st[r][c],&st[r][c-1]);
	 }
	 else if(ch==13)
	     break;
	 else
	     continue;
    }
    if (d==n*n)
    {
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	settextstyle(1,0,3);
	int x_=getmaxx()/4,y_=getmaxy()/3;
	outtextxy(x_,y_,"***_Y O U  W I N_***");
	settextstyle(7,0,4);
	outtextxy(x_+30,y_+40,"H");
	delay(150);
	outtextxy(x_+60,y_+40,"U");
	delay(150);
	outtextxy(x_+90,y_+40,"R");
	delay(150);
	outtextxy(x_+120,y_+40,"R");
	delay(150);
	outtextxy(x_+150,y_+40,"A");
	delay(150);
	outtextxy(x_+180,y_+40,"Y");
	delay(150);
	outtextxy(x_+200,y_+40,"!");
	delay(150);
	getch();
	closegraph();
    }
}

void start()
{
    {
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	setcolor(4);
	settextstyle(1,0,3);
	int x_=getmaxx()/4,y_=getmaxy()/3;
	outtextxy(x_,y_,"*** MADE BY --> VIPUL_KUMAR ***");
	settextstyle(7,0,4);
	setcolor(3);
	outtextxy(x_+30,y_+40,"W");
	delay(100);
	outtextxy(x_+60,y_+40,"E");
	delay(100);
	outtextxy(x_+90,y_+40,"L");
	delay(100);
	outtextxy(x_+120,y_+40,"C");
	delay(100);
	outtextxy(x_+150,y_+40,"O");
	delay(100);
	outtextxy(x_+180,y_+40,"M");
	delay(100);
	outtextxy(x_+210,y_+40,"E");
	outtextxy(x_+20,y_+80,"NUMber_puZZLE");
	delay(100);
	getch();
	closegraph();
    }
}

void main()
{
    char opt;
    start();
    label1:
    row=n,col=n,cnt=0;
    label:
    textcolor(WHITE);
    cputs("\n");
    clrscr();
    cout<<"\n\t***Select an option***  "<<endl<<"\n\t1.\tStart Game"<<endl<<"\t2.\tDifficulty Level"<<endl<<"\t3.\tHigh Score"<<endl<<"\t4.\tExit"<<endl;
    cout<<"\n\t enter choice 1 to 4: \n\t ";
    opt=getch();
    int d=check();
    if(opt=='2'&& d!=0)
    {
	textcolor(3); //cyan
	gotoxy(15,18);
	cputs(" Your progress will be lost (if any) ");
	gotoxy(15,20);
	cputs(" Press ENTER to continue... ");
	int flag=getch();
	textcolor(15); //white
	if(flag==13||flag==13)  //enter
	opt='2';
	else
	goto label;
    }
    switch(opt)
    {
	case '1':
	{
	    cout<<"Start game"<<endl;
	    sol();
	    grid();
	    scod();
	    getch();
	    closegraph();
	    grid();
	    cod();
	    game();
	    closegraph();
	    goto label;

	}
	case '2':
	{
	    clrscr();
	    int st_[6][6]={{3,2,6,13,18,27},{1,4,8,15,21,32},{5,7,9,11,24,28},{12,14,10,16,22,33},{23,19,20,17,25,35},{26,30,34,29,31,36}};
	    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    st[i][j]=st_[i][j];
	    char opt;
	    label2:
	    cout<<"Difficulty Level\n";
	    cout<<"\n\tselect an option"<<endl<<"\t1.\tEasy"<<endl<<"\t2.\tMedium"<<endl<<"\t3.\tHard"<<endl<<"\n\n\t\tPRESS X TO GO BACK"<<endl;
	    opt=getch();
	    switch(opt)
	    {
		case '1':
		{
		    if(n==3)
		     n++;
		    else
		     n=3;
		    clrscr();
		    goto label1;
		}
		case '2':
		{
		    n=5;
		    clrscr();
		    goto label1;
		}
		case '3':
		{
		    n=6;
		    clrscr();
		    goto label1;
		}
		default:
		{
		    if(opt=='x'||opt=='X')
		    goto label1;
		    else
		    {
		      textcolor(RED);
		      cputs("enter correct option");
		      delay(1000);
		      textcolor(WHITE);
		      clrscr();
		      goto label2;
		    }
		}
	    }
	}
	case '3':
	{
	    clrscr();
	    cout<<"\n\t*******High Score*******"<<endl;
	    cout<<"\tWill be updated soon  ...";
	    getch();
	    goto label;

	}
	case '4':
	{
	    char flag;
	    gotoxy(15,18);
	    textcolor(RED);
	    cputs("press Y to exit..");
	    flag=getch();
	    if(flag=='y'|| flag=='Y')
	    exit (0);
	    else
	    goto label;
	}
	default:
	{
	    textcolor(RED);
	    cputs("enter correct option");
	    cout<<endl;
	    delay(1000);
	    textcolor(WHITE);
	    clrscr();
	    goto label;
	}
    }
}
