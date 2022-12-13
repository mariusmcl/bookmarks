
// Following definitions are adapted from https://github.com/RayTracing/raytracing.github.io

//==============================================================================================
// Originally written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==============================================================================================

#include <cmath>
#include <iostream>


class vec3 {
    public:
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        double e[3];
};


// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

class Ray {
    public:
        vec3 origin;
        vec3 direction;
};

class Triangle {
    public:
        vec3 V0;
        vec3 V1;
        vec3 V2;
};

/**
 * Returns the result of a ray-triangle intersection
*/
class Result {
    public:
        bool hit;
        double intersectionDistance;
        vec3 intersectionPoint;
        std::string reason;
};

inline std::ostream& operator<<(std::ostream &out, const Result &res) {
    return out << "Hit:" << res.hit << "Distance: " << res.intersectionDistance << "Location" << res.intersectionPoint;
}


Result * intersect(Ray ray, Triangle triangle){
    vec3 N = cross(triangle.V1 - triangle.V0, triangle.V2 - triangle.V0);  // Normal vector of the triangle

    double denominator = dot(ray.direction, N);
    //std::cout << "ray.direction:" << ray.direction <<  "\n";
    //std::cout << "N :" << N  <<  "\n";

    if (abs(denominator) < 1e-8){
        // Ray is parallel to the triangle's plane
        //std::cout << "Parallel to plane" << "\n";
        Result * res_ptr = new Result();
        res_ptr->hit = false;
        res_ptr->reason = "Parallel to plane";
        return res_ptr;
    }

    double t = dot(triangle.V0 - ray.origin, N) / denominator;

    if(t < 0){
        // Triangle is behind ray
        //std::cout << "Triangle behind ray" << "\n";
        Result * res_ptr = new Result();
        res_ptr->hit = false;
        res_ptr->reason = "Triangle behind ray";
        return res_ptr;
    }

    vec3 P = ray.origin + t * ray.direction;

    vec3 edge0 = triangle.V1 - triangle.V0;
    vec3 edge1 = triangle.V2 - triangle.V1;
    vec3 edge2 = triangle.V0 - triangle.V2;

    vec3 C0 = cross(edge0, P - triangle.V0);
    vec3 C1 = cross(edge1, P - triangle.V1);
    vec3 C2 = cross(edge2, P - triangle.V2);

    double scores [3] = {dot(N, C0), dot(N, C1), dot(N, C2)};

    // If all the dot products have the same sign, the point is inside the triangle
    bool check = (scores[2] < 0) == (scores[0] < 0);
    for(int j = 0; j < 2;  j++){
        if(!check){
            //std::cout << "Unequal signs on index " << j << "\n";
            Result * res_ptr = new Result();
            res_ptr->hit = false;
            res_ptr->reason = "Outside of triangle";
            return res_ptr;
        }
        check = (scores[j] < 0) == (scores[j+1] < 0);
    }

    Result* res_ptr = new Result();
    res_ptr->hit = true;
    res_ptr->intersectionDistance = (t * ray.direction).length();
    res_ptr->intersectionPoint = P;

    return res_ptr;

};
