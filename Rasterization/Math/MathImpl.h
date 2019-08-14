//
// Created by bxs863 on 12/08/2019.
//

#ifndef SUMMERPROJECT_MATHIMPL_H
#define SUMMERPROJECT_MATHIMPL_H


#include <array>
#include <cmath>
#include <ostream>
#include <fstream>


/**
 * This is the implemtation part of Math module, it contains Vector and Matrix.
 */
namespace Kie::Math::Impl {
    /**
     * Declaration of Vector with various length
     * @tparam N
     */
    template<int N>
    class Vec;

    /**
     * Declaration of Matrix with various size
     * @tparam N
     */
    template<int N>
    class Mat;

    /**
     * Function overloading for Vector, which has a pretty print to debug
     * @tparam N
     * @param os
     * @param vec
     * @return
     */
    template<int N>
    std::ostream &operator<<(std::ostream &os, Vec<N> vec) {
        os << "[";
        for (int i = 0; i < N; i++) {
            os << vec.arr[i];
            if (i != N - 1) os << ",";
        }
        os << "]";
        return os;
    }

    /**
     * Function overloading for file IO,which mainly used to write to files
     * @tparam N
     * @param file
     * @param vec
     * @return
     */
    template<int N>
    std::fstream &operator<<(std::fstream &file, Vec<N> vec) {
        for (int i = 0; i < N; i++) {
            file << vec.arr[i];
            if (i != N - 1) file << " ";
        }
        return file;
    }

    /**
     * This is the main part of Vec class, which contains the data and defines several functions
     * @tparam N
     */
    template<int N>
    class Vec {

        // Friend
        friend std::ostream &operator<<<N>(std::ostream &os, Vec<N> vec);

        friend std::fstream &operator<<<N>(std::fstream &os, Vec<N> vec);

        friend class Mat<N>;


    protected:
        std::array<float, N> arr{}; // Data with initialization

        Vec() = default; //Constructor is protected which can only be used in subclass and this class

    public:
        /**
         * Constructor with initializer list
         * @param li
         */
        Vec(std::initializer_list<float> li) {
            int size = std::min(static_cast<int>(li.size()), N);
            for (int i = 0; i < size; i++) {
                arr[i] = *(li.begin() + i);
            }
        }

        /**
         * Initialize all the items with the same value
         * @param num
         */
        Vec(float num) {
            for (auto &i:arr) {
                i = num;
            }
        }

        /**
         * Copy constructor
         * @param vec
         */
        Vec(const Vec &vec) {
            for (int i = 0; i < arr.size(); i++) {
                arr[i] = *(vec.arr.begin() + i);
            }
        }

        /**
         * Move constructor
         * @param vec
         */
        Vec(Vec &&vec) {
            this->arr = std::move(vec.arr);
        }

