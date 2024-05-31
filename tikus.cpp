//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <GL/glut.h>

void drawTikus() {
    // Draw head
    glColor3f(0.8, 0.8, 0.8); // Abu muda
    glutSolidSphere(0.5, 50, 50); // Main body (head)

    // Draw ears
    glColor3f(0.6, 0.6, 0.6); // Gray color
    glPushMatrix();
    glTranslatef(-0.45, 0.4, 0.1); // Position of the left ear (slightly higher)
    glutSolidSphere(0.15, 50, 50); // Left ear
    glTranslatef(0.9, 0.0, 0.0); // Position of the right ear
    glutSolidSphere(0.15, 50, 50); // Right ear
    glPopMatrix();

    // Draw additional ear shapes
    glColor3f(1.0, 0.7, 0.65); // Reddish color
    glPushMatrix();
    glTranslatef(-0.45, 0.4, 0.15); // Position of the additional shape above left ear (slightly higher)
    glutSolidSphere(0.12, 50, 50); // Additional shape above left ear
    glTranslatef(0.9, 0.0, 0.0); // Position of the additional shape above right ear
    glutSolidSphere(0.12, 50, 50); // Additional shape above right ear
    glPopMatrix();

    // Draw eyes 1 (white)
    glColor3f(1.0, 1.0, 1.0); // White color
    glPushMatrix();
    glTranslatef(-0.22, 0.21, 0.44); // Position of the left eye (slightly more forward)
    glutSolidSphere(0.065, 50, 50); // Left eye (smaller)
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.2, 0.21, 0.44); // Position of the right eye (aligned with the black eye)
    glutSolidSphere(0.065, 50, 50); // Right eye (smaller)
    glPopMatrix();


    // Draw eyes 2 (black)
    glColor3f(0.0, 0.0, 0.0); // Black color
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 0.35); // Position of the left eye
    glutSolidSphere(0.13, 50, 50); // Left eye (larger)
    glTranslatef(0.4, 0.0, 0.0); // Position of the right eye
    glutSolidSphere(0.13, 50, 50); // Right eye (larger)
    glPopMatrix();


    // Draw nose 1 (pink)
    glColor3f(1.0, 0.55, 0.6); // Pink color
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.45); // Position of the nose
    glutSolidSphere(0.1, 50, 50); // Nose
    glPopMatrix();

    // Draw mouth
    glColor3f(0.0, 0.0, 0.0); // Black color
    glPushMatrix();
    glTranslatef(0.0, -0.2, 0.45); // Position of the mouth
    glScalef(1.0, 0.5, 1.0); // Make mouth wider
    glutSolidSphere(0.08, 50, 50); // Mouth
    glPopMatrix();
}
