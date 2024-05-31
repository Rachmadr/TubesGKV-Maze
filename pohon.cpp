//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <GL/glut.h>

float pohonCoordinates[][25] = {
    {-26.0f, 27.0f}, //1 
	{0.0f, -26.0f}, //2
	{-26.0f, -20.0f}, //3
	{26.0f, 0.0f}, //4
	{27.0f, -9.0f}, //5
	{28.0f, 10.0f}, //6
	{-15.0f, 26.0f}, //7
	{-20.0f, 25.0f}, //8
	{11.0f, 28.0f}, //9
	{21.0f, 26.0f}, //10
	{21.0f, -27.0f}, //11 
	{26.0f, 17.0f}, //12
	{-26.0f, 10.0f}, //13
	{-27.0f, -22.0f}, //14
	{26.0f, 8.0f}, //15
	{-11.0f, 30.0f}, //16
	{-26.0f, 1.0f}, //17
	{9.0f, -29.0f}, //18
	{29.0f, -15.0f}, //19	
	{25.0f, -4.0f}, //20
	{11.0f, 26.0f}, //21
	{29.0f, -7.0f}, //22
	{-26.0f, 12.0f}, //23
	{-14.0f, 27.0f}, //24
	{-28.0f, -20.0f} //25
    // Sisipkan koordinat dinding labirin lainnya di sini
};

void drawTree() {
    // Batang pohon (gunakan tabung)
    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f); // Posisi batang pohon
	glRotatef(90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.36f, 0.25f, 0.20f); // Warna cokelat untuk batang
    GLUquadricObj* trunk = gluNewQuadric();
    gluCylinder(trunk, 0.2f, 0.2f, 3.0f, 20, 20); // Buat batang pohon
    glPopMatrix();

    // Daun pohon (gunakan kerucut)
    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f); // Posisi daun pohon
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.8f, 0.0f); // Warna hijau untuk daun
    glutSolidCone(1.5f, 5.0f, 20, 20); // Buat daun pohon
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f); // Posisi daun pohon
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.8f, 0.0f); // Warna hijau untuk daun
    glutSolidCone(1.5f, 5.0f, 20, 20); // Buat daun pohon
    glPopMatrix();
}

void pohon(float x, float z){
	glPushMatrix();
	glTranslatef(x, 1.0f, z);
    drawTree();
    glPopMatrix();
}
void hutan(){
    for (int i = 0; i < sizeof(pohonCoordinates) / sizeof(pohonCoordinates[0]); i++) {
        pohon(pohonCoordinates[i][0], pohonCoordinates[i][1]);
    }
}
