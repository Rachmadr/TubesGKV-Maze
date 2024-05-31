//Kelompok 5:
//Rachmad Rifa'i - 24060122120014
//Sausan Berliana Arrizqi - 24060122130092
//Rona Realita Najma - 24060122140124
//Farid Rahman Fadhilah - 24060122140142
//28-05-2024

#include <GL/glut.h>

float wallCoordinates[][28] = {
    // x, z, sx, sz
    {1.0f, -3.0f, 15.0, 1.0}, //1 
	{4.0f, 7.0f, 1.0, 20.0}, //2
	{-6.0f, -7.0f, 1.0, 8.0}, //3
	{-8.0f, -11.0f, 15.0, 1.0}, //4
	{-15.0f, -9.0f, 1.0, 4.0}, //5
	{-7.0f, 3.0f, 15.0, 1.0}, //6
	{-15.0f, 3.0f, 1.0, 12.0}, //7
	{-16.0f, -3.0f, 10.0, 1.0}, //8
	{-11.0f, -5.0f, 1.0, 5.0}, //9
	{-21.0f, -10.0f, 1.0, 17.0}, //10
	{2.0f, 12.0f, 5.0, 1.0}, //11 
	{6.0f, 17.0f, 5.0, 1.0}, //12
	{-6.0f, 17.0f, 10.0, 1.0}, //13
	{-5.0f, 12.0f, 1.0, 9.0}, //14
	{-8.0f, 8.0f, 6.0, 1.0}, //15
	{-11.0f, 10.0f, 1.0, 5.0}, //16
	{-16.0f, 13.0f, 11.0, 1.0}, //17
	{9.0f, -9.0f, 10.0, 1.0}, //18
	{9.0f, -15.0f, 1.0, 5.0}, //19	
	{14.0f, -4.0f, 1.0, 20.0}, //20
	{11.0f, 2.0f, 5.0, 1.0}, //21
	{9.0f, 7.0f, 1.0, 10.0}, //22
	{11.0f, 12.0f, 5.0, 1.0}, //23
	{14.0f, 17.0f, 1.0, 15.0}, //24
	{0.0f, -18.0f, 42.0, 1.0}, //25
	{21.0f, 0.0f, 1.0, 37.0}, //26
	{0.0f, 24.0f, 43.0, 1.0}, //27
	{-21.0f, 14.0f, 1.0, 21.0} //28
    // Sisipkan koordinat dinding labirin lainnya di sini
};

void wall(float x, float z, float sx, float sz){
	glPushMatrix();
		glTranslatef(x, 0.0f, z); 
 		glScalef(sx, 5.0, sz); 
		glutSolidCube(1.0f); 
	glPopMatrix(); 
}

void labirin(){
	glColor3ub(143, 0, 255); //warna
	
    for (int i = 0; i < sizeof(wallCoordinates) / sizeof(wallCoordinates[0]); i++) {
        wall(wallCoordinates[i][0], wallCoordinates[i][1], wallCoordinates[i][2], wallCoordinates[i][3]);
    }
}

// Fungsi untuk mendeteksi tabrakan antara pemain dan dinding
bool checkCollision(float playerX, float playerZ) {
    for (int i = 0; i < sizeof(wallCoordinates) / sizeof(wallCoordinates[0]); i++) {
        float wallRight = wallCoordinates[i][0] + (wallCoordinates[i][2]/2);
		float wallLeft = wallCoordinates[i][0] - (wallCoordinates[i][2]/2);
        float wallTop = wallCoordinates[i][1] - (wallCoordinates[i][3]/2);
		float wallBottom = wallCoordinates[i][1] + (wallCoordinates[i][3]/2);

        if (playerX > wallLeft-1 && playerX < wallRight+1 &&
            playerZ < wallBottom+1 && playerZ > wallTop-1) {
            return true; // Terdapat tabrakan
        }
    }
    return false; // Tidak ada tabrakan
}


void bumiDatar() {
    glColor3ub(19, 133, 16); // Hijau
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, 100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glEnd();
}
