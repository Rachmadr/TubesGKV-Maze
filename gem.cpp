//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>

#include "platform.h"
#include "babiFarid.h"
#include "koin.h"
#include "tikus.h"
#include "pohon.h"

const double phi = 3.14159265358979323846;
float maju = 0.0f;
float samping = 0.0f;
float hadap = -90;

float angle = 0.0f; // Rotation angle

float cameraDistance = 10.0f; // Jarak kamera dari pemain
float cameraHeight = 5.0f; // Tinggi kamera dari pemain

typedef struct {
    float x;
    float y;
    bool visible;
} Coin;

// Inisialisasi koin
Coin coins[] = {
    {-12.0f, -9.0f, true}, //1
    {-4.0f, -9.0f, true},  //2
    {6.0f, -12.0f, true},  //3
    {-12.0f, 0.0f, true},  //4
    {-18.0f, 1.0f, true},  //5
    {-13.0f, 6.0f, true},  //6
    {-8.0f, 11.0f, true},  //7
    {-8.0f, 14.0f, true},  //8
    {1.5f, 9.5f, true},    //9
    {6.0f, 20.0f, true},   //10
    {11.5f, 5.0f, true},   //11
    {17.0f, -6.0f, true},  //12
    {17.0f, -2.0f, true},  //13
    {17.0f, 2.0f, true}    //14
};
int numCoins = sizeof(coins) / sizeof(coins[0]);

int score = 0;

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); // Aktifkan pencahayaan
    glEnable(GL_LIGHT0);   // Gunakan lampu pertama
    glEnable(GL_COLOR_MATERIAL); // Aktifkan warna material
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); // Terapkan warna material ke muka depan dan belakang
}

void drawGrid() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    for (float i = -50.0f; i <= 50.0f; i += 1.0f) {
        glVertex3f(i, 0.0f, -50.0f);
        glVertex3f(i, 0.0f, 50.0f);
    }
    glEnd();
    glBegin(GL_LINES);
    for (float i = -50.0f; i <= 50.0f; i += 1.0f) {
        glVertex3f(-50.0f, 0.0f, i);
        glVertex3f(50.0f, 0.0f, i);
    }
    glEnd();
}

void drawCoin(Coin coin) {
    if (coin.visible) {
        glPushMatrix();
        glTranslatef(coin.x, 1.0f, coin.y);
        glScalef(2.0f, 2.0f, 2.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        Koin(); // Fungsi menggambar koin
        glPopMatrix();
    }
}

void drawText(const char* text, float x, float y, float r, float g, float b, void* font) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600); // Set up orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING); // Matikan pencahayaan sementara
    glDisable(GL_DEPTH_TEST); // Matikan tes kedalaman sementara

    glColor3f(r, g, b); // Set warna teks
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }

    glEnable(GL_LIGHTING); // Nyalakan kembali pencahayaan
    glEnable(GL_DEPTH_TEST); // Nyalakan kembali tes kedalaman

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


void display() {
    glClearColor(137.0f / 255.0f, 207.0f / 255.0f, 240.0f / 255.0f, 1.0f); // Langit biru
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Hitung posisi kamera berdasarkan posisi dan arah hadap pemain
    float cameraX = maju - cameraDistance * cos(hadap * phi / 180.0f);
    float cameraZ = samping - cameraDistance * sin(hadap * phi / 180.0f);
    gluLookAt(cameraX, cameraHeight, cameraZ,  // posisi kamera (mata)
              maju, 0.0f, samping,             // titik yang dilihat (target)
              0.0f, 1.0f, 0.0f);               // arah atas (arah sumbu Y positif)

    //drawGrid(); // Gambar garis-garis grid

    // Gambar dinding labirin
    glPushMatrix();
    labirin(); // Fungsi menggambar labirin
    glPopMatrix();

    // Hitung sudut rotasi agar pemain selalu menghadap ke arah berlawanan dengan kamera
    float angleToCamera = atan2(cameraX - maju, cameraZ - samping) * 180.0f / phi;
    angleToCamera += 180.0f; // Balikkan arah rotasi

    // Gambar pemain
    glPushMatrix();
    glTranslatef(maju, 0.5f, samping); // Pindahkan pemain ke posisinya
    glScalef(2.0f, 2.0f, 2.0f);
    glRotatef(angleToCamera, 0.0f, 1.0f, 0.0f); // Rotasi agar menghadap ke arah berlawanan dengan kamera
    drawPigFace(); // Fungsi menggambar pemain
    glPopMatrix();

    // Gambar koin
    for (int i = 0; i < numCoins; i++) {
        drawCoin(coins[i]);
    }

	glPushMatrix();
    glTranslatef(-26.0f, 0.5f, 0.0f); // Pindahkan pemain ke posisinya
    glRotatef(90, 0.0f, 1.0f, 0.0f);
	drawTikus(); // Fungsi menggambar pemain
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(26.0f, 0.5f, 20.0f); // Pindahkan pemain ke posisinya
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
	drawTikus(); // Fungsi menggambar pemain
    glPopMatrix();
    
    // Gambar platform horizontal
    bumiDatar(); // Fungsi menggambar platform
    
    hutan();
	
	// Tampilkan nama kelompok
    drawText("Kelompok 5", 10.0f, 570.0f, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18); // Teks putih
    drawText("Rachmad Rifa'i - 24060122120014", 10.0f, 550.0f, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18); // Teks putih
    drawText("Sausan Berliana Arrizqi - 24060122130092", 10.0f, 530.0f, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18); // Teks putih
    drawText("Rona Realita Najma - 24060122140124", 10.0f, 510.0f, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18); // Teks putih
	drawText("Farid Rahman Fadhilah - 24060122140142", 10.0f, 490.0f, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18); // Teks putih
    // Tampilkan skor
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    drawText(scoreText, 650.0f, 570.0f, 1.0f, 1.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24);

    glutSwapBuffers();
}



