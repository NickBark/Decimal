#include <check.h>
#include <stdio.h>

#include "s21_decimal.h"

START_TEST(is_less) {
    s21_decimal ppp1 = {{12, 11, 10, 0b10110000000000011000000000000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0b00110000000000011000000000000000}};

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 1);

    ppp1.bits[0] = 12;
    ppp1.bits[1] = 11;
    ppp1.bits[2] = 10;
    ppp1.bits[3] = 0b10110000000000011000000000000000;

    ppp2.bits[0] = 11;
    ppp2.bits[1] = 11;
    ppp2.bits[2] = 10;
    ppp2.bits[3] = 0b10110000000000011000000000000000;

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 1);

    ppp1.bits[0] = 12;
    ppp1.bits[1] = 11;
    ppp1.bits[2] = 10;
    ppp1.bits[3] = 0b00110000100000010000000000000000;

    ppp2.bits[0] = 11;
    ppp2.bits[1] = 11;
    ppp2.bits[2] = 10;
    ppp2.bits[3] = 0b00110000000000011000000000000000;

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 1);
}
END_TEST

Suite *s21_decimal_suite(void) {
    Suite *suite = suite_create("s21_decimal");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of s21_decimal");

    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, is_less);

    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main() {
    int failed_count = 0;
    Suite *suite = s21_decimal_suite();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}