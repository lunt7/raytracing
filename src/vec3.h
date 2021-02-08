#ifndef VEC3_H
#define VEC3_H

#include <cmath>

struct vec3 {
    vec3() : e{0.0, 0.0, 0.0} {}
    vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec3& operator+=(const vec3& v) {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    vec3& operator*=(double k) {
        e[0] *= k;
        e[1] *= k;
        e[2] *= k;
        return *this;
    }

    vec3& operator/=(double k) {
        return *this *= 1/k;
    }

    double magnitude() const {
        return sqrt(magnitude_squared());
    }

    double magnitude_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    double e[3];
};

using point3 = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2] << "\n";
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0],
                u.e[1] + v.e[1],
                u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0],
                u.e[1] - v.e[1],
                u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0],
                u.e[1] * v.e[1],
                u.e[2] * v.e[2]);
}

inline vec3 operator*(double k, const vec3& v) {
    return vec3(k * v.e[0],
                k * v.e[1],
                k * v.e[2]);
}

inline vec3 operator*(const vec3& v, double k) {
    return k * v;
}

inline vec3 operator/(const vec3& v, double k) {
    return (1/k) * v;
}

inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0] +
           u.e[1] * v.e[1] +
           u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.magnitude();
}

#endif

