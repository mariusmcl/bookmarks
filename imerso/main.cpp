#include "intersect.h"
// using namespace glm;

void main(){
    
    Triangle triangle{vec3(-1, 0, 1), vec3(1, 0, 1), vec3(0, 2, 1)};

    Ray ray{vec3(0, 0, 0), vec3(0, 0, 1), 0}

    Result* answer = intersect(ray, triangle);
    

}