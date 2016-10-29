#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <minimd/container.h>

void test_alloc() {
    Container* cont = alloc_cont(1024);
    CU_ASSERT_PTR_NOT_NULL_FATAL(cont);
    CU_ASSERT_PTR_NOT_NULL(cont->mass);
    CU_ASSERT_PTR_NOT_NULL(cont->coordinates);
    CU_ASSERT_PTR_NOT_NULL(cont->velocities);
    dealloc_cont(cont);
}

void test_get_coordinate() {
    const size_t size = 3;

    Container* cont = alloc_cont(size);
    float vec[3];
    for (size_t i = 0; i < size; ++i) {
        get_coordinate(cont, i, vec);
        CU_ASSERT_EQUAL(vec[0], 0.0);
        CU_ASSERT_EQUAL(vec[1], 0.0);
        CU_ASSERT_EQUAL(vec[2], 0.0);
    }
    dealloc_cont(cont);
}

void test_set_coordinate() {
    Container* cont = alloc_cont(3);
    set_coordinate(cont, 1, 10.0, 2.0, 5.0);
    float vec[3];
    get_coordinate(cont, 1, vec);
    CU_ASSERT_EQUAL(vec[0], 10.0);
    CU_ASSERT_EQUAL(vec[1],  2.0);
    CU_ASSERT_EQUAL(vec[2],  5.0);
    dealloc_cont(cont);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Container", NULL, NULL);

    CU_add_test(suite, "test alloc", test_alloc);
    /* CU_add_test(suite, "test get_coordinate", test_get_coordinate); */
    /* CU_add_test(suite, "test set_coordinate", test_set_coordinate); */

    CU_basic_run_suite(suite);
    int exit_code = CU_get_number_of_failures() == 0 ? 0 : 1;
    CU_cleanup_registry();

    return exit_code;
}

