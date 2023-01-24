#include <gtest/gtest.h>
#include <vector>
#include <diagram.h>

TEST(Constructor, default_values) {
    diagram::Diagram d;
    std::vector<diagram::signal> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(diagram::signal{'0', 1});

    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Constructor, const_values) {
    diagram::Diagram d(20, '1', 2);
    std::vector<diagram::signal> v1;
    for (int i = 0; i < 20; ++i)
        v1.push_back(diagram::signal{'1', 2});

    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Constructor, ascii_values) {
    diagram::Diagram d(5, "01XX1", 2);
    std::vector<diagram::signal> v1;
    
    v1.push_back(diagram::signal{'0', 2});
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'1', 2});

    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Methods, get_signals) {
    diagram::Diagram d(5, '1', 20);
    std::vector<diagram::signal> v1;
    for (int i = 0; i < 5; ++i)
        v1.push_back(diagram::signal{'1', 20});

    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Methods, copy) {
    diagram::Diagram d(5, '1', 2);
    std::vector<diagram::signal> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(diagram::signal{'1', 2});

    d.copy(1);
    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Methods, rotate_left) {
    diagram::Diagram d(5, "01XX1", 2);
    std::vector<diagram::signal> v1;
    
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'0', 2});

    d.rotate_left(1);
    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}


TEST(Methods, rotate_right) {
    diagram::Diagram d(5, "01XX1", 2);
    std::vector<diagram::signal> v1;
    
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'0', 2});
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'X', 2});

    d.rotate_right(1);
    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

TEST(Methods, update_signal) {
    diagram::Diagram d(5, "01XX1", 2);
    std::vector<diagram::signal> v1;
    
    
    v1.push_back(diagram::signal{'0', 2});
    v1.push_back(diagram::signal{'1', 2});
    v1.push_back(diagram::signal{'0', 3});
    v1.push_back(diagram::signal{'X', 2});
    v1.push_back(diagram::signal{'1', 2});

    d.update_signal(2, '0', 3);
    std::vector<diagram::signal> v2 = d.get_signals();

    ASSERT_EQ(v1.size(), v2.size());

    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i].length, v2[i].length);
        ASSERT_EQ(v1[i].value, v2[i].value);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}