        /**
         * Normalize the vector, and return the result without modifying the original vector
         * @return
         */
        Vec normalize() {
            float l = 0.0f;
            for (int i = 0; i < N; i++) {
                l += arr[i] * arr[i];
            }
            l = std::sqrt(l);
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] / l;
            }
            return res;
        }

        /**
         * Negative the vector
         * @return
         */
        Vec operator-() const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = -this->arr[i];
            }
            return res;
        }

        /**
         * Add the vector with another one, without modifying the original one
         * @param vec
         * @return
         */
        Vec operator+(const Vec &vec) const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] + vec.arr[i];
            }
            return res;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param num
         * @return
         */
        Vec operator+(float num) const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] + num;
            }
            return res;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param vec
         * @return
         */
        Vec &operator+=(const Vec &vec) {
            for (int i = 0; i < N; i++) {
                arr[i] += vec.arr[i];
            }
            return *this;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param num
         * @return
         */
        Vec &operator+=(float num) {
            for (int i = 0; i < N; i++) {
                arr[i] += num;
            }
            return *this;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param vec
         * @return
         */
        Vec operator-(const Vec &vec)const  {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] - vec.arr[i];
            }
            return res;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param vec
         * @return
         */
        Vec &operator-=(const Vec &vec) {
            for (int i = 0; i < N; i++) {
                arr[i] -= vec.arr[i];
            }
            return *this;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param vec
         * @return
         */
        Vec operator*(const Vec &vec) const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] * vec.arr[i];
            }
            return res;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param num
         * @return
         */
        Vec operator*(float num) const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] * num;
            }
            return res;
        }

        Vec operator/(float num) const {
            Vec res;
            for (int i = 0; i < N; i++) {
                res.arr[i] = arr[i] / num;
            }
            return res;
        }

        /**
         * Same meaning with Mathematics meaning
         * @param vec
         * @return
         */
        Vec &operator*=(const Vec &vec) {
            for (int i = 0; i < N; i++) {
                arr[i] = arr[i] * vec.arr[i];
            }
            return *this;
        }


        /**
         * Same meaning with Mathematics meaning
         * @param num
         * @return
         */
        Vec &operator*=(float num) {
            for (int i = 0; i < N; i++) {
                arr[i] = arr[i] * num;
            }
            return *this;
        }

        Vec &operator/=(float num) {
            for (int i = 0; i < N; i++) {
                arr[i] = arr[i] / num;
            }
            return *this;
        }

        /**
         * Copy assignment operator overloading
         * @param vec
         * @return
         */
        Vec &operator=(const Vec &vec) {
            for (int i = 0; i < N; i++) {
                arr[i] = vec.arr[i];
            }
            return *this;
        }

        /**
         * Move assignment operator overloading
         * @param vec
         * @return
         */
        Vec &operator=(Vec &&vec) noexcept {
            arr = vec.arr;
            return *this;
        }

        /**
         * Access by index
         * @param index
         * @return
         */
        float& operator[](int index){
            return arr[index];
        }

        /**
         * Overloading for const object
         * @param index
         * @return
         */
        float operator[](int index) const{
            return arr[index];
        }

        /**
         * Dot product with another function
         * @param vec
         * @return
         */
        float dotProduct(const Vec &vec) {
            float res = 0.0f;
            for (int i = 0; i < N; i++) {
                res += arr[i] * vec.arr[i];
            }
            return res;
        }

    };


    /**
     * Output for matrix
     * @tparam N
     * @param os
     * @param mat
     * @return
     */
    template<int N>
    std::ostream &operator<<(std::ostream &os, Mat<N> mat) {
        os << "["<<std::endl;
        for (int i = 0; i < N; i++) {
            os<<"  ";
            for (int j = 0; j < N; j++) {
                os << mat.mat[i][j];
                if (j != N - 1) os << ",";
            }
            os<<std::endl;
        }
        os << "]";
        return os;
    }

    /**
     * File io for matrix
     * @tparam N
     * @param file
     * @param mat
     * @return
     */
    template<int N>
    std::fstream &operator<<(std::fstream &file, Mat<N> mat) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                file << mat.mat[i][j];
                if (j != N - 1) file << " ";
            }
            file<<'|';
        }
        return file;
    }

    template<int N>
    class Mat {
        Mat() {
            for(auto& i : mat){
                i=std::array<float,N>{};
            }
        } // it could be Mat()=delete;
        friend std::fstream &operator<< <N>(std::fstream &file, Mat<N> mat);
        friend std::ostream &operator<< <N>(std::ostream &os, Mat<N> mat);

    protected:
        std::array<std::array<float, N>, N> mat;
    public:

        Mat(float num) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    mat[i][j] = num;
                }
            }
        }

        Mat(std::initializer_list<std::array<float, N>> li) {
            int size = std::min(static_cast<int>(li.size()), N);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < N; j++) {
                    mat[i][j] = (*(li.begin() + i))[j];
                }
            }
        }

        Mat(const Mat &other) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }

        Mat(Mat &&other) {
            mat = std::move(other.mat);
        }

        Mat operator+(Mat &other) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = mat[i][j] + other.mat[i][j];
                }
            }
            return res;
        }

        Mat operator-(Mat &other) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = mat[i][j] - other.mat[i][j];
                }
            }
            return res;
        }

        Mat operator+(float num) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = mat[i][j] + num;
                }
            }
            return res;
        }

        Mat operator-(float num) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = mat[i][j] - num;
                }
            }
            return res;
        }

        Mat operator*(float num) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = mat[i][j] * num;
                }
            }
            return res;
        }

        Mat operator*(const Mat &other) {
            Mat res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    float tempRes = 0.0f;
                    for(int temp=0;temp<N;temp++){
                        tempRes+=mat[i][temp]*other.mat[temp][j];
                    }
                    res.mat[i][j] = tempRes;
                }
            }
            return res;
        }

        Vec<N> operator*(const Vec<N> &vec) {
            Vec<N> res;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                     res[i] +=mat[i][j]*vec[j];
                }
            }
            return res;
        }

        Mat& operator=(const Mat &other) {
            this->mat = other.mat;
            return *this;
        }

        Mat& operator=(Mat&& other) {
            this->mat = other.mat;
            return *this;
        }

        std::array<float,N>& operator[](int index){
            return mat[index];
        }

        std::array<float,N> operator[](int index) const{
            return mat[index];
        }

    };

    class Interpolation{
        float _start=0.0f;
        float _end = 0.0f;
        float _step = 0.0f;
    public:
        Interpolation(float start,float end,int count):_start(start),_end(end){
            _step = (end-start)/ static_cast<float>(count);
        }

        Interpolation& begin(){
            return *this;
        }

        Interpolation& end(){
            return *this;
        }

        float operator*(){
            return _start;
        }

        bool operator!=(Interpolation& other){
            return _start<_end;
        }

        float operator++(){
            _start+=_step;
            return _start;
        }

    };

}
#endif //SUMMERPROJECT_MATHIMPL_H
