#include "intersect.h"
#include <iostream>

int main(){
    
    Triangle triangle{vec3(-1, -1, -5), vec3(1, -1, -5), vec3(0, 1, -5)};

    Ray ray{vec3(0, 0, 0), vec3(1, 0, -1)};

    Result* answer = intersect(ray, triangle);
    
    std::cout << *answer << "\n";

}