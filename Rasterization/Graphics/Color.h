//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_COLOR_H
#define SUMMERPROJECT_COLOR_H



namespace Kie {
    class Color {

        friend class InterpColor;
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

    class InterpColor{
        Color c;
        float step_r;
        float step_g;
        float step_b;
        int count;
    public:
        InterpColor(const Color& start,const Color& end,int count);

        InterpColor& begin();
        InterpColor& end();
        bool operator !=(InterpColor& other);
        Color operator*();
        Color operator++();
    };
}


#endif //SUMMERPROJECT_COLOR_H
