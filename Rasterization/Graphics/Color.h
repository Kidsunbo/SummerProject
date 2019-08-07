//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_COLOR_H
#define SUMMERPROJECT_COLOR_H



namespace Kie {
    class Color {
    private:
        float r;
        float g;
        float b;
    public:
        float getR() const;

        float getG() const;

        float getB() const;

    public:
        Color(int r, int g, int b);

        Color(float r, float g, float b, bool normalized = true);

        Color operator +(Color& color);

        Color operator -(Color& color);
    };
}


#endif //SUMMERPROJECT_COLOR_H
