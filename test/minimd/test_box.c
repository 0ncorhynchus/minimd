#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <math.h>
#include <minimd/box.h>

void test_alloc() {
    Container* container = alloc_cont(3);
    Box* box = alloc_normal_box(container);
    dealloc_cont(container);
}

void test_num_beads() {
    Container* container = alloc_cont(3);
    Box* box = alloc_normal_box(container);
    CU_ASSERT_EQUAL(num_beads(box), 3);
    dealloc_cont(container);
}

void test_get_direction() {
    Container* container = alloc_cont(3);
    Box* box = alloc_normal_box(container);
    set_coordinate(container, 0, 3.0, 0.0, 0.0);
    set_coordinate(container, 1, 0.0, 0.0, 1.0);
    set_coordinate(container, 2, 0.0, 2.0, 0.0);
    float vec[3];

    get_direction(box, 0, 1, vec);
    CU_ASSERT_EQUAL(vec[0], -3.0);
    CU_ASSERT_EQUAL(vec[1], 0.0);
    CU_ASSERT_EQUAL(vec[2], 1.0);

    get_direction(box, 1, 2, vec);
    CU_ASSERT_EQUAL(vec[0], 0.0);
    CU_ASSERT_EQUAL(vec[1], 2.0);
    CU_ASSERT_EQUAL(vec[2], -1.0);

    get_direction(box, 2, 0, vec);
    CU_ASSERT_EQUAL(vec[0], 3.0);
    CU_ASSERT_EQUAL(vec[1], -2.0);
    CU_ASSERT_EQUAL(vec[2], 0.0);

    dealloc_cont(container);
}

void test_get_length() {
    Container* container = alloc_cont(3);
    Box* box = alloc_normal_box(container);
    set_coordinate(container, 0, 3.0, 0.0, 0.0);
    set_coordinate(container, 1, 0.0, 0.0, 1.0);
    set_coordinate(container, 2, 0.0, 2.0, 0.0);

    CU_ASSERT_EQUAL(get_length(box, 0, 1), sqrt(10.0));
    CU_ASSERT_EQUAL(get_length(box, 1, 2), sqrt(5.0));
    CU_ASSERT_EQUAL(get_length(box, 2, 0), sqrt(13.0));

    dealloc_cont(container);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Box", NULL, NULL);

    CU_add_test(suite, "test alloc", test_alloc);
    CU_add_test(suite, "test num_beads", test_alloc);
    CU_add_test(suite, "test get_direction", test_get_direction);

    CU_basic_run_suite(suite);
    int exit_code = CU_get_number_of_failures() == 0 ? 0 : 1;
    CU_cleanup_registry();

    return exit_code;
}
