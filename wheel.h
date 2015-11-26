#ifndef __WHEEL_H__ 
#define __WHEEL_H__ 
//
// draw a square
// 
#ifdef __cplusplus
extern "C" {
#endif


void wheel(double r, double m, double R, double h1, double h2, Color color, int rotateDirection);
void twowheels(double r, double m, double R, double h1, double h2, double distance, Color color, int rotateDirection);
void threewheels(double r, double m, double R, double h1, double h2, double distance, Color color, int rotateDirection);

#ifdef __cplusplus
}
#endif

#endif // __WHEEL_H__ 
