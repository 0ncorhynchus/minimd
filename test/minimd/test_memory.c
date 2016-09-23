#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <minimd/memory.h>

void test_alloc() {
    float* vec3 = alloc_float(3);
    CU_ASSERT_PTR_NOT_NULL_FATAL(vec3);
    for (size_t i = 0; i < 3; ++i) {
        CU_ASSERT_EQUAL(0.0, vec3[i]);
    }
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Memory", NULL, NULL);

    CU_add_test(suite, "test alloc", test_alloc);

    CU_basic_run_suite(suite);
    int exit_code = CU_get_number_of_failures() == 0 ? 0 : 1;
    CU_cleanup_registry();

    return exit_code;
}
