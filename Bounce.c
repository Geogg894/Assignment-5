#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//including  packages necessary to assignment.



/*
 =======================================================================================================================
 Name        : Bounce.c
 Author      : George Garxenaj
 Version     :
 Copyright   : Your copyright notice
 Description : Simulates the bouncing of a single ball under the influence of an energy loss parameter and other factors
 ========================================================================================================================
 */

    int main (void){

   #define  WIDTH 600
	//defines the width of the screen in pixels
	# define HEIGHT 600
	//distance from top of the screen to ground plane
	# define OFFSE 200
	//distance from bottom of screen to ground plane
	#define g 9.8
	//MKS gravitational constant 9.8m/s^2
	#define Pi 3.141592654
	//value of pi
    printf("This double value, %.2f, is printed with 2 decimal places\n",Pi);

	//only 2 decimal places of the Pi value will be printed.

    # define mass  1.0
	//Mass of the ball(kg)
	#define Xinit 5.0
	//Initial ball location (X)
	#define TICK 0.1
	//Clock tic duration (sec)
	#define ETHR 0.01
	//If either Vx or Vy<ETHR STOP
	#define XMAX 100.0
	//Maximum value of X
	#define YMAX 100.0
	//Maximum value of Y
	#define PD 1
	//Trace point diameter
	#define k 0.0016
	//Parameter k
	#define FALSE 0
	//defines the false variable as the zero integer.
	#define TRUE ! FALSE
	// defines the boolean value true as any non-zero integer.
	#define  SCALE 600/100.0
	//Pixels/meter
    #define run
    //defines run to translate the (public void run part of java)
    #define myBall
    //defining the myBall object

	           //source: from Assignment 1 pdf.



        double Vo;
        //declaring Vo as a variable of type double.
        printf("Initial velocity of the ball in m/s [0,100]");
        //print
        scanf("%lf",&Vo);
        //scan

        double theta;
        //declaring theta as a variable of type double.
        printf("Launch angle in degrees [0,90]");
        //print
        scanf("%lf",&theta);
        //scan

        double bSize;
        //declaring bSize as a variable of type double.
        printf("Radius of the ball in meters [0.1,5]");
        //print
        scanf("%lf",&bSize);
        //scan

        double Elossparameter;
        //declaring ELossparameter as a variable of type double.
        printf("Energy loss parameter [0,1]");
        //print
        scanf("%lf",&Elossparameter);
        //scan



		//setting up user input




        const double Yo=bSize;
		//Initial ball location (Y)


		myBall(Xinit*SCALE,(HEIGHT-bSize)*SCALE,2*bSize*SCALE,2*bSize*SCALE);

		//initial position of ball and its dimensions


        int TEST=FALSE;
        //creating variable for while loop

		//Initialize Variables
		double Vt=(mass*g)/(4*Pi*bSize*bSize*k);
		//terminal velocity

		double Vox=(Vo*cos(theta*Pi/180));
		//x component of initial velocity

		double Voy=(Vo*sin(theta*Pi/180));
		//y component of initial velocity

		double Xlast=Xinit;
		double Ylast= Yo;
		double time=0;
                double Xo = Xinit;

                //source: Assignment 1 pdf.



		//Simulation loop
		//will run while the boolean variable remains as TRUE.


        while(!TEST) {
			double X= Xo+Vox*Vt/g*(1-exp(-g*time/Vt));
			//X coordinate of ball

			double Y=bSize + Vt/g*(Voy+Vt)*(1-exp(-g*time/Vt))-Vt*time;
			//Y coordinate of ball

			double Vx=(X-Xlast)/TICK;
			//X component of ball's velocity

			double Vy=(Y-Ylast)/TICK;
			//Y component of ball's velocity


			//Initializing X,Y,Vx,Vy in loop
			//Source: Assignment 1 pdf.

			Xlast=X;
			Ylast=Y;

			//X and Y values to be used in subsequent iterations



			if (!TEST)  printf //print following values on console if test true
			("t: %.2f  X: %.2f  Y: %.2f  Vx: %.2f  Vy:%.2f\n", time,Xlast+X,Y,Vx,Vy);

			//source: Assignment 1 pdf.



			time+=TICK;


			//Large TICK, could lead to error/ball going slightly below the plank

			//sets time as a sum of clock tick
			//A second pause between each tick

			if(Y<=bSize&&Vy<0) {
				double KEx=((double) 0.5* mass* (pow(Vx, 2)))*(1-Elossparameter);

				//Formula for x component of kinetic energy


				 double KEy=((double) 0.5* mass* (pow(Vy, 2)))*(1-Elossparameter);

				//Formula for Y component of kinetic energy

				 Vox = sqrt(2*KEx);  // Resulting horizontal velocity
				Voy = sqrt(2*KEy);  // Resulting vertical velocity )

				Xo=Xlast;
				Y=bSize;
				time=0;
				X=0;

				//parameters for bouncing of the ball to occur

                                if ((KEx <= ETHR) | (KEy <= ETHR)) break;

                                //if statement source: Assignment 1 pdf.



                                if(X>XMAX||Y>YMAX)

                                { printf("ERROR!");

                                // ERROR if XMAX or YMAX surpassed by ball

                                }


			}

		}
    }















