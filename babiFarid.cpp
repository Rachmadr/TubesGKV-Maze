//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <GL/glut.h>

void drawPigFace() {
    // Snout
    glColor3f(1.0f, 0.75f, 0.75f); // Pink color
    glutSolidSphere(0.3, 20, 5);
    
    // Eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glTranslatef(-0.1f, 0.15f, 0.2f);
    glutSolidSphere(0.05, 10, 10);
    glTranslatef(0.2f, 0.0f, 0.0f);
    glutSolidSphere(0.05, 10, 10);
    
    // Nose
    glColor3f(1.0f, 0.5f, 0.5f); // Pink color
    glTranslatef(-0.1f, -0.1f, 0.05f);
    glutSolidSphere(0.10, 10, 10);
    
    // Black Circle Right of Nose
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glTranslatef(0.035f, 0.02f, 0.08f);
    glutSolidSphere(0.025, 10, 15);
    
    // Black Circle Left of Nos
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glTranslatef(-0.065f, 0.0045f, 0.0010f);
    glutSolidSphere(0.025, 10, 10);
    
    // Ears
    glColor3f(1.0f, 0.5f, 0.5f);// Pink color
    
    // Left Ear
    glTranslatef(-0.1f, 0.0f, -0.3f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.3f, 0.28f, 0.0f); // Top vertex
    glVertex3f( 0.1f, 0.19f, 0.0f); // Bottom left vertex
    glVertex3f(-0.16f, -0.04f, 0.0f); // Bottom right vertex
    glEnd();
    
    // Right Ear
    glTranslatef(-0.1f, 0.0f, -0.01f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.68f, 0.24f, 0.0f); // Top vertex
    glVertex3f(0.5f, -0.1f, 0.0f); // Bottom left vertex
    glVertex3f(0.3f, 0.2f, 0.0f); // Bottom right vertex
    glEnd();
    
    // Mouth
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for mouth
    glTranslatef(0.23f, -0.25f, 0.23f); // Move to the mouth position
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f); // Rotate to align with the snout
    glBegin(GL_QUADS);
    glVertex3f(-0.05f, 0.0f, 0.0f); // Bottom-left vertex
    glVertex3f(0.05f, 0.0f, 0.0f); // Bottom-right vertex
    glVertex3f(0.05f, 0.1f, 0.0f); // Top-right vertex
    glVertex3f(-0.05f, 0.1f, 0.0f); // Top-left vertex
    glEnd();
    
    // Circle at the Bottom of Pig
    glColor3f(1.0f, 0.5f, 0.5f);  // Black color
    glTranslatef(-0.01f, -0.13f, -0.5f);
    glutSolidSphere(0.025, 10, 15);
}
