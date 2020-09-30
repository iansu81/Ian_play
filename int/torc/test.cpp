#include <iostream>

using namespace std;

float integrateFunction(float t_end, float x0, float x_d0, float dt) {
    /*
     * Write your code here.
     */
     float x_pos = x0;
     float x_dot = x_d0;
     float t = dt;
     while( t <= t_end )
     {
        float F = (x_dot < 0) ? 0.5 : -0.5;
        float x_dot_dot = -x_pos + F/4.0;
        x_pos = x_pos + x_dot*dt;
        x_dot = x_dot + x_dot_dot * dt; 
        t += dt;
     }
     return x_pos;
}


int main()
{
    cout << "Ans: " << integrateFunction(6.43, 4.713, 0.34, 0.15);

    return 0;
}