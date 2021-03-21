
#include <Windows.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

GLfloat xCor1, yCor1, xCor2, yCor2;


void display() {
	

	
	GLfloat x1 = xCor1, y1 = yCor1, x2 = xCor2, y2 = yCor2;


	GLfloat M, p, dx, dy,x,y,t;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

    

    //check for undefined
	if ((x2 - x1) == 0) {
        //slope of line
		M = (y2 - y1);
	}
	else {
        //slope of line
		M = (y2 - y1) / (x2 - x1);
	}

    //if absolute slope is less than 1 
	if (fabs(M) < 1)
	{

        //swap values if x1>x2
		if (x1 > x2) {
			t = x1;
			x1 = x2;
			x2 = t;
			t = y1;
			y1 = y2;
			y2 = t;
		}


		dx = fabs(x2 - x1);
		dy = fabs(y2 - y1);


        //Parametric value
		p = 2 * dy - dx;

		x = x1;
		y = y1;
        
        //we go from x1 to x2 and put on y
		glBegin(GL_POINTS);
		while (x <= x2)
		{
			glVertex2f(x, y);

            //increment x
			x = x + 1;

            //fractional differences
			if (p >= 1)
			{	
				if (M < 1)
                    //increment if M<1 just a double check
					y = y + 1;
				else
					y = y - 1;
				p = p + 2 * dy - 2 * dx;

			}
			else {
				y = y;
				p = p + 2 * dy;
			}

		}
		glEnd();

	}

    //if slope is greater than 1
	if (fabs(M) >= 1)
	{

        
		if (y1 > y2) {
			t = x1;
			x1 = x2;
			x2 = t;
			t = y1;
			y1 = y2;
			y2 = t;
		}

		dx = fabs(x2 - x1);
		dy = fabs(y2 - y1);

		p = 2 * dx - dy;

		x = x1;
		y = y1;

		glBegin(GL_POINTS);
		while (y <= y2)
		{
			glVertex2f(x, y);
			y = y + 1;

			if (p >= 1)
			{
				if (M >= 1)
					x = x + 1;
				else
					x = x - 1;
				p = p + 2 * dx - 2 * dy;

			}
			else {
				x = x;
				p = p + 2 * dx;
			}

		}
		glEnd();

	}
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {


	std::cout << "Enter x1 coordinate" << std::endl;
	std::cin >> xCor1;

	std::cout << "Enter y1 coordinate" << std::endl;
	std::cin >> yCor1;

	std::cout << "Enter x2 coordinate" << std::endl;
	std::cin >> xCor2;

	std::cout << "Enter y2 coordinate" << std::endl;
	std::cin >> yCor2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Brenham's Line Drawing Algo");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();


	return 0;
}