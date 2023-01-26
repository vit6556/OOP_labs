#include <gtest/gtest.h>
#include <diagram.h>

using namespace diagram;

TEST(Constructor, default_values) {
    Diagram *d = new Diagram();
    diagram::signal *v1 = new diagram::signal[10];
    for (int i = 0; i < 10; ++i)
        v1[i] = diagram::signal{'0', 1};

    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 10);

    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Constructor, const_values) {
    Diagram *d = new Diagram(20, '1', 2);
    diagram::signal *v1 = new diagram::signal[20];
    for (int i = 0; i < 20; ++i)
        v1[i] = diagram::signal{'1', 2};

    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 20);

    for (int i = 0; i < 20; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Constructor, ascii_values) {
    Diagram *d = new Diagram(5, "01XX1", 2);
    diagram::signal *v1 = new diagram::signal[5];
    v1[0] = diagram::signal{'0', 2};
    v1[1] = diagram::signal{'1', 2};
    v1[2] = diagram::signal{'X', 2};
    v1[3] = diagram::signal{'X', 2};
    v1[4] = diagram::signal{'1', 2};


    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 5);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Methods, get_signals) {
    Diagram *d = new Diagram(5, '1', 20);
    diagram::signal *v1 = new diagram::signal[5];
    for (int i = 0; i < 5; ++i)
        v1[i] = diagram::signal{'1', 20};

    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 5);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Methods, copy) {
    Diagram *d = new Diagram(5, '1', 20);
    diagram::signal *v1 = new diagram::signal[10];
    for (int i = 0; i < 10; ++i)
        v1[i] = diagram::signal{'1', 20};

    d->copy(1);
    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 10);

    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Methods, rotate_left) {
    Diagram *d = new Diagram(5, "01XX1", 2);
    diagram::signal *v1 = new diagram::signal[5];
    v1[0] = diagram::signal{'1', 2};
    v1[1] = diagram::signal{'X', 2};
    v1[2] = diagram::signal{'X', 2};
    v1[3] = diagram::signal{'1', 2};
    v1[4] = diagram::signal{'0', 2};

    d->rotate_left(1);
    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 5);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Methods, rotate_right) {
    Diagram *d = new Diagram(5, "01XX1", 2);
    diagram::signal *v1 = new diagram::signal[5];
    v1[0] = diagram::signal{'1', 2};
    v1[1] = diagram::signal{'0', 2};
    v1[2] = diagram::signal{'1', 2};
    v1[3] = diagram::signal{'X', 2};
    v1[4] = diagram::signal{'X', 2};

    d->rotate_right(1);
    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 5);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

TEST(Methods, update_signal) {
    Diagram *d = new Diagram(5, "01XX1", 2);
    diagram::signal *v1 = new diagram::signal[5];
    v1[0] = diagram::signal{'0', 2};
    v1[1] = diagram::signal{'1', 2};
    v1[2] = diagram::signal{'0', 3};
    v1[3] = diagram::signal{'X', 2};
    v1[4] = diagram::signal{'1', 2};

    d->update_signal(2, '0', 3);
    diagram::signal *v2 = d->get_signals();

    ASSERT_EQ(d->get_length(), 5);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }

    delete d;
    delete v1;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}