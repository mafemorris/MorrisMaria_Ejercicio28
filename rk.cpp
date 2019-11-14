#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const float g = -9.8;

template <class T>
void escribe(string archivo, T* datos1, T*datos2, T*datos3, int n_dat){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < n_dat; i++){
    outfile << datos1[i]<< "\t" << datos2[i] << "\t" << datos3[i] << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}

void rk4 (float* vx, float* vy, float h, float k, float n, int pasos);

float f1(float vx);
float f2(float vx, float magv, float k, float n);
float f3(float vx, float magv, float k, float n);

void xs(float* t, float* vx, float* x, float x0, float pasos);
void ys(float* t, float* vy, float* y, float y0, float pasos);

int main(){
    float n[3] = {1, 3.0/2.0, 2};

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

    float* t = new float[pasos];
    t[0]=h;
    for(int i = 1; i<pasos; i++){
        t[i]=t[i-1]+h;
    }

    for(int i=0; i<3; i++){
        float* x = new float[pasos];
        float* y = new float[pasos];

        float* vx = new float[pasos];
        vx[0]=vx0;
        float* vy = new float[pasos];
        vy[0]=vy0;

        rk4(vx,vy,h,k,n[i],pasos);

        ys(t, vy, y, y0, pasos);
        xs(t, vx, x, x0, pasos);

        escribe(nombresx[i], t, x, vx, pasos);
        escribe(nombresy[i], t, x, vy, pasos);

        delete[] vx;
        delete[] vy;
    }
    

    return 0;
}
float f1(float vx){
    return vx;
}
float f2 (float vx, float magv, float k, float n){
    return -k*pow(vx,n)*(vx/magv);
}
float f3 (float vx, float magv, float k, float n){
    return -g-k*pow(vx,n)*(vx/magv);
}

void xs(float* t, float* vx, float* x, float x0, float pasos){
    for(int i = 0; i<pasos; i++){
        x[i] = x0 + t[i]*vx[i];
    }
}

void ys(float* t, float* vy, float* y, float y0, float pasos){
    for(int i = 0; i<pasos; i++){
        y[i] = y0 + t[i]*vy[i] + (1.0/2.0)*g*t[i]*t[i];
    }
}

void rk4 (float* vx, float* vy, float h, float k, float n, int pasos){
    for(int i = 1; i< pasos; i++){
        float k10x, k11x, k20x, k21x, k30x, k31x, k40x, k41x;
        float k10y, k11y, k20y, k21y, k30y, k31y, k40y, k41y;

        float magv = sqrt(pow(vx[i-1],2) + pow(vy[i-1],2));
        // cout << magv << "\t" << vx[i-1] << "\t" << vy[i-1] << "\t";

        k10x = h*f1(vx[i-1]);
        k11x = h*f2(vx[i-1], magv, k, n);
        k20x = h*f1(vx[i-1] + k11x/2);
        k21x = h*f2(vx[i-1] + k10x/2, magv, k, n);
        k30x = h*f1(vx[i-1] + k21x/2);
        k31x = h*f2(vx[i-1] + k20x/2, magv, k, n);
        k40x = h*f1(vx[i-1] + k31x);
        k41x = h*f2(vx[i-1] + k30x, magv, k, n);

        k10y = h*f1(vy[i-1]);
        k11y = h*f3(vy[i-1], magv, k, n);
        k20y = h*f1(vy[i-1] + k11y/2);
        k21y = h*f3(vy[i-1] + k10y/2, magv, k, n);
        k30y = h*f1(vy[i-1] + k21y/2);
        k31y = h*f3(vy[i-1] + k20y/2, magv, k, n);
        k40y = h*f1(vy[i-1] + k31y);
        k41y = h*f3(vy[i-1] + k30y, magv, k, n);

        vx[i] = vx[i-1] + (1.0/6.0)*(k11x + 2*k21x + 2*k31x + k41x);
        //cout << vx[i] << "\t";
        vy[i] = vy[i-1] + (1.0/6.0)*(k11y + 2*k21y + 2*k31y + k41y);
        //cout << vy[i] << endl;
    }
}