#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/X.h>
#define PREFER_W    80  /* preferred window width in characters */
#define PREFER_H    24  /* preferred window height in characters */
int main(int argc, char *kwargs[]) {
    Display *dis = XOpenDisplay(NULL);
    if (!dis) {
        printf("Could not get display!\n");
        exit(-1);
    }
    int screen;
    Window win;
    GC gc;
    screen = XDefaultScreen(dis);
    XFontStruct *font = XLoadQueryFont(dis, "-bitstream-*-medium-r-normal-*-*-*-*-*-m-*-*-*");
    if (!font) {
        printf("Could not get monospace font!\n");
        exit(-1);
    }
    int cw, ch;
    int win_w, win_h;
    //Since the font we are using is monospace, we only need to measure the proportions of one character to get our window
    cw = font->max_bounds.rbearing - font->max_bounds.lbearing;
    ch = font->max_bounds.ascent + font->max_bounds.descent;

    win = XCreateSimpleWindow(dis, XDefaultRootWindow(dis) , 0, 0, cw * PREFER_W, ch * PREFER_H, 0, 0, 0);
    XSetStandardProperties(dis, win, "simple-term-emulator", "simple-term-emulator", None, NULL, 0, NULL);
    XSelectInput(dis, win, KeyPressMask | ExposureMask);
    gc = XCreateGC(dis, win, 0, NULL);
    XSetBackground(dis, gc, 0);
    XSetForeground(dis, gc, 0xFFFFFFFF);
    XClearWindow(dis, win);
    XMapRaised(dis, win);
    printf("Hello World!\n");
    while (1) {};
}