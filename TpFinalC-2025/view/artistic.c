/* ARTIST.C */
 
#include <stdio.h>
#include <graphics.h>
#include <math.h>
 
int pmain(void)
{
int in, index = 1;
int xloc = 0, yloc = 0, x1 = 0, y1 = 0;
FILE *fpointer;
void *gpointer;
char fillarray[] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
int g_driver, g_mode;
 
g_driver = CGA;
g_mode = CGAC3;
 
initgraph(&g_driver, &g_mode, "..\\bgi");
 
setgraphmode(CGAC3);
 
setcolor(index);
 
setfillpattern(fillarray, 1);
 
while((in = getch()) != 'q')
{
if (!in)
in = getch() + 128;
switch (in)
{
case 208: /* up */
yloc++;
break;
case 203: /* left */
xloc--;
break;
case 205: /* right */
xloc++;
break;
case 200: /* down */
yloc--;
break;
case 'p': /* put pixel */
putpixel(xloc, yloc, index);
moveto(xloc, yloc);
x1 = xloc;
y1 = yloc;
break;
case 'l': /* draw line */
lineto(xloc, yloc);
break;
case 'r': /* draw a rectangle */
rectangle(x1, y1, xloc, yloc);
break;
case 'e': /* draw ellipse */
ellipse((x1+xloc)/2, (y1+yloc)/2, 0, 360, abs(xloc-x1)/2, abs(yloc-y1)/2);
break;
case 'f': /* fill */
floodfill(xloc, yloc, index);
break;
case ' ': /* change color */
(index >= 3 ? index = 1 : index++);
setcolor(index);
break;
case 'd': /* delete */
index = 0;
setcolor(index);
break;
 
 
/* HERE!!! >> */
 
 
case 's': /* save screen */
if ((fpointer = fopen("..\\output\\screen.dmp", "wb")) != NULL)
{
gpointer = (void *)0xb8000000; /* works only if the cast (void *) is used. used to work without cast */
fwrite(gpointer, 16*1024, 1, fpointer); /* stores the screen into a file. the file is being created */
fclose(fpointer);
}
else
outtextxy(10, 10, "Error writing screen.dmp");
break;
case 'o': /* restore from file */
if ((fpointer = fopen("..\\output\\screen.dmp", "rb")) != NULL)
{
gpointer = (void *)0xb8000000; /* works only if the cast (void *) is used. used to work without cast */
fread(gpointer, 16*1024, 1, fpointer); /* reads the file into the screen memory. it seems the reading doesn't work */
fclose(fpointer);
}
else
outtextxy(10, 10, "Error reading screen.dmp");
break;
 
 
/* << HERE!!! */
default:
;
}
}
 
return 0;
}
 
/* EOF */
