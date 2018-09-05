#ifndef VECTOR2_H
#define VECTOR2_H

#include<math.h>
class Vec2 {
    public:
        double x, y;

        Vec2();
        Vec2(double x, double y);
        void SetPos(double x, double y);
        void SetPosY(double y);
        void SetPosX(double x);
        void Rotate(double angle); 
};

#endif // VECTOR2_H
