#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <stdlib.h>

/* ---------- DDA LINE ---------- */
void dda(int x1,int y1,int x2,int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = x1, y = y1;

    for(int i=0;i<=steps;i++){
        putpixel((int)(x+0.5),(int)(y+0.5),WHITE);
        x += xinc;
        y += yinc;
    }
}

/* ---------- BRESENHAM LINE ---------- */
void bresenhamLine(int x1,int y1,int x2,int y2){
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while(1){
        putpixel(x1,y1,WHITE);
        if(x1==x2 && y1==y2) break;
        int e2 = 2*err;
        if(e2 > -dy){ err -= dy; x1 += sx; }
        if(e2 < dx){ err += dx; y1 += sy; }
    }
}

/* ---------- MIDPOINT CIRCLE ---------- */
void midpointCircle(){
    int xc,yc,r;
    cout<<"Enter center (xc yc): ";
    cin>>xc>>yc;
    cout<<"Enter radius: ";
    cin>>r;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int x=0,y=r,p=1-r;
    while(x<=y){
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc-x,WHITE);
        x++;
        if(p<0) p+=2*x+1;
        else{ y--; p+=2*(x-y)+1; }
    }
    getch();
    closegraph();
}

/* ---------- BRESENHAM CIRCLE ---------- */
void bresenhamCircle(){
    int xc,yc,r;
    cout<<"Enter center (xc yc): ";
    cin>>xc>>yc;
    cout<<"Enter radius: ";
    cin>>r;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int x=0,y=r,d=3-2*r;
    while(x<=y){
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc-x,WHITE);
        if(d<0) d+=4*x+6;
        else{ d+=4*(x-y)+10; y--; }
        x++;
    }
    getch();
    closegraph();
}

/* ---------- LINE MENU ---------- */
void drawLine(){
    int x1,y1,x2,y2,choice;
    cout<<"Enter x1 y1: ";
    cin>>x1>>y1;
    cout<<"Enter x2 y2: ";
    cin>>x2>>y2;

    cout<<"1. DDA\n2. Bresenham\n";
    cin>>choice;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    if(choice==1) dda(x1,y1,x2,y2);
    else if(choice==2) bresenhamLine(x1,y1,x2,y2);

    getch();
    closegraph();
}

/* ---------- RECTANGLE ---------- */
void drawRectangle(){
    int x,y,w,h;
    cout<<"Enter top-left (x y): ";
    cin>>x>>y;
    cout<<"Enter width height: ";
    cin>>w>>h;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    bresenhamLine(x,y,x+w,y);
    bresenhamLine(x+w,y,x+w,y+h);
    bresenhamLine(x+w,y+h,x,y+h);
    bresenhamLine(x,y+h,x,y);

    getch();
    closegraph();
}

/* ---------- SQUARE ---------- */
void drawSquare(){
    int x,y,s;
    cout<<"Enter top-left (x y): ";
    cin>>x>>y;
    cout<<"Enter side: ";
    cin>>s;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    bresenhamLine(x,y,x+s,y);
    bresenhamLine(x+s,y,x+s,y+s);
    bresenhamLine(x+s,y+s,x,y+s);
    bresenhamLine(x,y+s,x,y);

    getch();
    closegraph();
}

/* ---------- MAIN ---------- */
void main(){
    int choice;
    cout<<"1.Line\n2.Circle\n3.Rectangle\n4.Square\n";
    cin>>choice;

    if(choice==1) drawLine();
    else if(choice==2){
        cout<<"1.Midpoint\n2.Bresenham\n";
        cin>>choice;
        if(choice==1) midpointCircle();
        else bresenhamCircle();
    }
    else if(choice==3) drawRectangle();
    else if(choice==4) drawSquare();
}
