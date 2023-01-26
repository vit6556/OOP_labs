#include <vector>
#ifndef DIAGRAM_H
#define DIAGRAM_H

namespace diagram {
    struct signal {
        char value = '0';
        int length = 1;
    };

    class Diagram {
        private:
            int length = 10;
            signal *signals;
        public:
            Diagram();
            Diagram(int length, char value, int max_signal_length);
            Diagram(int length, std::string values, int max_signal_length);
            Diagram(int length, signal *value);
            ~Diagram();
            void copy(int amount);
            void print();
            void rotate_left(int amount);
            void rotate_right(int amount);
            void update_signal(int index, char value, int length);
            signal *get_signals();
            int get_length();
            Diagram* operator + (Diagram *d);
    };
}
#endif //DIAGRAM_H