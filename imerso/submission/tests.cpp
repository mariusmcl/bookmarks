#include "intersect.h"
#include <iostream>

void print_test_result(Result* res_ptr, int test_number){
    if(res_ptr->hit == 1){
        std::cout << "Test[" + std::to_string(test_number) + "]: PASS.\n";
    }
    else{
        std::cout << "Test[" + std::to_string(test_number) + "]: FAILED. Reason: " + res_ptr->reason + "\n";
    }
}

void print_test_prompt(std::string prompt, int test_number){
    std::cout << "Test[" + std::to_string(test_number) + "]: -- " + prompt + " --" << "\n";
}


int main(){
    
    print_test_prompt("Hits triangle orthogonally", 1);

    Result* answer1 = intersect(Ray({vec3(0, 0, 0), vec3(0, 0, -1)}), Triangle({vec3(-1, -1, -5), vec3(1, -1, -5), vec3(0, 1, -5)}));

    print_test_result(answer1, 1);

    print_test_prompt("Hits triangle orthogonally, different vertex order", 2);

    Result* answer2 = intersect(Ray({vec3(0, 0, 0), vec3(0, 0, -1)}), Triangle({ vec3(1, -1, -5), vec3(-1, -1, -5), vec3(0, 1, -5)}));

    print_test_result(answer2, 2);


    print_test_prompt("Hits triangle at off-angle", 3);

    Result* answer3 = intersect(Ray({vec3(0, 0, 0), vec3(0, 0, -1)}), Triangle({vec3(-1, -1, -10), vec3(1, -1, -10), vec3(0, 1, -5)}));

    print_test_result(answer3, 3);

    print_test_prompt("Triangle behind ray", 4);

    Result* answer4 = intersect(Ray({vec3(0, 0, 0), vec3(0, 0, 1)}), Triangle({vec3(-1, -1, -5), vec3(1, -1, -5), vec3(0, 1, -5)}));

    print_test_result(answer4, 4);

    print_test_prompt("Triangle behind ray, switched signs", 5);

    Result* answer5 = intersect(Ray({vec3(0, 0, 0), vec3(0, 0, -1)}), Triangle({vec3(-1, -1, 5), vec3(1, -1, 5), vec3(0, 1, 5)}));

    print_test_result(answer5, 5);

    print_test_prompt("Ray parallel to triangle", 6);

    Result* answer6 = intersect(Ray({vec3(2, -2, 0), vec3(0, 1, 0)}), Triangle({vec3(-1, -1, 5), vec3(1, -1, 5), vec3(0, 1, 5)}));

    print_test_result(answer6, 6);


    print_test_prompt("Hits outside of triangle", 7);

    Result* answer7 = intersect(Ray({vec3(1, -1, 1), vec3(0, 2, 1)}), Triangle({vec3(-1, -1, 5), vec3(1, -1, 5), vec3(0, 1, 5)}));

    print_test_result(answer7, 7);

}