void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f); // Pengaturan proyeksi
    glMatrixMode(GL_MODELVIEW);
}

void update(int value) {
    angle += 5.0f; // Rotasi
    if (angle > 360) {
        angle -= 360;
    }

    // Check for collision with the coins
    for (int i = 0; i < numCoins; i++) {
        if (coins[i].visible) {
            float dx = maju - coins[i].x;
            float dy = samping - coins[i].y;
            float distance = sqrt(dx * dx + dy * dy);
            if (distance < 1.0f) { // Assuming 1.0f as the collision distance threshold
                coins[i].visible = false;
                score += 100;
                printf("Coin %d collected. Score: %d\n", i, score);
            }
        }
    }
    glutPostRedisplay(); // Update the screen
    glutTimerFunc(16, update, 0); // Call update function every 16 milliseconds (approximately 60 fps)
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': {
            float nextX = maju + 1.0f * cos(hadap * phi / 180.0f); // Hitung posisi x berikutnya
            float nextZ = samping + 1.0f * sin(hadap * phi / 180.0f); // Hitung posisi z berikutnya
            if (!checkCollision(nextX, nextZ)) { // Periksa tabrakan dengan dinding
                maju = nextX;
                samping = nextZ;
            }
            break;
        }
        case 's': {
            float nextX = maju - 1.0f * cos(hadap * phi / 180.0f); // Hitung posisi x berikutnya
            float nextZ = samping - 1.0f * sin(hadap * phi / 180.0f); // Hitung posisi z berikutnya
            if (!checkCollision(nextX, nextZ)) { // Periksa tabrakan dengan dinding
                maju = nextX;
                samping = nextZ;
            }
            break;
        }
        case 'a': {
            hadap -= 5.0f; // Rotasi ke kiri
            break;
        }
        case 'd': {
            hadap += 5.0f; // Rotasi ke kanan
            break;
        }
        case 'r': {
        	maju = 0.0f;
        	samping = 0.0f;
        	break;
        }
        case 27: // ESC key
            exit(0);
            break;
    }

    glutPostRedisplay(); // Update the screen
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: {
            float nextX = maju + 1.0f * cos(hadap * phi / 180.0f); // Hitung posisi x berikutnya
            float nextZ = samping + 1.0f * sin(hadap * phi / 180.0f); // Hitung posisi z berikutnya
            if (!checkCollision(nextX, nextZ)) { // Periksa tabrakan dengan dinding
                maju = nextX;
                samping = nextZ;
            }
            break;
        }
        case GLUT_KEY_DOWN: {
            float nextX = maju - 1.0f * cos(hadap * phi / 180.0f); // Hitung posisi x berikutnya
            float nextZ = samping - 1.0f * sin(hadap * phi / 180.0f); // Hitung posisi z berikutnya
            if (!checkCollision(nextX, nextZ)) { // Periksa tabrakan dengan dinding
                maju = nextX;
                samping = nextZ;
            }
            break;
        }
        case GLUT_KEY_LEFT: {
            hadap -= 5.0f; // Rotasi ke kiri
            break;
        }
        case GLUT_KEY_RIGHT: {
            hadap += 5.0f; // Rotasi ke kanan
            break;
        }
    }
    glutPostRedisplay(); // Update the screen
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kelompok 5 C1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(16, update, 0); // Call update function every 16 milliseconds (approximately 60 fps)
    glutMainLoop();
    return 0;
}
