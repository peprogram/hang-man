#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
class hangman
{
int level;
char hint[50],phrase[50];
public:
hangman()
{ level=0; }
void input();
void output();
void edit(char[]);
int getlevel()
{ return level; }
char* gethint()
{ return hint; }
char* getphrase()
{ return phrase; }
void modify();
void check(char,char[],int&,int&);
}h,h1;
void hangman::input()
{
cout<<"Level: "<<++level<<"\n";
cout<<"Enter the hint: ";
gets(hint);
cout<<"Enter the phrase: ";

- 7 -

gets(phrase);
}
void hangman::output()
{
cout<<"Level: "<<level;
cout<<"\nHint: ";
puts(hint);
cout<<"Phrase: ";
puts(phrase);
cout<<"\n";
}
void hangman::modify()
{
output();
char nphrase[50],nhint[50];
cout<<"New Hint: ";
gets(nhint);
strcpy(hint,nhint);
cout<<"New Phrase: ";
gets(nphrase);
strcpy(phrase,nphrase);
}
void hangman::edit(char TEXT[50])
{
for (int i=0; i<50; i++)
if (!isalpha(phrase[i]))
TEXT[i]=phrase[i];
gotoxy(10,15);
puts(TEXT);
}
void hangman::check(char CH, char TEXT[50],int &WRONG,int
&SCORE)
{

- 8 -

int match=0;
for (int i=0; phrase[i]!='\0'; i++)
if (CH==toupper(phrase[i])||CH==tolower(phrase[i]))
{
TEXT[i]=CH;
match=1;
SCORE+=100;
}
gotoxy(10,15);
puts(TEXT);
if (strcmpi(phrase,TEXT)==0)
SCORE+=10000;
if (match==0)
{
WRONG++;
setcolor(WHITE);
switch(WRONG)
{
case 1: line(450,425,625,425);
line(600,140,600,425);
line(500,140,600,140);
line(500,140,500,185); break;
case 2: circle(500,220,35); break;
case 3: line(500,255,500,355); break;
case 4: line(500,315,550,275); break;
case 5: line(500,315,450,275); break;
case 6: line(500,355,450,400); break;
case 7: line(500,355,550,400); break;
}
}
}
void main()
{
ifstream fin; ofstream fout;
fout.open("hangman.dat",ios::trunc|ios::binary);
fout.close();

- 9
-

int gd=DETECT, gm, mode;
initgraph(&gd, &gm, "c:

\\turboc3
\\bgi");

do{
cleardevice();
setcolor(LIGHTBLUE);
settextstyle(9, HORIZ_DIR, 7);
outtextxy(70,5,"HANG");
outtextxy(350,5,"MAN");
setcolor(LIGHTRED);
line(430,425,560,425);
line(560,140,560,425);
line(480,140,560,140);
line(480,140,480,185);
circle(480,220,30);
line(480,255,480,355);
line(480,315,530,275);
line(480,315,430,275);
line(480,355,430,400);
line(480,355,530,400);
setcolor(YELLOW);
settextstyle(9, HORIZ_DIR, 3);
outtextxy(70,140,"1. PLAYER");
outtextxy(70,200,"2. ADMIN");
settextstyle(8, HORIZ_DIR, 1);
outtextxy(70,390,"Enter 0 to exit");
setcolor(WHITE);
rectangle(70,340,290,370);
settextstyle(8, HORIZ_DIR, 1);
outtextxy(75,340,"Enter your choice:");
gotoxy(35,23);
cin>>mode;
switch(mode) {
case 1:
int player;

- 10 -

do
{
cleardevice();
settextstyle(9, HORIZ_DIR, 5);
setcolor(YELLOW);
outtextxy(200,10,"PLAYER");
setcolor(WHITE);
settextstyle(9, HORIZ_DIR, 2);
outtextxy(50,120,"1. HELP");
outtextxy(50,190,"2. PLAY");
outtextxy(50,260,"3. EXIT");
rectangle(355,180,520,280);
setcolor(YELLOW);
settextstyle(9, HORIZ_DIR, 1);
outtextxy(360,190,"Enter your");
outtextxy(360,223,"choice:");
gotoxy(60,16);
cin>>player;
cleardevice();
setcolor(WHITE);
settextstyle(9, HORIZ_DIR, 5);
switch(player)
{
case 1:
cleardevice();
setcolor(GREEN);
settextstyle(9, HORIZ_DIR, 5);
outtextxy(230,10,"HELP");
settextstyle(8, HORIZ_DIR, 1);
outtextxy(200,100,"Welcome to HANGMAN!!");
outtextxy(85,350,"GOOD LUCK & HAVE FUN PLAYING
HANGMAN!!");
setcolor(LIGHTBLUE);
outtextxy(25,150,"Guess the phrase with the help of the hint
given.");
outtextxy(25,190,"Each - depicts an alphabet of the phrase to be
guessed.");

- 11 -
outtextxy(25,230,"You can have a maximum of seven wrong
guesses only,");
outtextxy(25,250,"that is, before the whole body of the man
appears.");
outtextxy(25,290,"Guess the right phrase to advance to the next
level.");
getch();
break;
case 2:
fin.open("hangman.dat",ios::in|ios::binary);
while(fin.read((char*)&h,sizeof(h)))
{
cleardevice();
setcolor(LIGHTBLUE);
settextstyle(9, HORIZ_DIR, 5);
outtextxy(200,10,"PLAY");
setcolor(DARKGRAY);
line(450,425,625,425);
line(600,140,600,425);
line(500,140,600,140);
line(500,140,500,185);
circle(500,220,35);
line(500,255,500,355);
line(500,315,550,275);
line(500,315,450,275);
line(500,355,450,400);
line(500,355,550,400);
char ch, text[50], s[2]="-", ex[2]="0";
for (int t=0; t<strlen(h.getphrase()); t++)
text[t]=s[0];
h.edit(text);
int wrong=0,score=0,x=24;
while (wrong<7||score>=10000)
{
gotoxy(3,10);
settextstyle(8, HORIZ_DIR, 1);

- 12 -

setcolor(RED);
outtextxy(10,135,"HINT: ");
gotoxy(10,10);
puts(h.gethint());
outtextxy(10,311,"Already Guessed: ");
setcolor(YELLOW);
outtextxy(10,370,"Enter 0 to exit");
outtextxy(10,170,"ENTER ANY LETTER: ");
gotoxy(30,12);
cin>>ch;
gotoxy(x,21);
cout<<ch;
x+=2;
setcolor(BLUE);
outtextxy(10,170,"ENTER ANY LETTER: ");
delay(200);
if (ch==ex[0])
exit(0);
else
{
gotoxy(10,15);
h.check(ch,text,wrong,score);
if (wrong==7)
{
cleardevice();
setcolor(RED);
settextstyle(9, HORIZ_DIR, 6);
outtextxy(60,150,"GAME OVER");
gotoxy(50,18);
settextstyle(9, HORIZ_DIR, 3);
outtextxy(225,250,"SCORE:");
cout<<score;
delay(1000);
while(!fin.eof())
fin.read((char*)&h,sizeof(h));
}
else if (wrong<7 && score>10000)

- 13 -

{
cleardevice();
setcolor(GREEN);
settextstyle(9, HORIZ_DIR, 7);
outtextxy(100,125,"YOU WIN");
gotoxy(50,18);
settextstyle(9, HORIZ_DIR, 3);
outtextxy(225,250,"SCORE:");
cout<<score;
break;
}
}
}
}
fin.close();
}
}
while(player!=3);
break;
case 2:
int admin, l; char PASS[6],pass[6]={"hm123"};
settextstyle(8, HORIZ_DIR, 1);
setcolor(LIGHTBLUE);
outtextxy(120,260,"PASSWORD:");
line(120,305,220,305);
gotoxy(19,19);
gets(PASS);
if(strcmpi(PASS,pass)==0)
do
{
cleardevice();
settextstyle(9, HORIZ_DIR, 5);
setcolor(YELLOW);
outtextxy(230,10,"ADMIN");
settextstyle(9, HORIZ_DIR, 2);
setcolor(WHITE);

- 14 -

outtextxy(50,100,"1. ADD");
outtextxy(50,150,"2. MODIFY");
outtextxy(50,200,"3. SEARCH");
outtextxy(50,250,"4. DELETE");
outtextxy(50,300,"5. DISPLAY");
outtextxy(50,350,"6. EXIT");
rectangle(355,180,520,280);
setcolor(YELLOW);
settextstyle(9, HORIZ_DIR, 1);
outtextxy(360,190,"Enter your");
outtextxy(360,223,"choice:");
gotoxy(60,16);
cin>>admin;
cleardevice();
setcolor(WHITE);
settextstyle(9, HORIZ_DIR, 5);
switch(admin)
{
case 1:
outtextxy(250,30,"ADD");
fout.open("hangman.dat",ios::out|ios::app|ios::binary);
char ans='y';
gotoxy(1,10);
while(ans=='y'||ans=='Y')
{
h.input();
fout.write((char*)&h,sizeof(h));
cout<<"Level created!!\n";
cout<<"Create more levels?(y/n): ";
cin>>ans;
cout<<'\n';
}
fout.close();
break;
case 2:
outtextxy(200,30,"MODIFY");

- 15 -

fstream fio("hangman.dat",ios::in|ios::out|ios::binary);
long pos; char found='f';
gotoxy(1,10);
cout<<"\nEnter level: ";
cin>>l;
while(!fio.eof())
{
pos=fio.tellg();
fio.read((char*)&h,sizeof(h));
if(l==h.getlevel())
{
h.modify();
fio.seekg(pos);
fio.write((char*)&h,sizeof(h));
found='t';
break;
}
}
if(found=='f')
cout<<"Level not found!!\n";
else
{
fio.seekg(0);
cout<<"Remaining levels\n";
while(fio.read((char*)&h1,sizeof(h1)))
h1.output();
getch();
}
fio.close();
break;
case 3:
outtextxy(200,30,"SEARCH");
found='n';
fin.open("hangman.dat",ios::in|ios::binary);
gotoxy(1,10);
cout<<"Enter level: ";

- 16
-

cin>>l;
while(fin.read((char*)&h,sizeof(h)))
if(h.getlevel()==l) {
h.output();
getch();
found='y';
break;
}
if(found=='n')
cout<<"Level not found!!!"<<endl;
fin.close();
getch();
break;
case 4:
outtextxy(200,30,"DELETE");
fin.open("hangman.dat",ios::in|ios::binary);
fout.open("temp.dat",ios::out|ios::binary);
found='f';
gotoxy(1,10);
cout<<"Enter level: ";
cin>>l;
while(fin.read((char*)&h,sizeof(h))) {
if(h.getlevel()==l) {
h.output();
getch();
found='t';
}
else fout.write((char*)&h,sizeof(h));
}
if(found=='f')
cout<<"Level not found!!
\n";

fin.close();
fout.close();

- 17 -

remove("hangman.dat");
rename("temp.dat","hangman.dat");
fin.open("hangman.dat",ios::in|ios::binary);
cout<<"Now the file contains\n";
while(fin.read((char*)&h1,sizeof(h1)))
h1.output();
getch();
fin.close();
break;
case 5:
outtextxy(200,30,"DISPLAY");
fin.open("hangman.dat",ios::in|ios::binary);
gotoxy(1,10);
while(fin.read((char*)&h,sizeof(h)))
h.output();
getch();
fin.close();
}
}
while (admin!=6);
}
}
while (mode!=0);
}
