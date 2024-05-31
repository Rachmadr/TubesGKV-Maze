//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <GL/glut.h>
#include <cmath>

void Koin() {
    glColor3f(1.0f, 0.843f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        glVertex3f(sin(theta) * 0.5f, cos(theta) * 0.5f, 0.0f);
    }
    glEnd();
}
