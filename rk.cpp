#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const float g = -9.8;

template <class T>
void escribe(string archivo, T* datos1, T*datos2, T* datos3, int n_dat){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < n_dat; i++){
    outfile << datos1[i]<< "\t" << datos2[i] << "\t" << datos3[i] << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}

float f0x (float x);
float f0y (float y);

float f1x (float vx, float magv, float k, float n);
float f1y (float vy, float magv, float k, float n);

void rk4 (float* x, float* y, float* vx, float* vy, float h, float k, float n, int pasos);

int main(){
    float n[3] = {1, 3/2, 2};
    
    string nombresx[3] = {"ed1x.txt", "ed32x.txt", "ed2x.txt"};
    string nombresy[3] = {"ed1y.txt", "ed32y.txt", "ed2y.txt"};

    float k=3;

    float vx0=2;
    float vy0=4;
    float x0=0;
    float y0=0;

    float tmin = 0;
    float tmax = 10;
    float h = 0.1;
    int pasos = (tmax-tmin)/h;
    
    cout << pasos << endl;

    float* t = new float[pasos];
    t[0]=h;
    for(int i = 1; i<pasos; i++){
        t[i]=t[i-1]+h;
    }
    
    for(int i=0; i<3; i++){
        float* x = new float[pasos];
        x[0]=x0;
        float* y = new float[pasos];
        y[0]=y0;
        float* vx = new float[pasos];
        vx[0]=vx0;
        float* vy = new float[pasos];
        vy[0]=vy0;

        rk4(x,y,vx,vy,h,k,n[i],pasos);

        escribe(nombresx[i], t, x, vx, pasos);
        escribe(nombresy[i], t, y, vy, pasos);

        delete[] x;
        delete[] y;
        delete[] vx;
        delete[] vy;
    }


    return 0;
}

float f0x(float x){
    return x; 
}

float f0y(float y){
    return y; 
}

float f1x (float vx, float magv, float k, float n){
    return -k*pow(vx,n)*(vx/magv);
}

float f1y (float vy, float magv, float k, float n){
    return g-k*pow(vy,n)*(vy/magv);
}

void rk4 (float* x, float* y, float* vx, float* vy, float h, float k, float n, int pasos){
    for(int i = 1; i< pasos; i++){
        float k10x, k11x, k20x, k21x, k30x, k31x, k40x, k41x;
        float k10y, k11y, k20y, k21y, k30y, k31y, k40y, k41y;

        float magv = sqrt(pow(vx[i-1],2) + pow(vy[i-1],2));
        cout << magv << "\t" << vx[i-1] << "\t" << vy[i-1] << "\t";

        k10x = h*f0x(x[i]);
        k11x = h*f1x(vx[i], magv, k, n);
        k20x = h*f0x(x[i] + k10x/2);
        k21x = h*f1x(vx[i] + k11x/2, magv, k, n);
        k30x = h*f0x(x[i] + k20x/2);
        k31x = h*f1x(vx[i] + k21x/2, magv, k, n);
        k40x = h*f0x(x[i] + k30x);
        k41x = h*f1x(vx[i] + k31x, magv, k, n);

        k10y = h*f0y(y[i]);
        k11y = h*f1y(vy[i], magv, k, n);
        k20y = h*f0y(y[i] + k10y/2);
        k21y = h*f1y(vy[i] + k11y/2, magv, k, n);
        k30y = h*f0y(y[i] + k20y/2);
        k31y = h*f1y(vy[i] + k21y/2, magv, k, n);
        k40y = h*f0y(y[i] + k30y);
        k41y = h*f1y(vy[i] + k31y, magv, k, n);

        x[i] = x[i-1] + (1.0/6.0)*(k10x + 2*k20x + 2*k30x + k40x);
        vx[i] = vx[i-1] + (1.0/6.0)*(k11x + 2*k21x + 2*k31x + k41x);
        cout << x[i] << "\t";
        y[i] = y[i-1] + (1.0/6.0)*(k10y + 2*k20y + 2*k30y + k40y);
        vy[i] = vy[i-1] + (1.0/6.0)*(k11y + 2*k21y + 2*k31y + k41y);
        cout << y[i] << endl;
    }
}


