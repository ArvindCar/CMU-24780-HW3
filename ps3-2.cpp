#include <stdio.h>
#include "fssimplewindow.h"
#include <math.h>
#define M_PI 3.14159265358979323846

void DrawOval(int cx, int cy, int rx, int ry, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180.0;
        double x = cx + rx * cos(angle);
        double y = cy + ry * sin(angle);
        glVertex2d(x, y);
    }
    glEnd();
}



void DrawLeaf(int cx, int cy, float scale, int inversion, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2i(cx, cy);           
    glVertex2i(cx +  0.05 * scale * inversion, cy - 1 * scale); 
    glVertex2i(cx +  0.25 * scale * inversion, cy - 2 * scale); 
    glVertex2i(cx +  0.50 * scale * inversion, cy - 3 * scale); 
    glVertex2i(cx +  1.00 * scale * inversion, cy - 4 * scale);   
    glVertex2i(cx +  1.80 * scale * inversion, cy - 5 * scale);
    glVertex2i(cx +  3.00 * scale * inversion, cy - 6 * scale);
    glVertex2i(cx +  4 * scale * inversion, cy - 6.50 * scale);   
    glVertex2i(cx +  5 * scale * inversion, cy - 7 * scale);
    glVertex2i(cx +  6 * scale * inversion, cy - 7.30 * scale);
    glVertex2i(cx +  7 * scale * inversion, cy - 7.6 * scale); 
    glVertex2i(cx +  8 * scale * inversion, cy - 7.8 * scale);
    glVertex2i(cx +  9 * scale * inversion, cy - 7.9 * scale);    
    glVertex2i(cx +  10 * scale * inversion, cy - 7.95 * scale); 
    glVertex2i(cx +  11 * scale * inversion, cy - 7.8 * scale); 
    glVertex2i(cx +  12 * scale * inversion, cy - 7.5 * scale); 
    glVertex2i(cx +  11.7 * scale * inversion, cy - 6.7 * scale);
    glVertex2i(cx +  11.5 * scale * inversion, cy - 6 * scale);
    glVertex2i(cx +  11.0 * scale * inversion, cy - 5 * scale);
    glVertex2i(cx +  10.5 * scale * inversion, cy - 4 * scale);
    glVertex2i(cx +  10 * scale * inversion, cy - 3.1 * scale);
    glVertex2i(cx +  9.1 * scale * inversion, cy - 2 * scale);
    glVertex2i(cx +  8 * scale * inversion, cy - 0.9 * scale);
    glVertex2i(cx +  6.7 * scale * inversion, cy - 0 * scale);
    glVertex2i(cx +  5 * scale * inversion, cy + 0.5 * scale);
    glVertex2i(cx +  4 * scale * inversion, cy + 0.6 * scale);
    glVertex2i(cx +  3 * scale * inversion, cy + 0.55 * scale);
    glVertex2i(cx +  2 * scale * inversion, cy + 0.45 * scale);
    glVertex2i(cx +  1 * scale * inversion, cy + 0.25 * scale);
                
    glEnd();
}

void DrawRectangle(int x1, int y1, int x2, int y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();
}


int main(void) {
    FsOpenWindow(16, 16, 800, 800, 0);


    // Clear the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int stem_W = 40;
    int circle_X = 400;
    int circle_Y = 300;

    DrawRectangle(circle_X - stem_W/2, circle_Y + 150, circle_X + stem_W/2, circle_Y + 350, 0.1, 0.7, 0.0);

 
    DrawLeaf(circle_X, 600, 15.0, 1, 0.1, 0.7, 0.0);
    DrawLeaf(circle_X, 600, 15.0, -1, 0.1, 0.7, 0.0);

    DrawOval(circle_X, circle_Y, 205, 155, 0.2, 0.1, 0.0); 
    DrawOval(circle_X, circle_Y, 200, 150, 1.0, 0.0, 0.0);
    DrawOval(circle_X, circle_Y, 175, 125, 0.2, 0.1, 0.0); 
    DrawOval(circle_X, circle_Y, 170, 120, 1.0, 1.0, 0.0);  
    DrawOval(circle_X, circle_Y, 145, 95, 0.2, 0.1, 0.0);
    DrawOval(circle_X, circle_Y, 140, 90, 1.0, 1.0, 1.0);

    int eye_L = 320;
    int eye_R = 460;
    int eye_w = 20;
    int eye_offset = 5;
    int eye_Y = 260;
    int eye_H = 60;
    int eye_h = 5;
 
    DrawRectangle(eye_L, eye_Y, eye_L+eye_w, eye_Y+eye_H, 0.0, 0.0, 0.0);
    DrawRectangle(eye_R, eye_Y, eye_R+eye_w, eye_Y+eye_H, 0.0, 0.0, 0.0); 
    DrawRectangle(eye_L+eye_offset, eye_Y, eye_L+eye_w-eye_offset, eye_Y+eye_h, 1.0, 1.0, 1.0);  
    DrawRectangle(eye_R+eye_offset, eye_Y, eye_R+eye_w-eye_offset, eye_Y+eye_h, 1.0, 1.0, 1.0); 

    // Flush and display
    glFlush();
    FsPollDevice();
    
    while (FSKEY_NULL == FsInkey()) {
        FsPollDevice();
        FsSleep(25);
    }

    return 0;
}
