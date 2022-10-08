#ifndef TRACTRIX_H
#define TRACTRIX_H

namespace tractrix {
    struct Point {
        double x = 0;
        double y = 0;
    };


    class Tractrix {
        private:
            double length;
        public:
            Tractrix();
            Tractrix(double l);
            void set_length(double l);
            double get_length();

            Point get_point(double square);
            double get_arc_length(double square);
            double get_radius_of_curvature(double square);
            double get_area(double square);
            double get_area_of_surface(double square);
            double get_volume(double square);

    };
}
#endif //TRACTRIX_H