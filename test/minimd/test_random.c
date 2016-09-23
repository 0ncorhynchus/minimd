#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <minimd/random.h>

void test_uniform() {
    for (int i = 0; i < 1000; ++i) {
        float rnd = uniform();
        CU_ASSERT(rnd >= 0 && rnd < 1);
    }
}

void test_uniform_int() {
    for (int i = 0; i < 1000; ++i) {
        int rnd = uniform_int(10);
        CU_ASSERT(rnd >= 0 && rnd <= 10);
    }
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Random", NULL, NULL);

    CU_add_test(suite, "test uniform", test_uniform);

    CU_basic_run_suite(suite);
    int exit_code = CU_get_number_of_failures() == 0 ? 0 : 1;
    CU_cleanup_registry();

    return exit_code;
}

