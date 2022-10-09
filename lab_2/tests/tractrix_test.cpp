#include <gtest/gtest.h>
#include <tractrix.h>

TEST(TractrixMethods, get_length) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(10, t.get_length(), 0.0001);
}

TEST(TractrixMethods, set_length) {
    tractrix::Tractrix t(10);
    t.set_length(15);
    ASSERT_NEAR(15, t.get_length(), 0.0001);
}

TEST(TractrixMethods, get_point) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(-1.74267, t.get_point(45).x, 0.0001);
    ASSERT_NEAR(7.07107, t.get_point(45).y, 0.0001);
}

TEST(TractrixMethods, get_arc_length) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(3.46574, t.get_arc_length(45), 0.0001);
}

TEST(TractrixMethods, get_radius_of_curvature) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(10, t.get_radius_of_curvature(45), 0.0001);
}

TEST(TractrixMethods, get_area) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(39.2699, t.get_area(45), 0.0001);
}

TEST(TractrixMethods, get_area_of_surface) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(314.159, t.get_area_of_surface(45), 0.001);
}

TEST(TractrixMethods, get_volume) {
    tractrix::Tractrix t(10);
    ASSERT_NEAR(523.599, t.get_volume(45), 0.001);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}