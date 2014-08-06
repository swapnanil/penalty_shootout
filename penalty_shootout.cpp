
 #include<iostream>
 #include<math.h>
 #include<iomanip.h>
 #include<conio.h>
 #include<stdio.h>
 #include<fstream.h>
 #include<stdlib.h>
 #include<process.h>

 //Declaring function prototypes
 int pl (int);
 int pr (int);
 int tl (int, int);
 int tr (int, int);
 int hit(int, int);

 //Declaring two required global variables
 int i;
 double k,l;

 //Declaring stucture for high score records
 struct highscorer
 {
 char name[20];
 int T,G;
 }hs,hs1;

 void main()
 {
 int j,h,p,c,g,t,s,b,f;          // j for loop control, f for flag, ch for choice
 float min=0;                    //h:health, p:power, g:goals, t:tries, b:bonus tracking, c:player location
 char ch;                        //s:slop of target



 WELCOME: //Welcome screen
  	for(i=0;i<25;i++)
	{
	 gotoxy(30,i);cout<<"WELCOME TO TOPGOAL!" ;
	 for(k=0;k<20000000;k++);
	 gotoxy(30,i);cout<<"                   " ;
	}

    clrscr();

	 cout<<"\n\t\t\tRULES:\n\n\t1.In the game, the player has to make goals.\n\t2.The player has to set directions and power of kick.\n\t3.With each successful goal, the difficulty level may increase.\n\t4.There is no parmanent winner, the player who scores more goals in \t\t  minimum number of turns, becomes a high scorer!\n\t5.Choose the level of power as 1,2,3,4 or 5.\n\t6. To set direction of hit, press A for left, D for right.\n\t7.To move striker, press Q for left, E for right\n\t8.To avoid injuring yourself, try not hitting the ball to hard.";
	 for(k=0;k<900000000;k++);

	 A: cout<<"\n\n\n\t\tPress H to begin goaling!";
	 cin>>ch;
	 if(ch!='h'&&ch!='H')goto A;
  //End of welcome screen

  h=8;c=41;g=0;t=0;b=0;  //Setting default values for new player

  clrscr();

 //Making field boundary
 for(i=0;i<25;i++)
	 {gotoxy(19,i);cout<<"||";
	  gotoxy(64,i);cout<<"||";}

 //Making goal post
 for(i=0;i<3;i++)
    {gotoxy(41-5,i);cout<<"|";
	  gotoxy(41+5,i);cout<<"|";}

 RESTART://Displaying Power, Direction Instuctions, Player Health, Stats
 gotoxy(5,5);cout<<" POWER\n 1  2  3  4  5";
 gotoxy(0,12);cout<<"KEY  FUNCTION\n\nQ=Move Player Left\nE=Move Player Right\nA=Turn left\nD=Turn right";
 gotoxy(67,11);cout<<"Move player";
 gotoxy(67,15);cout<<"Turn player";
 gotoxy(67,18);cout<<" Press H ";gotoxy(66,19);cout<<" To Select " ;
 gotoxy(5,9);cout<<" Restart R";
 gotoxy(5,10);cout<<" Leave game L";
 gotoxy(69,5);cout<<"HEALTH";gotoxy(68,6);cout<<"========";
 t=0;g=0;

 //Setting default health, player position, and ball position
 gotoxy(c-1,24);cout<<"[o]"; h=8;

 //Begin next try
 TRY:gotoxy(67,1);cout<<"GOALS: "<<g;
 gotoxy(67,2);cout<<"TRIES: "<<t;
 gotoxy(69,5);cout<<"HEALTH";gotoxy(68,6);cout<<"        ";gotoxy(68,6);for(i=1;i<=h;i++){cout<<"=";}

				  //Clearing field
					 for(i=0;i<25;i++)
					 for(j=21;j<64;j++)
					 {gotoxy(j,i);cout<<" ";}

              //Making field boundary
					 for(i=0;i<25;i++)
					 {gotoxy(19,i);cout<<"||";
					 gotoxy(64,i);cout<<"||";}

				 //Making goal post
					 for(i=0;i<3;i++)
					 {gotoxy(41-5,i);cout<<"|";
					 gotoxy(41+5,i);cout<<"|";}

              gotoxy(c-1,24);cout<<"[o]";

 //Get Power
 PW:gotoxy(0,7);cout<<"-> ";
 gotoxy(3,7); cin>>p;
 if((int)p>0&&(int)p<6)goto P;
 else goto PW;

 //Get player position
 P:
 gotoxy(67,12);cout<<"-> ";gotoxy(69,12);cin>>ch;
 if      (ch=='q'||ch=='Q'){c= pl(c); goto P;}
 else if (ch=='e'||ch=='E'){c= pr(c); goto P;}
 else if (ch=='h'||ch=='H')goto in;
 else if (ch=='r'||ch=='R')goto RESTART;
 else if (ch=='l'||ch=='l')goto SC;
 else goto P;

  //Set default hit direction
  in:
  s=0;
  for(i=23;i>3;i--)
  {gotoxy(c,i);cout<<"*";}

 //Get dirction of hit and hit ball
  D:
 gotoxy(67,16);cout<<"-> ";gotoxy(69,16);cin>>ch;
 if      (ch=='a'||ch=='A'){ s=tl(c,s); goto D;}
 else if (ch=='d'||ch=='D'){ s=tr(c,s); goto D;}
 else if (ch=='r'||ch=='R')goto RESTART;
 else if (ch=='l'||ch=='l')goto SC;
 else if (ch=='h'||ch=='H'){ f=hit(c,s);
									  t++;
									  h=h-p;
									  if(f)      //i.e, If goal
									  {g++; b++;}
									  else
									  b=0;
									  if(b==3){h++;
												 gotoxy(25,15);
												 cout<<"Congrats! Health bonus for hattrick!";
												 for(k=0;k<100000000;k++);
                                     gotoxy(35,15);
												 cout<<"                                    ";
                                     }
									  if(h<1)goto GO;
									  else goto TRY;}
 else goto D;

 //Game Over
 GO:
 clrscr();
 gotoxy(38,12);cout<<"GAME";
 gotoxy(38,13);cout<<"OVER";
 for(k=0;k<3;k++)
 {
	 for(i=5;i<10;i++)
		for(j=0;j<2000;j++)
		 {
		 gotoxy(40+i*cos(j),12+i*sin(j));cout<<"$";
		 }

		 for(l=0;l<10000000;l++);

		for(i=9;i>4;i--)
		for(j=0;j<2000;j++)
		 {
		 gotoxy(40+i*cos(j),12+i*sin(j));cout<<" ";
		 }
 }
 clrscr();
 //Checking records of high scorers and updating if required
 SC:
 fstream file("Highscores.text",ios::in||ios::out||ios::binary);
 if(!file.eof())file.read((char*)&hs,sizeof(highscorer));
 if(hs.T==0)min=0;
 else min=((hs.G)/(hs.T));p=0;
 for(i=1;i<5;i++)
 {
 file.read((char*)&hs,sizeof(hs));
 if(hs.T!=0){if(min>((hs.G)/(hs.T))){min=((hs.G)/(hs.T));p=i;}}
 else;
 }

 if(t!=0){if((g/t)>min)  {cout<<"Congratulations! You are a high scorer! \nName: ";
					  gets(hs.name);
					  hs1.G=g;
					  hs1.T=t;
					  file.seekp(p*sizeof(highscorer));
					  file.write((char*)&hs1,sizeof(hs1));
					  file.close(); }
			  else file.close();	  }

 else;

 E:;          //Blank label to exit program
 }



 int pl (int c)     //Move stiker left
 {
 if(c>23)
  {gotoxy(c-1,24);cout<<"   ";
	gotoxy(c-3,24);cout<<"[o]";
	return (c-2);
  }
 else return c;
 }


 int pr (int c)      //Move stiker right
 {
 if(c<61)
  {gotoxy(c-1,24);cout<<"   ";
	gotoxy(c+1,24);cout<<"[o]";
	return (c+2);
  }
 else return c;
 }


 int tl(int c, int s)  //Turn direction of hit to left
 {
 int r;
  switch(s)
	{
	case -2:
	r= s;
	break;

	case -1:
	for(i=c-2;i>20;i--)
	{gotoxy(i,24);cout<<"*";}
	for(i=c;i>20;i--)
	{gotoxy(i,23+i-c);cout<<" ";}
	r= --s;
	break;

	case 0:
	for(i=c;i>20;i--)
	{gotoxy(i,23+i-c);cout<<"*";}
	for(i=23;i>3;i--)
	{gotoxy(c,i);cout<<" ";}
	r= --s;
	break;

	case 1:
	for(i=23;i>3;i--)
	{gotoxy(c,i);cout<<"*";}
	for(i=c;i<63;i++)
	{gotoxy(i,23-i+c);cout<<" ";}
	r= --s;
	break;

	case 2:
	for(i=c;i<63;i++)
	{gotoxy(i,23-i+c);cout<<"*";}
	for(i=c+2;i<63;i++)
	{gotoxy(i,24);cout<<" ";}
	r= --s;
	break;

	default:
	r= s;
	};
  return r;
 }


 int tr(int c, int s)   //Turn direction of hit to right
 {
 int r;
  switch(s)
	{
	case -2:
	for(i=c;i>20;i--)
	{gotoxy(i,23+i-c);cout<<"*";}
	for(i=c-2;i>20;i--)
	{gotoxy(i,24);cout<<" ";}
	r=++s;
	break;

	case -1:
	for(i=23;i>3;i--)
	{gotoxy(c,i);cout<<"*";}
	for(i=c;i>20;i--)
	{gotoxy(i,23+i-c);cout<<" ";}
	r= ++s;
	break;

	case 0:
	for(i=c;i<63;i++)
	{gotoxy(i,23-i+c);cout<<"*";}
	for(i=23;i>3;i--)
	{gotoxy(c,i);cout<<" ";}
	r= ++s;
	break;

	case 1:
	for(i=c+2;i<63;i++)
	{gotoxy(i,24);cout<<"*";}
	for(i=c;i<63;i++)
	{gotoxy(i,23-i+c);cout<<" ";}
	r= ++s;
	break;

	case 2:
	r=s;
	break;

	default:
	r= s;
	};
  return r;
 }

 int hit(int c, int s)   //Hit the ball
 {
   gotoxy(c,24);cout<<" ";
	int r=0;

	switch(s)
	{
	case -2:
	for(i=c-2;i>20;i--)
	{gotoxy(i,24);cout<<" ";}
	for(i=c-3;i>20;i--)
	{for(k=0;k<10000000;k++);
	gotoxy(i,24);cout<<"O";
	gotoxy(i+1,24);cout<<" ";}
	r=0;
	break;

	case -1:
	for(i=c;i>20;i--)
	{gotoxy(i,23+i-c);cout<<" ";}
	for(i=c-1;i>20;i--)
	{for(k=0;k<10000000;k++);
	gotoxy(i,22+i-c);cout<<"O";
	gotoxy(i+1,23+i-c);cout<<" ";}
	if(c>57)r=1;
	break;

   case 0:
	for(i=23;i>0;i--)
	{gotoxy(c,i);cout<<" ";}
	for(i=22;i>3;i--)
	{for(k=0;k<10000000;k++);
	gotoxy(c,i);cout<<"O";
	gotoxy(c,i+1);cout<<" ";}
	if(c>36&&c<46)r=1;
	break;

   case 1:
	for(i=c+1;i<63;i++)
	{gotoxy(i,23-i+c);cout<<" ";}
	for(i=c;i<63;i++)
	{for(k=0;k<10000000;k++);
	gotoxy(i,22-i+c);cout<<"O";
	gotoxy(i-1,23-i+c);cout<<" ";}
   if(22+c>36&&22+c<46)r=1;
	break;

   case 2:
	for(i=c+2;i<63;i++)
	{gotoxy(i,24);cout<<" ";}
	for(i=c+3;i<63;i++)
	{for(k=0;k<10000000;k++);
	gotoxy(i,24);cout<<"O";
	gotoxy(i-1,24);cout<<" ";
	}
	r= 0;
	break;

	default:;
	};

	return r;
 }
